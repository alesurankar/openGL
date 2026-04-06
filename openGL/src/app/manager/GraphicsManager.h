#pragma once
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <graphics/shader/ShaderClass.h>


class GraphicsManager 
{
public:
    static void SetupLight(Shader& shader, const glm::vec3& lightPos, const glm::vec4& lightColor);
};