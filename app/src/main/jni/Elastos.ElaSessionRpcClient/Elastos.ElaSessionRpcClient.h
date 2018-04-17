#ifndef __CAR_ELASTOS_ELASESSIONRPCCLIENT_H__
#define __CAR_ELASTOS_ELASESSIONRPCCLIENT_H__

#ifndef _NO_INCLIST
#include <elastos.h>
using namespace Elastos;
#include <Elastos.CoreLibrary.h>

#endif // !_NO_INCLIST


namespace Elastos {
namespace ElaSessionRpcClient {
interface ICarrierNodeListener;
EXTERN const _ELASTOS InterfaceID EIID_ICarrierNodeListener;
interface IElaSessionRpcClient;
EXTERN const _ELASTOS InterfaceID EIID_IElaSessionRpcClient;
interface ICElaSessionRpcClientClassObject;
EXTERN const _ELASTOS InterfaceID EIID_ICElaSessionRpcClientClassObject;
EXTERN const _ELASTOS ClassID ECLSID_CElaSessionRpcClient;
EXTERN const _ELASTOS ClassID ECLSID_CElaSessionRpcClientClassObject;
}
}





#ifdef __ELASTOS_ELASESSIONRPCCLIENT_USER_TYPE_H__
#include "Elastos.ElaSessionRpcClient_user_type.h"
#endif

#endif // __CAR_ELASTOS_ELASESSIONRPCCLIENT_H__
