#include <stdio.h>

/*
    Scrivere una funzione che riceva in ingresso due numeri
    di tipo float e restituisca 1 se la differenza tra i 
    due numeri è minore di eps=10-9, oppure 0 in caso
    contrario.

    NOTA: puoi utilizzare anche una funzione di appoggio
    abs() per calcolare il valore assoluto della differenza 
    di a e b!
*/


/*
    Funzione per calcolare il valore assoluto della 
    differenza tra due numeri x e y.
*/
float valore_assoluto(float x, float y) 
{
    float diff = x - y;
    if (diff < 0)
        return diff * -1;
    return diff;
}


/* 
    Funzione ricorsiva per calcolare la potenza.
    NOTA: la funzione vale solo per n>0.
*/
float potenza(int a, int n) 
{
    if (n == 0)
        return 1;
    return a * potenza(a, n-1);
}


/*
    Funzione per calcolare la potenza, valida anche per 
    esponenti n < 0.
*/
float pow_it(int a, int n)
{
    float n_negativo = 0;
    
    if (n < 0) 
    {
        // se n è negativo, la variabile n_negativo 
        // viene modificata a 1 e il segno di n viene
        // invertito
        n_negativo = 1;
        n = n * -1;
    }

    // calcolo la potenza a^n
    float p = potenza(a, n);

    // se n era negativo, calcolo a^(-n) come 1/a^(n)
    if (n_negativo == 1)
        p = 1 / p;
    return p;
}


/*
    Funzione che prende come input due interi a e b, 
    e un intero n, che corrisponde all'esponente che 
    vogliamo assegnare ad epsilon.
    Esempio: n = -10 -> eps = 10^(-10)
*/
int controlla_uguaglianza(float a, float b, int n)
{
    // calcoliamo il valore desiderato di epsilon
    float eps = pow_it(10, n);

    // calcoliamo il valore assoluto della differenza tra a e b
    float diff = valore_assoluto(a, b);

    // se la differenza è minore di epsilon, a e b sono approssimativamente uguali
    if (diff < eps) 
        return 1;
    return 0;
}

int main()
{
    float a, b;
    int n;

    printf("Inserire il primo numero: \n");
    scanf("%f", &a);
    printf("Inserire il secondo numero: \n");
    scanf("%f", &b);
    printf("Inserire il valore dell'esponente: \n");
    scanf("%d", &n);

    int final = controlla_uguaglianza(a, b, n);
    if (final == 0) 
        printf("I due numeri non sono uguali\n");
    else
        printf("I due numeri sono uguali\n");
    return 0;
}