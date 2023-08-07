#include "self_organized_linkedList.h"
#include <stdio.h>

void main() {
  char name1[100] = "lapis";
  char name2[100] = "estojo";
  char name3[100] = "borracha";
  char name4[100] = "caneta";
  char name5[100] = "caneta 4 cores";
  char name6[100] = "apontador";
  char name7[100] = "caderno";
  char name8[100] = "lapis de cor";
  char name9[100] = "lapisera";
  char name10[100] = "mochila";
  char name11[100] = "calculadora";

  List *L = List_create();

  Node *node1 = Node_create(name1,2.50,1);
  Node *node2 = Node_create(name2,10.50,2);
  Node *node3 = Node_create(name3,1.80,3);
  Node *node4 = Node_create(name4,5.60,4);
  Node *node5 = Node_create(name5,8.90,5);
  Node *node6 = Node_create(name6,6.00,6);
  Node *node7 = Node_create(name7,17.40,7);
  Node *node8 = Node_create(name8,7.80,8);
  Node *node9 = Node_create(name9,10.60,9);
  Node *node10 = Node_create(name10,49.99,10);
  Node *node11 = Node_create(name11,17.50,11);

  List_insert_last(L,node1);
  List_insert_last(L,node2);
  List_insert_last(L,node3);
  List_insert_last(L,node4);
  List_insert_last(L,node5);
  List_insert_last(L,node6);
  List_insert_last(L,node7);
  List_insert_last(L,node8);
  List_insert_last(L,node9);
  List_insert_last(L,node10);
  List_insert_last(L,node11);

  List_print(L);
  List_search(L,1);
  List_search(L,4);
  List_search(L,1);
  List_print(L);
}