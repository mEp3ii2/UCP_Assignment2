#include <stdio.h>
#include <stdlib.h>
#include "setup.h"
#include "validator.h"


int main(int argc, char* argv[]){
    
    /* check if valid paramters have been passed*/
    if(validator(argc,argv) != 0)
    {
        
        printf("\nDesired input:\n");
        printf("./traffic <filename.txt>\n");
        printf("\nGoodbye!\n");
    }
    else
    {

        setup(argv[1]);        
    }

    return 0;    
}