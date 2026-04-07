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
	glfwSwapInterval(2); // enable vsync

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		glfwDestroyWindow(handle_);
		glfwTerminate();
		throw std::runtime_error("Failed to initialize GLAD");
	}
	// associate this Window instance
	glViewport(0, 0, width, height);
	// associate this Window instance
	glfwSetWindowUserPointer(handle_, this);

	// framebuffer size callback
	glfwSetFramebufferSizeCallback(handle_, [](GLFWwindow* win, int w, int h) {
		glViewport(0, 0, w, h);
	});

	// set initial viewport
	glfwSetKeyCallback(handle_, [](GLFWwindow* win, int key, int scancode, int action, int mods) {
		Window* pWindow = static_cast<Window*>(glfwGetWindowUserPointer(win));
		if (action == GLFW_PRESS) {
			pWindow->kbd.OnKeyPressed(static_cast<unsigned char>(key));
		}
		else if (action == GLFW_RELEASE) {
			pWindow->kbd.OnKeyReleased(static_cast<unsigned char>(key));
		}
	});

	glfwSetCharCallback(handle_, [](GLFWwindow* win, unsigned int c) {
		Window* pWindow = static_cast<Window*>(glfwGetWindowUserPointer(win));
		pWindow->kbd.OnChar(static_cast<char>(c));
	});

	glfwSetCursorPosCallback(handle_, [](GLFWwindow* win, double xpos, double ypos) {
		Window* pWindow = static_cast<Window*>(glfwGetWindowUserPointer(win));
		pWindow->mouse.OnMouseMove(static_cast<int>(xpos), static_cast<int>(ypos));
	});

	glfwSetMouseButtonCallback(handle_, [](GLFWwindow* win, int button, int action, int mods) {
		Window* pWindow = static_cast<Window*>(glfwGetWindowUserPointer(win));
		double x, y;
		glfwGetCursorPos(win, &x, &y);
		if (button == GLFW_MOUSE_BUTTON_LEFT) {
			if (action == GLFW_PRESS) {
				pWindow->mouse.OnLeftPressed(static_cast<int>(x), static_cast<int>(y));
			}
			else if (action == GLFW_RELEASE) {
				pWindow->mouse.OnLeftReleased(static_cast<int>(x), static_cast<int>(y));
			}
		}
		else if (button == GLFW_MOUSE_BUTTON_RIGHT) {
			if (action == GLFW_PRESS) {
				pWindow->mouse.OnRightPressed(static_cast<int>(x), static_cast<int>(y));
			}
			else if (action == GLFW_RELEASE) {
				pWindow->mouse.OnRightReleased(static_cast<int>(x), static_cast<int>(y));
			}
		}
	});

	glfwSetScrollCallback(handle_, [](GLFWwindow* win, double xoffset, double yoffset) {
		Window* pWindow = static_cast<Window*>(glfwGetWindowUserPointer(win));
		pWindow->mouse.OnWheelDelta(0, 0, static_cast<int>(yoffset));
	});

	gfx_ = std::make_unique<Graphics>(handle_);
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

Graphics& Window::Gfx()
{
	return *gfx_;
}
