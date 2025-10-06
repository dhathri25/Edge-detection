package com.example.edgeviewer.gl;

import android.app.Activity;
import android.opengl.GLSurfaceView;
import android.os.Bundle;

public class GLSurfaceViewActivity extends Activity {
    private GLSurfaceView glSurfaceView;
    private GLRenderer renderer;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        glSurfaceView = new GLSurfaceView(this);
        glSurfaceView.setEGLContextClientVersion(2);
        renderer = new GLRenderer();
        glSurfaceView.setRenderer(renderer);
        setContentView(glSurfaceView);
    }

    public void updateFrame(byte[] imageData) {
        renderer.updateImage(imageData);
        glSurfaceView.requestRender();
    }
}
