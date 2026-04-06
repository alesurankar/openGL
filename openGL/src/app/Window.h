#pragma once
#include <glad/glad.h> 
#include <GLFW/glfw3.h>
#include <app/Graphics.h>
#include <string>
#include <optional>
#include <memory>

class Window
{
public:
	Window(int width, int height, const char* title);
	Window(const Window&) = delete;
	Window& operator=(const Window&) = delete;
	~Window();
	GLFWwindow* GetHandle() const { return handle_; }
	static inline std::optional<int> quitCode_ = std::nullopt;
	static std::optional<int> ProcessMessages(GLFWwindow* window) noexcept;
	Graphics& Gfx();
private:
	int width;
	int height;
	GLFWwindow* handle_;
	std::unique_ptr<Graphics> gfx_;
};