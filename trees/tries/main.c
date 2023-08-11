#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define N_alphabet 26

typedef struct node {
  struct node *children[N_alphabet];
  bool end;
} NODE;
typedef NODE* PONT;

PONT Trie_create_node() {
  PONT p = NULL;
  p = (PONT)calloc(1,sizeof(NODE));
  if (p) {
    p->end = false;
    int i;
    for (i=0;i<N_alphabet;i++) {
      p->children[i] = NULL;
    }
  }
  return p;
}

int indexMap(char c) {
  return((int) c - (int)'a');
}

void Tree_insert(PONT root,char *key) {
  int level;
  int compare = strlen(key);
  int i;

  PONT p = root;
  for(level = 0;level < compare;level++) {
    i = indexMap(key[level]);
    if(!p->children[i]) {
      p->children[i] = Trie_create_node();
    }
    p = p->children[i];
  }
}

bool Trie_search(PONT root,char *key) {
  int level;
  int compare = strlen(key);
  int i;
  PONT p = root;

  for(level = 0;level < compare;level++) {
    i = indexMap(key[level]);
    if(!p->children[i]) return false;
    p = p->children[i];
  }
  return p->end;
}

int main() {
  PONT root = Trie_create_node();

  return 0;
}
