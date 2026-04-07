#pragma once
#include <glad/glad.h> 
#include <GLFW/glfw3.h>

class Graphics
{
public:
	Graphics(GLFWwindow* handle_);
	Graphics(const Graphics&) = delete;
	Graphics& operator=(const Graphics&) = delete;
	~Graphics();
	void BeginFrame(float red, float green, float blue) noexcept;
	void EndFrame();
private:
};