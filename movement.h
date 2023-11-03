#ifndef MOVEMENT_H
#define MOVEMENT_H
#include "carStruct.h"
#include "playerStruct.h"
#include "mapStruct.h"
void movement(Map* myMap, Car* car, Player* Player);
int moveCheck(Map* myMap, int row, int col);
void updatePositions(int* cords, Player* player,Car* car);
void updateCords(int * cords, Player* player, Car* car);
int goalReached(Map* myMap, Player* player);

#endif