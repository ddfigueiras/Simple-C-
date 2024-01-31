#include <stdio.h>
#include <string.h>
#include "our_ints.h"

const char *author = "Diogo Silva";

int remove_spaces(char *a , int na , char *b )
{
    int contador = 0;
    for(int i = 0 ; i < na ; i++)
    {
        if (a[i] != '_')
        {
            b[contador] = a[i];
            contador++;
        }
    }
    
    return contador;
}

void telegramas_teste(void)
{
    char a[1000];
    char b[1000];
    while(scanf("%s", a) != EOF)
    {    
        int na = sizeof(a); 
        remove_spaces(a, na, b);
        printf("%s\n", b);
    }
}


int main()
{
    telegramas_teste();
    return 0;
}