/*
    This is the library of List Operations
*/
#include <stdio.h>

/*
    DECLARATION OF LIST
*/
typedef int ItemType;  //the type of List

typedef struct NodeType{
    ItemType data;
    struct NodeType *next;
} Node;

typedef Node List;



/*
    LIST OPERATIONS
*/

//Creates an empty List
List *create_list(void);

//Is empty
void is_empty_list(List *mylist);

//Length of the List
int length_list(List *mylist);

//Inserts new item on the List (last)
void insert_last_list(List **mylist, ItemType Item);

//Delete last node 
void delete_last_list(List **mylist);

//Prints the List
void print_list(List *mylist);