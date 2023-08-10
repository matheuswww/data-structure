#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _node {
  float value;
  int column;
  struct _node* next;
} NODE;

typedef NODE* PONT;

typedef struct _matrice{
  PONT *A;
  int rows;
  int cols;
} MATRICE;

MATRICE* matriceInit(MATRICE* m,int lin,int col) {
  int i;
  m->rows = lin;
  m->cols = col;
  m->A = (PONT*) malloc(lin*sizeof(PONT));
  for(i=0;i<lin;i++) m->A[i] = NULL;
  return m;
}

bool assignMatrice(MATRICE* m,int row,int col,float val) {
  if(row<0 || row>=m->rows || col<0 || col>=m->cols) {
    return false;
  }
  PONT prev = NULL;
  PONT current = m->A[row];
  while(current != NULL && current->column<col) {
    prev = current;
    current = current->next;
  }
  if(current != NULL && current->column == col) {
    if(val == 0) {
      if(prev == NULL) m->A[row] = current->next;
      else prev->next = prev->next;
      free(current);
    } else {
      current->value = val;
    }
  } else {
    PONT new_node = (PONT) malloc(sizeof(NODE));
    new_node->column = col;
    new_node->value = val;
    new_node->next = current;
    if(prev == NULL) m->A[row] = new_node;
    else prev->next = new_node;
  }
  return true;
}

float matriceVal(MATRICE*m,int row,int col) {
  if(row<0 || row>=m->rows || col<0 || col>=m->cols) {
    return 0;
  }
  PONT current = m->A[row];
  while(current != NULL && current->column < col) {
    current = current->next;
  }
  if(current != NULL && current->column == col) {
    return current->value;
  }
  return 0;
}

void main() {
  MATRICE *matrice = (MATRICE*) calloc(1,sizeof(MATRICE));
  matriceInit(matrice,3,4);
  assignMatrice(matrice,1,1,10.0);
  printf("%f\n",matriceVal(matrice,1,1));
}