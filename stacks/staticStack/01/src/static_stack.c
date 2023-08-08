#include "static_stack.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct _static_stack {
  int *data;
  long capacity;
  long top;
} StaticStack;

StaticStack *StaticStack_create(long capacity) {
  StaticStack *S = (StaticStack *) calloc(1,sizeof(StaticStack));
  S->capacity = capacity;
  S->top = -1;
  S->data = (int*) calloc(S->capacity,sizeof(int));
  return S;
}

void StaticStack_ERROR(char msg[]) {
  fprintf(stderr,"%s\n'",msg);
  exit(EXIT_FAILURE);
}

void StaticStack_destroy(StaticStack **S_ref) {
  StaticStack *S = *S_ref;

  free(S->data);
  free(S);

  *S_ref = NULL;
}

bool StaticStack_is_empty(const StaticStack *S) {
  return S->top == -1;
}

bool StaticStack_is_full(const StaticStack *S) {
  return S->top == (S->capacity - 1);
}

void StaticStack_push(StaticStack *S,int val) {
  if(StaticStack_is_full(S)) {
    StaticStack_ERROR("ERROR in StaticStack_push: list is full");
  }
  S->top++;
  S->data[S->top] = val;
}

long StaticStack_peek(const StaticStack *S) {
  if(StaticStack_is_empty(S)) {
    StaticStack_ERROR("ERROR in StaticStack_peek: list is empty");
  }
  return S->data[S->top];
}

long StaticStack_pop(StaticStack *S) {
  if(StaticStack_is_empty(S)) {
    StaticStack_ERROR("ERROR in StaticStack_pop: list is empty");
  }
  int val = S->data[S->top];
  S->top--;
  return val;
}

void StaticStack_print(const StaticStack *S) {
  printf("capacity: %ld\n",S->capacity);
  printf("top: %ld\n",S->top);

  for (long i = 0;i <= S->top;i++) {
    printf("%d, ",S->data[i]);
  }
  puts("");
}