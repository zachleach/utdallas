#include <stdio.h>

int f(int, int);
int g(int);

int gl;

int main(int argc, char** argv) {
  int n1 = f(3,-5);
  printf("addr of main %p \n", main);
  printf("addr of global gl %p \n", &gl);
  printf("addr of n1 %p \n", &n1);
  n1 = g(n1);
}

int f(int p1, int p2) {
  int x;
  int a[3];
  printf("addr of f %p \n", f);
  printf("addr of x %p \n", &x);
  x = g(a[2]);
  return x;
}

int g(int param) {
  return param * 2;
}
