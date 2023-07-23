#include "linked_list.h"
#include <stdio.h>

int main() {
  LinkedList *L = LinkedList_create();
  
    //LinkedList_add_first(L,5);
    //LinkedList_print(L);
    //LinkedList_add_first(L,4);
    //LinkedList_print(L);
    //LinkedList_add_first(L,2);
    //LinkedList_print(L);
    //LinkedList_add_first(L,10);

    LinkedList_add_last(L,10);
    LinkedList_add_last(L,2);
    LinkedList_add_last(L,2);
    LinkedList_add_last(L,2);
    LinkedList_add_last(L,7);
    LinkedList_print(L);

    LinkedList_destroy(&L);
    printf("%d\n",L == NULL ? 1 : 0);
  return 0;
}