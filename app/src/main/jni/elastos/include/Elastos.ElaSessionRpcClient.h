#ifndef __CAR_ELASTOS_ELASESSIONRPCCLIENT_H__
#define __CAR_ELASTOS_ELASESSIONRPCCLIENT_H__

#ifndef _NO_INCLIST
#include "elastos.h"
using namespace Elastos;
#include "Elastos.CoreLibrary.h"

#endif // !_NO_INCLIST

#ifndef __UUNM_Elastos_ElaSessionRpcClient_DEFINED__
#define __UUNM_Elastos_ElaSessionRpcClient_DEFINED__
#define c_pElastos_ElaSessionRpcClientUunm "libElastos.ElaSessionRpcClient.so"
#endif // __UUNM_Elastos_ElaSessionRpcClient_DEFINED__

#ifndef __ECLSID_CElaSessionRpcClient_DEFINED__
#define __ECLSID_CElaSessionRpcClient_DEFINED__
static const _ELASTOS ClassID ECLSID_CElaSessionRpcClient = {
    {0x9BE23036,0x7B4C,0xF80E,{0xE3,0x6F,0x98,0x61,0xA2,0xCF,0x8F,0xF6}},
    (char *)c_pElastos_ElaSessionRpcClientUunm,
    0x498a20b3 };
#endif // __CLSID_CElaSessionRpcClient_DEFINED__

#ifndef __ECLSID_CElaSessionRpcClientClassObject_DEFINED__
#define __ECLSID_CElaSessionRpcClientClassObject_DEFINED__
static const _ELASTOS ClassID ECLSID_CElaSessionRpcClientClassObject = {
    {0x60CC3B32,0x7B4C,0xF80E,{0xE3,0x6F,0x98,0x61,0xA2,0x8F,0x1E,0xA3}},
    (char *)c_pElastos_ElaSessionRpcClientUunm,
    0x498a20b3 };
#endif // __CLSID_CElaSessionRpcClientClassObject_DEFINED__

#ifndef __EIID_ICarrierNodeListener_DEFINED__
#define __EIID_ICarrierNodeListener_DEFINED__
static const _ELASTOS InterfaceID EIID_ICarrierNodeListener = \
    {0xD48C9743,0x8312,0x7A44,{0x9F,0x79,0x99,0x55,0xC1,0x22,0xB3,0x67}};
#endif // __IID_ICarrierNodeListener_DEFINED__

#ifndef __EIID_IElaSessionRpcClient_DEFINED__
#define __EIID_IElaSessionRpcClient_DEFINED__
static const _ELASTOS InterfaceID EIID_IElaSessionRpcClient = \
    {0x7725B134,0x7B52,0xF80E,{0xE3,0x6F,0x98,0x61,0xA2,0xCF,0x0F,0x7F}};
#endif // __IID_IElaSessionRpcClient_DEFINED__

#ifndef __EIID_ICElaSessionRpcClientClassObject_DEFINED__
#define __EIID_ICElaSessionRpcClientClassObject_DEFINED__
static const _ELASTOS InterfaceID EIID_ICElaSessionRpcClientClassObject = \
    {0x0065613F,0x8312,0x1CF6,{0xF0,0xC7,0xDF,0x30,0xC3,0x44,0x1F,0x3D}};
#endif // __IID_ICElaSessionRpcClientClassObject_DEFINED__

interface ICarrierNodeListener;
interface IElaSessionRpcClient;
interface ICElaSessionRpcClientClassObject;





#ifdef __ELASTOS_ELASESSIONRPCCLIENT_USER_TYPE_H__
#include "Elastos.ElaSessionRpcClient_user_type.h"
#endif
ELAPI _Impl_AcquireCallbackHandler(PInterface pServerObj, _ELASTOS REIID iid, PInterface *ppHandler);
ELAPI _Impl_CheckClsId(PInterface pServerObj, const _ELASTOS ClassID* pClassid, PInterface *ppServerObj);

CAR_INTERFACE("D48C9743-8312-7A44-9F79-9955C122B367")
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

    static CARAPI_(ICarrierNodeListener*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
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
CAR_INTERFACE("7725B134-7B52-F80E-E36F-9861A2CF0F7F")
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

    static CARAPI_(IElaSessionRpcClient*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI InitElaSession() = 0;

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
        /* [in] */ ICarrierNodeListener * listener) = 0;

    virtual CARAPI SendMessage(
        /* [in] */ const _ELASTOS String& userid,
        /* [in] */ const _ELASTOS String& msg) = 0;

    virtual CARAPI CreateElaSession(
        /* [in] */ const _ELASTOS String& userid) = 0;

    virtual CARAPI ReplySessionRequest(
        /* [in] */ _ELASTOS Boolean agree) = 0;

    virtual CARAPI SessionRequest() = 0;

};
CAR_INTERFACE("0065613F-8312-1CF6-F0C7-DF30C3441F3D")
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

    static CARAPI_(ICElaSessionRpcClientClassObject*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
#ifndef _INSIDE_ELASTOS_ELASESSIONRPCCLIENT_
class CElaSessionRpcClient
{
public:
    static _ELASTOS ECode New(
        /* [out] */ IElaSessionRpcClient** __object)
    {
        return _CObject_CreateInstance(ECLSID_CElaSessionRpcClient, RGM_SAME_DOMAIN, EIID_IElaSessionRpcClient, (PInterface*)__object);
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
#endif // _INSIDE_ELASTOS_ELASESSIONRPCCLIENT_


#endif // __CAR_ELASTOS_ELASESSIONRPCCLIENT_H__
