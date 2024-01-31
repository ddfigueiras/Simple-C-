#include <stdio.h>
#include <math.h>

// 

double arredondar(double x)
{
  return (round(x * 100)) / 100;
}

double gasto(int a)
{
  int base = 8;
  double contador = 0;
  double preco = 8;
  for(int i = 1; i <= a; i++)
  {
    contador += preco;
    if(i % 100 == 0)
    {
      preco = preco - arredondar((preco * 0.1));
    }
  }
  return contador;
}

void teste(void)
{
  int a;
  while (scanf("%d", &a) != EOF)
  {
    double z = gasto(a);
    printf("%f", z);
  }
}

int main(void)
{
  teste();
  return 0;
}