#include "App.h"
#include <utils/MyException.h>


int App::Run()
{
	// Initialize GLFW
	if (!glfwInit()) {
		throw MyException(__LINE__, __FILE__);
	}

	// Create window
	GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL App", nullptr, nullptr);
	if (!window) {
		glfwTerminate();
		throw MyException(__LINE__, __FILE__);
	}

	// Main loop
	while (!glfwWindowShouldClose(window) && running) {
		// Clear screen
		glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// TODO: handle input, update, render

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	// Cleanup
	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}
