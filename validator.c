#include <stdio.h>
#include <stdlib.h>

/* NAME: validator
 * PURPOSE: validates the command line arguments
 * IMPORTS: argc, argv
 * EXPORTS: 1 for invalid command line params else 0
 */

int validator(int argc, char*argv[]){
    
    int result;
    result = 0;
    /* checks the amount of command line args*/
    if(argc < 2){
        printf("Not enought command line args\n");
        result = 1;
    }
    else if(argc > 2){
        result = 1;
        printf("Warning! Too many command line args\n");
    }
  
    return result;
}
