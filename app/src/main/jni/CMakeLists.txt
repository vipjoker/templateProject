cmake_minimum_required(VERSION 3.4.1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11 -frtti -DCC_ENABLE_CHIPMUNK_INTEGRATION=1  -fsigned-char")

include_directories(
        .
        graphnode

        $ENV{COCOS_LITE}/include

)
set(SOURCES
        main.cpp
        AppDelegate.cpp
        HelloWorldScene.cpp
        StartScene.cpp
        graphnode/Triangulate.cpp
        graphnode/CCGraphicsNode.cpp)




set(abi armeabi-v7a)
ADD_DEFINITIONS(-DUSE_FILE32API)

add_library(MyGame SHARED
        ${SOURCES})

message($ENV{COCOS_LITE})
set(wholelib
        $ENV{COCOS_LITE}/libs/${ANDROID_ABI}/libcocos2dInternal.a
        $ENV{COCOS_LITE}/libs/${ANDROID_ABI}/libcocos2dxandroid_static.a
        $ENV{COCOS_LITE}/libs/${ANDROID_ABI}/libcocos2d.a)



target_link_libraries(
        MyGame
        android
        GLESv1_CM
        GLESv2
        log
        EGL
        OpenSLES

        -Wl,-whole-archive ${wholelib} -Wl,-no-whole-archive
        $ENV{COCOS_LITE}/libs/${ANDROID_ABI}/libjpeg.a
        $ENV{COCOS_LITE}/libs/${ANDROID_ABI}/libpng.a
        $ENV{COCOS_LITE}/libs/${ANDROID_ABI}/libfreetype.a
        $ENV{COCOS_LITE}/libs/${ANDROID_ABI}/libtiff.a
        $ENV{COCOS_LITE}/libs/${ANDROID_ABI}/libtinyxml2.a
        $ENV{COCOS_LITE}/libs/${ANDROID_ABI}/libz.a
        $ENV{COCOS_LITE}/libs/${ANDROID_ABI}/libwebsockets.a
        $ENV{COCOS_LITE}/libs/${ANDROID_ABI}/libunzip.a
        $ENV{COCOS_LITE}/libs/${ANDROID_ABI}/libcurl.a
        $ENV{COCOS_LITE}/libs/${ANDROID_ABI}/libssl.a
        $ENV{COCOS_LITE}/libs/${ANDROID_ABI}/libcrypto.a
        $ENV{COCOS_LITE}/libs/${ANDROID_ABI}/libtremolo.a
        $ENV{COCOS_LITE}/libs/${ANDROID_ABI}/libpvmp3dec.a
        $ENV{COCOS_LITE}/libs/${ANDROID_ABI}/libxxhash.a

        )
