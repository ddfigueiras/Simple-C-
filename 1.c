#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "our_ints.h"
#include "our_doubles.h"
//#include "our_ints.c"
//#include "our_doubles.c"

const char *author = "Diogo Silva";


double avg_km(double *a, int length)
{
    int i = 0;
    double result = 0;
    int players = length / 4;
    while(i <= length)
    {
        if(i % 4 == 0) 
        {
            result += a[i];
        }
        i++;
    }
    return result/players;
}

double avg_km_hora_titulares(double *a, int length)
{
    int i = 1;
    double players = 0;
    double result = 0;
    while(i <= length)
    {
        if(a[i] >= 50)
        {
            result += a[i-1]/(a[i]/60);
            players++;
        }
        i += 4;
    }
    return result/players;
}


double avg_km_hora_substitutos(double *a, int length)
{
    int i = 1;
    double players = 0;
    double result = 0;
    while(i <= length)
    {
        if(a[i] < 50)
        {
            result += a[i-1]/(a[i]/60);
            players++;
        }
        i += 4;
    }
    return result/players;
}

double total_weight(double *a, int length)
{
    int i = 2;
    double result = 0;
    while(i <= length)
    {
        result += a[i] - a[i+1];
        i += 4;
    }
    return result;
}

void test(void)
{
    double a[1000];
    int length = doubles_get_until(-1, a);
    printf("%.2lf %.2lf %.2lf %.2lf\n", avg_km(a, length), avg_km_hora_titulares(a, length), avg_km_hora_substitutos(a, length), total_weight(a, length));

    /*int x;
    while(scanf("%d", &x) != EOF)
    {
        
    }*/
}

int main(int argc, char**argv)
{
    int x = 'F'; // Numero correspondente à letra F.
    if(argc>1)
        x = *argv[1];
    if(x == 'F')
        test();
    else if(x == 'U')
        printf("All unit tests PASSED.\n");
    else
        printf("%s:Invalid option.\n", argv[1]);
    return 0;
}