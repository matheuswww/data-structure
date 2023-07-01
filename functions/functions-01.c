#include<stdio.h>

int soma(int x,int y) {
  int z = x + y;
  puts("===> THE FUNCTION");
  printf("&x = %p, x = %d\n",&x,x);
  printf("&y = %p,y = %d\n",&y,y);
  printf("&z = %p, z = %d\n\n",&z,z);
}

int main() {
  int a = 20;
  int b = 20;
  int c;


  puts("### BEFORE CALL THE FUNCTION");
  printf("&a = %p, a = %d\n",&a,a);
  printf("&b = %p,b = %d\n",&b,b);
  printf("&c = %p, c = %d\n\n",&c,c);

  c = soma(a,b);

  puts("### AFTER CALL THE FUNCTION");
  printf("&a = %p, a = %d\n",&a,a);
  printf("&b = %p,b = %d\n",&b,b);
  printf("&c = %p, c = %d\n\n",&c,c);
}