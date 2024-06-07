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
    bool full, empty;

    //MAIN BODY
    mystack = create_stack(capacity);  //create_stack test
    if(mystack != NULL){ //It has a point to test the Stack Operations, if the Stack has been created
        full = is_full(mystack);  //is_full test
        empty = is_empty(mystack);  //is_empty test
    if(full == 1){
        printf("Stack is full.\n");
    }
    if(empty == 1){
        printf("Stack is empty.\n"); 
    }
    destroy_stack(mystack);  //destroy_stack test
    }
    
    return 0;
}