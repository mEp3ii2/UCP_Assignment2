#ifndef PRINTER_H
#define PRINTER_H
#include "mapStruct.h"
#include "carStruct.h"
#include "playerStruct.h"
void printer(Map* myMap, Car* car,Player* player);
void refresh();
char carDirection(int direction);
#endif
