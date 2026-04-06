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

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	handle_ = glfwCreateWindow(width, height, title, nullptr, nullptr);
	if (!handle_) { 
		glfwTerminate(); 
		throw std::runtime_error("Failed to create GLFW window"); 
	}

	glfwMakeContextCurrent(handle_);
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		glfwDestroyWindow(handle_);
		glfwTerminate();
		throw std::runtime_error("Failed to initialize GLAD");
	}
	glViewport(0, 0, width, height);
	glfwSetFramebufferSizeCallback(handle_, [](GLFWwindow* win, int w, int h) {
		glViewport(0, 0, w, h);
		});
}

Window::~Window()
{
	DBG_LOG("Destroying Window");
	if (handle_) {
		glfwDestroyWindow(handle_);
	}
	glfwTerminate();
}

std::optional<int> Window::ProcessMessages(GLFWwindow* window) noexcept
{
	glfwPollEvents();

	if (window && glfwWindowShouldClose(window)) {
		quitCode_ = 0;
	}

	return quitCode_;
}