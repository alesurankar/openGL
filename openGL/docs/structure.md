## Project Structure


```text
src/
├─ app/   
│   ├─ manager/   
│   │   ├─ GraphicsManager
│   │   └─ ModelManager
│   ├─ utils/   
│   │   └─ WindowManagerUtils
│   ├─ App
│   ├─ Graphics
│   ├─ Main.cpp    # entry
│   └─ Window
│
├─ external/
│   ├─ stb.cpp
│   └─ glad.c
│
├─ graphics/
│   ├─ camera/
│   │   └─ Camera
│   ├─ core/
│   │   ├─ EBO      # Index buffer object
│   │   ├─ VAO      # Vertex Array Object
│   │   └─ VBO      # Vertex Buffer Object
│   ├─ mesh/
│   │   └─ Mesh    # Drawable geometry
│   ├─ model/
│   │   └─ Model    # 3D asset loader
│   ├─ shader/
│   │   └─ ShaderClass  # Shader program wrapper
│   └─ texture/
│       └─ Texture   # Image texture loader
│
└─ utils/
    ├─ DebugLog
    ├─ FrameTimer
    └─ MyException
```