#include <stdio.h>
#include <stdlib.h>

/* NAME: Car
 * PURPOSE: defines a car struct 
 * IMPORTS: carRow int value of cars row position, 
 *          carCol int value of cars column position, 
 *          direction int value to store the direction car is traveling
 * ASSERTIONS: valid row and column cords are given
 * 
 */
typedef struct{
    int carRow;
    int carCol;
    int direction; /*  1 >    2 <    3 ^    4 v */
}Car;