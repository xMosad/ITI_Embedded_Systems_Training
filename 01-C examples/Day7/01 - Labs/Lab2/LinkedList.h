/*****************************************************/
 /* Author      : Abdelrhman Mosad                   */
 /* Version     : v01                                */
 /* date        : 11/8/2021                          */
/*****************************************************/
#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

/* User defined data types */
struct Node_type{
    u32 value;
    struct Node_type *Next;
};
typedef struct Node_type node;


/* Prototype */
void AddNode(u32 val);
void PrintLinkedList(void);
void deleteNode(u32 val);
void insertNode(u32 val , u32 position );

#endif