#include <stdio.h>
#include <string.h>
#include <assert.h>

const char *author = "Diogo Silva";

int str_find(char *s, char x)
{
    int result = -1;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if(s[i] == x && result == -1)
        {
            result = i;
        }
    }
    return result;
}

int str_find2(char *s, char x, int n)
{
    int result = -1;
    for (int i = n; s[i] != '\0'; i++)
    {
        if(s[i] == x)
        {
            result = i;
        }
    }
    return result;
}

int  alpha2(char *letra, char *p)
{
    int zero = str_find(p, letra[0]);
    int primeiro = str_find2(p, letra[1], zero);
    int result = 0;
    if(zero < primeiro)
    {
        result = 1;
    }    
    return result;
}

void test()
{
    char s[1000];
    scanf("%s", s);
    char x[1000]; 
    while (scanf("%s", x) != EOF)
    {
        int verificar = alpha2(s, x);
        if (verificar == 0)
            printf("NO\n");
        else if (verificar == 1)
            printf("YES\n");
    }
 }

void unit_test_str_find(void)
{
    assert(str_find("abcdedfghi", 'a') == 0);
    assert(str_find("abcdedfghi", 'd') == 3);
    assert(str_find("abcdedfghi", 'g') == 7);
    assert(str_find("abcdedfghi", 'i') == 9);
    assert(str_find("abcdedfghi", 'p') == -1); 
    assert(str_find("abcdefghijklmn", 'z') == -1);
}


void unit_test_alpha2(void)
{
    assert(alpha2("pt", "portugal"));
    assert(alpha2("fr", "franca"));
    assert(alpha2("lk", "sri lanka"));
    assert(!alpha2("de", "alemanha"));
    assert(!alpha2("zb", "brazil"));
}

int main(int argc, char**argv)
{
    unit_test_str_find();
    unit_test_alpha2();
    int x = 'A';
    if(argc>1)
        x = *argv[1];
    if(x == 'A')
        test();
    else if(x == 'U')
        printf("All unit tests PASSED.\n");
    else
        printf("%s:Invalid option.\n", argv[1]);
    return 0;
}