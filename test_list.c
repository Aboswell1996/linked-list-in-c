// Sample test routine for the list module.
#include <stdio.h>
#include "list.h"
#include <stdbool.h>
#include <string.h>
#include <assert.h>

/*
 * Main()
 */
int main(int argc, char** argv)
{
	printf("Starting tests...\n");

	//Alex's testing


	struct nodeStruct *alexhead = NULL;
	assert(List_countNodes(alexhead) == 0);

	struct nodeStruct* node1 = List_createNode(1);
	struct nodeStruct* node2 = List_createNode(2);
	struct nodeStruct* node3 = List_createNode(3);
	struct nodeStruct* node4 = List_createNode(4);
	struct nodeStruct* node5 = List_createNode(5);
	struct nodeStruct* node6 = List_createNode(6);
	//struct nodeStruct* node7 = List_createNode(7);

	printf("Testing InsertHead\n");

	printf("Inserting node with item 3 into the list\n");
	List_insertHead(&alexhead, node3);
	if ((List_countNodes(alexhead) == 1)&&(List_findNode(alexhead, 3) == node3))
	{
		printf("It worked!\n");
	}
	else{
		printf("Test Failed\n");
	}
	printf("Inserting node with item 2 into the list\n");
	List_insertHead(&alexhead, node2);
	if ((List_countNodes(alexhead) == 2)&&(List_findNode(alexhead, 2) == node2)){
		printf("It worked!\n");
	}
	else{
		printf("Test Failed\n");
	}
	printf("Inserting node with item 1 into the list\n");
	List_insertHead(&alexhead, node1);
	if ((List_countNodes(alexhead) == 3)&&(List_findNode(alexhead, 1) == node1)){
		printf("It worked!\n");
	}
	else{
		printf("Test Failed\n");
	}

	printf("Testing InsertTail\n");

	printf("Inserting node with item 4 into the list\n");
	List_insertTail(&alexhead, node4);
	if ((List_countNodes(alexhead) == 4)&&(List_findNode(alexhead, 4) == node4))
	{
		printf("It worked!\n");
	}
	else{
		printf("Test Failed\n");
	}
	printf("Inserting node with item 5 into the list\n");
	List_insertTail(&alexhead, node5);
	if ((List_countNodes(alexhead) == 5)&&(List_findNode(alexhead, 5) == node5))
	{
		printf("It worked!\n");
	}
	else{
		printf("Test Failed\n");
	}
	printf("Inserting node with item 6 into the list\n");
	List_insertTail(&alexhead, node6);
	if ((List_countNodes(alexhead) == 6)&&(List_findNode(alexhead, 6) == node6))
	{
		printf("It worked!\n");
	}
	else{
		printf("Test Failed\n");
	}
	printf("Testing Deletenode\n");
	printf("We currently have %d nodes\n", (List_countNodes(alexhead)));
	List_deleteNode(&alexhead, node1);
	if (List_countNodes(alexhead) == 5)
	{
		printf("It worked!\n");
	}
	else{
		printf("Test Failed\n");
	}
	printf("We currently have %d nodes\n", (List_countNodes(alexhead)));
	List_deleteNode(&alexhead, node2);
	if (List_countNodes(alexhead) == 4)
	{
		printf("It worked!\n");
	}
	else{
		printf("Test Failed\n");
	}
	printf("We currently have %d nodes\n", (List_countNodes(alexhead)));
	//List_deleteNode(&head, node3);
	List_deleteNode(&alexhead, node3);
	if (List_countNodes(alexhead) == 3)
	{
		printf("It worked!\n");
	}
	else{
		printf("Test Failed\n");
	}
	printf("We currently have %d nodes\n", (List_countNodes(alexhead)));
	List_deleteNode(&alexhead, node4);
	if (List_countNodes(alexhead) == 2)
	{
		printf("It worked!\n");
	}
	else{
		printf("Test Failed\n");
	}
	printf("We currently have %d nodes\n", (List_countNodes(alexhead)));
	List_deleteNode(&alexhead, node5);
	if (List_countNodes(alexhead) == 1)
	{
		printf("It worked!\n");
	}
	else{
		printf("Test Failed\n");
	}
	printf("We currently have %d nodes\n", (List_countNodes(alexhead)));
	List_deleteNode(&alexhead, node6);
	if (List_countNodes(alexhead) == 0)
	{
		printf("It worked!\n");
	}
	else{
		printf("Test Failed\n");
	}
	printf("We currently have %d nodes\n", (List_countNodes(alexhead)));
	//end of Alex's testing

	struct nodeStruct *head = NULL;

	// Starting count:
	assert(List_countNodes(head) == 0);

	// Create 1 node:
	struct nodeStruct* firstNode = List_createNode(0);
    
	List_insertHead(&head, firstNode);
     
	assert(List_countNodes(head) == 1);

    printf("%d\n",List_countNodes(head));
     
	assert(List_findNode(head, 0) == firstNode);
	assert(List_findNode(head, 1) == NULL);

	// Insert tail:
	struct nodeStruct* lastNode = List_createNode(-5);
     
	List_insertTail(&head, lastNode);
 
	assert(List_countNodes(head) == 2);
    
	assert(List_findNode(head, 0) == firstNode);    //
       
	assert(List_findNode(head, -5) == lastNode);
	assert(List_findNode(head, 1) == NULL);
    
	// Verify list:
	struct nodeStruct *current = head;
	assert(current->item == 0);
	assert(current->next != NULL);
	current = current->next;
	assert(current->item == -5);
	assert(current->next == NULL);

	// Sort and verify:
	List_sort(&head);
	current = head;
	assert(current->item == -5);
	assert(current->next != NULL);
	current = current->next;
	assert(current->item == 0);
	assert(current->next == NULL);

	// Delete
	assert(List_countNodes(head) == 2);
	struct nodeStruct *nodeOf0 = List_findNode(head, 0);
	List_deleteNode(&head, nodeOf0);
	assert(List_countNodes(head) == 1);
	assert(List_findNode(head, 0) == NULL);
	assert(List_findNode(head, 1) == NULL);
	current = head;
	assert(current->item == -5);
	assert(current->next == NULL);

    struct nodeStruct *nodeOfm5 = List_findNode(head, -5);
    List_deleteNode(&head, nodeOfm5);

	printf("\nExecution finished.\n");



	return 0;
}

