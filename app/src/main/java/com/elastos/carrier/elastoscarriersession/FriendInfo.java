package com.elastos.carrier.elastoscarriersession;

public class FriendInfo implements Comparable<FriendInfo> {
    public FriendInfo(String userid) {
        mUserId = userid;
    }

    public void SetConnecttionState(int state) {
        mConnecttionState = state;
    }

    public void SetStreamState(int state) {
        mStreamState = state;
    }

    public boolean IsReady() {
        return mConnecttionState == 0 && mStreamState == 0;
    }

    @Override
    public int compareTo(FriendInfo o) {
        if(this.mUserId == o.mUserId) {
            return 0;
        }

        return -1;
    }

    private String mUserId = null;
    private int mConnecttionState = -1;
    private int mStreamState = -1;
}
