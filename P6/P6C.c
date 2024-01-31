#include <stdio.h>
#include <math.h>

//feito por diogo silva
double arredondar(double x)
{
  return (round(x * 1000000)) / 1000000;
}

double indice(double w, double h)
{
  return w/pow(h, 2);
}

int obeso(double i, int s)
{
  return s == 0 ? i >= 32.4 ? 1 : 0 : i >= 31.2 ? 1 : 0;
}

void inverte_test(void)
{
  int s;
  double w;
  double h;
  while(scanf("%d%lf%lf", &s, &w, &h) != EOF)
  {
    double i = indice(w, h);
    printf("%f %d\n", i, obeso(i, s));
  }
}

int main(void)
{
  inverte_test();
  return 0;
}