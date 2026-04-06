#pragma once
#include <glad/glad.h> 
#include <GLFW/glfw3.h>


class App
{
public:
	int Run();
private:
	static GLFWwindow* InitWindow(int width, int height, const char* title);
private:
	bool running = true;
};