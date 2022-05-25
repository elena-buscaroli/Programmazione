#include <stdio.h>

/*
    Si scriva una funzione che, dati quattro numeri interi a,b,c,d, scambi i loro
    valori in modo che, una volta finita l'esecuzione della funzione, si abbia: a<=b<=c<=d.
    Gli interi devono essere passati alla funzione tramite puntatore e la funzione deve
    ritornare void. La funzione sarà definita come segue: void ordine_decrescente(int* a, int* b, int* c, int* d)

    Nota: puoi utilizzare la funzione scambia dell’Esempio 5.2 della dispensa, ed implementare
    una funzione minimo che calcoli il minimo tra due interi passati tramite puntatore: int min(int* a, int* b)
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
    {
        min = *a;
    }
    else
    {
        min = *b;
    }
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

int main()
{
    // variabile dove leggere gli interi da ordinare
    int a, b, c, d;

    // li leggo da tastiera
    printf("Inserire 4 interi: \n");
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    scanf("%d", &d);

    printf("Ordine prima della funzione: %d %d %d %d\n", a, b, c, d);

    // li ordino in modo decrescente
    ordine_decrescente(&a, &b, &c, &d);

    // stampo per verificare che tutto funzioni
    printf("Ordine dopo la funzione: %d %d %d %d\n", a, b, c, d);

    return (0);
}
