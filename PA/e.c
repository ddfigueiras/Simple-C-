#include <assert.h>
#include <stdio.h>
#include <assert.h>
#include "our_ints.h"
//#include "our_ints.c"

const char *author = "Diogo Silva";

int ints_take(int *a, int x, int n, int *b) 
{
  int nb = 0;
  if(x > n)
  {
    x = n;
  } else if(x < 0)
  {
    x = 0;
  }
  for (int i = 0; i < x; i++) 
  {
    b[nb] = a[i];
    nb += 1;
  }
  return nb;
}

void ints_argsmax_teste(void) 
{
  int a[1000];
  int b[1000];
  int n = ints_get_until(-1, a);
  int x;
  while (scanf("%d", &x) != EOF)
  {
    int nb = ints_take(a, x, n, b);
    ints_println_special(b, nb);
  }
}

void teste_assert(void)
{
  int a[8] = {1,2,3,4,5,6,8,3};
  int b[1000];
  assert(ints_take(a, 1, 8, b) == 1);
  assert(ints_take(a, 2, 8, b) == 2);
  assert(ints_take(a, 3, 8, b) == 3);
  assert(ints_take(a, 4, 8, b) == 4);
}

int main() 
{
  teste_assert();
  ints_argsmax_teste();
  return 0;
}