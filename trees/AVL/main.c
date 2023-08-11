#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int KEYTYPE;

typedef struct tree {
  KEYTYPE key;
  struct tree *left;
  struct tree *right;
  int h;
} NODE;

typedef NODE* PONT;

PONT Tree_create_node(KEYTYPE key) {
  PONT new_node = (PONT)malloc(sizeof(NODE));
  new_node->key = key;
  new_node->left = NULL;
  new_node->right = NULL;
  new_node->h = 1;  // Initialize height to 1 for a single node
  return new_node;
}

int Tree_max(int a, int b) {
  return (a > b) ? a : b;
}

int Tree_height(PONT root) {
  if (!root) return 0;  // Return 0 for an empty subtree
  return root->h;
}

PONT Tree_right(PONT r) {
  PONT aux = r->left;
  r->left = aux->right;
  aux->right = r;

  r->h = Tree_max(Tree_height(r->right), Tree_height(r->left)) + 1;
  aux->h = Tree_max(Tree_height(aux->left), r->h) + 1;
  return aux;
}

PONT Tree_left(PONT r) {
  PONT aux = r->right;
  r->right = aux->left;
  aux->left = r;

  r->h = Tree_max(Tree_height(r->right), Tree_height(r->left)) + 1;
  aux->h = Tree_max(Tree_height(aux->right), r->h) + 1;
  return aux;
}

PONT Tree_leftRight(PONT r) {
  r->left = Tree_left(r->left);
  return Tree_right(r);
}

PONT Tree_rightLeft(PONT r) {
  r->right = Tree_right(r->right);
  return Tree_left(r);
}

PONT Tree_insert(PONT root, KEYTYPE key) {
  if (!root) return Tree_create_node(key);

  if (key < root->key) {
    root->left = Tree_insert(root->left, key);
    if (Tree_height(root->left) - Tree_height(root->right) == 2) {
      if (key < root->left->key)
        root = Tree_right(root);
      else
        root = Tree_leftRight(root);
    }
  } else if (key > root->key) {
    root->right = Tree_insert(root->right, key);
    if (Tree_height(root->right) - Tree_height(root->left) == 2) {
      if (key > root->right->key)
        root = Tree_left(root);
      else
        root = Tree_rightLeft(root);
    }
  }
  root->h = Tree_max(Tree_height(root->left), Tree_height(root->right)) + 1;
  return root;
}

void Tree_print(PONT root) {
  if (root != NULL) {
    printf("%d(", root->key);
    Tree_print(root->left);
    printf(",");
    Tree_print(root->right);
    printf(")");
  } else {
    printf("()");
  }
}

int main() {
  PONT r = NULL;

  // Inserindo elementos na árvore
  r = Tree_insert(r, 10);
  r = Tree_insert(r, 5);
  r = Tree_insert(r, 15);
  r = Tree_insert(r, 3);
  r = Tree_insert(r, 7);
  r = Tree_insert(r, 12);
  r = Tree_insert(r, 18);

  // Imprimindo os valores da árvore em ordem
  printf("Valores da árvore em ordem: ");
  Tree_print(r);
  printf("\n");

  return 0;
}
