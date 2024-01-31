#include <stdio.h>
#include <string.h>
#include <assert.h>

const char *author = "Diogo Silva";

int str_find2(char *s, char x, int n)
{
    for (int i = n; s[i] != '\0'; i++)
        if(s[i] == x)
            return i;
    return -1;
}

int alpha2(char *letra, char *p)
{
    int zero = str_find2(p, letra[0], 0); // Vai fazer o str_find2 e o ciclo for vai começar em 0 (n = 0)
    int primeiro = str_find2(p, letra[1], zero + 1);  // Vai fazer o str_find2 e o ciclo for vai começar no index onde a primeira letra foi encontrada (n = index do zero)
    int terceiro = str_find2(p, letra[2], primeiro + 1); // Vai fazer o str_find2 e o ciclo for vai começar no index onde a segunda letra foi encontrada (n = index do primeiro)
    return terceiro;
}

void test()
{
    char s[1000];
    scanf("%s", s);
    char x[1000]; 
    while (scanf("%s", x) != EOF)
    {
        if (alpha2(s, x) == -1)
            printf("NO\n");
        else
            printf("YES\n");
    }
}

void unit_test_alpha3(void)
{
    assert(alpha2("prt", "portugal"));
    assert(alpha2("fra", "franca"));
    assert(alpha2("sri", "sri lanka"));
    assert(alpha2("esp", "espanha"));
    assert(alpha2("ago", "angola"));
}

int main(int argc, char**argv)
{

    int x = 'B';
    if(argc>1)
        x = *argv[1];
    if(x == 'B')
        test();
    else if(x == 'U')
        printf("All unit tests PASSED.\n");
    else
        printf("%s:Invalid option.\n", argv[1]);
    return 0;
}