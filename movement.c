#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "terminal.h"
#include "movement.h"
#include "carStruct.h"
#include "playerStruct.h"
#include "mapStruct.h"
#include "carMovement.h"
#include "printer.h"
#include "linkedList.h"
#include "carCollide.h"

/* NAME: movement
 * PURPOSE: move the player around the map
 * IMPORTS:myMap,car,player
 * EXPORTS: NONE
 * ASSERTIONS:
 * 	PRE: myMap.map has valid values, player and car have been loaded
 * 	     the game has been printed out to the player before prompted for 
 * 	     movement.
 * 	POST: end condition has been met of either player has entered x to exit 
 * 	      player lost due to collision
 * 	      or player won by reaching the goal
 */
void movement(Map* myMap, Car* car, Player* player){
    char mov = 'l';
    int moveR, moveC,move;
    LinkedList* list = createLinkedList();
    int * cords; 
    cords = (int*)malloc(5*sizeof(int));
    updateCords(cords,player,car);
    insertStart(cords,list);
    
    while(mov != 'x'){
        moveR = 0;
        moveC = 0;
        move = 0;
    
        printf("Enter movement: ");
        disableBuffer();
        scanf(" %c",&mov);
        enableBuffer();

        switch (mov)
        {
        case 'w':
            moveR = -1;
            move = moveCheck(myMap,player->row-1,player->col);
            break;
        case 'd':
            moveC = 1;
            move = moveCheck(myMap,player->row,player->col+1);
            break;
        case 's':
            moveR = 1;
            move = moveCheck(myMap,player->row+1,player->col);
            break;
        case 'a':
            moveC = -1;
            move = moveCheck(myMap,player->row,player->col-1);
            break;
        case 'u':
            deleteLastNode(list);
            if(isEmpty(list)==0){
                /* cords = (int*)malloc(5*sizeof(int)); */
                cords = (int*)list->TAIL->data;
                updatePositions(cords,player,car);
            }
            
            move = 1;
            break;
        case 'x':
            printf("\nGame Over!\n");
            deleteEntireList(list);
            move = 1;
            break;
        default:
            move =1;
            break;
        }

        if(move == 0)
        {
            player->row += moveR;
            player->col += moveC;
            carMovement(car,myMap);
            cords = (int*)malloc(5*sizeof(int));
            updateCords(cords,player,car);
            insertEnd(cords,list);
        }
        printer(myMap,car,player);
        if(goalReached(myMap,player)==1){
            mov = 'x';
            printf("You Win!\n");
        }
        else if (carCollision(car,player)== 1)
        {
            mov = 'x';
            printf("Crashed You Lose!");
        }
        
    }
    free(cords);
    cords= NULL;
    list->TAIL->data = NULL;
    deleteEntireList(list);
    
    
}

/* NAME: moveCheck
 * PURPOSE: check the validity of the inputed movement
 * IMPORTS: myMap, row, col
 * EXPORTS: 0 if not valid and 1 if valid
 * ASSERTIONS: map is populated
 */
int moveCheck(Map* myMap, int row, int col){
    int result = 0;
    if(myMap->map[row][col]==5){
        result = 1;
    }
    return result;
}

/* NAME: updatePositions
 * PURPOSE: updates the player and car values using the cords array
 * IMPORTS: cords, player, car
 * EXPORTS: NONE
 * ASSERTIONS: cords has been populated with new values 
 */
void updatePositions(int* cords, Player* player,Car* car){
    player->row = cords[0];
    player->col = cords[1];
    car->carRow = cords[2];
    car->carCol = cords[3];
    car->direction = cords[4];
}

/* NAME: updateCords
 * PURPOSE: update the values of the cords array
 * IMPORTS: cords, player, car
 * EXPORTS: NONE
 * ASSERTIONS: player and car have made a move
 */
void updateCords(int * cords, Player* player, Car* car){
    cords[0] = player->row;
    cords[1] = player->col;
    cords[2] = car->carRow;
    cords[3] = car->carCol;
    cords[4] = car->direction;
}

/* NAME: goalReached
 * PURPOSE: checks if the player has reached the goal
 * IMPORTS: myMap,player
 * EXPORTS: result int 1 for yes else 0
 * ASSERTIONS: player and game is still running
 */
int goalReached(Map* myMap, Player* player){
    int result = 0;
    if(myMap->goalrow == player->row && myMap->goalcol == player->col){
        result = 1;
    }
    return result;
}




    
