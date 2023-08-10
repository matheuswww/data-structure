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

int Tree_count(PONT root) {
  if(!root) return 0;
  return(Tree_count(root->left)) + 1 + Tree_count(root->right);
}

PONT Tree_search_node(PONT root,KEYTYPE key,PONT *parent) {
  PONT current = root;
  *parent = NULL;
  while(current) {
    if(current->key == key) return current;
    *parent = current;
    if(key < current->key) current = current->left;
    else current = current->right;
  }
  return NULL;
}

PONT Tree_delete(PONT root,KEYTYPE key) {
  PONT parent,no,p,q;
  no = Tree_search_node(root,key,&parent);
  if(no == NULL) return root;
  if(!no->left || !no->right) { 
    if(!no->left) q = no->right;
    else q = no->left;
  } else {
    p = no;
    q = no->left;
    while (q->right) {
      p = q;
      q = q->right;
   }
    if(p != no) {
      p->right = q->left;
      q->left = no->left;
    }
    q->right = no->right; 
  }
  if(!parent) {
    free(no);
    return q;
  }
  if(key < parent->key) parent->left = q;
  else parent->right = q;
  free(no);
  return root; 
}

int main() {
  PONT root = NULL;
  PONT node = Node_create(6);
  root = Tree_add(root,node);
  PONT node2 = Node_create(16);
  root = Tree_add(root,node2);

  Tree_delete(root,16);
  Tree_print(root);
  printf("\n%d\n",Tree_count(root)); 
}