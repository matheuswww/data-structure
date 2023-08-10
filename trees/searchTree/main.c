#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int KEYTYPE;
typedef struct tree {
  KEYTYPE key;
  struct tree *left,*right;
} NODE;

typedef NODE* PONT;

PONT Tree_add(PONT root,PONT node) {
  if(root == NULL) return node;
  if(node->key < root->key) {
    root->left = Tree_add(root->left,node);
  } else {
    root->right = Tree_add(root->right,node);
  }
  return root;
}

PONT Node_create(int val) {
  PONT node = (PONT) calloc(1,sizeof(PONT));
  node->key = val;
  node->left = NULL;
  node->right = NULL;
  return node;
}

PONT Tree_search(KEYTYPE key,PONT root) {
  if(root == NULL) return NULL;
  if(root->key == key) return root;
  if(root->key > key) {
    return Tree_search(key,root->left);
  } else {
    return Tree_search(key,root->right);
  }
}

void Tree_print(PONT root) {
  if(root != NULL) {
    printf("%d",root->key);
    printf("(");
    Tree_print(root->left);
    Tree_print(root->right);
    printf(")");
  }
}

int nodeCount(PONT root) {
  if(!root) return 0;
  return(nodeCount(root->left)) + 1 + nodeCount(root->right);
}

int main() {
  PONT root = NULL;
  PONT node = Node_create(6);
  root = Tree_add(root,node);
  PONT node2 = Node_create(16);
  root = Tree_add(root,node2);

  Tree_print(root);
  printf("%d\n",nodeCount(root));

}