#include <stdlib.h>
#include <stdio.h>

void scalar_vector_sum(int v[],int n,int escalar) {
  for (int i = 0; i < n; i++)
  {
    v[i] += escalar;
  }
}

void print_vetor(const int *v,int n) {
  for (int i = 0; i < n; i++)
  {
    printf("&v[%d] = %p,v[%d] = %d\n",i,&v[i],i,v[i]);
  }
}

void deallocate_vector(int **v) {
  free(*v);
  *v = NULL;
}

int main() {
  int vs[5] = {0,10,20,50,48};
  puts("### VETOR ESTATICO");
  print_vetor(vs,5);
  scalar_vector_sum(vs,5,9);

  puts("### VETOR DINAMICO");
  int *vh = (int *)calloc(5,sizeof(int));

  for (int i = 0; i < 5; i++)
  {
    vh[i] = i * 100;
  }

  scalar_vector_sum(vh,5,9);
  print_vetor(vh,5);

  free(&vh);
  vh = NULL;

  return 0;
}