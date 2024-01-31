#include <stdio.h>
#include <assert.h>
#include "our_ints.h"
//#include "our_ints.c"

const char *author = "Diogo Silva";

int digits_sum(int n)
{
    int sum = 0, r;
    while(n > 0) 
    {
      r = n % 10;
      sum = sum + r;
      n = n/10;
    }
    return sum;
}

int digits_sums(int *a, int n, int *b) 
{
    for(int i = 0; i < n; i++)
    {
        b[i] = digits_sum(a[i]);
    }
    return 1;
}


void ints_argsmax_teste(void) 
{
  int a[1000];
  int b[1000];
  int n = ints_get_until(-1, a);
  digits_sums(a, n, b);
  ints_println_special(b, n);
}

void teste_assert(void)
{
  assert(digits_sum(10) == 1);
  assert(digits_sum(22) == 4);
  assert(digits_sum(42) == 6);
  assert(digits_sum(51) == 6);
}

int main() 
{
  teste_assert();
  ints_argsmax_teste();
  return 0;
}
