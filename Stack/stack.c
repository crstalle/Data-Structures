/*
    This is a library for all the operations of a Stack
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "stack.h"


//Creates a new empty Stack
Stack *create_stack(int capacity){
    //If capacity == 0, we cannot create a stack
    if(capacity == 0){
        return NULL;
    } 
    Stack *mystack = malloc(sizeof(Stack));
    //We need to check if malloc was successful in order to continue, else we return NULL
    if(mystack == NULL){
        return NULL;
    }

    //Now we need to allocate the capacity of the Stack
    mystack->collection = malloc(sizeof(int) * capacity);
    //Lets check again if malloc was successful
    if(mystack->collection == NULL){
        return NULL;
    }

    //As everything went good, we initialize the characteristics into mystack
    mystack->capacity = capacity;
    mystack->size = 0;  //empty

    return mystack;
}

//Destroys the Stack
void destroy_stack(Stack *mystack){
    free(mystack->collection);
    free(mystack);
}

//Is stack full?
bool is_full(Stack *mystack){
    return (mystack->capacity == mystack->size);
}

//Is stack empty?
bool is_empty(Stack *mystack){
    return (mystack->size == 0);
}