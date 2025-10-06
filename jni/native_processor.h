#ifndef NATIVE_PROCESSOR_H
#define NATIVE_PROCESSOR_H

#include <jni.h>

extern "C" {
JNIEXPORT jbyteArray JNICALL
Java_com_example_edgeviewer_NativeProcessor_processFrame(
        JNIEnv *env,
        jobject obj,
        jbyteArray inputFrame,
        jint width,
        jint height,
        jboolean useCanny);
}

#endif // NATIVE_PROCESSOR_H
