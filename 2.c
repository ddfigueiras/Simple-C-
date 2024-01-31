#include <stdio.h>
#include <stdlib.h>
#include "our_ints.c"
#include "our_doubles.c"
//#include "our_ints.c"
//#include "our_doubles.c"

int gas(int num_gas, double *prices, double *discounts, double *limits, int liters) 
{        
    double valor_maximo = 0;
    int indice_maximo = -1;
    double total = 0;
    
    for(int i = 0; i < num_gas ; i++)
    {
        total = gas_cost(prices[i], discounts[i], limits[i], liters);
        if(i == 0 || total < valor_maximo)
        {
            indice_maximo = i;
            valor_maximo = total;
        }
    }
    return indice_maximo;
}

double gas_cost(double price, double discount, double limit, int liters) 
{
    double final_price = 0;
    if(limit == 0 || discount == 0)
        final_price = liters * price;
    else if(liters <= limit)
        final_price = limit * (price - discount);
    else if(liters > limit)
        final_price = limit * (price - discount) + (liters - limit) * price;            
    return final_price;

}

void test_fuel(void) 
{
    int i;
    double prices[1000];
    double discounts[1000];
    double limits[1000];
    int num_gas = doubles_get_until(-1, prices);
    num_gas = doubles_get_until(-1, discounts);
    num_gas = doubles_get_until(-1, limits);
    int liters = 0;;
    while (scanf("%d" , &liters) != EOF)
    {
        int cheapest_gas = gas(num_gas, prices, discounts, limits, liters);
        double cost = gas_cost(prices[cheapest_gas], discounts[cheapest_gas], limits[cheapest_gas], liters);
        double price_per_liter = cost / liters;
        printf("%d %.2f %.2f", cheapest_gas, cost, price_per_liter);
    }
}

int main(void) 
{
    test_fuel();
    return 0;
}