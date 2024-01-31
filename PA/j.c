#include <assert.h>
#include <stdio.h>
#include <assert.h>
#include "our_ints.h"
//#include "our_ints.c"

const char *author = "Diogo Silva";

int ints_find_triple(int *a, int n) 
{
  int checkResult = -1;
  for (int i = 0; i < n && checkResult == -1; i++)
  {
    if(a[i] == a[i+1] && a[i] == a[i+2])
    {
      checkResult = i;
    }
  }
  return checkResult;
}

void ints_argsmax_teste(void) 
{
  int a[1000];
  int n = ints_get_until(-1, a);
  printf("%d\n", ints_find_triple(a, n));
}

void teste_assert(void)
{
  int a[8] = {1,2,2,2,5,6,8,7};
  assert(ints_find_triple(a, 8) == 1);
  assert(ints_find_triple(a, 7) == 1);
  assert(ints_find_triple(a, 6) == 1);
  assert(ints_find_triple(a, 5) == 1);
}

int main() 
{
  teste_assert();
  ints_argsmax_teste();
  return 0;
}
//6 2 8 5 9 9 9 1 9 2 2 2 a função devolverá 4; se for  1 6 3 8 8 3 8 2 ent é -1


int count_char(char *s, char x)
{
    int count;
    for(int i = 0; s[i] != '\0'; i++)  
        if(s[i] == x)
            count++;
    return count;
}