
#include <jni.h>
#include <android/log.h>

//For Elastos
#include <elastos/core/Object.h>
#include "Elastos.ElaSessionRpcClient.h"

#define TAG "Elastos_Session_RPC_Log"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,TAG ,__VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,TAG ,__VA_ARGS__)
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN,TAG ,__VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,TAG ,__VA_ARGS__)
#define LOGF(...) __android_log_print(ANDROID_LOG_FATAL,TAG ,__VA_ARGS__)

using Elastos::Core::Object;
//using Elastos::ElaSessionRpcClient::CElaSessionRpcClient;
//using Elastos::ElaSessionRpcClient::IElaSessionRpcClient;
//using Elastos::ElaSessionRpcClient::ICarrierNodeListener;

#define JNIREG_CLASS_ELARPCUTILS "com/elastos/carrier/elastoscarriersession/ElaRpcUtils"
#define JNIREG_CLASS_ELAMAINACTIVITY "com/elastos/carrier/elastoscarriersession/MainActivity"

class CarrierNodeListener
    : public Object
    , public ICarrierNodeListener
{
public:
    CAR_INTERFACE_DECL()

    CarrierNodeListener(
        /* [in] */ JNIEnv* env,
        /* [in] */ jobject jobj);

    ~CarrierNodeListener();

    CARAPI OnConnection(
        /* [in] */ Int32 status);

    CARAPI OnReady();

    CARAPI OnSessionReady();

    CARAPI OnFriendConnection(
        /* [in] */ const String& friendid,
        /* [in] */ Int32 status);

    CARAPI OnFriendRequest(
        /* [in] */ const String& userid,
        /* [in] */ const String& hello);

    CARAPI OnFreindAdded(
        /* [in] */ const String& userid);

    CARAPI OnFriendMessage(
        /* [in] */ const String& from,
        /* [in] */ const String& msg);

    CARAPI OnSessionRequest(
        /* [in] */ const String& userid);

    CARAPI OnStreamStateChanged(
        /* [in] */ Int32 streamId,
        /* [in] */ Int32 state);

private:
    JNIEnv* GetEnv();
    void Detach();

private:
    JavaVM* mVM;
    jobject mObj;
};


static AutoPtr<IElaSessionRpcClient> sSessionRpcClient;
static AutoPtr<CarrierNodeListener> sCarrierNodeListener;
static void JNICALL nativeCreateCarrierNodeWithSession(JNIEnv *env, jobject jobj)
{
    if (sSessionRpcClient == NULL) {
        CElaSessionRpcClient::New((IElaSessionRpcClient**)&sSessionRpcClient);
    }

    sCarrierNodeListener = new CarrierNodeListener(env, jobj);
    sSessionRpcClient->SetCarrierNodeListener(sCarrierNodeListener);
    sSessionRpcClient->CreateCarrierNodeWithSession();
}

static jstring JNICALL nativeGetAddress(JNIEnv *env, jobject jobj)
{
    if (sSessionRpcClient == NULL) {
        return env->NewStringUTF("nativeGetAddress NULL");
    }

    String address;
    sSessionRpcClient->GetAddress(&address);
    LOGD("nativeGetAddress===================address=[%s]", address.string());
    return env->NewStringUTF(address.string());
}

static jint JNICALL nativeAddFriend(JNIEnv *env, jobject jobj, jstring jAddress, jstring jHello)
{
    const char* address = env->GetStringUTFChars(jAddress, NULL);
    const char* hello = env->GetStringUTFChars(jHello, NULL);
    LOGD("nativeAddFriend===================address=[%s]", address);
    assert(sSessionRpcClient != NULL);
    Int32 result = 0;
    sSessionRpcClient->AddFriend(String(address),String(hello), &result);

    //Release the strings.
    env->ReleaseStringUTFChars(jAddress, address);
    env->ReleaseStringUTFChars(jHello, hello);
    return result;
}

static void JNICALL nativeSendMessage(JNIEnv *env, jobject jobj, jstring juserid, jstring jmsg)
{
    const char* userid = env->GetStringUTFChars(juserid, NULL);
    const char* msg  = env->GetStringUTFChars(jmsg, NULL);
    LOGD("nativeSendMessage===================userid=[%s]", userid);
    assert(sSessionRpcClient != NULL);
    sSessionRpcClient->SendMessage(String(userid),String(msg));

    //Release the strings.
    env->ReleaseStringUTFChars(juserid, userid);
    env->ReleaseStringUTFChars(jmsg, msg);
}

static void JNICALL nativeCreateElaSession(JNIEnv *env, jobject jobj, jstring juserid)
{
    const char* userid = env->GetStringUTFChars(juserid, NULL);
    LOGD("nativeCreateElaSession===================userid=[%s]", userid);
    assert(sSessionRpcClient != NULL);
    sSessionRpcClient->CreateElaSession(String(userid));

    //Release the strings.
    env->ReleaseStringUTFChars(juserid, userid);
}

