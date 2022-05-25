#include <stdio.h>

/*
    Scrivere una funzione che prenda in ingresso due interi a e b, con b>0,
    e restituisca il risultato della potenza a^b.
*/


/* Soluzioni svolte a lezione */

/* Soluzione iterativa */
int esp (int a, int b)
{
    int z = 1; // variabile per salvare il valore della potenza finale, inizializzato a 1
    for(int i = 1; i <= b; i++) // iteriamo su ogni i=1,...,b
    {
        /* all'inizio di ogni iterazione i, z conterrà il
        valore della potenza a^(i-1) */
        z = z * a; // moltiplichiamo z per a, per ottenere a^i
    }

    // dopo b iterazioni, z conterrà il valore di a^b
    return z;
}


/* Soluzione ricorsiva */
int power(int a, int b)
{
  if (b == 0) // se l'esponente è 0, il valore a^0=1
    return 1;
  else // altrimenti a^b = a * a^(b-1)
    return a * power ( a , (b - 1) );
} 

int main(void) {
    int a = 3;
    int b = 3;
    printf ("esp(%d,%d)=%d\n", a, b, esp(a, b));
    printf ("power(%d,%d)=%d\n", a, b, power(a, b));
    return 0;
}
