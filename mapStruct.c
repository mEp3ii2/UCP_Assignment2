#include <stdio.h>
#include <stdlib.h>

/* NAME: Map
 * PURPOSE: creates a map stuct to store the 2d array and size along with goal cords
 * IMPORTS: map 2d array, row and col ints for the map size and goalrow goalcol ints for the goal cords 
 * ASSERTIONS: provided file exists and is not empty, row and col in the file map the map data in the 
 */
typedef struct {
    int ** map;
    int row;
    int col;
    int goalrow;
    int goalcol;
} Map;
