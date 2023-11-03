#include <stdio.h>
#include <stdlib.h>

/* NAME: Player
 * PURPOSE: a player struct to store its cordiantes
 * IMPORTS: row int value and col int value
 * ASSERTIONS: row and column are valid positions on the map
 */
typedef struct{
    int row;
    int col;
}Player;