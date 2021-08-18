/*****************************************************/
 /* Author      : Abdelrhman Mosad                   */
 /* Version     : v01                                */
 /* date        : 11/8/2021                          */
/*****************************************************/
#include "STD_Types.h"
#include "LinkedList.h"
#include <stdlib.h>
#include <stdio.h>
node *head  ;
u32 ListLength = 0;

void AddNode(u32 val)
{
	/* First Node to Create */
	if (ListLength == 0)
	{
		/* 1 - Allocate the node */
		node *new = (node*) malloc(sizeof(node));
		head = new ;
		
		/* 2 - Assign the received value to the new node */
		head -> value = val;
		head->Next  = NULL; 
	}
	
	
	/* Other nodes to Create */
	else
	{
		node *last;
		
		/*1- Allocate the node */
		node *new = (node*) malloc(sizeof(node));
		
		/*2- Assign the received value to the new node */
		new -> value = val;
		/* Make the new node next pointer to Null, as it will 
		be added to the end of the list */
		new -> Next  = NULL;
		
		last = head;
		
		/* Search for the last node */
		while( (last -> Next) != NULL )
		{
			last = (last -> Next);
		}
		
		/* Make the last node point at the new node */
		last -> Next = new;
	}
	
	/* Increase the list length by one node */
	ListLength++;
	
	return;
}

void PrintLinkedList(void)
{
	printf("\n\n----------------------\n");
	/* at lease 1 node is created */
	if (ListLength > 0)
	{
		node *Last = head;
		u32 i = 1;
		
		/* Print the list head */
		printf("Node Number %d = %d\n", i,Last -> value);
	
		/* Print all nodes util you find the last node
		which has the next pointer equals to NULL  */
		while ((Last -> Next) != NULL)
		{
			i++;
			Last = Last -> Next;
			printf("Node Number %d = %d\n", i,Last -> value);
		}
	}
	
	else
	{
		printf("List is Empty\n");
	}
	
	printf("----------------------\n\n\n");
}


void deleteNode(u32 val)
{
	node *first = head;
	node *last = first->Next ;

	while (last->Next != NULL)
	{
		/* Check if last hold the value to be deleted */
		if (last->value == val)
		{
			/* make pervios node point at the node after the node you need to delete*/
			first->Next = last->Next ; 
			/* Free the wanted node */
			free(last);
			/* Move last to the next node */
			last = first->Next;
			/* Decremnt list length */
			ListLength--;
		}
		else
		{
			/* To move throug the list to the next elemnt */
			first = first->Next ;
			last = last->Next;
		}
	}
	
	/* Corner case 1 the head */
	if (head -> value == val)
	{
		/* Hold the node after the head by temp*/
		node *temp = head -> Next;
		free(head);
		/* update the head to the second node */
		head = temp;
		/* Decremnt list length */
		ListLength--;
	}
	
	/* Corner case 2 the tail */
	if (last -> value == val)
	{
		free(last);
		first -> Next = NULL ;
		/* Decremnt list length */
		ListLength--;
	}
}

void insertNode(u32 val , u32 position )
{
	node *after = head;
	node *before;
	/* Insert at first position */
	if (position == 1)
	{
		/* Allocate the node */
		node *new = (node*) malloc(sizeof(node));
		/* Assign the received value to the new node */
		new -> value = val;
		new -> Next = head ;
		/* Update the head */
		head = new;
		ListLength++;
	}
	
	/* Insert in other positions */
	else if (position <= ListLength)
	{
		for (int i = 1; i < position ; i++)
		{
			before = after ;
			after = after -> Next ;
		}
		/* Allocate the node */
		node *new = (node*) malloc(sizeof(node));
		/* Assign the received value to the new node */
		new -> value = val;
		new -> Next = after ;
		before->Next = new ;
		ListLength++;		
	}
	else
	{
		printf ("\n Wrong position !!!!!\n");
	}
	
}