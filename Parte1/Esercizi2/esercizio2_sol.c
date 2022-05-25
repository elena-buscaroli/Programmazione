#include <stdio.h>

/*
    Scrivere una funzione che prenda in ingresso tre numeri interi e
    restituisca il minimo tra i tre numeri.
*/

int minimo(int a, int b, int c)
{
    int min;
    if (a < b)
    {
        min = a;
    }
    else
    {
        min = b;
    }
    if (c <= min)
    {
        min = c;
    }
    return min;
}

int main()
{
    int a = 10;
    int b = 2;
    int c = -1;
    int min = minimo(a, b, c);
    printf("minimum among %d, %d, %d is %d\n", a, b, c, min);
    return 0;
}
