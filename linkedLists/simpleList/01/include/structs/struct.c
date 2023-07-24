typedef struct _node {
  int val;
  struct _node *next;
} Node;

typedef struct _linked_list {
  Node *begin;
  Node *end;
  size_t size; 
} LinkedList;
