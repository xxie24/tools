LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := cpu_task
LOCAL_SRC_FILES += cpu_task.c

include $(BUILD_EXECUTABLE)
