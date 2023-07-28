#include "double_linked_list.h"
#include <stdio.h>

int main() {
  List *L  = List_create();

  List_add_first(L,7);
  List_add_first(L,4);
  List_add_first(L,2);
  List_add_first(L,10);

  List_print(L);

  List_remove(L,7);

  List_print(L);
  return 0;
}