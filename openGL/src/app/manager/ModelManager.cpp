#include "ModelManager.h"
#include <filesystem>
namespace fs = std::filesystem;


Models LoadModels(const std::string& baseDir) 
{
    Models models;
    models.ground = new Model((baseDir + "/OpenGL/Models/ground/scene.gltf").c_str());
    models.grass = new Model((baseDir + "/OpenGL/Models/grass/scene.gltf").c_str());
    models.windows = new Model((baseDir + "/OpenGL/Models/windows/scene.gltf").c_str());
    models.shape = new Model((baseDir + "/OpenGL/Models/shape/untitled.gltf").c_str());
    return models;
}