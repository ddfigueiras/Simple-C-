#include <assert.h>
#include <stdio.h>
#include <assert.h>
#include "our_ints.h"
//#include "our_ints.c"

const char *author = "Diogo Silva";

int ints_unaccumulate(int *a, int n, int *b) 
{
  int soma = 0;
  for (int i = 0; i < n + 1; i++) 
  {
    b[i] = a[i+1] - soma;
    soma += b[i];
  }
  return n - 1; // se no ultimo adicionamos por causa do 0, agr tiramos pq n temos 0
}
//5 1 4 1 3 4
//0 5 6 10 11 14 18
void ints_argsmax_teste(void) 
{
  int a[1000];
  int b[1000];
  int n = ints_get_until(-1, a);
  int nb = ints_unaccumulate(a, n, b);
  ints_println_special(b, nb);
}

void teste_assert(void)
{
  int a[8] = {1,2,3,4,5,6,8,7};
  int b[1000];
  assert(ints_unaccumulate(a, 8, b) == 7);
  assert(ints_unaccumulate(a, 7, b) == 6);
  assert(ints_unaccumulate(a, 6, b) == 5);
  assert(ints_unaccumulate(a, 5, b) == 4);
}

int main() 
{
  teste_assert();
  ints_argsmax_teste();
  return 0;
}
