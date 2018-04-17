package com.elastos.carrier.elastoscarriersession;

import android.app.Activity;
import android.content.Context;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.LinearLayout;
import android.widget.ListView;
import android.widget.TextView;
import java.util.ArrayList;
import java.util.List;

public class ChatActivity extends Activity implements ElaRpcUtils.OnElaCarrierNodeListener {
    private static final String TAG = "ChatActivity";
    private ListView mListView;
    private List<Msg> msgList = new ArrayList<Msg>();
    private MsgAdapter msgAdapter;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_chat);

        initView();
    }

    private void initView() {
        mListView = (ListView) findViewById(R.id.listview);
        msgAdapter  = new MsgAdapter(this, R.layout.itemlayout, msgList);
        mListView.setAdapter(msgAdapter);
    }

    private Handler mHandler = new Handler() {
        @Override
        public void handleMessage(Message msg) {
            switch (msg.what) {
                case STATEMSG.RECEIVEMSG: {
                    String message = (String)msg.obj;
                    Log.d(TAG, "[handleMessage] ============================ RECEIVEMSG, message="+message);
                }
                default: {
                    Log.d(TAG, "error ============================ ");
                }
            }
        }
    };

    @Override
    public void OnConnection(boolean status) {
        //TODO
    }

    @Override
    public void OnReady() {
        //TODO
    }

    @Override
    public void OnSessionReady() {

    }

    @Override
    public void OnFriendConnection(String friendid, int status) {
        //TODO
    }

    @Override
    public void OnFriendRequest(String userid, String hello) {
        //TODO
    }

    @Override
    public void OnFreindAdded(String userid) {
        //TODO
    }

    @Override
    public void OnSessionRequest(String userid) {

    }

    @Override
    public void OnFriendMessage(String from, String msg) {
        Log.d(TAG, "[Java] OnFriendMessage ============================msg=["+msg+"]");
        Message message = new Message();
        message.what = STATEMSG.RECEIVEMSG;
        message.obj = msg;
        mHandler.sendMessage(message);
    }

    @Override
    public void OnStreamStateChanged(int streamId, int state) {

    }

    private class STATEMSG {
        public static final int UNCONNECTED = 0;
        public static final int CONNECTED = 1;
        public static final int RECEIVEMSG = 2;
        public static final int CARRIERREADY = 3;
    }

    public class Msg {
        public static final int MSG_RECEIVE = 0;
        public static final int MSG_SEND = 1;

        private int type;
        private String content;

        public Msg(String content, int type) {
            this.content = content;
            this.type = type;
        }

        public String getMessage() {
            return content;
        }
        public int getType() {
            return type;
        }
    }

    public class MsgAdapter extends ArrayAdapter<Msg> {
        private int resourceID;

        public MsgAdapter(Context context, int resource, List<Msg> objects) {
            super(context, resource, objects);
            resourceID = resource;
        }

        @Override
        public View getView(int position, View convertView, ViewGroup parent) {
            Msg msg = getItem(position);
            View view;
            ViewHolder viewHolder;
            if(convertView == null) {
                view = LayoutInflater.from(getContext()).inflate(resourceID,  null);
                viewHolder = new ViewHolder();
                viewHolder.leftLayout = (LinearLayout)view.findViewById(R.id.left_layout);
                viewHolder.rightLayout = (LinearLayout) view.findViewById(R.id.right_layout);
                viewHolder.leftMsg = (TextView) view.findViewById(R.id.left_msg);
                viewHolder.leftMsg.setTextColor(STATECOLOR.BLUE);

                viewHolder.rightMsg = (TextView) view.findViewById(R.id.right_msg);
                viewHolder.rightMsg.setTextColor(STATECOLOR.GREEN);
                view.setTag(viewHolder);
            }
            else {
                view = convertView;
                viewHolder = (ViewHolder) view.getTag();
            }

            if(msg.getType() == Msg.MSG_RECEIVE) {
                viewHolder.leftLayout.setVisibility(View.VISIBLE);
                viewHolder.rightLayout.setVisibility(View.GONE);
                viewHolder.leftMsg.setText(msg.getMessage());
            }
            else {
                viewHolder.rightLayout.setVisibility(View.VISIBLE);
                viewHolder.leftLayout.setVisibility(View.GONE);
                viewHolder.rightMsg.setText(msg.getMessage());
            }
            return view;
        }

        class ViewHolder {
            LinearLayout leftLayout;
            LinearLayout rightLayout;
            TextView leftMsg;
            TextView rightMsg;
        }
    }

    private class STATECOLOR {
        public static final int RED = 0xFFFF0000;
        public static final int GREEN = 0xFF00FF00;
        public static final int BLUE = 0xFF0000FF;
    };
}
