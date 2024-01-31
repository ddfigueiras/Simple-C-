#include <assert.h>
#include <stdio.h>
#include <assert.h>
#include "our_ints.h"
//#include "our_ints.c"

const char *author = "Diogo Silva";

int ints_drop(int *a, int x, int n, int *b) 
{
  int nb = 0;
  if(x > n)  // Se caso o X for maior que o N quer dizer que vai ser o conjunto vazio, e o for lá em baixo não vai fazer nada porque o i vai ser igual ao x que é igual ao n, logo acaba logo o loop
  {
    x = n;
  } else if(x < 0)
  {
    x = 0;  // Se for 0 ou menos, então o i, no for em baixo vai começar no 0 e acabar no N, isto é, vai printar TODOS os numeros
  }
  for (int i = x; i < n; i++) 
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
    int nb = ints_drop(a, x, n, b);
    ints_println_special(b, nb);
  }
}

void teste_assert(void)
{
  int a[8] = {1,2,3,4,5,6,8,3};
  int b[1000];
  assert(ints_drop(a, 3, 8, b) == 5);
  assert(ints_drop(a, 4, 8, b) == 4);
  assert(ints_drop(a, 5, 8, b) == 3);
  assert(ints_drop(a, 6, 8, b) == 2);
}

int main() 
{
  teste_assert();
  ints_argsmax_teste();
  return 0;
}