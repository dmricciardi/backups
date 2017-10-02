#include <stdio.h>

/* every C program must have a main function*/
int main(){
  
  int a; // reserved 4 bytes on the "stack"
  int b;
  double c; // reserved 8 bytes on the "stack"
  a = 3;
  b = 6;
  c = 1.2;

  printf("a=%d\n", a);
  printf("b=%d\n", b);
  printf("a+b=%d\n", a+b);
  printf("a-b=%d\n", a-b);
  printf("a/b=%d\n", a/b);
  printf("a*b=%d\n", a*b);
  
  printf("c=%f\n", c);
  printf("b=%d\n", b);
  printf("c+b=%f\n", c+b);
  printf("c-b=%f\n", c-b);
  printf("c/b=%f\n", c/b);
  printf("c*b=%f\n", c*b);
  
  return 0;
  
}
