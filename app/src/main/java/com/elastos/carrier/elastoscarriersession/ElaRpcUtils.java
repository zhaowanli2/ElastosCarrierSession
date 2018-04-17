package com.elastos.carrier.elastoscarriersession;

public class ElaRpcUtils {
    public interface OnElaCarrierNodeListener {
        void OnConnection(
            /* [in] */ boolean status);

        void OnReady();

        void OnSessionReady();

        void OnFriendConnection(
        /* [in] */ String friendid,
        /* [in] */ int status);

        void OnFriendRequest(
        /* [in] */ String userid,
        /* [in] */ String hello);

        void OnFreindAdded(
        /* [in] */ String userid);

        void OnSessionRequest(
        /* [in] */ String userid);

        void OnFriendMessage(
        /* [in] */ String from,
        /* [in] */ String msg);

        void OnStreamStateChanged(
        /* [in] */ int streamId,
        /* [in] */ int state);
    }

    public static String GetAddress() {
        return nativeGetAddress();
    }

    public static void InitElaSession() {
        nativeInitElaSession();
    }

    public static void SessionRequest() {
        nativeSessionRequest();
    }

    public static int AddFriend(String address, String hello) {
        return nativeAddFriend(address, hello);
    }

    public static void CreateElaSession(String userid) {
        nativeCreateElaSession(userid);
    }

    public static void AcceptRequest(String userid) {
        nativeAcceptRequest(userid);
    }

    public static void SendMessage(String userid, String msg) {
        nativeSendMessage(userid, msg);
    }

    public static void ReplySessionRequest(boolean agree) {
        nativeReplySessionRequest(agree);
    }

    private static native String nativeGetAddress();
    private static native void nativeInitElaSession();
    private static native void nativeSessionRequest();
    private static native void nativeReplySessionRequest(boolean agree);
    private static native void nativeCreateElaSession(String userid);
    private static native void nativeAcceptRequest(String userid);
    private static native int nativeAddFriend(String address, String hello);
    private static native void nativeSendMessage(String userid, String msg);
}
