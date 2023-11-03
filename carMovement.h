#ifndef CARMOVEMENT_H
#define CARMOVEMENT_H
#include "carStruct.h"
#include "mapStruct.h"
void carMovement(Car* car, Map* myMap);
int checkUp(Map* myMap, Car* car);
int checkDown(Map* myMap, Car* car);
int checkRight(Map* myMap, Car* car);
int checkLeft(Map* myMap, Car* car);
void moveRight(Car* car);
void moveLeft(Car* car);
void moveDown(Car* car);
void moveUp(Car* car);
#endif