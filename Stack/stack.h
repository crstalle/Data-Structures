/*
    This is a library for all the operations of a Stack
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Declaration of Stack
typedef struct{
    int *collection;  //The dynamic allocated array that contains the items
    int capacity;  //The maximum capacity Stack can hold
    int size;  //The number of items currently on Stack
} Stack;


//Creates a new empty Stack
Stack *create_stack(int capacity);

//Destroys the Stack
void destroy_stack(Stack *mystack);

//Checks if Stack is full
bool is_full(Stack *mystack);