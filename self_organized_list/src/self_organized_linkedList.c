#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct _node {
  struct _node *next;
  struct _node *prev;

  char name[100];
  float price;
  int serial_number;
  int cost;
} Node;

typedef struct _self_organized_list {
  Node *begin;
  Node *end;

  int total_cost;
  int size;
} List;

void list_ERROR(char msg[]) {
  fprintf(stderr,"%s\n",msg);
  fprintf(stderr,"List is empty\n");
  exit(EXIT_FAILURE);
}

bool list_is_empty(List *L) {
  return L->begin == NULL;
}

void List_print_cost(List *L) {
  Node *aux = L->begin;
  printf("Custo: ");
  while (aux != NULL) {
    if(aux->next == NULL) {
      printf("%d",aux->cost);
    } else {
      printf("%d + ",aux->cost);
    }
    aux = aux->next;
  }
  free(aux);
  aux = NULL;
}

void List_print_nodes(List *L) {
  if(list_is_empty(L)) {
    printf("List_print: ERROR List is empty!\n");
    return;
  }
  int cost = 0;
  Node *aux = L->begin;
  while (aux != NULL) {
    printf("%d,%s,%.2f\n",aux->cost,aux->name,aux->price);
    cost += aux->cost;
    aux = aux->next;
  }
  List_print_cost(L);
  printf("\nCusto total: %d",L->total_cost);
  puts("");
  free(aux);
  aux = NULL;
}

void List_print(List *L) {
  if (list_is_empty(L)) {
    printf("List_print: ERROR List is empty!\n");
    return;
  }
  Node *aux = L->begin;
  int cost = 0;
  while (aux != NULL) {
    if(aux->serial_number == L->begin->serial_number) {
      printf("serial number -> %d,NEXT -> %d,PREV -> NULL,COUNT -> %d\n",aux->serial_number,aux->next->serial_number,aux->cost);
    } else if(aux->serial_number == L->end->serial_number) {
      printf("serial number -> %d,NEXT -> NULL,PREV -> %d,COUNT -> %d\n",aux->serial_number,aux->prev->serial_number,aux->cost);
    } else {
      printf("serial number -> %d,NEXT -> %d,PREV -> %d,COUNT -> %d\n",aux->serial_number,aux->next->serial_number,aux->prev->serial_number,aux->cost);
    }
    cost += aux->cost;
    aux = aux->next;
  }
    List_print_cost(L);
  printf("\nCusto total: %d",cost);
  puts("");
  free(aux);
  aux = NULL;
}


List* List_create() {
  List *list = (List*) malloc(sizeof(List));
  list->begin = NULL;
  list->end = NULL;
  list->total_cost = 0;
  return list;
}

Node* Node_create(char name[100],float price,int serial_number) {
  if(price < 1 || serial_number < 1) {
    list_ERROR("Node_create: ERROR invalid argument!\n");
  }
  Node *node = (Node*) malloc(sizeof(Node));

  node->next = NULL;
  node->prev = NULL;

  node->cost = 0;
  strcpy(node->name,name);
  node->price = price;
  node->serial_number = serial_number;
  return node;
}

void List_insert_first(List *L, Node *node) {
  node->prev = NULL;
  node->next = L->begin;
  if (list_is_empty(L)) {
    L->end = node;
  } else {
    L->begin->prev = node;
  }
  L->begin = node;
  L->size++;
}

void List_insert_last(List *L,Node *node) {
  node->prev = L->end;
  node->next = NULL;
  if(list_is_empty(L)) {
    L->begin = node;
  } else {
    L->end->next = node;
  }
  L->end = node;
  L->size++;
}

void list_change_position(List* L, Node* node) {
  Node *list = node->prev;

  while (list != NULL && list->cost < node->cost) {
    list = list->prev;
  }

  if(node->prev != NULL) {
    node->prev->next = node->next;
  } else {
    L->begin = node->next;
  }

  if(node->next != NULL) {
    node->next->prev = node->prev;
  } else {
    L->end = node->prev;
  }

  node->next = (list != NULL) ? list->next : L->begin;
  node->prev = list;

  if(node->next != NULL) {
    node->next->prev = node;
  } else {
    L->end = node;
  }

  if(node->prev != NULL) {
    node->prev->next = node;
  } else {
    L->begin = node;
  }
}

Node* List_search(List *L,int serial_number) {
  if(list_is_empty(L)) {
    list_ERROR("List_search: ERROR list is empty!");
  }
  int count = 1;
  Node *node = L->begin;
  while (node->serial_number != serial_number && node != NULL) {
    node = node->next;
    count += 1;
  }
  if(node == NULL) {
    list_ERROR("List_search: ERROR serial number not found!");
  }
  node->cost += count;
  L->total_cost += count;
  list_change_position(L,node);
  return node;
}