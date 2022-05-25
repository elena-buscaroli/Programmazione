#include <stdio.h>

/*
    Esercizio 2
*/

// Funzione per scambiare due variabili
void scambia(int *p, int *q)
{
    int temp;
    temp = *p;
    *p = *q;
    *q = temp;
}

// Funzione per trovare il min tra due interi
int min(int *a, int *b)
{
    int min;
    if (*a <= *b)
        min = *a;
    else
        min = *b;
    return min;
}

// Funzione per ordinare in modo decrescente quattro interi
void ordine_decrescente(int *a, int *b, int *c, int *d)
{
    // devo mettere il min in a
    if (min(a, b) == *b)
        scambia(a, b);
    if (min(a, c) == *c)
        scambia(a, c);
    if (min(a, d) == *d)
        scambia(a, d);

    // adesso metto in b il più piccolo tra b c d
    if (min(b, c) == *c)
        scambia(b, c);
    if (min(b, d) == *d)
        scambia(b, d);

    // adesso metto in c il più piccolo tra c e d
    if (min(c, d) == *d)
        scambia(c, d);
}

/*
    Esercizio 3
*/
void somma_armonica(int n, double *h)
{
    if (n == 1) // se n = 1 la somma è 1
        *h = 1.0;
    else // altrimenti chiamo ricorsivamente la funzione
    {
        somma_armonica(n - 1, h);
        *h = 1.0 / (n) + *h; // aggiorno il valore di h
    }
}
