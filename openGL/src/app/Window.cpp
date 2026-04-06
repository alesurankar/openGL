#include "Window.h"
#include <utils/DebugLog.h>


Window::Window(int width_in, int height_in, const char* title)
	: 
	width(width_in), 
	height(height_in)
{
	DBG_LOG("Constructing Window");
	if (!glfwInit()) {
		throw std::runtime_error("Failed to initialize GLFW");
	}

	handle_ = glfwCreateWindow(width, height, title, nullptr, nullptr);
	if (!handle_) { 
		glfwTerminate(); throw std::runtime_error("Failed to create GLFW window"); 
	}

	glfwMakeContextCurrent(handle_);
}

Window::~Window()
{
	DBG_LOG("Destroying Window");
	if (handle_) {
		glfwDestroyWindow(handle_);
	}
	glfwTerminate();
}

std::optional<int> Window::ProcessMessages() noexcept
{
	return std::optional<int>();
}