static void JNICALL nativeAcceptRequest(JNIEnv *env, jobject jobj, jstring juserid)
{
    const char* userid = env->GetStringUTFChars(juserid, NULL);
    LOGD("nativeAcceptRequest===================userid=[%s]", userid);
    assert(sSessionRpcClient != NULL);
    sSessionRpcClient->AcceptRequest(String(userid));

    //Release the strings.
    env->ReleaseStringUTFChars(juserid, userid);
}

static void JNICALL nativeSessionRequest(JNIEnv *env, jobject jobj)
{
    LOGD("nativeSessionRequest===================");
    assert(sSessionRpcClient != NULL);
    sSessionRpcClient->SessionRequest();
}

static void JNICALL nativeInitElaSession(JNIEnv *env, jobject jobj)
{
    LOGD("nativeInitElaSession===================");
    assert(sSessionRpcClient != NULL);
    sSessionRpcClient->InitElaSession();
}

static void JNICALL nativeReplySessionRequest(JNIEnv *env, jobject jobj, jboolean agree)
{
    LOGD("nativeReplySessionRequest===================");
    assert(sSessionRpcClient != NULL);
    sSessionRpcClient->ReplySessionRequest(agree);
}

static const JNINativeMethod gElaRpcUtilsMethods[] = {
    {"nativeGetAddress", "()Ljava/lang/String;", (void*)nativeGetAddress},
    {"nativeCreateElaSession", "(Ljava/lang/String;)V", (void*)nativeCreateElaSession},
    {"nativeAcceptRequest", "(Ljava/lang/String;)V", (void*)nativeAcceptRequest},
    {"nativeAddFriend", "(Ljava/lang/String;Ljava/lang/String;)I", (void*)nativeAddFriend},
    {"nativeSendMessage", "(Ljava/lang/String;Ljava/lang/String;)V", (void*)nativeSendMessage},
    {"nativeSessionRequest", "()V", (void*)nativeSessionRequest},
    {"nativeInitElaSession", "()V", (void*)nativeInitElaSession},
    {"nativeReplySessionRequest", "(Z)V", (void*)nativeReplySessionRequest},
};

static const JNINativeMethod gMainActivityMethods[] = {
    {"nativeCreateCarrierNodeWithSession", "()V", (void*)nativeCreateCarrierNodeWithSession},
};

extern "C" {
    extern jint PJ_JNI_OnLoad(JavaVM* vm, void* reserved);
}

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* reserved){
    JNIEnv * env;
    jclass cls;
    jint result = -1;
    if(vm->GetEnv((void **)&env,JNI_VERSION_1_6) != JNI_OK){
        return JNI_ERR;
    }

    //ElaRpcUtils
    cls = env->FindClass(JNIREG_CLASS_ELARPCUTILS);
    env->RegisterNatives(cls, gElaRpcUtilsMethods, sizeof(gElaRpcUtilsMethods)/sizeof(JNINativeMethod));

    //MainActivity
    jclass cls2 = env->FindClass(JNIREG_CLASS_ELAMAINACTIVITY);
    env->RegisterNatives(cls2, gMainActivityMethods, sizeof(gMainActivityMethods)/sizeof(JNINativeMethod));

//    PJ_JNI_OnLoad(vm, reserved);
    return JNI_VERSION_1_6;
}


//using Elastos::ElaSessionRpcClient::EIID_ICarrierNodeListener;
CAR_INTERFACE_IMPL(CarrierNodeListener, Object, ICarrierNodeListener)
CarrierNodeListener::CarrierNodeListener(
    /* [in] */ JNIEnv* env,
    /* [in] */ jobject jobj)
{
    mObj = env->NewGlobalRef(jobj);
    env->GetJavaVM(&mVM);
}

CarrierNodeListener::~CarrierNodeListener()
{
    if (mObj) {
        GetEnv()->DeleteGlobalRef(mObj);
    }
}

JNIEnv* CarrierNodeListener::GetEnv()
{
    JNIEnv* env;
    assert(mVM != NULL);
    mVM->AttachCurrentThread(&env, NULL);
    return env;
}

void CarrierNodeListener::Detach()
{
    assert(mVM != NULL);
    mVM->DetachCurrentThread();
}

ECode CarrierNodeListener::OnConnection(
    /* [in] */ Int32 status)
{
    LOGD("CarrierNodeListener==================func=[%s], line=[%d]", __FUNCTION__, __LINE__);
    JNIEnv* env = GetEnv();

    jclass clazz = env->GetObjectClass(mObj);
    jmethodID methodId = env->GetMethodID(clazz,"OnConnection","(Z)V");
    env->CallVoidMethod(mObj, methodId, (!status) ? true : false);

    Detach();
    return NOERROR;
}

ECode CarrierNodeListener::OnReady()
{
    LOGD("CarrierNodeListener==================func=[%s], line=[%d]", __FUNCTION__, __LINE__);
    assert(mObj != NULL);
    JNIEnv* env = GetEnv();

    jclass clazz = env->GetObjectClass(mObj);
    jmethodID methodId = env->GetMethodID(clazz,"OnReady","()V");
    env->CallVoidMethod(mObj, methodId);
    Detach();
    return NOERROR;
}

