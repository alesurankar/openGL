#pragma once
#include <glad/glad.h>
#include <vector>


class EBO
{
public:
	EBO(const std::vector<GLuint>& indices);
	EBO(const EBO&) = delete;
	EBO& operator=(const EBO&) = delete;
	EBO(EBO&& other) noexcept;
	EBO& operator=(EBO&& other) noexcept;
	~EBO();
	void Bind();
	void Unbind();
	void Delete();
public:
	GLuint ID = 0;
};