#include <assert.h>
#include <stdio.h>
#include <assert.h>
#include "our_ints.h"
//#include "our_ints.c"

const char *author = "Diogo Silva";

int ints_accumulate(int *a, int n, int *b) 
{
  int soma = 0;
  for (int i = 0; i < n + 1; i++) // +1 por causa do 0
  {
    b[i] = soma;
    soma += a[i];
  }
  return n + 1;
}

void ints_argsmax_teste(void) 
{
  int a[1000];
  int b[1000];
  int n = ints_get_until(-1, a);
  int nb = ints_accumulate(a, n, b);
  ints_println_special(b, nb);
}

void teste_assert(void)
{
  int a[8] = {1,2,3,4,5,6,8,7};
  int b[1000];
  assert(ints_accumulate(a, 8, b) == 9);
  assert(ints_accumulate(a, 7, b) == 8);
  assert(ints_accumulate(a, 6, b) == 7);
  assert(ints_accumulate(a, 5, b) == 6);
}

int main() 
{
  teste_assert();
  ints_argsmax_teste();
  return 0;
}