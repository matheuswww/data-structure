#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "double_linked_list.h"

typedef struct _static_enqueue {
  List *data;
} Queue;

Queue *Queue_create() {
  Queue *Q = (Queue*) calloc(1,sizeof(Queue));
  Q->data = List_create();
  return Q;
}

void list_ERROR(char msg[]) {
  fprintf(stderr,"%s\n",msg);
  exit(EXIT_FAILURE);
}

void Queue_destroy(Queue **q_ref) {
  Queue *Q = *q_ref;
  List_destroy(&Q->data);
  free(Q);
  *q_ref = NULL;
}

bool Queue_is_empty(const Queue *Q) {
  return List_is_empty(Q->data);
}

long Queue_size(Queue *Q) {
  return List_size(Q->data);
}

void Queue_enqueue(Queue *Q,int val) {
  List_add_last(Q->data,val);
}

int Queue_peek(const Queue *Q) {
  if(Queue_is_empty(Q)) {
    list_ERROR("Queue_peek: ERROR list is empty");
  }
  return List_get_first_val(Q->data);
}

int Queue_dequeue(Queue *Q) {
  if(Queue_is_empty(Q)) {
    list_ERROR("Queue_dequeue: ERROR list is empty");
  }
  int val = List_get_first_val(Q->data);
  List_remove_first(Q->data);
  return val;
}

void Queue_print(const Queue *Q) {
  List_print(Q->data);
}