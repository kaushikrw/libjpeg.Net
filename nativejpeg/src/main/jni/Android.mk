LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := libjpeg-turbo
LOCAL_SRC_FILES := libjpeg-turbo.a
#LOCAL_EXPORT_C_INCLUDES := C:\Users\peter\AndroidStudioProjects\libjpeg\turbojpeg\src\main\jni\libjpeg-turbo-2.0.1\
#LOCAL_C_INCLUDES := C:\Users\peter\AndroidStudioProjects\libjpeg\turbojpeg\src\main\jni\include\
#LOCAL_LDLIBS := -llog -lz -lm -ljpeg
include $(PREBUILT_STATIC_LIBRARY)

include $(CLEAR_VARS)

LOCAL_MODULE := nativejpeg
LOCAL_SRC_FILES := loadimage.cpp
LOCAL_C_INCLUDES := C:\Users\peter\AndroidStudioProjects\libjpeg\turbojpeg\src\main\jni\libjpeg-turbo-2.0.1
LOCAL_C_INCLUDES += C:\Users\peter\AndroidStudioProjects\libjpeg\turbojpeg\src\main\jni\include\
LOCAL_LDLIBS := -llog -lz -lm
LOCAL_STATIC_LIBRARIES := libjpeg-turbo
include $(BUILD_SHARED_LIBRARY)			# start building based on everything since CLEAR_VARS






