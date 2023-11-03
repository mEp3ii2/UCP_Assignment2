#include <stdio.h>
#include <stdlib.h>
#include "carStruct.h"
#include "playerStruct.h"

/* NAME: carCollision
 * PURPOSE: checks if car and player are occupying the same position
 * IMPORTS: car,player
 * EXPORTS: result int 1 if collided else 0
 * ASSERTIONS: player has moved 
 */

int carCollision(Car* car, Player* player){
    int result = 0;
    if(car->carRow == player->row && car->carCol == player->col){
        result = 1;
    }
    return result;
}