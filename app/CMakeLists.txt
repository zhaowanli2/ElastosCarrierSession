# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)

include_directories(src/main/jni/elastos/include)
link_directories(src/main/jni/elastos/libs)

set(SOURCES
    src/main/jni/elastos_session_rpc.cpp
)

add_library(elastoscarrier SHARED ${SOURCES})

target_link_libraries(elastoscarrier
    spvsdk
    Elastos.Runtime
    Elastos.Runtime_static
    Elastos.CoreLibrary
    crystal
    elacarrier
    elasession
    Elastos.ElaSessionRpcClient
    log
)