ECode CarrierNodeListener::OnSessionReady()
{
    LOGD("CarrierNodeListener==================func=[%s], line=[%d]", __FUNCTION__, __LINE__);
    assert(mObj != NULL);
    JNIEnv* env = GetEnv();

    jclass clazz = env->GetObjectClass(mObj);
    jmethodID methodId = env->GetMethodID(clazz,"OnSessionReady","()V");
    env->CallVoidMethod(mObj, methodId);
    LOGD("CarrierNodeListener==================func=[%s], line=[%d]", __FUNCTION__, __LINE__);

    //TODO: need to Detach?
    // Detach();
    LOGD("CarrierNodeListener==================func=[%s], line=[%d]", __FUNCTION__, __LINE__);
    return NOERROR;
}

ECode CarrierNodeListener::OnFriendConnection(
    /* [in] */ const String& friendid,
    /* [in] */ Int32 status)
{
    LOGD("CarrierNodeListener==================func=[%s], line=[%d]", __FUNCTION__, __LINE__);

    JNIEnv* env = GetEnv();

    jclass clazz = env->GetObjectClass(mObj);
    jmethodID methodId = env->GetMethodID(clazz,"OnFriendConnection","(Ljava/lang/String;I)V");
    jstring userid = env->NewStringUTF(friendid.string());
    env->CallVoidMethod(mObj, methodId, userid, status);
    Detach();
    return NOERROR;
}

ECode CarrierNodeListener::OnFriendRequest(
    /* [in] */ const String& userid,
    /* [in] */ const String& hello)
{
    LOGD("CarrierNodeListener==================func=[%s], line=[%d], userid=[%s], hello=[%s]",
        __FUNCTION__, __LINE__, userid.string(), hello.string());

    JNIEnv* env = GetEnv();

    jclass clazz = env->GetObjectClass(mObj);
    jmethodID methodId = env->GetMethodID(clazz,"OnFriendRequest","(Ljava/lang/String;Ljava/lang/String;)V");
    jstring jUserid = env->NewStringUTF(userid.string());
    jstring jHello = env->NewStringUTF(hello.string());
    env->CallVoidMethod(mObj, methodId, jUserid, jHello);

    Detach();

    return NOERROR;
}

ECode CarrierNodeListener::OnFreindAdded(
    /* [in] */ const String& userid)
{
    LOGD("CarrierNodeListener==================func=[%s], line=[%d], userid=[%s]",
        __FUNCTION__, __LINE__, userid.string());

    JNIEnv* env = GetEnv();

    jclass clazz = env->GetObjectClass(mObj);
    jmethodID methodId = env->GetMethodID(clazz,"OnFreindAdded","(Ljava/lang/String;)V");
    jstring jUserid = env->NewStringUTF(userid.string());
    env->CallVoidMethod(mObj, methodId, jUserid);

    //TODO: need to Detach?
    // Detach();
    return NOERROR;
}

ECode CarrierNodeListener::OnSessionRequest(
    /* [in] */ const String& userid)
{
    LOGD("CarrierNodeListener==================func=[%s], line=[%d], userid=[%s]",
        __FUNCTION__, __LINE__, userid.string());

    JNIEnv* env = GetEnv();

    jclass clazz = env->GetObjectClass(mObj);
    jmethodID methodId = env->GetMethodID(clazz,"OnSessionRequest","(Ljava/lang/String;)V");
    jstring jUserid = env->NewStringUTF(userid.string());
    env->CallVoidMethod(mObj, methodId, jUserid);

    //TODO: need to Detach?
    // Detach();
    return NOERROR;
}

ECode CarrierNodeListener::OnStreamStateChanged(
    /* [in] */ Int32 streamId,
    /* [in] */ Int32 state)
{
    LOGD("CarrierNodeListener==================func=[%s], line=[%d], state=[%d], streamId=[%d]",
        __FUNCTION__, __LINE__, state, streamId);

    JNIEnv* env = GetEnv();

    jclass clazz = env->GetObjectClass(mObj);
    jmethodID methodId = env->GetMethodID(clazz,"OnStreamStateChanged","(II)V");
    env->CallVoidMethod(mObj, methodId, streamId, state);

    //TODO: need to Detach?
    // Detach();
    return NOERROR;
}

ECode CarrierNodeListener::OnFriendMessage(
    /* [in] */ const String& from,
    /* [in] */ const String& msg)
{
    LOGD("CarrierNodeListener==================func=[%s], line=[%d], from=[%s], msg=[%s]",
        __FUNCTION__, __LINE__, from.string(), msg.string());

    JNIEnv* env = GetEnv();
    jclass clazz = env->GetObjectClass(mObj);
    jmethodID methodId = env->GetMethodID(clazz,"OnFriendMessage","(Ljava/lang/String;Ljava/lang/String;)V");
    jstring jFrom = env->NewStringUTF(from.string());
    jstring jMsg = env->NewStringUTF(msg.string());
    env->CallVoidMethod(mObj, methodId, jFrom, jMsg);

    Detach();
    return NOERROR;
}
