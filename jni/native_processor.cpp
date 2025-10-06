#include <jni.h>
#include <opencv2/opencv.hpp>
#include <android/log.h>

#define LOG_TAG "NativeProcessor"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)

using namespace cv;

extern "C"
JNIEXPORT jbyteArray JNICALL
Java_com_example_edgeviewer_NativeProcessor_processFrame(
        JNIEnv *env,
        jobject /* this */,
        jbyteArray inputFrame,
        jint width,
        jint height,
        jboolean useCanny) {

    // Convert input byte array to Mat
    jbyte* inputBytes = env->GetByteArrayElements(inputFrame, nullptr);
    Mat yuv(height + height / 2, width, CV_8UC1, (unsigned char*)inputBytes);
    Mat bgr;
    cvtColor(yuv, bgr, COLOR_YUV2BGR_NV21);

    Mat processed;
    if (useCanny) {
        cvtColor(bgr, processed, COLOR_BGR2GRAY);
        Canny(processed, processed, 100, 200);
    } else {
        cvtColor(bgr, processed, COLOR_BGR2GRAY);
    }

    // Convert processed Mat to byte array
    std::vector<uchar> buf;
    imencode(".png", processed, buf);
    jbyteArray output = env->NewByteArray(buf.size());
    env->SetByteArrayRegion(output, 0, buf.size(), reinterpret_cast<jbyte*>(buf.data()));

    env->ReleaseByteArrayElements(inputFrame, inputBytes, JNI_ABORT);
    return output;
}
