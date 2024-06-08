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

//Pushes an item on the top of the Stack
bool push(Stack *mystack, int data){
    //Check if Stack is full
    if(is_full(mystack)){
        return false;
    }

    //If it isn't, we can push the item
    mystack->collection[mystack->size] = data;
    mystack->size++;
    return true;
}

//Pops an item from the top of the Stack
bool pop(Stack *mystack, int *popped_data){
    //Check if Stack is empty
    if(is_empty(mystack)){
        return false;
    }

    //Stack is not empty, so we can pop an item from the top of the Stack
    mystack->size--;
    *popped_data = mystack->collection[mystack->size];

    //we dont need to decrease the size again, because there will be pushed an item. So, we return true
    return true;

}

//Prints the Stack
void print_stack(Stack *mystack){
    for(int i = mystack->size - 1; i>= 0; i--){
        printf("%d\n", mystack->collection[i]);
    }
}