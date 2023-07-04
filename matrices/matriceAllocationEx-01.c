#include <stdio.h>
#include <stdlib.h>

void create_int_3D_matrice(int ***m,unsigned int slices,unsigned  rows,unsigned  cols,unsigned  scalar) {
  int n_slices = slices;
  int n_rows = rows;
  int n_cols = cols;

  for (int j = 0; j < n_slices; j++)
  {
    m[j] = (int **) calloc(n_rows,sizeof(int*));
    for (int i = 0; i < n_cols; i++)
    {
      m[j][i] = (int *) calloc(n_cols,sizeof(int));
    }
  }
}

void print_int_3D_matrice(int ***m,int slices,int rows,int cols,int scalar) 
{
  int count = 0;
  for (int k = 0; k < slices; k++)
  {
    printf("&m[%d] = %p,m[%d] = %p\n",k,&m[k],k,m[k]);
    for (int j = 0; j < rows; j++)
    {
      printf("&m[%d][%d] = %p,m[%d][%d] = %p\n",k,j,&m[k][j],k,j,m[k][j]);
        for (int i = 0; i < cols; i++)
        {
          m[k][j][i] = (count += scalar);
          printf("&m[%d][%d][%d] = %p,m[%d][%d][%d] = %d\n",k,j,i,&m[k][j][i],k,j,i,m[k][j][i]);
        }
      puts("");
    }
  }
}

void main(int argc,char *argv[]) {
  if(argc != 5) {
    printf("ERROR\n %s nrows ncols slices scalar\n",argv[0]);
    exit(-1);
  }

  int nrows = atoi(argv[1]);
  int ncols = atoi(argv[2]);
  int slices = atoi(argv[3]);
  int scalar = atoi(argv[4]);
  
  int ***m = (int ***) calloc(slices,sizeof(int**));
  create_int_3D_matrice(m,slices,nrows,ncols,scalar);
  print_int_3D_matrice(m,slices,nrows,ncols,scalar);

  for (int k = 0; k < slices; k++)
  {
    for (int i = 0; i < nrows; i++)
    {
      free(m[k][i]);
    }
    free(m[k]);
  }

  free(m);
  m = NULL;
}
