#include "Graphics.h"
#include <utils/DebugLog.h>


Graphics::Graphics(GLFWwindow* handle_)
{
    DBG_LOG("Constructing Graphics");
}

Graphics::~Graphics()
{
    DBG_LOG("Destroying Graphics");
}

void Graphics::BeginFrame(float red, float green, float blue) noexcept
{
    glClearColor(red, green, blue, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Graphics::EndFrame()
{
    glfwSwapBuffers(glfwGetCurrentContext());
}