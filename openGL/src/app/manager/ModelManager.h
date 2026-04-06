#pragma once
#include <graphics/model/Model.h>
#include <string>


struct Models 
{
    Model* ground;
    Model* grass;
    Model* windows;
    Model* shape;
};

Models LoadModels(const std::string& baseDir);