#include "GraphicsManager.h"


void GraphicsManager::SetupLight(Shader& shader, const glm::vec3& lightPos, const glm::vec4& lightColor) 
{
    shader.Activate();
    glUniform4f(glGetUniformLocation(shader.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
    glUniform3f(glGetUniformLocation(shader.ID, "lightPos"), lightPos.x, lightPos.y, lightPos.z);
}