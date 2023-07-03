#include<stdio.h>

int main() {
  int n_slices = 2;
  int n_rows = 2;
  int n_cols = 3;

  int m[2][2][3] = {
    {
      {0,1,2},
      {3,4,5}
    },
    {
      {7,8,9},
      {10,11,12},
    }
  };

  printf("&m = %p,m = %p\n\n",&m,m);

  for (int k = 0; k < n_slices; k++) {
    for (int i = 0; i < n_rows; i++)
    {
      for (int j = 0; j < n_cols; j++)
      {
        printf("&m[%d][%d][%d] = %p,m[%d][%d][%d] = %d\n",k,i,j,&m[k][i][j],k,i,j,m[k][i][j]);
      }
      
    }
    
  }

  
}