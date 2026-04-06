#pragma once
#include <glm/glm.hpp>


const unsigned int numWindows = 100;
extern glm::vec3 positionsWin[numWindows];
extern float rotationsWin[numWindows];
extern unsigned int orderDraw[numWindows];
extern float distanceCamera[numWindows];

int Compare(const void* a, const void* b);