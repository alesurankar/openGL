#include<filesystem>
namespace fs = std::filesystem;

#include <app/manager/GraphicsManager.h>
#include <app/manager/ModelManager.h>
#include <app/manager/WindowManager.h>
#include <app/utils/WindowManagerUtils.h>
#include <utils/FrameTimer.h>
#include <thread>


int main() 
{
    const unsigned int width = 1880;
    const unsigned int height = 1020;

    GLFWwindow* window = WindowManager::InitWindow(width, height, "OpenGL");
    if (!window) return -1;

    Shader shaderProgram("shaders/default.vert", "shaders/default.frag");
    Shader grassProgram("shaders/default.vert", "shaders/grass.frag");
    Shader winProgram("shaders/default.vert", "shaders/windows.frag");

    glm::vec4 lightColor(1.0f);
    glm::vec3 lightPos(0.5f, 0.5f, 0.5f);

    GraphicsManager::SetupLight(shaderProgram, lightPos, lightColor);
    GraphicsManager::SetupLight(grassProgram, lightPos, lightColor);

    Camera camera(width, height, glm::vec3(0.0f, 2.0f, 2.0f));

    std::string parentDir = fs::current_path().parent_path().string();
    auto models = LoadModels(parentDir);

    // window generation, main loop, etc.
}