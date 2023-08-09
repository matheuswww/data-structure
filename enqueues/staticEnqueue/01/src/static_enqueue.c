#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _static_enqueue {
  int *data;
  long capacity;
  long size;
  long begin;
  long end;
} StaticQueue;


StaticQueue *StaticQueue_create(long capacity) {
  StaticQueue *Q = (StaticQueue*) calloc(1,sizeof(StaticQueue));
  Q->data = (int*) calloc(capacity,sizeof(int));
  Q->capacity = capacity;
  Q->size = 0;
  Q->begin = 0;
  Q->end = 0;
  return Q;
}

void list_ERROR(char msg[]) {
  fprintf(stderr,"%s\n",msg);
  exit(EXIT_FAILURE);
}

void StaticQueue_destroy(StaticQueue **q_ref) {
  StaticQueue *Q = *q_ref;
  free(Q->data);
  free(Q);

  *q_ref = NULL;
}

bool StaticQueue_is_empty(const StaticQueue *Q) {
  return Q->size == 0;
}

bool StaticQueue_is_full(const StaticQueue *Q) {
  return Q->size == Q->capacity;
}

long StaticQueue_size(const StaticQueue *Q) {
  return Q->size;
}

void StaticQueue_enqueue(StaticQueue *Q,int val) {
  if(StaticQueue_is_full(Q)) {
    list_ERROR("Static_enqueue: ERROR List is FULL!");
  }

  Q->data[Q->end] = val;
  Q->end = (Q->end + 1) % Q->capacity;
  Q->size++;
}

int StaticQueue_peek(const StaticQueue *Q) {
  if(StaticQueue_is_empty(Q)) {
    list_ERROR("StaticQueue_peek: ERROR List is empty!");
  }
  return Q->data[Q->begin];
}

int StaticQueue_dequeue(StaticQueue *Q) {
  if(StaticQueue_is_empty(Q)) {
    list_ERROR("Static_dequeue: ERROR list is empty!");
  }
  int val = Q->data[Q->begin];
  Q->begin = (Q->begin + 1) % Q->capacity;
  Q->size--;
  return val;
}

void StaticQueue_print(const StaticQueue *Q) {
  printf("capacity: %ld\n",Q->capacity);
  printf("size: %ld\n",Q->size);
  printf("begin: %ld\n",Q->begin);
  printf("end: %ld\n\n",Q->end);

  long s,i;

  for(s = 0,i = Q->begin;s < Q->size;s++,i = (i + 1) % Q->capacity) {
    printf("%d, ",Q->data[i]);
  }
  puts("");
}