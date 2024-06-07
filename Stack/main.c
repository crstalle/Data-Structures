#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"


int main(int argc, char **argv){
    //ERROR INPUT EXAMINATION
    if(argc != 2){
        printf("Call the program as follows: ./myprog <capacity>\n");
        exit(1);
    }

    //DECLARATIONS
    int capacity = atoi(argv[1]);
    Stack *mystack = NULL;
    bool full;

    //MAIN BODY
    mystack = create_stack(capacity);
    full = is_full(mystack);
    if(full == 0){
        printf("Stack is not full.\n");
    }
    else{
        printf("Stack is full.\n");
    }
    destroy_stack(mystack);

    return 0;
}