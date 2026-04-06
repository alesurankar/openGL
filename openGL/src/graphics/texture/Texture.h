#pragma once
#include <glad/glad.h>
#include <stb/stb_image.h>
#include <graphics/shader/ShaderClass.h>


class Texture
{
public:
	Texture(const char* image, const char* texType, GLuint slot);
	void texUnit(Shader& shader, const char* uniform, GLuint unit);
	void Bind();
	void Unbind();
	void Delete();
public:
	GLuint ID;
	const char* type;
	GLuint unit;

};