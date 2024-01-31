#include <assert.h>
#include <stdio.h>
#include <assert.h>
#include "our_ints.h"
//#include "our_ints.c"

const char *author = "Diogo Silva";

int ints_less_than(int *a, int x, int n, int *b) 
{
  int nb = 0;
  for (int i = 0; i < n; i++) 
  {
    if (a[i] < x) 
    {
      b[nb] = a[i];
      nb += 1;
    }
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
    int nb = ints_less_than(a, x, n, b);
    ints_println_special(b, nb);
  }
}

void teste_assert(void)
{
  int a[8] = {1,2,3,4,5,6,8,7};
  int b[1000];
  assert(ints_less_than(a, 7, 8, b) == 6);
  assert(ints_less_than(a, 6, 8, b) == 5);
  assert(ints_less_than(a, 5, 8, b) == 4);
  assert(ints_less_than(a, 4, 8, b) == 3);
}

int main() 
{
  teste_assert();
  ints_argsmax_teste();
  return 0;
}