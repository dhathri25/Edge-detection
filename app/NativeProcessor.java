package com.example.edgeviewer;

public class NativeProcessor {
    static {
        System.loadLibrary("native_processor");
    }

    public native byte[] processFrame(byte[] inputFrame, int width, int height, boolean useCanny);
}
