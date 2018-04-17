
LOCAL_PATH := $(call my-dir)

#Elastos.Runtime
include $(CLEAR_VARS)
LOCAL_MODULE    := Elastos.Runtime
LOCAL_SRC_FILES := $(LOCAL_PATH)/elastos/libs/libElastos.Runtime.so
include $(PREBUILT_SHARED_LIBRARY)

#Elastos.CoreLibrary
include $(CLEAR_VARS)
LOCAL_MODULE    := Elastos.CoreLibrary
LOCAL_SRC_FILES := $(LOCAL_PATH)/elastos/libs/libElastos.CoreLibrary.so
include $(PREBUILT_SHARED_LIBRARY)

#Elastos.ElaSessionRpcClient
include $(CLEAR_VARS)
LOCAL_MODULE    := Elastos.ElaSessionRpcClient
LOCAL_SRC_FILES := $(LOCAL_PATH)/Elastos.ElaSessionRpcClient/libElastos.ElaSessionRpcClient.so
include $(PREBUILT_SHARED_LIBRARY)

#Carrier
include $(CLEAR_VARS)
LOCAL_MODULE    := elacarrier
LOCAL_SRC_FILES := $(LOCAL_PATH)/elastos/libs/libelacarrier.so
include $(PREBUILT_SHARED_LIBRARY)

#Carrier
include $(CLEAR_VARS)
LOCAL_MODULE    := elacommon
LOCAL_SRC_FILES := $(LOCAL_PATH)/elastos/libs/libelacommon.so
include $(PREBUILT_SHARED_LIBRARY)

#Carrier
include $(CLEAR_VARS)
LOCAL_MODULE    := elasession
LOCAL_SRC_FILES := $(LOCAL_PATH)/elastos/libs/libelasession.so
include $(PREBUILT_SHARED_LIBRARY)


#Elastos.CoreLibrary depend libcrypto.so
include $(CLEAR_VARS)
LOCAL_MODULE    := crypto
LOCAL_SRC_FILES := $(LOCAL_PATH)/elastos/libs/libcrypto.so
include $(PREBUILT_SHARED_LIBRARY)

#Elastos.CoreLibrary depend libicuuc.so
include $(CLEAR_VARS)
LOCAL_MODULE    := icuuc
LOCAL_SRC_FILES := $(LOCAL_PATH)/elastos/libs/libicuuc.so
include $(PREBUILT_SHARED_LIBRARY)

#Elastos.CoreLibrary depend libstlport.so
include $(CLEAR_VARS)
LOCAL_MODULE    := stlport
LOCAL_SRC_FILES := $(LOCAL_PATH)/elastos/libs/libstlport.so
include $(PREBUILT_SHARED_LIBRARY)


### shared library
include $(CLEAR_VARS)
LOCAL_SRC_FILES := elastos_session_rpc.cpp

LOCAL_C_INCLUDES := $(LOCAL_PATH)/elastos/include \
      $(LOCAL_PATH)/elastos/include/elasys \
      $(LOCAL_PATH)/Elastos.ElaSessionRpcClient

LOCAL_CFLAGS += -std=c++11 -D_GNUC -D_linux -D_UNDEFDLLEXP -fvisibility=hidden
LOCAL_MODULE := elasessionrpc

#The elastos eco and lib.
#LOCAL_LDFLAGS := $(LOCAL_PATH)/elastos/libs/libElastos.Runtime.so \
#		$(LOCAL_PATH)/elastos/libs/libElastos.CoreLibrary.so \
#		$(LOCAL_PATH)/elastos/libs/libelasession.so \
#		$(LOCAL_PATH)/Elastos.ElaSessionRpcClient/libElastos.ElaSessionRpcClient.so \
#		$(LOCAL_PATH)/elastos/libs/Elastos.Runtime.lib

#The elastos eco and lib.e
LOCAL_LDFLAGS := -L$(LOCAL_PATH)/elastos/libs/ -lElastos.Runtime -lElastos.CoreLibrary -lelasession \
		$(LOCAL_PATH)/Elastos.ElaSessionRpcClient/libElastos.ElaSessionRpcClient.so \
		$(LOCAL_PATH)/elastos/libs/Elastos.Runtime.lib

LOCAL_LDLIBS := -llog
LOCAL_LDFLAGS += -fuse-ld=bfd

include $(BUILD_SHARED_LIBRARY)
