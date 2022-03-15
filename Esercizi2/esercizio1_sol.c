#include <stdio.h>

/*
    Scrivere una funzione che prenda in ingresso due interi a e b, con b>0,
    e restituisca il risultato della potenza a^b.
*/


/* Soluzioni svolte a lezione */

/* Soluzione iterativa */
int esp (int a, int b)
{
    int z = 1;
    for(int i = 1; i <= b; i++)
    {
        z = z * a;
    }
    return z;
}

/* Soluzione ricorsiva */
int power(int a, int b)
{
  if (b == 0) 
    return 1;
  else
    return a * power ( a , (b - 1) );
} 

int main(void) {
    int a = 3;
    int b = 3;
    printf ("esp(%d,%d)=%d\n", a, b, esp(a, b));
    printf ("power(%d,%d)=%d\n", a, b, power(a, b));
    return 0;
}
