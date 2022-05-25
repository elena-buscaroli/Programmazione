#include <stdio.h>

/*
    Scrivere una funzione ricorsiva riceva in ingresso un intero N e che ritorni
    il valore dell’N-esimo elemento della successione di Fibonacci.
    L'n-esimo elemento della successione di Fibonacci è definito come:
        - 0 se i=0;
        - 1 se i=1;
        - F(n-1)+F(n-2) se i>1.
*/


/* Soluzione svolte a lezioni */
int fib (int n)
{
    if (n==0) // l'elemento a indice n=0 è uguale a 0 per definizione
        return 0;
    if (n==1) // l'elemento a indice n=1 è uguale a 1 per definizione
        return 1;
    return fib(n-1) + fib(n-2); // // l'elemento a indice n=n è uguale alla somma dei due elementi precedenti
}


/*
    Funzione per calcolare l'n-esimo elemento
    della successione di Fibonacci.
    Soluzione iterativa.
*/
int fib_it(int n) 
{
    int f_i_2 = 0; // valore della sequenza all'indice i-2
    int f_i_1 = 1; // valore della sequenza all'indice i-1

    int f_i; // valore della sequenza all'indice i
    for (int i=2; i <= n; i++) {
        f_i = f_i_2 + f_i_1; // f_i è uguale alla somma dei due elementi precedenti
        f_i_2 = f_i_1; // aggiorno il valore all'indice i-2
        f_i_1 = f_i; // aggiorno il valore all'indice i-1
    }

    return f_i;
}


int main(void) 
{
    int n = 12;
    printf("fib:%d\n", fib(n));
    printf("fib iterativo:%d\n", fib_it(n));
}
