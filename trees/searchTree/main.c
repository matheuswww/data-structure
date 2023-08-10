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

void Tree_print(PONT root) {
  if(root->left != NULL) {
    printf("%d -> \n",root->left->key);
    Tree_print(root->left);
  }
  if(root ->right != NULL) {
    printf("%d -> \n",root->right->key);
    Tree_print(root->right);
  }
}

int main() {
  PONT root = NULL;
  PONT node = Node_create(6);
  root = Tree_add(root,node);
  printf("%d -> ",root->key);
  PONT node2 = Node_create(16);
  root = Tree_add(root,node2);

  Tree_print(root);
}