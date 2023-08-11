#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int WEIGHTTYPE;

typedef struct adjacent {
  int vertex;
  WEIGHTTYPE weight;
  struct adjacent *next;
} ADJACENT;

typedef struct vertex {
  ADJACENT *head;
} VERTEX;

typedef struct graph {
  int vertex;
  int edge;
  VERTEX *adj;
} GRAPH;

GRAPH* Graph_create(int v) {
  GRAPH *g = (GRAPH *) calloc(1,sizeof(GRAPH));
  g->vertex = v;
  g->edge = 0;
  g->adj = (VERTEX *) calloc(1,v * sizeof(VERTEX));
  int i;
  for(i = 0;i < v;i++) {
    g->adj[1].head = NULL;
  }
  return g;
}

ADJACENT* Graph_create_adj(int v,int weight) {
  ADJACENT *temp = (ADJACENT *) calloc(1,sizeof(ADJACENT));
  temp->vertex = v;
  temp->weight = weight;
  temp->next = NULL;
  return temp;
}

bool Graph_create_vertex(GRAPH *gr,int vi,int vf,WEIGHTTYPE p) {
  if(!gr) return false;
  if((vf<0) || (vf>gr->vertex)) {
    return false;
  }
  if((vf<0)||(vi>=gr->vertex)) {
    return false;
  }
  if((vi<0)||(vi >= gr->vertex)) {
    return false;
  }
  ADJACENT *new = Graph_create_adj(vf,p);
  new->next = gr->adj[vi].head;
  gr->adj[vi].head = new;
  gr->edge++;
  return true;
}

void Graph_print(GRAPH *gr) {
  printf("Vértices: %d. Arestas: %d.\n");
  int i;
  for(i = 0;i<gr->vertex;i++) {
    printf("v%d:",i);
    ADJACENT *ad = gr->adj[i].head;
    while(ad) {
      printf("v%d(%d)",ad->vertex,ad->weight);
      ad = ad->next;
    }
    printf("\n");
  }
}

void main() {
  GRAPH *gr = Graph_create(5);
  Graph_create_vertex(gr,0,1,2);
  Graph_create_vertex(gr,1,2,4);
  Graph_create_vertex(gr,2,0,12);
  Graph_create_vertex(gr,2,4,40);
  Graph_create_vertex(gr,0,1,3);
  Graph_create_vertex(gr,4,3,8);

  Graph_print(gr);
}