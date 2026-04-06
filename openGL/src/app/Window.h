#pragma once
#include <glad/glad.h> 
#include <GLFW/glfw3.h>
#include <string>
#include <memory>
#include <optional>

class Window
{
public:
	Window(int width, int height, const char* title);
	~Window();
	Window(const Window&) = delete;
	Window& operator=(const Window&) = delete;
	static std::optional<int> ProcessMessages() noexcept;
private:
	int width;
	int height;
	GLFWwindow* handle_;
};