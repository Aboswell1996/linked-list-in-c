#include "list.h"
#include <stdio.h>
#include <stdlib.h>

//http://www.cs.sfu.ca/~keval/teaching/cmpt300/spring18/assignments/prj1/linkedLists.pdf

/*
 * Allocate memory for a node of type struct nodeStruct and initialize
 * it with the value item. Return a pointer to the new node.
 */
struct nodeStruct* List_createNode(int item){

    struct nodeStruct* temp = NULL;             //create node Pointer before allocating memory on the heap
    temp = malloc(sizeof(struct nodeStruct));   //allocate memory

    temp->item = item;                          //assign values to struct and return
    temp->next = NULL;

    return temp;
}


/*
 * Insert node at the head of the list.
 */
void List_insertHead (struct nodeStruct **headRef, struct nodeStruct *node){

    if (*headRef == NULL){
        *headRef = node;    //list is empty and insert at the beginning
    }
    else{
        node->next = *headRef;  //point newnode to head and then head to new node
        *headRef = node;
    }
}


/*
 * Insert node after the tail of the list.
 */
void List_insertTail (struct nodeStruct **headRef, struct nodeStruct *node){

    //struct nodeStruct* temp = *headRef;             //create node Pointer 


    if ((*headRef) == NULL){
        (*headRef) = node;      //list is empty
    }
    else if ((*headRef)->next == NULL){
        (*headRef)->next = node;    //list has one node
    }
    else{       //list has >1 nodes and we have to iterate to the end
        struct nodeStruct* temp = *headRef;             
        while (temp->next != NULL){
            temp = temp->next;
        }
        temp->next = node;
    }
}


/*
 * Count number of nodes in the list.
 * Return 0 if the list is empty, i.e., head == NULL
 */
int List_countNodes (struct nodeStruct *head){

    int listLength = 0;

    struct nodeStruct* temp = head;

    while (temp != NULL){

        listLength ++;                  //increment until we're at the end and return length
        temp = temp->next;              //while loop stops when we reach the last node

    }
//free(temp);
return listLength;
}


/*
 * Return the first node holding the value item, return NULL if none found
 */
struct nodeStruct* List_findNode(struct nodeStruct *head, int item){

    struct nodeStruct* temp = head;

    if (temp == NULL){  
        return NULL;       //case where list is empty
    }
    else if(temp->item == item){
        return temp;    //case where the first node has the item
    }
    else        //otherwise we iterate until we find it
    {
        //temp = temp->next;
        while(temp->next!= NULL)   //list has >1 node
        {   
            temp = temp->next;
            if(temp->item == item){ //check if we have the right node
            return temp;
            }
            /*else{
            temp = temp->next;
            }*/

        }
        //free(temp);
        return NULL;
    }
}

/*
 * Delete node from the list and free memory allocated to it.
 * This function assumes that node has been properly set to a valid node 
 * in the list. For example, the client code may have found it by calling 
 * List_findNode(). If the list contains only one node, the head of the list 
 * should be set to NULL.
 */
void List_deleteNode (struct nodeStruct **headRef, struct nodeStruct *node){

    if(*headRef != NULL){   //if list is not empty

        if((*headRef)->next == NULL){   // is list has 1 node
            free(*headRef);
            *headRef = NULL;        //set to NULL otherwise the countnode function won't work
        }
        else{   //else list has >1 nodes

            struct nodeStruct* parse_ptr = (*headRef)->next;
            struct nodeStruct* follow_ptr = *headRef;  //this pointer is always the node behind the parse_ptr

            if(follow_ptr->item == node->item){ //corner case: element to delete is the first item in the list
                (*headRef) = parse_ptr;
                free(follow_ptr);
            }
            else
            {
                while(parse_ptr->item != node->item){  //assuming the node to be deleted exists somewhere in the list
                    parse_ptr = parse_ptr->next;
                    follow_ptr = follow_ptr->next;
                }

                follow_ptr->next = parse_ptr->next;
        /*        once we find the node to delete, we point the follow_ptr to the pointer with parse deletes and then free parse pointer
                so there are no missing links or holes in our linked list*/
                free(parse_ptr);
            }
        }
    }

}


/*
 * Sort the list in ascending order based on the item field.
 * Any sorting algorithm is fine.
 */
void List_sort(struct nodeStruct **headRef)
{   
    //sorting a linkedlist using bubble sort adapted to work with nodes of type nodeStruct
    struct nodeStruct *temp1 = *headRef;
    struct nodeStruct *temp2 = NULL;    //used to swap elements
    int didSwap = 1;    //1 is true, 0 is false
    if (temp1 == NULL){
        return; //nothing to sort!
    }
    do
    {
        didSwap = 0;    //stop sorting if this doesn't change in l154

        
        temp1 = *headRef;
        //makefile is using a setting where all warnings are errors so temp2 is being used here to it doesn't raise an error
        //bubble sort method! when swapping elements we need to swap them between the nodes using swapNodes
        while (temp1->next != temp2)
        {
            if (temp1->item > temp1->next->item)
            { 
                swapNodes(temp1, temp1->next);

                didSwap = 1;    //keep sorting
            }
            temp1 = temp1->next;
        }
        temp2 = temp1; 
    }

    while (didSwap == 1);
}

/* function to swap item of two nodes temp1 and temp2*/
void swapNodes(struct nodeStruct *temp1, struct nodeStruct *temp2)
{
    int temp = temp1->item; //assign temp1 to temp

    temp1->item = temp2->item;  //assign temp 2 to temp 1

    temp2->item = temp; //assign temp to temp2 to swap
}
