#include <stdio.h>
#include <stdlib.h>
#include "mapStruct.h"
#include "printer.h"
#include "carStruct.h"
#include "playerStruct.h"
#include "carCollide.h"

/* NAME: printer
 * PURPOSE: to display the current game state to the user
 * IMPORTS: myMap, car, player structs
 * EXPORTS: NONE
 * ASSERTIONS: all structs have been initalised with valid values
 */
void printer(Map* myMap, Car* car,Player* player){
   int i, j;
   refresh();

    for(i = 0; i < myMap->row+2; i++)
    {
        for(j = 0; j < myMap->col+2; j++)
        {
            if(i== car->carRow && j == car->carCol){
                printf("%c",carDirection(car->direction));
            }
            else if(i== player->row && j == player->col){
                    printf("P");
            }
            else{
                if(myMap->map[i][j] == 0)
                {
                    printf(" ");
                }
                else if(myMap->map[i][j]==1){
                    printf(".");
                }
                else if(myMap->map[i][j]==2)
                {
                    printf(">");
                }
                else if(myMap->map[i][j]==3)
                {
                    printf("P");
                }
                else if(myMap->map[i][j] == 4)
                {
                    printf("G");
                }
                else if(myMap->map[i][j] == 5)
                {
                    printf("*");
                }
                else{
                    printf("!");
                }
            }
            
        }
        printf("\n");
    } 
    
    printf("Howdy");
    printf("Player row: %d\n",player->row);
    printf("Player col: %d\n",player->col);
    printf("Car row: %d\n",car->carRow);
    printf("Car col: %d\n",car->carCol);
}

/* NAME: refresh
 * PURPOSE: clear the terminal screen 
 * IMPORTS: NONE
 * EXPORTS: NONE
 * ASSERTIONS: N/A
 */
void refresh()
{
    system("clear");
}

/* NAME: carDirection
 * PURPOSE: returns a char charater to appropriately display the direction the car is travelling
 * IMPORTS: direction an in value from the car struct
 * EXPORTS: charDirection - char character to reperesent the cars direction
 * ASSERTIONS: direction is an int from 1-4
 */

char carDirection(int direction){
    char charDirection;
    switch (direction)
    {
    case 1:
        charDirection ='>';
        break;
    case 2:
        charDirection ='<';
        break;
    case 3:
        charDirection ='^';
        break;
    case 4:
        charDirection ='v';
        break;
    default:
        break;
    }
    return charDirection;
}