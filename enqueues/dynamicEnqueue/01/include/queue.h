#ifndef STATIC_QUEUE_H
#define STATIC_QUEUE_H
#include <stdbool.h>

typedef struct _static_enqueue Queue;

Queue *Queue_create();
void Queue_destroy(Queue **q_ref);
bool Queue_is_empty(const Queue *Q);
bool Queue_size(const Queue *Q);
void Queue_enqueue(Queue *Q,int val);
int Queue_peek(const Queue *Q);
int Queue_dequeue(Queue *Q);
void Queue_print(const Queue *Q);

#endif