#include <stdio.h>

/*
    Scrivere una funzione che riceva in ingresso due numeri di tipo double e restituisca 1
    se la differenza tra i due numeri è minore di eps=10-9, oppure 0 in caso contrario.
*/

float abs(float x, float y) 
{
    float diff = x - y;
    if (diff < 0)
        return diff * -1;
    return diff;
}

double pow_it(int a, int n)
{
    float flag = 0;
    if (n < 0) 
    {
        flag = 1;
        n = n * -1;
    }
    
    double p = pow(a, n);
    if (flag == 1) // se n era negativo
        p = 1 / p;
    return p;
}

double pow(int a, int n) 
{
    if (n == 0)
        return 1;
    return a * pow(a, n-1);
}

int controlla_uguaglianza(float a, float b, int n)
{
    float eps = pow_it(10, n);
    float diff = abs(a, b);
    if (diff < eps) 
        return 1;
    return 0;
}

int main()
{
    float a, b;
    float eps = 10e-9;
    scanf("%f", &a);
    scanf("%f", &b);
    
    

    return 0;
}