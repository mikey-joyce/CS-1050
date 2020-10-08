#include<stdio.h>

int main(void){
  int x, y;
  scanf("%d %d", &x, &y);
  printf("X: %d\nY: %d", &x, &y);
  printf("X*Y: %d", &x * &y);
  printf("(X+1)*Y: %d", (&x+1) * &y);
  printf("X: %d\nY: %d", &x, &y);
  return 0;
}
