#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

typedef struct _node {
  int val;
  struct _node *next;
} Node;

typedef struct _linked_list {
  Node *begin;
  Node *end;
} LinkedList;

Node *Node_create(int val) {
  Node *node = (Node*) calloc(1,sizeof(Node));
  node->val = val;
  node->next = NULL;

  return node;
}

LinkedList *LinkedList_create() {
  LinkedList *L = (LinkedList *) calloc(1,sizeof(LinkedList));
  L->begin = NULL;
  L->end = NULL;

  return L;
}

void LinkedList_destroy(LinkedList **L_ref) {
  LinkedList *L = *L_ref;
  Node *p = L->begin;
  Node *aux = NULL;

  while(p != NULL) {
    aux = p;
    p = p->next;
    free(aux);
  }
  free(L);

  *L_ref = NULL;
}

//void LinkedList_add_first(LinkedList *L,int val) {
//  Node *p = Node_create(val);
//  p->next = L->begin;
//  L->begin = p;
//}

bool LinkedList_is_empty(const LinkedList *L) {
  return (L->begin == NULL && L->end == NULL);
}

void LinkedList_add_first(LinkedList *L,int val) {
  Node *p = Node_create(val);
  p->next = L->begin;

  if (LinkedList_is_empty(L))
  {
    L->end = p;
  }

  L->begin = p;

  printf("L->end: %d\n",L->end->val);
}

void LinkedList_print(const LinkedList *L) {
  Node *p = L->begin;

  printf("L -> ");

  while(p != NULL) {
    printf("%d -> ",p->val);
    p = p->next;
  }
  printf("NULL\n");
}

void LinkedList_add_last_slow(LinkedList *L,int val) {
  Node *q = Node_create(val);
  
  if(LinkedList_is_empty(L)) {
    L->begin = q;
  } else {
    Node *p = L->begin;

    while (p->next != NULL) {
      p = p->next; 
    }

    p->next = q;
  }
}

void LinkedList_add_last(LinkedList *L,int val) {
  Node *q = Node_create(val);
  
  if(LinkedList_is_empty(L)) {
    L->begin = L->end = q;
  } else {
    L->end->next = q;
    L->end = L->end->next;
  }
}

void LinkedList_remove_v1(LinkedList *L,int val) { 
  if (!LinkedList_is_empty(L)) {
    if(L->begin->val == val) {
      Node *pos = L->begin;
      if(L->begin == L->end) {
        L->end = NULL;
      }
      L->begin = L->begin->next;
      free(pos);
    } else {
      Node *prev = L->begin;
      Node *pos = L->begin->next; 

      while(pos != NULL && pos->val != val) {
        prev = prev->next;
        pos = pos->next;
      }

      if(pos != NULL) {
        prev->next = pos->next;
        if(pos->next == NULL) {
          L->end = prev;
        }
        free(pos);
      }
    }
  }
}

void LinkedList_remove(LinkedList *L,int val) { 
  if (!LinkedList_is_empty(L)) {
      Node *prev = L->begin;
      Node *pos = L->begin->next; 

      while(pos != NULL && pos->val != val) {
        prev = pos;
        pos = pos->next;
      }

      if(pos != NULL) {
        if(L->end == pos) {
          L->end = prev;
        }
        if(L->begin == pos) {
          L->begin = pos->next;
        } else {
          prev->next = pos->next;
        }
        free(pos);
    }
  }
}

void LinkedList_remove_all(LinkedList *L,int val) {
  if(!LinkedList_is_empty(L)) {
    Node *prev = L->begin;
    Node *pos = L->begin->next;

    while(pos != NULL) {
      if(pos->val == val) {
        prev->next = pos->next;
        free(pos);
        pos = prev->next;
      } else {
        prev = pos;
        pos = pos->next;
      }
    }
  }
}

