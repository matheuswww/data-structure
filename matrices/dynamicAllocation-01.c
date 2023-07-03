#include <stdio.h>
#include <stdlib.h>

int main() {
  int nrows = 2;
  int ncols = 3;

  int **m = (int **) calloc(nrows,sizeof(int *));

  for (int i = 0; i < nrows; i++)
  {
    m[i] = (int*) calloc(ncols,sizeof(int));
  }

  printf("&m = %p,m = %p\n\n",&m,m);

  int count = 0;

  for (int i = 0; i < nrows; i++)
  {
    printf("&m[%d] = %p,m[%d] = %p\n",i,&m[i],i,m[i]);

    for (int j = 0; j < ncols; j++)
    {
      m[i][j] = count++;
      printf("&m[%d][%d] = %p,m[%d][%d] = %d\n",i,j,&m[i][j],i,j,m[i][j]);
    }
    puts("");
  }

  return 0;  
}