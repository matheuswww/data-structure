#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include<stddef.h>

typedef struct _node {
  int val;
  struct _node *next;
} Node;

typedef struct _linked_list {
  Node *begin;
  Node *end;
  size_t size; 
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
  L->size = 0;

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
  return (L->size == 0);
}

void LinkedList_ERROR(char msg[]) {
  fprintf(stderr,"%s\n",msg);
  fprintf(stderr,"List is empty\n");
  exit(EXIT_FAILURE);
}

void LinkedList_add_first(LinkedList *L,int val) {
  Node *p = Node_create(val);
  p->next = L->begin;

  if (LinkedList_is_empty(L))
  {
    L->end = p;
  }

  L->begin = p;
  L->size++;

  printf("L->end: %d\n",L->end->val);
}

void LinkedList_print(const LinkedList *L) {
  Node *p = L->begin;

  while(p != NULL) {
    printf("%d -> ",p->val);
    p = p->next;
  }
  puts("");
}

void LinkedList_add_last_slow(LinkedList *L,int val) {
  Node *q = Node_create(val);
  if(LinkedList_is_empty(L)) {
    L->begin = q;
    L->size++;
  } else {
    Node *p = L->begin;

    while (p->next != NULL) {
      p = p->next; 
    }

    p->next = q;
  }
  L->size++;
}

void LinkedList_add_last(LinkedList *L,int val) {
  Node *q = Node_create(val);
  
  if(LinkedList_is_empty(L)) {
    L->begin = L->end = q;
  } else {
    L->end->next = q;
    L->end = L->end->next;
  }
  L->size++;
}

Node* LinkedList_return_pointer(LinkedList *L,int pos) {
  if(LinkedList_is_empty(L)) {
    LinkedList_ERROR("Error in 'LinkedList_return_pointer'");
  } else {
    Node* p = L->begin;
    for (int i = 1; i <= L->size; i++) {
     if(i == pos) {
        return p;
      }
      p = p->next;
    }
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
      L->size --;
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
        L->size --;
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
        L->size --;
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

size_t LinkedList_count_slow(const LinkedList *L) {
  Node *node = L->begin->next;
  int count = 1;

  while (node != NULL)
  {
    count++;
    node = node->next;
  }
  return count;
}

size_t LinkedList_return_first_element(const LinkedList *L) {
  if(!LinkedList_is_empty(L)) {
    LinkedList_ERROR("ERROR in 'LinkedList_return_first_element list is empty'"); 
  } else {
    return L->begin->val;
  }
  return -1;
}

size_t LinkedList_return_last_element(const LinkedList *L) {
  if(LinkedList_is_empty(L)) {
    LinkedList_ERROR("ERROR in 'LinkedList_return_last_element list is empty'");
  } else {
    return L->end->val; 
  }
  return -1;
}

size_t LinkedList_size(const LinkedList *L) {
  return L->size;
}

int LinkedList_get_val(const LinkedList *L,int index) {
  if(LinkedList_is_empty(L)) {
    LinkedList_ERROR("Error in 'LinkedList_get_val' list is empty");
  } else if(index < 0 || index >= L->size) {
    LinkedList_ERROR("Error in 'LinkedList_get_val index not valid'");
  } else {
    int i = 0;
    Node *p = L->begin;

    while(i != index) {
      p = p->next;
      i++;
    }

    return p->val;
  }
}

void LinkedList_selection_sort(LinkedList *L) {
  int min_value = 0;
  Node* current_min_value_pos = 0;
  Node* j_pos = 0;

  for (int j = 1; j <= L->size - 1; j++) {
    min_value = j;
    j_pos = LinkedList_return_pointer(L,min_value);
    for (int i = j + 1; i <= L->size - 1; i++) {
      if(LinkedList_return_pointer(L,i)->val < LinkedList_return_pointer(L,min_value)->val) {
        current_min_value_pos = LinkedList_return_pointer(L,i);
        min_value = i;
      };
    }
    if(j_pos->val > current_min_value_pos->val) {
        int aux = j_pos->val;
        j_pos->val = current_min_value_pos->val;
        current_min_value_pos->val = aux;
    }
  }
}

void LinkedList_bubble_sort(LinkedList *L) {
  int aux = 0;
  Node* current_pos = 0;
  Node* next_pos = 0;

  for (int j = 1; j < L->size; j++)
  {
    for (int i = 1; i < L->size; i++)
    {
      current_pos = LinkedList_return_pointer(L,i);
      next_pos = LinkedList_return_pointer(L,i + 1);
      if(current_pos->val > next_pos->val) {
        aux = current_pos->val;
        current_pos->val = next_pos->val;
        next_pos->val = aux;
      }
    }
  }
}