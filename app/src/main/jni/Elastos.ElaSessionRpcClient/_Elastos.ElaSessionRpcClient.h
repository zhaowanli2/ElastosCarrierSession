#ifndef ___Elastos_ElaSessionRpcClient_h__
#define ___Elastos_ElaSessionRpcClient_h__

#include <Elastos.ElaSessionRpcClient.h>

ELAPI _Impl_AcquireCallbackHandler(PInterface pServerObj, _ELASTOS REIID iid, PInterface *ppHandler);
ELAPI _Impl_CheckClsId(PInterface pServerObj, const _ELASTOS ClassID* pClassid, PInterface *ppServerObj);

namespace Elastos {
namespace ElaSessionRpcClient {
CAR_INTERFACE("5B49B34C-8312-7A44-9F79-9955C122B367")
ICarrierNodeListener : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICarrierNodeListener*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICarrierNodeListener*)pObj->Probe(EIID_ICarrierNodeListener);
    }

    static CARAPI_(ICarrierNodeListener*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICarrierNodeListener*)pObj->Probe(EIID_ICarrierNodeListener);
    }

    virtual CARAPI OnConnection(
        /* [in] */ _ELASTOS Int32 status) = 0;

    virtual CARAPI OnReady() = 0;

    virtual CARAPI OnFriendConnection(
        /* [in] */ const _ELASTOS String& friendid,
        /* [in] */ _ELASTOS Int32 status) = 0;

    virtual CARAPI OnFriendRequest(
        /* [in] */ const _ELASTOS String& userid,
        /* [in] */ const _ELASTOS String& hello) = 0;

    virtual CARAPI OnFreindAdded(
        /* [in] */ const _ELASTOS String& userid) = 0;

    virtual CARAPI OnFriendMessage(
        /* [in] */ const _ELASTOS String& from,
        /* [in] */ const _ELASTOS String& msg) = 0;

    virtual CARAPI OnSessionRequest(
        /* [in] */ const _ELASTOS String& userid) = 0;

    virtual CARAPI OnSessionReady() = 0;

    virtual CARAPI OnStreamStateChanged(
        /* [in] */ _ELASTOS Int32 streamId,
        /* [in] */ _ELASTOS Int32 state) = 0;

};
}
}

namespace Elastos {
namespace ElaSessionRpcClient {
CAR_INTERFACE("B22DCD22-7B52-F80E-E36F-9861A2CF8FF6")
IElaSessionRpcClient : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IElaSessionRpcClient*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IElaSessionRpcClient*)pObj->Probe(EIID_IElaSessionRpcClient);
    }

    static CARAPI_(IElaSessionRpcClient*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IElaSessionRpcClient*)pObj->Probe(EIID_IElaSessionRpcClient);
    }

    virtual CARAPI CreateCarrierNodeWithSession() = 0;

    virtual CARAPI GetAddress(
        /* [out] */ _ELASTOS String * address) = 0;

    virtual CARAPI AddFriend(
        /* [in] */ const _ELASTOS String& address,
        /* [in] */ const _ELASTOS String& hello,
        /* [out] */ _ELASTOS Int32 * result) = 0;

    virtual CARAPI AcceptRequest(
        /* [in] */ const _ELASTOS String& userid) = 0;

    virtual CARAPI SetCarrierNodeListener(
        /* [in] */ Elastos::ElaSessionRpcClient::ICarrierNodeListener * listener) = 0;

    virtual CARAPI SendMessage(
        /* [in] */ const _ELASTOS String& userid,
        /* [in] */ const _ELASTOS String& msg) = 0;

    virtual CARAPI InitElaSession() = 0;

    virtual CARAPI CreateElaSession(
        /* [in] */ const _ELASTOS String& userid) = 0;

    virtual CARAPI ReplySessionRequest(
        /* [in] */ _ELASTOS Boolean agree) = 0;

    virtual CARAPI SessionRequest() = 0;

};
}
}

namespace Elastos {
namespace ElaSessionRpcClient {
CAR_INTERFACE("87217D29-8312-1CF6-F0C7-DF30C3441F3D")
ICElaSessionRpcClientClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICElaSessionRpcClientClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICElaSessionRpcClientClassObject*)pObj->Probe(EIID_ICElaSessionRpcClientClassObject);
    }

    static CARAPI_(ICElaSessionRpcClientClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICElaSessionRpcClientClassObject*)pObj->Probe(EIID_ICElaSessionRpcClientClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}

namespace Elastos {
namespace ElaSessionRpcClient {
class CElaSessionRpcClient
{
public:
    static _ELASTOS ECode New(
        /* [out] */ Elastos::ElaSessionRpcClient::IElaSessionRpcClient** __object)
    {
        return _CObject_CreateInstance(ECLSID_CElaSessionRpcClient, RGM_SAME_DOMAIN, Elastos::ElaSessionRpcClient::EIID_IElaSessionRpcClient, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CElaSessionRpcClient, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CElaSessionRpcClient, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CElaSessionRpcClient, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}

#endif // ___Elastos_ElaSessionRpcClient_h__
