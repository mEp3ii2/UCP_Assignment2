#include <stdio.h>
#include <stdlib.h>
#include "box.h"

/* NAME: box
 * PURPOSE: fills the map array with the values
 * IMPORTS: myMap, f, car, player
 * EXPORTS: NONE
 * ASSERTIONS: structs have been created and file read in
 */

void box (Map* myMap, FILE * f, Car* car,Player* player){

    int i,j, value;

    for(i = 0; i < myMap->row + 2; i++){
        for(j = 0; j < myMap->col+2; j++)
        {
            if( i == 0 || i == myMap->row+1){
                myMap->map[i][j] = 5;
            }
            else if (j==0 || j == myMap->col+1){
                myMap->map[i][j] = 5;
            }
            else{
                if(fscanf(f,"%d", &value) !=1){
                    printf("Failed to read data from the file\n");
                    fclose(f);                    
                }
                else{
                    if(value== 2){
                        car->carRow=i;
                        car->carCol=j;
                        car->direction = 1;
                        myMap->map[i][j] = 1;
                    }
                    else if (value== 3)
                    {
                        player->row = i;
                        player->col = j;
                        myMap->map[i][j] = 0;
                        
                    }
                    else if (value == 4)
                    {
                        myMap->goalrow =i;
                        myMap->goalcol =j;
                        myMap->map[i][j]= value;
                    }
                    
                    else{
                        myMap->map[i][j]= value;
                    }
                }
            }
            
        }
    }
}