/* Singly Linked List
 * Functions definitions
*/

#include "dataio.h"


int slIndexOf(sl_node *head, int key) {
    int i = 0;

    while (head != NULL) {
        if (head->id == key)
            return i;
        i++;
        head = head->next;
    }

    return -1;
}

int slIsEmpty(sl_node *head) {
    if (head == NULL)
        return 1;

    return 0;
}

sl_node *slFind(sl_node *head, int key) {
    while (head != NULL) {
        if (head->id == key)
            return head;
        head = head->next;
    }

    return NULL;
}

sl_node *slFirst(sl_node *head) {
    return head;
}

sl_node *slInsert(sl_node *head, int new_id) {
    sl_node *elem = (sl_node *) malloc(sizeof(sl_node));

    if (elem == NULL) {
        if (E_MEM_EXCEPTION)
            exit(1);
        return head;
    }
    elem->id = new_id;
    elem->next = head;

    return elem;
}

// sl_node *slInsertAt(sl_node *head, int index, int new_id);

sl_node *slInsertLast(sl_node *head, int new_id) {
    sl_node *elem = (sl_node *) malloc(sizeof(sl_node)), *iter = head;

    if (elem == NULL) {
        if (E_MEM_EXCEPTION)
            exit(1);
        return head;
    }
    elem->id = new_id;
    elem->next = NULL;

    if (iter == NULL)
        return elem;
    while (iter->next != NULL)
        iter = iter->next;
    iter->next = elem;

    return head;
}

// sl_node *slInsertOrder(sl_node *head, int new_id);

sl_node *slLast(sl_node *head) {
    if (head == NULL)
        return NULL;
    while (head->next != NULL)
        head = head->next;

    return head;
}

// sl_node *slRemove(sl_node *head, int key);
// sl_node *slRemoveAt(sl_node *head, int index);
// sl_node *slSort(sl_node *head);

void slPrint(sl_node *head) {
    while (head != NULL) {
        printf("%d --> ", head->id);
        head = head->next;
    }
    printf("NULL\n");
}
