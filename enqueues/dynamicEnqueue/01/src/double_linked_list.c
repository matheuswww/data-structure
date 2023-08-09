#include "double_linked_list.h"
#include<stdlib.h>
#include<stdio.h>
#include<stddef.h>

typedef struct _doubly_node {
  int val;
  struct _doubly_node *prev;
  struct _doubly_node *next;
} DoublyNode,Node;

typedef struct doubly_linked_list {
  DoublyNode *begin;
  DoublyNode *end;
  size_t size; 
} DoublyLinkedList,List;

Node *Node_create(int val) {
  Node* node = (Node *) calloc(1,sizeof(Node));
  node->prev = NULL;
  node->next = NULL;
  node->val = val;

  return node;
}

bool List_is_empty(const List *L) {
  return L->size == 0;
}

size_t List_size(const List *L) {
  return L->size;
}

void List_ERROR(char msg[]) {
  fprintf(stderr,"%s\n",msg);
  fprintf(stderr,"List is empty\n");
  exit(EXIT_FAILURE);
}

List *List_create() {
  List *L = (List*) calloc(1,sizeof(List));
  L->begin = NULL;
  L->end = NULL;
  L->size = 0;

  return L;
}

void List_destroy(List **L_ref) {
  List *L = *L_ref;
  Node *p = L->begin;
  Node *aux = NULL;
  while (p != NULL) {
    aux = p;
    p = p->next;
    free(aux);
  }
  free(L);
  *L_ref = NULL;
}

void List_add_first(List *L,int val) {
  Node *p = Node_create(val);
  if(List_is_empty(L)) {
    L->end = p; 
  } else {
    p->next = L->begin;
    L->begin->prev = p;
  }
  L->begin = p;
  L->size++;
}

void List_add_last(List *L,int val) {
  Node *p = Node_create(val);
  p->prev = L->end;

  if(List_is_empty(L)) {
    L->begin = p;
  } else {
    L->end->next = p;
  }
  L->end = p;
  L->size++;
}

void List_print(const List *L) {
  Node *p = L->begin;

  while(p != NULL) {
    printf("%d -> ",p->val);
    p = p->next;
  }
  puts("");
}

void List_inverted_print(const List *L) {
  if(List_is_empty(L)) {
    List_ERROR("LinkedList_print: ERROR list is empty");
  }
  Node *p = L->end;

  while(p != NULL) {
    printf("%d -> ",p->val);
    p = p->prev;
  }
  puts("");
}

void List_remove(List *L,int val) {
  if(!List_is_empty(L)) {
      Node *p = L->begin;
      if(L->begin->val == val) {
        L->begin = p->next;
        if(L->size == 1) {
          L->end = NULL;
        } else {
          L->begin->prev = NULL;
        }
        free(p);
        L->size--;
      } else {
        p = p->next;
        while (p != NULL) {
          if(p->val == val) {
            p->prev->next = p->next;
            if(L->end == p) {
              L->end = p->prev;
            } else {
              p->next->prev = p->prev;
            }
            free(p);
            p = NULL;
            L->size--;
          } else {
            p = p->next;
          }
      }
    }
  } 
}

void List_remove_first(List *L) {
  if(!List_is_empty(L)) {
    Node *p = L->begin;
    if(L->begin == L->end) {
      L->begin = NULL;
      L->end = NULL;
    } else {
      L->begin = L->begin->next;
      L->begin->prev = NULL;
    }
    free(p);
    L->size--;
  }
}

void List_remove_last(List *L,int val) {
  if(!List_is_empty(L)) {
    Node *p = L->end;
    if(L->begin == L->end) {
      L->begin = L->end = NULL;
    } else {
      L->end = L->end->prev;
      L->end->next = NULL;
    }
    free(p);
    L->size--;
  }
}

int List_get_last_val(const List *L) {
  if(List_is_empty(L)) {
    List_ERROR("List_get_last_val: ERRO list is empty");
  }
  return L->end->val;
}

int List_get_first_val(const List *L) {
  if(List_is_empty(L)) {
    List_ERROR("List_get_first_val: ERRO list is empty!");
  }
  return L->begin->val;
}