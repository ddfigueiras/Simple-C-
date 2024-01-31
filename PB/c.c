#include <stdio.h>
#include <assert.h>
#include <string.h>
//#include "our_ints.h"

int str_find(char *a, int x, int n)
{
    for(int i = n; a[i] != '\0'; i++)
        if(a[i] == x)
        {
            printf("%d", i);
            return i;
        }
    return -1;
}
//aab aba
void test_alpha2()
{
    char x[1000];
    char a[1000];
    while(scanf("%s", x) != EOF && scanf("%s", a) != EOF) // Até ctr + D vai pedir valores para as o array X e para o array A
    {
        int n = str_find(a, x[0], 0);
        for(int i = 1; x[i] != '\0'; i++) // Vai fazer um ciclo para testar todas as letras do array X na função str_find
        {
            if(n != -1)
                n = str_find(a, x[i], n + 1); // a variavel n ao inicio é 0 porque começa no index 0, depois a variavel n vai ser o index que vier da letra anterior (tal como no PB b)
        }
        if(n == -1)
            printf("NO\n");
        else
            printf("YES\n");
    }
}

int main() 
{
  //teste_assert();
  test_alpha2();
  return 0;
}
