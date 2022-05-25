#include <stdio.h>

/*
    Si scriva una funzione ricorsiva (possibilmente ricorsiva dal basso), che prenda come
    input un intero positivo n e il puntatore della variabile H, che conterrà il seguente risultato:
    H(n)=i=1n1i=1+12+...+1n
    La funzione deve essere definita nel seguente modo: void somma_armonica(int n, double* h)
*/

void somma_armonica(int n, double *h)
{
    if (n == 1) // se n = 1 la somma è 1
    {
        *h = 1.0;
    }
    else // altrimenti chiamo ricorsivamente la funzione
    {
        somma_armonica(n - 1, h);
        *h = 1.0 / (n) + *h; // aggiorno il valore di h
    }
}

int main()
{
    int n;
    double h;

    printf("Inserire n: \n");
    scanf("%d", &n);

    somma_armonica(n, &h); // Passo l'indirizzo della variabile h
    printf("Somma dei primi %d termini della serie armonica: %lf\n", n, h);

    return 0;
}