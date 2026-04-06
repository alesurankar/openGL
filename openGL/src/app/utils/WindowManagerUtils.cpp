#include "WindowManagerUtils.h"
#include <cmath>


glm::vec3 positionsWin[numWindows];
float rotationsWin[numWindows];
unsigned int orderDraw[numWindows];
float distanceCamera[numWindows];

int Compare(const void* a, const void* b) 
{
    double diff = distanceCamera[*(int*)b] - distanceCamera[*(int*)a];
    return (0 < diff) - (diff < 0);
}