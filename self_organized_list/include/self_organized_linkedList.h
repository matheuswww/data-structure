#ifndef SELF_ORGANIZED_LINKEDLIST_H
#define SELF_ORGANIZED_LINKEDLIST_H
#include <stdbool.h>


typedef struct _node Node;
typedef struct _array Array;
typedef struct _self_organized_list List;

Node* Node_create(char name[100],float price,int serial_number);
List* List_create();
void List_insert_last(List *L,Node *node);
void List_insert_first(List *L,Node *node);
void List_print_cost(List *L);
void List_print_nodes(List *L);
void List_print(List *L);
Node* List_search(List *L,int serial_number);


#endif