package com.elastos.carrier.elastoscarriersession;

import android.content.Context;
import android.os.Bundle;
import android.support.v4.app.Fragment;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.LinearLayout;
import android.widget.ListView;
import android.widget.TextView;

import java.util.ArrayList;
import java.util.List;

public class MainFragment extends Fragment {
	private View mMain;
	private TextView mShowInfo;
	private Button mSendBtn;
    private ListView mListView;
    private List<Msg> mMsgList = new ArrayList<Msg>();
    private MsgAdapter mMsgAdapter;

	@Override
	public View onCreateView(LayoutInflater inflater, ViewGroup container,
			Bundle savedInstanceState) {
		mMain = inflater.inflate(R.layout.fragment_message, container, false);
		mShowInfo = (TextView) mMain.findViewById(R.id.showinfotv);
        mSendBtn = (Button) mMain.findViewById(R.id.btn_send);
        mSendBtn.setOnClickListener((MainActivity)this.getActivity());
        mListView = (ListView) mMain.findViewById(R.id.listview);
        mMsgAdapter  = new MsgAdapter(this.getActivity(), R.layout.itemlayout, mMsgList);
        mListView.setAdapter(mMsgAdapter);
		return mMain;
	}

    public void showInfo(String info) {
		mShowInfo.setText(info);
    }


    public void ReceiveMessage(String message) {
        Msg msg = new Msg(message, Msg.MSG_RECEIVE);
        mMsgList.add(msg);
        mMsgAdapter.notifyDataSetChanged();
        mListView.setSelection(mMsgList.size());
    }

    public void SendMessage(String userid, String message) {
        Msg msg = new Msg(message, Msg.MSG_SEND);
        mMsgList.add(msg);
        mMsgAdapter.notifyDataSetChanged();
        mListView.setSelection(mMsgList.size());

        //Send message
        ElaRpcUtils.SendMessage(userid, message);
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
//				viewHolder.leftMsg.setTextColor(STATECOLOR.BLUE);

				viewHolder.rightMsg = (TextView) view.findViewById(R.id.right_msg);
//				viewHolder.rightMsg.setTextColor(STATECOLOR.GREEN);
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
