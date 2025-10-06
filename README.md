# 📸 Edge Detection Viewer – Android + OpenCV + OpenGL + Web

This project is a minimal real-time edge detection viewer built for an R&D internship assessment. It integrates Android Camera2 API, OpenCV (C++), OpenGL ES 2.0, and a TypeScript-based web viewer.

---

## ✅ Features Implemented

### 📱 Android App
- Camera2 API with `TextureView` for live frame capture
- JNI bridge to native C++ for frame processing
- OpenCV C++ logic for:
  - Canny Edge Detection
  - Grayscale filtering
- OpenGL ES 2.0 renderer for displaying processed frames
- Toggle between raw and processed view (optional)

### 🌐 Web Viewer
- Static HTML + TypeScript viewer
- Displays a sample processed frame (base64-encoded)
- Shows FPS and resolution overlay
- Buildable via `tsc`

---

## 🧠 Architecture Overview

/app
→ Android Camera2 + JNI bridge
/jni
→ OpenCV C++ processing logic
/gl
→ OpenGL ES rendering classes
/web
→ TypeScript viewer for processed frame

### 🔄 Frame Flow
1. Camera2 captures YUV frame
2. Java passes frame to C++ via JNI
3. OpenCV processes frame (Canny or Grayscale)
4. Result is rendered via OpenGL ES
5. One frame saved as PNG/base64 for web viewer

---

## ⚙️ Setup Instructions

### 🛠 Android
- Requires Android Studio with NDK support
- Add OpenCV SDK to your project and link via `CMakeLists.txt`
- Ensure `native_processor.cpp` is compiled as a shared library
- Permissions: `CAMERA`, `WRITE_EXTERNAL_STORAGE`

### 🌐 Web
- Install TypeScript: `npm install -g typescript`
- Compile: `tsc viewer.ts`
- Open `index.html` in browser

---

## 📷 Screenshots

> *(Add screenshots or GIFs of your app running here)*  
> Example: Raw vs Edge-detected frame, Web viewer with stats

---

## 📦 Repository Structure
edge-viewer-project/
├── app/
│   ├── CameraActivity.java
│   └── NativeProcessor.java
├── jni/
│   ├── native_processor.cpp
│   ├── native_processor.h
│   └── CMakeLists.txt
├── gl/
│   ├── GLRenderer.java
│   └── GLSurfaceViewActivity.java
├── web/
│   ├── index.html
│   ├── viewer.ts
│   └── tsconfig.json
└── README.md

---

## 📜 Commit History

All commits reflect modular development:
- `feat(jni): Add OpenCV C++ edge detection via JNI`
- `feat(app): Add Camera2 API and JNI bridge`
- `feat(gl): Add OpenGL ES renderer for processed frames`
- `feat(web): Add TypeScript viewer for processed frame`


