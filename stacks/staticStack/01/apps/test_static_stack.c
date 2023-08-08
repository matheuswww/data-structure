#include "static_stack.h"
#include <stdio.h>

int main() {
  StaticStack *S = StaticStack_create(5);
  int top_val;

  StaticStack_print(S);
  
  StaticStack_push(S,6);
  StaticStack_push(S,3);
  StaticStack_push(S,5);


  StaticStack_print(S);
  printf("%ld\n",StaticStack_peek(S));
  StaticStack_pop(S);
  StaticStack_print(S);

  return 0;
}