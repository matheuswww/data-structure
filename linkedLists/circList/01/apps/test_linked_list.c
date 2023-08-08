#include "circ_list.h"
#include <stdio.h>

int main() {

  CircList *L = CircList_create();

  CircList_add_last(L,34);
  CircList_add_last(L,10);
  CircList_add_last(L,6);
  CircList_add_last(L,14);
  CircList_add_last(L,53);

  CircList_print(L);
  CircList_remove(L,34);
  CircList_remove(L,6);
  CircList_remove(L,53);
  CircList_inverted_print(L);
  CircList_destroy(&L);
  return 0;
}