/*
    This is the library of List Operations
*/
#include <stdio.h>
#include <stdlib.h>
#include "list.h"


//creates an empty List
Node *create_list(){
    return NULL;
}

//Is empty
void is_empty_list(List *mylist){
    //Check if the first node points to NULL
    if(mylist == NULL){
        printf("List is empty.\n");
    }
    else{
        printf("List is not empty.\n");
    }
}

//Length of the List
int length_list(List *mylist){
    //Create a temporary node to run through the List
    Node *temp = mylist;
    int counter = 0;

    while(temp != NULL){
        counter++;
        temp = temp->next;
    }
    return counter;
}

//Inserts new item on the List (last)
void insert_last_list(List **mylist, ItemType Item){
    //Firstly, lets create the Node we want to insert
    Node *insertion = malloc(sizeof(Node));
    insertion->next = NULL;
    insertion->data = Item;

    //Lets create a temporary node to run through the List
    Node *temp = *mylist;

    //Lets run through the List
    if(*mylist == NULL){
        *mylist = insertion;
    }
    else{
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = insertion;
    }
}

//Delete last node 
void delete_last_list(List **mylist){
    //Create 1 temp node and 1 for the last node
    Node *temp = *mylist;
    Node *last = *mylist;

    if(*mylist != NULL){
        //If list has 1 node, destroy the node and the pointer to the List becomes NULL
        if((*mylist)->next == NULL){
            free(*mylist);
            *mylist = NULL;
        }
        else{
            //Lets go to the last node
            while(last->next != NULL){
                last = last->next;
            }
            //Lets go to the pre-last node
            while(temp->next != last){
                temp = temp->next;
            }
            free(last);
            temp->next = NULL;
        }
    }
}

//Prints the List
void print_list(List *mylist){
    //Lets create the temp node to run through the list
    Node *temp = mylist;

    //Run through the List
    if(mylist != NULL){
        printf("{");
    }
    while(temp != NULL){
        printf("%d, ", temp->data);
        temp = temp->next;
    }
    if(mylist != NULL){
        printf("\b\b}\n");
    }
}