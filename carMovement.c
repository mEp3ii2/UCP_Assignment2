#include <stdio.h>
#include <stdlib.h>
#include "carMovement.h"
#include "carStruct.h"
#include "mapStruct.h"

/* NAME: carMove
 * PURPOSE: moves cars along the play area
 * IMPORTS: car,myMap
 * EXPORTS: NONE
 * ASSERTIONS: player has made a valid move
 */
void carMovement(Car* car, Map* myMap){
    
    switch (car->direction)
    {
        case 1:
            if(myMap->map[car->carRow][car->carCol+1]==1){
                moveRight(car);                
            }else{
                if(checkUp(myMap,car)!=1){
                    checkDown(myMap,car);
                }
            }
            break;
        case 2:
            if(myMap->map[car->carRow][car->carCol-1]==1){
                moveLeft(car);
                
            }else{
                if(checkUp(myMap,car)!=1){
                    checkDown(myMap,car);
                }
            }
            break;
        case 3:
            if(myMap->map[car->carRow-1][car->carCol]==1){
                moveUp(car);
            }
            else{
                if(checkRight(myMap,car)!=1){
                    checkLeft(myMap,car);
                }
            }
            break;
        case 4:
            if(myMap->map[car->carRow+1][car->carCol]==1){
                moveDown(car);
            }else{
                if(checkRight(myMap,car)!=1){
                    checkLeft(myMap,car);
                }
            }
            break;
        default:
            break;
    }
}

/* NAME: checkUp
 * PURPOSE: checks if the position up from the car is a road character
 * IMPORTS: myMap, car
 * EXPORTS: result int 1 fo yes 0 for no
 * ASSERTIONS: car can no longer continue on its current path
 */

int checkUp(Map* myMap, Car* car){
    int result =0;
    if(myMap->map[car->carRow-1][car->carCol]==1){
        car->direction =3;
        moveUp(car);
        result = 1;
    }
    return result;
}

/* NAME: checkDown
 * PURPOSE: checks if the position down from the car is a road character
 * IMPORTS: myMap, car
 * EXPORTS: result int 1 fo yes 0 for no
 * ASSERTIONS: car can no longer continue on its current path
 */
int checkDown(Map* myMap, Car* car){
    int result =0;
    if(myMap->map[car->carRow+1][car->carCol]==1){
        car->direction=4;
        moveDown(car);
        result = 1;
    }
    return result;
}

/* NAME: checkLeft
 * PURPOSE: checks if the position to the right from the car is a road character
 * IMPORTS: myMap, car
 * EXPORTS: result int 1 fo yes 0 for no
 * ASSERTIONS: car can no longer continue on its current path
 */
int checkRight(Map* myMap, Car* car){
    int result = 0;
    if(myMap->map[car->carRow][car->carCol+1]==1){
        car->direction= 1;
        moveRight(car);
        result =1;
    }
    return result;
}

/* NAME: checkLeft
 * PURPOSE: checks if the position to the left from the car is a road character
 * IMPORTS: myMap, car
 * EXPORTS: result int 1 fo yes 0 for no
 * ASSERTIONS: car can no longer continue on its current path
 */
int checkLeft(Map* myMap, Car* car){
    int result = 0;
    if(myMap->map[car->carRow][car->carCol-1]==1){
        car->direction= 2;
        moveLeft(car);
        result =1;
    }
    return result;
}

/* NAME: moveRight
 * PURPOSE: increment the car column value by 1
 * IMPORTS: car
 * EXPORTS: NONE
 * ASSERTIONS: car can move right
 */
void moveRight(Car* car){
    car->carCol +=1;
}

/* NAME: moveLeft
 * PURPOSE: decrement the car column value by 1
 * IMPORTS: car
 * EXPORTS: NONE
 * ASSERTIONS: car can move left
 */
void moveLeft(Car* car){
    car->carCol -=1;
}

/* NAME: moveDown
 * PURPOSE: increment the car row value by 1
 * IMPORTS: car
 * EXPORTS: NONE
 * ASSERTIONS: car can move down
 */
void moveDown(Car* car){
    car->carRow +=1;
}

/* NAME: moveUp
 * PURPOSE: decrement the car row value by 1
 * IMPORTS: car
 * EXPORTS: NONE
 * ASSERTIONS: car can move right
 */
void moveUp(Car* car){
    car->carRow -=1;
}