#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <stdbool.h>
#include<stddef.h>

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
size_t LinkedList_count_slow(const LinkedList *L);
size_t LinkedList_return_first_element(const LinkedList *L);
size_t LinkedList_return_last_element(const LinkedList *L);
size_t LinkedList_size(const LinkedList *L);
int LinkedList_get_val(const LinkedList *L,int index);
void LinkedList_selection_sort(LinkedList *L);
Node* LinkedList_return_pointer(LinkedList *L,int val);
void LinkedList_bubble_sort(LinkedList *L);
void LinkedList_insert_sort(LinkedList *L);
LinkedList* LinkedList_get_position(LinkedList *L,int init_pos,int end_pos);
void LinkedList_merge_sort(LinkedList *L,int start,int end);
void LinkedList_merge(LinkedList *L,int start,int middle,int end);
int LinkedList_partition(LinkedList *L,int start,int end);
void LinkedList_quick_sort(LinkedList *L,int init,int end);
#endif