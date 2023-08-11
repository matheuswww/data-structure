#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int KEYTYPE;
typedef struct tree {
  KEYTYPE key;
  struct tree *firstBorn;
  struct tree *brother;
} NODE;
typedef NODE* PONT;

PONT Tree_create_new_node(KEYTYPE key) {
  PONT new_node = (PONT) calloc(1,sizeof(NODE));
  new_node->firstBorn = NULL;
  new_node->brother = NULL;
  new_node->key = key;
  return new_node;
}

PONT Tree_searchKey(KEYTYPE key,PONT root) {
  if(root == NULL) return NULL;
  if(root->key == key) return root;
  PONT p = root->firstBorn;
  while(p) {
    PONT resp = Tree_searchKey(key,p);
    if(resp) return resp;
    p = p->brother;
  }
  return NULL;
}

bool Tree_insert(PONT root,KEYTYPE newKey,KEYTYPE parentKey) {
  PONT parent = Tree_searchKey(parentKey,root);
  if(!parent) return false;
  PONT children = Tree_create_new_node(newKey);
  PONT p = parent->firstBorn;
  if(!p) parent->firstBorn = children;
  else {
    while (p->brother) {
      p = p->brother;
    }
    p->brother = children;
  }
  return true;
}

void Tree_print(PONT root) {
  if(root == NULL) return;
  printf("%d(",root->key);
  PONT p = root->firstBorn;
  while(p) {
    Tree_print(p);
    p = p->brother;
  }
  printf(")");
}

int main() {
  PONT root = Tree_create_new_node(10);
  PONT node2 = Tree_create_new_node(6);
  PONT node3 = Tree_create_new_node(15);
  PONT node4 = Tree_create_new_node(3);
  PONT node5 = Tree_create_new_node(8);
  PONT node6 = Tree_create_new_node(12);
  PONT node7 = Tree_create_new_node(18);

  Tree_insert(root, node2->key, root->key);
  Tree_insert(root, node3->key, root->key);
  Tree_insert(root, node4->key, root->key);
  Tree_insert(root, node5->key, node2->key);
  Tree_insert(root, node6->key, node2->key);
  Tree_insert(root, node7->key, node3->key);

  Tree_print(root);
  puts("");

  return 0;
}
