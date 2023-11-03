#include <stdio.h>
#include <stdlib.h>
#include "setup.h"
#include "box.h"
#include "printer.h"
#include "mapStruct.h"
#include "carStruct.h"
#include "playerStruct.h"
#include "movement.h"


/* NAME: setup
 * PURPOSE: setups the map and  calls other methods then free after finished
 * IMPORTS: fileName
 * EXPORTS: NONE
 * ASSERTIONS: validator function returned 0
 */

void setup(char fileName[])
{
    int i;
    Car* car =(Car*) malloc(sizeof(Car));
    Player* player = (Player*) malloc(sizeof(Player));
    Map* myMap = (Map*) malloc (sizeof (Map));
    FILE * f = fopen(fileName,"r");
    
    if(f == NULL)
    {
        perror("Error: could not open file\n");
    }
    else
    {
        if(fscanf(f, "%d %d",&myMap->row,&myMap->col)==2){

            myMap->map = (int**) malloc (( myMap->row + 2 ) * sizeof (int *) );
            for(i = 0; i < ( myMap->row + 2); i++){
                myMap->map[i]=malloc((myMap->col + 2) * sizeof(int));
            }
        }
    }

    /*call methods */
    box(myMap,f,car,player); /*init creation of playspace*/
    printer(myMap,car,player); /*init print to screen*/
    movement(myMap,car,player);

    /* game finished now
     * free everything
     */
    for(i = 0; i < myMap->row + 2; i++)
    {    
        free(myMap->map[i]);
    }


    free(myMap->map);
    free(myMap);
    free(car);
    free(player);
    fclose(f);
}
