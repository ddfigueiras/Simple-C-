#include <assert.h>
#include <stdio.h>
#include <assert.h>
#include "our_ints.h"
//#include "our_ints.c"

const char *author = "Diogo Silva";

int ints_append(const int *a, int n, const int *b, int m, int *c)
{
    for(int i = 0; i < m + n; i++)
    {
        if(i < n)
        {
            c[i] = a[i];
        }
        else
        {
            c[i] = b[i - n];
        }
    }
    return *c;
}

void ints_argsmax_teste(void) 
{
  int a[1000];
  int n = ints_get_until(-1, a);
  int b[1000];
  int m = ints_get_until(-1, b);
  int c[1000];
  
  ints_append(a, n, b, m, c);
  ints_println_special(c, n + m);
  ints_append(b, m, a, n, c);
  ints_println_special(c, n + m);
}


void teste_assert(void)
{
  int a[8] = {1,2,3,4,5,6,8,7};
  int b[2] = {1, 2};
  int c[1000];
  assert(ints_append(a, 8, b, 2, c) == 1);
  assert(ints_append(a, 7, b, 2, c) == 1);
  assert(ints_append(a, 6, b, 2, c) == 1);
  assert(ints_append(a, 5, b, 2, c) == 1);
}

int main() 
{
  teste_assert();
  ints_argsmax_teste();
  return 0;
}
