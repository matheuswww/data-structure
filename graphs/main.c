#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define WHITE 0
#define YELLOW 1
#define RED 2

typedef int KEYTYPE;

typedef struct _register {
  KEYTYPE key;
} REGISTER;

typedef struct aux {
  REGISTER reg;
  struct aux* next;
} ELEMENT, *PONT;

typedef struct _queue {
  PONT init;
  PONT end;
} QUEUE;

void Queue_init(QUEUE *f) {
  f->init = NULL;
  f->end = NULL;
}

bool Queue_insert(QUEUE *f, REGISTER reg) {
  PONT new = (PONT)calloc(1, sizeof(ELEMENT));
  new->reg = reg;
  new->next = NULL;
  if (f->init == NULL)
    f->init = new;
  else
    f->end->next = new;
  f->end = new;
  return true;
}

bool Queue_delete(QUEUE* f, REGISTER* reg) {
  if (f->init == NULL)
    return false;
  PONT delete = f->init;
  f->init = f->init->next;
  free(delete);
  if (f->init == NULL)
    f->end = NULL;
  return true;
}

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

void visitP(GRAPH *g,int u,int *color) {
  color[u] = YELLOW;
  ADJACENT *v = g->adj[u].head;
  while(v) {
    if(color[v->vertex] == WHITE) {
      visitP(g,v->vertex,color);
    }
    v = v->next;
  }
  color[u] = RED;
}

void Graph_depth(GRAPH *g) {
  int color[g->vertex];

  int u;
  for(u = 0;u<g->vertex;u++) {
    color[u] = WHITE;
  }
  for(u = 0;u<g->vertex;u++) {
    if(color[u] == WHITE) {
      visitP(g,u,color);
    }
  }
}

void visitL(GRAPH *g,int s,bool *expl) {
  QUEUE f;
  Queue_init(&f);
  expl[s] = true;
  REGISTER *u = (REGISTER*) calloc(1,sizeof(REGISTER));
  u->key = s;
  Queue_insert(&f,*u);
  while(f.init) {
    Queue_delete(&f,u);
    ADJACENT *v = g->adj[u->key].head;
    while(v) {
      if(!expl[v->vertex]) {
        expl[v->vertex] = true;
        u->key = v->vertex;
        Queue_insert(&f,*u);
      }
      v = v->next;
    }
  }
  free(u);
}

void Graph_width(GRAPH *g) {
  bool expl[g->vertex];
  int u;
  for(u = 0;u<g->vertex;u++) {
    expl[u] = false;
  }
  for(u = 0;u<g->vertex;u++) {
    if(!expl[u]) {
      visitL(g,u,expl);
    }
  }
}





















void Graph_init(GRAPH *g,int *d,int *p,int s) {
  int v;
  for(v=0;v<g->vertex;v++) {
    d[v] = INT_MAX/2;
    p[v] = -1;
  }
  d[s] = 0;
}

void Graph_relax(GRAPH *g,int *d,int *p,int u,int v) {
  ADJACENT *ad = g->adj[u].head;
  while(ad && ad->vertex != v) {
    ad = ad->next;
  }
  if(ad) {
    if(d[v] > d[u] + ad->weight) {
      d[v] = d[u] + ad->weight;
      p[v] = u;
    }
  }
}

bool Graph_exist_open(GRAPH *g, bool *open) {
  for (int i = 0; i < g->vertex; i++) {
    if (open[i]) {
      return true;
    }
  }
  return false;
}

int Graph_less_dist(GRAPH *g,bool *open,int *d) {
  int i;
  for(i = 0;i<g->vertex;i++) {
    if(open[i]) break;
  }
  if(i==g->vertex) return (-1);
  int less = i;
  for(i = less+1;i<g->vertex;i++) {
    if(open[i] && (d[less]>d[i])) {
      less = i;
    }
  }
  return less;
}

int* Graph_dijkstra(GRAPH *g, int s) {
  int *d = (int *) calloc(1,g->vertex * sizeof(int));
  int p[g->vertex];
  bool open[g->vertex];
  Graph_init(g, d, p, s);
  for (int i = 0; i < g->vertex; i++) {
    open[i] = true;
  }
  while (Graph_exist_open(g, open)) {
    int u = Graph_less_dist(g, open, d);
    open[u] = false;

    ADJACENT *ad = g->adj[u].head;
    while (ad) {
      Graph_relax(g, d, p, u, ad->vertex);
      ad = ad->next;
    }
  }
  return d;
}
void main() {
  GRAPH *gr = Graph_create(5);
  Graph_create_vertex(gr,0,1,2);
  Graph_create_vertex(gr,1,2,4);
  Graph_create_vertex(gr,2,0,12);
  Graph_create_vertex(gr,2,4,40);
  Graph_create_vertex(gr,0,1,3);
  Graph_create_vertex(gr,4,3,8);


  int *r = Graph_dijkstra(gr,0);

  int i;
  for(i = 0;i<gr->vertex;i++) {
    printf("D(v0=>v%d) = %d\n",i,r[i]);
  }

}