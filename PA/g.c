#include <assert.h>
#include <stdio.h>
#include <assert.h>
#include "our_ints.h"
//#include "our_ints.c"

const char *author = "Diogo Silva";

int ints_ascending(int *a, int n, int *b) 
{
  int nb = 0;
  int Maximo = a[0];
  for (int i = 0; i < n; i++) 
  {
    if (a[i] >= Maximo) 
    {
      b[nb] = a[i];
      Maximo = a[i];
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
  int nb = ints_ascending(a, n, b);
  ints_println_special(b, nb);
}

void teste_assert(void)
{
  int a[8] = {1,2,3,4,5,6,8,3};
  int b[1000];
  assert(ints_ascending(a, 3, b) == 3);
  assert(ints_ascending(a, 4, b) == 4);
  assert(ints_ascending(a, 5, b) == 5);
  assert(ints_ascending(a, 6, b) == 6);
}

int main() 
{
  teste_assert();
  ints_argsmax_teste();
  return 0;
}