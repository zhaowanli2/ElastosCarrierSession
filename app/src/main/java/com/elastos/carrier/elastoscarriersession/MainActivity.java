package com.elastos.carrier.elastoscarriersession;

import android.Manifest;
import android.app.AlertDialog;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.graphics.Point;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.support.v4.app.ActivityCompat;
import android.support.v4.app.FragmentActivity;
import android.support.v4.app.FragmentTransaction;
import android.support.v4.content.ContextCompat;
import android.util.Log;
import android.view.MenuInflater;
import android.view.MenuItem;
import android.view.WindowManager;
import android.widget.Button;
import android.widget.EditText;
import android.widget.PopupMenu.OnMenuItemClickListener;
import android.view.View;
import android.view.Window;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.PopupMenu;
import android.widget.Toast;

import com.google.zxing.activity.CaptureActivity;

import java.util.ArrayList;
import java.util.List;

public class MainActivity extends FragmentActivity implements View.OnClickListener
                , OnMenuItemClickListener, ElaRpcUtils.OnElaCarrierNodeListener {
    private static final String TAG = "MainActivity";
    private LinearLayout mTabMain;
    private LinearLayout mTabMe;

    private ImageView mImgMain;
    private ImageView mImgMe;

    private MainFragment mMainFragment = null;
    private MeFragment mMeFragment = null;

    private ImageView mOtherTools;
    private List<FriendInfo> mFriendInfoList = new ArrayList<FriendInfo>();
    private boolean mHasTask = false;
    private boolean mSessionEnabled = false;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        getWindow().setSoftInputMode(WindowManager.LayoutParams.SOFT_INPUT_STATE_HIDDEN);
        requestWindowFeature(Window.FEATURE_NO_TITLE);
        setContentView(R.layout.activity_main);

        initView();
        initEvents();
        setSelect(0);
        initElaRpc();
    }

    public native void nativeCreateCarrierNodeWithSession();

    private void initElaRpc() {
        Log.d(TAG, "[initElaRpc Run] ============================0");
        nativeCreateCarrierNodeWithSession();
    }

    static {
        System.loadLibrary("log");
        System.loadLibrary("crystal");
        System.loadLibrary("elacarrier");
        System.loadLibrary("elasession");
        System.loadLibrary("Elastos.Runtime");
        System.loadLibrary("Elastos.CoreLibrary");
        System.loadLibrary("Elastos.ElaSessionRpcClient");
        System.loadLibrary("elastoscarrier");
    }

    @Override
    public void onClick(View v) {
        switch (v.getId()) {
            case R.id.id_tab_main:
                setSelect(0);
                break;
            case R.id.id_tab_frd:
                setSelect(1);
                break;
            case R.id.othertools: {
                PopupMenu popup = new PopupMenu(this, v);
                MenuInflater inflater = popup.getMenuInflater();
                inflater.inflate(R.menu.othertools, popup.getMenu());
                popup.setOnMenuItemClickListener(this);
                popup.show();
                break;
            }
            case R.id.btn_send: {
                String message = ((EditText)findViewById(R.id.et_sendmessage)).getText().toString();
                if(!"".equals(message)) {
                    mMainFragment.SendMessage(mFriendUserId, message);
                }
                else {
                    Toast.makeText(MainActivity.this, "input can't be empty", Toast.LENGTH_SHORT).show();
                }
                ((EditText)findViewById(R.id.et_sendmessage)).setText("");
            }

            default:
                break;
        }
    }

    private void enabledSendControl() {
        if (mSessionEnabled) {
            findViewById(R.id.btn_send).setEnabled(true);
            findViewById(R.id.et_sendmessage).setEnabled(true);
        }
    }


    private class RPCMSG {
        //Carrier session callback flag.
        public static final int CARRIER_CONNECTION = 0;
        public static final int CARRIER_READY = 1;
        public static final int FRIEND_CONNECTION = 2;
        public static final int FRIEND_REQUEST = 3;
        public static final int FRIEND_ADDED = 4;
        public static final int FRIEND_MESSAGE = 5;
        public static final int SESSION_REQUEST = 6;
        public static final int SESSION_READY = 7;
        public static final int STREAM_STATE_CHANGED = 8;
    }

    private boolean mCarrierNodeIsReady = false;
    private String mSelfAddress = null;
    private Handler mHandler = new Handler() {
        @Override
        public void handleMessage(android.os.Message msg) {
            switch (msg.what) {
                case RPCMSG.FRIEND_REQUEST: {
                    Bundle data = msg.getData();
                    if (data != null) {
                        String hello = data.getString(RPCKEY.HELLO);
                        String userid = data.getString(RPCKEY.USERID);
                        showAcceptRequestDialog(userid, hello);
                    }
                    break;
                }
                case RPCMSG.FRIEND_MESSAGE: {
                    String message = (String) msg.obj;
                    Log.d(TAG, "[handleMessage] ============================ FRIEND_MESSAGE, message=" + message);
                    mMainFragment.ReceiveMessage(message);
                }
                case RPCMSG.CARRIER_CONNECTION: {
                    break;
                }
                case RPCMSG.CARRIER_READY: {
                    mSelfAddress = ElaRpcUtils.GetAddress();
                    Log.d(TAG, "[handleMessage] ============================ CARRIER_READY, address=" + mSelfAddress);
                    if (mMeFragment != null) {
                        mMeFragment.setAddress(mSelfAddress, getQrcWidth());
                    }

                    //TODO: InitSession
                    ElaRpcUtils.InitElaSession();
                    break;
                }
                case RPCMSG.FRIEND_CONNECTION: {
                    if (mMainFragment != null && mFriendUserId != null && !mFriendUserId.isEmpty()) {
                        mMainFragment.showInfo(mFriendUserId);
                    }
                    break;
                }
                case RPCMSG.FRIEND_ADDED: {
                    AddFriendInfoList((String) msg.obj);
                    break;
                }
                case RPCMSG.SESSION_REQUEST: {
                    Log.d(TAG, "[SESSION_REQUEST] ============================2");
                    if (mFriendUserId != null && !mFriendUserId.isEmpty()) {
                        ElaRpcUtils.CreateElaSession(mFriendUserId);
                        mHasTask = true;
                    }
                    break;
                }
                case RPCMSG.SESSION_READY: {
                    showSimpleDialog("SESSION_READY");
                    mSessionEnabled = true;
                    enabledSendControl();
                    break;
                }
                case RPCMSG.STREAM_STATE_CHANGED: {
//                    showSimpleDialog("STREAM_STATE_CHANGED");
                    if (mHasTask) {
                        ElaRpcUtils.ReplySessionRequest(true);
                    }
                    mHasTask = false;

                    break;
                }
                default: {
                    break;
                }
            }
        }

        ;
    };

    @Override
    public void OnConnection(boolean status) {
        Log.d(TAG, "[OnConnection] ============================");
        Message msg = new Message();
        msg.what = RPCMSG.CARRIER_CONNECTION;
        msg.arg1 = status ? 1 : 0;
        mHandler.sendMessage(msg);
    }

    @Override
    public void OnReady() {
        mCarrierNodeIsReady = true;
        Log.d(TAG, "[OnReady] ============================");
        Message msg = new Message();
        msg.what = RPCMSG.CARRIER_READY;
        mHandler.sendMessage(msg);
    }

    @Override
    public void OnSessionReady() {
        Log.d(TAG, "[OnSessionReady] ============================");
        Message msg = new Message();
        msg.what = RPCMSG.SESSION_READY;
        mHandler.sendMessage(msg);
    }

    @Override
    public void OnFriendConnection(String friendid, int status) {
        Log.d(TAG, "[OnFriendConnection] ============================status=[" + status + "]");
        Message msg = new Message();
        msg.what = RPCMSG.FRIEND_CONNECTION;
        msg.arg1 = status;
        msg.obj = friendid;
        mFriendUserId = friendid;
        mHandler.sendMessage(msg);
    }

    private class RPCKEY {
        static final String HELLO = "hello";
        static final String USERID = "userid";
    }

    @Override
    public void OnFriendRequest(String userid, String hello) {
        Log.d(TAG, "[OnFriendRequest] ============================hello=[" + hello + "]");
        Message msg = new Message();
        msg.what = RPCMSG.FRIEND_REQUEST;
        Bundle data = new Bundle();
        data.putString(RPCKEY.USERID, userid);
        data.putString(RPCKEY.HELLO, hello);
        msg.setData(data);
        mHandler.sendMessage(msg);
    }

    private String mFriendUserId = null;

    @Override
    public void OnFreindAdded(String userid) {
        Log.d(TAG, "[OnFreindAdded] ============================userid=[" + userid + "]");
        Message msg = new Message();
        msg.what = RPCMSG.FRIEND_ADDED;
        msg.obj = userid;
        mFriendUserId = userid;
        mHandler.sendMessage(msg);
    }

    @Override
    public void OnSessionRequest(String userid) {
        Log.d(TAG, "[OnSessionRequest] ============================1");
        Message msg = new Message();
        msg.what = RPCMSG.SESSION_REQUEST;
        mHandler.sendMessage(msg);
    }

    @Override
    public void OnFriendMessage(String from, String msg) {
        Log.d(TAG, "[OnFriendMessage] ============================from=[" + from + "], msg=[" + msg + "]");
        Message m = new Message();
        m.what = RPCMSG.FRIEND_MESSAGE;
        m.obj = msg;
        mHandler.sendMessage(m);
    }

    @Override
    public void OnStreamStateChanged(int streamId, int state) {
        Log.d(TAG, "[OnStreamStateChanged] ============================1");
        Message m = new Message();
        m.what = RPCMSG.STREAM_STATE_CHANGED;
        m.arg1 = streamId;
        m.arg2 = state;
        mHandler.sendMessage(m);
    }

    @Override
    protected void onResume() {
        super.onResume();

        setSelect(0);
    }

    @Override
    public boolean onMenuItemClick(MenuItem item) {
        switch (item.getItemId()) {
            case R.id.scantoaddfriend: {
                startQrCode();
                break;
            }
            case R.id.createsession: {
                if (mFriendUserId != null && !mFriendUserId.isEmpty()) {
                    ElaRpcUtils.CreateElaSession(mFriendUserId);
                } else {
                    Toast.makeText(MainActivity.this, "mFriendUserId==NULL", Toast.LENGTH_SHORT).show();
                }
                break;
            }
            case R.id.sessionrequest: {
                ElaRpcUtils.SessionRequest();
                Toast.makeText(MainActivity.this, "SessionRequest", Toast.LENGTH_SHORT).show();
                break;
            }
            case R.id.sendmessage: {
                ElaRpcUtils.SendMessage(mFriendUserId, "xxxxxxxxxxxxxxxxxxxxx");
                break;
            }
            default:
                break;
        }
        return false;
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        super.onActivityResult(requestCode, resultCode, data);

        if (requestCode == QRCodeUtils.Constant.REQ_QR_CODE && resultCode == RESULT_OK) {
            Bundle bundle = data.getExtras();
            String scanResult = bundle.getString(QRCodeUtils.Constant.INTENT_EXTRA_KEY_QR_SCAN);
            mMainFragment.showInfo(scanResult);
            setSelect(0);

            //Show a dialog to add a friend
            showAddFriendDialog(scanResult);
        }
    }

    private void startQrCode() {
        if (!mCarrierNodeIsReady) {
            Toast.makeText(MainActivity.this, "The Carrier Node isn't ready.", Toast.LENGTH_SHORT).show();
            return;
        }

        if (ContextCompat.checkSelfPermission(this, Manifest.permission.CAMERA) != PackageManager.PERMISSION_GRANTED) {
            ActivityCompat.requestPermissions(MainActivity.this, new String[]{Manifest.permission.CAMERA}, QRCodeUtils.Constant.REQ_PERM_CAMERA);
            return;
        }
        Intent intent = new Intent(MainActivity.this, CaptureActivity.class);
        startActivityForResult(intent, QRCodeUtils.Constant.REQ_QR_CODE);
    }

    private void setSelect(int index) {
        resetImg();
        FragmentTransaction transaction = getSupportFragmentManager().beginTransaction();
        hideFragment(transaction);

        switch (index) {
            case 0:
                if (mMainFragment == null) {
                    mMainFragment = new MainFragment();
                    transaction.add(R.id.id_content, mMainFragment);
                } else {
                    transaction.show(mMainFragment);
                }
                mImgMain.setImageResource(R.drawable.tab_message_pressed);
                break;
            case 1:
                if (mMeFragment == null) {
                    mMeFragment = new MeFragment();
                    transaction.add(R.id.id_content, mMeFragment);
                } else {
                    transaction.show(mMeFragment);
                }
                mMeFragment.setAddress(mSelfAddress, getQrcWidth());
                mImgMe.setImageResource(R.drawable.tab_find_frd_pressed);
                break;

            default:
                break;
        }
        transaction.commit();
    }

    private void hideFragment(FragmentTransaction transaction) {
        if (mMainFragment != null) {
            transaction.hide(mMainFragment);
        }
        if (mMeFragment != null) {
            transaction.hide(mMeFragment);
        }
    }

    private void showAcceptRequestDialog(final String userid, String hello) {
        AlertDialog.Builder builder = new AlertDialog.Builder(MainActivity.this);
        builder.setIcon(R.drawable.uv);

        String title = "Add Friend Request";
        builder.setTitle(title);
        builder.setMessage(hello);
        builder.setPositiveButton("确定", new DialogInterface.OnClickListener() {
            @Override
            public void onClick(DialogInterface dialog, int which) {
                // Receive a request for adding a friend.
                ElaRpcUtils.AcceptRequest(userid);
            }
        });

        builder.setNegativeButton("取消", new DialogInterface.OnClickListener() {
            @Override
            public void onClick(DialogInterface dialog, int which) {
            }
        });

        builder.show();
    }

    private void showAddFriendDialog(String info) {
        AlertDialog.Builder builder = new AlertDialog.Builder(MainActivity.this);
        builder.setIcon(R.drawable.uv);

        final String content = info;
        builder.setTitle("Add Friend");
        builder.setMessage(info);
        builder.setPositiveButton("确定", new DialogInterface.OnClickListener() {
            @Override
            public void onClick(DialogInterface dialog, int which) {
                //Add a friend
                int result = ElaRpcUtils.AddFriend(content, "Elastos Test");
                Log.d(TAG, "[showAddFriendDialog] ============================result=[" + result + "]");
            }
        });

        builder.setNegativeButton("取消", new DialogInterface.OnClickListener() {
            @Override
            public void onClick(DialogInterface dialog, int which) {
            }
        });

        builder.show();
    }

    private void showSimpleDialog(String info) {
        AlertDialog.Builder builder = new AlertDialog.Builder(MainActivity.this);
        builder.setIcon(R.drawable.uv);

        String msg = "Only Test";
        String title = info;
        builder.setTitle(title);
        builder.setMessage(msg);
        builder.setPositiveButton("确定", new DialogInterface.OnClickListener() {
            @Override
            public void onClick(DialogInterface dialog, int which) {
            }
        });

        builder.setNegativeButton("取消", new DialogInterface.OnClickListener() {
            @Override
            public void onClick(DialogInterface dialog, int which) {
            }
        });

        builder.show();
    }

    private void resetImg() {
        mImgMain.setImageResource(R.drawable.tab_message_normal);
        mImgMe.setImageResource(R.drawable.tab_find_frd_normal);
    }

    private void initEvents() {
        mTabMain.setOnClickListener(this);
        mTabMe.setOnClickListener(this);
        mOtherTools.setOnClickListener(this);
    }

    private void initView() {
        mTabMain = (LinearLayout) findViewById(R.id.id_tab_main);
        mTabMe = (LinearLayout) findViewById(R.id.id_tab_frd);
        mImgMain = (ImageView) findViewById(R.id.id_tab_main_img);
        mImgMe = (ImageView) findViewById(R.id.id_tab_frd_img);
        mOtherTools = (ImageView) findViewById(R.id.othertools);
    }

    private void AddFriendInfoList(String userid) {
        FriendInfo info = new FriendInfo(userid);
        if (!mFriendInfoList.contains(info)) {
            mFriendInfoList.add(info);
        }
    }

    private int getQrcWidth() {
        Point point = new Point();
        getWindowManager().getDefaultDisplay().getSize(point);
        Log.d(TAG, "[showAddFriendDialog] ============================point=[" + point.toString() + "], x="+point.x);
        return point.x * 6 / 10; //60%;
    }
}