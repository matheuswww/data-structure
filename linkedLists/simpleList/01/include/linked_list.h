#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <stdbool.h>

typedef struct _node Node;
typedef struct _linked_list LinkedList;

Node *Node_create(int val);

LinkedList *LinkedList_create();
void LinkedList_destroy(LinkedList **L_ref);
bool LinkedList_is_empty(const LinkedList *L);
void LinkedList_add_first(LinkedList *L,int val);
void LinkedList_add_last_slow(LinkedList *L,int val);
void LinkedList_add_last(LinkedList *L,int val);
void LinkedList_print(LinkedList *L);
void LinkedList_remove_v1(LinkedList *L,int val);
void LinkedList_remove(LinkedList *L,int val);
void LinkedList_remove_all(LinkedList *L,int val);

#endif