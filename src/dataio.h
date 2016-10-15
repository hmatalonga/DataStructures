#ifndef DATAIO_H
#define	DATAIO_H

// Errors handlers (ON = 1|OFF = 0)
#ifndef E_MEM_EXCEPTION
#define E_MEM_EXCEPTION 0
#endif

#include <stdlib.h>
#include <stdio.h>

/* Data Structures */

// Singly Linked List
typedef struct sl_node {
    int id;
    struct sl_node *next;
} sl_node;

// Doubly linked list
typedef struct dl_node {
    int id;
    struct dl_node *next, *prev;
} dl_node;

// Binary Tree
typedef struct btree_node {
    int id;
    struct btree_node *left, *right;
} btree_node;

/*
 * Functions declarations
 * Sorted alphabetically, each start with same
 * prefix name as the respective data structure
*/

// Singly Linked List
int slIndexOf(sl_node *head, int key);
int slIsEmpty(sl_node *head);
int slSize(sl_node *head);
sl_node *slFind(sl_node *head, int key);
sl_node *slFirst(sl_node *head);
sl_node *slInsert(sl_node *head, int new_id);
sl_node *slInsertAt(sl_node *head, int index, int new_id);
sl_node *slInsertLast(sl_node *head, int new_id);
sl_node *slInsertOrder(sl_node *head, int new_id);
sl_node *slLast(sl_node *head);
sl_node *slRemove(sl_node *head, int key);
sl_node *slRemoveAt(sl_node *head, int index);
sl_node *slSort(sl_node *head);
void slPrint(sl_node *head);

// Doubly linked list


#endif /* DATAIO_H */
