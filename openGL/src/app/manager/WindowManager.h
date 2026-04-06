#pragma once
#include <glad/glad.h> 
#include <GLFW/glfw3.h>


class WindowManager 
{
public:
    static GLFWwindow* InitWindow(int width, int height, const char* title);
};