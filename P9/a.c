#include <stdio.h>
#include <math.h>
#include <assert.h>

const char *author ="Diogo Silva";

int soma_pares(const int*a, int n)
{
  int SomaTotal = 0;
  int SomaImpares = 0;
  for (int i = 0; i<n ; i++)
  {
    if(i % 2 != 0)
    {
      SomaImpares += a[i];
    } 
    SomaTotal += a[i];
  }
  return (SomaTotal - SomaImpares);  
}

void test_soma_pares(void)
{
  int a[100];
  int n = 0;
  int x;
  while(scanf("%d", &x) != EOF)
  {
    a[n] = x;
    n++;
  }
  int result = soma_pares(a, n);
  printf("%d\n", result);
}

void unit_test_soma_pares(void)
{
  int a[8] = {1,2,3,4,5,6,7,8};
  assert(soma_pares(a, 8) == 16);
  
  int b[5] = {1, 3, 5, 7, 9};
  assert(soma_pares(b, 5) == 15);
  
  int c[1] = {2};
  assert(soma_pares(c, 1) == 2);
  
  int d[3] = {10, 10, 10};
  assert(soma_pares(d, 3) == 20);
}

int main(void)
{
  unit_test_soma_pares();
  test_soma_pares();
  return 0;
}