/*****************************************************/
 /* Author      : Abdelrhman Mosad                   */
 /* Version     : v01                                */
 /* date        : 11/8/2021                          */
/*****************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "STD_Types.h"
#include "LinkedList.h"

void main(void)
{
	
	u32 input;
	u32 newValue;
	u8  ExitFlag = 0;
	u32 pos ;
	
	/* While to ensure the app keep running till user choose to exit*/
	while (ExitFlag == 0)
	{
		/* Print the options */
		printf("To add node enter 1\n");
		printf("To print the linked list enter 2\n");
		printf("To insert at certain position 3\n");
		printf("To delete a node 4\n");
		printf("To exit press to 5\n");
		printf("Your Choice: ");
		scanf("%d",&input);
		
		switch (input)
		{
			case 1 : 
				printf("Please Enter Node Value: ");
			    scanf("%d",&newValue);
				AddNode(newValue);
				printf("Node Added Thank You \n\n\n");
				 break;
				 
			case 2 : 
				PrintLinkedList(); break;
				
			case 3 : 
				printf("Please Enter Node Value: ");
			    scanf("%d",&newValue);
				printf("Please Enter the position: ");
			    scanf("%d",&pos);
				insertNode(newValue , pos);
				break;
				
			case 4 :
				printf("Please Enter Node Value: ");
			    scanf("%d",&newValue);
				deleteNode(newValue);
				break ;
				
			case 5 : 
				printf("Thank You\nGood Bye"); ExitFlag = 1;
				break;
			
			/* Handle choise out of range */
			default:
				printf("Invalid Choice please try again\n"); 
				break;
		}
	}
}


