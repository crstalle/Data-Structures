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

//Inserts new second node
void insert_second_list(List **mylist, ItemType Item){
    //Create and setup the new node 
    Node *insertion = malloc(sizeof(Node));
    insertion->data = Item;
    
    //Create a temporary node
    Node *temp = *mylist;
    //Go to the second node and connect the insertion with the second node 
    temp = temp->next;   //second node
    insertion->next = temp; //connect the insertion with the second node

    //Connect the first node with insertion
    (*mylist)->next = insertion; 
}

//Inserts new last node 
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

//Search for an item in the List
Node *search_list(List *mylist, ItemType Item){
    //Create temporary node
    Node *temp = mylist;

    //Search
    while(temp != NULL){
        if(temp->data == Item){
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

//Replace list[i] item
void replace_item_list(List **mylist, ItemType Item, int position){
    //Check if position is in the range of length
    if(position > length_list(*mylist)){
        printf("Position out of length.\n");
    }
    else{ //If is in the range...
        //Create a temporary node to run through the List
        Node *temp = *mylist;
        for(int i = 1; i < position; i++){
            temp = temp->next;
        }
        temp->data = Item;
    }
}