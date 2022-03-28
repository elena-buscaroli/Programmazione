#include <stdio.h>

/*
    Un numero è definito triangolare se è costituito dalla somma dei primi
    n numeri interi positivi per un certo n.
    Di conseguenza, per un valore di n, possiamo trovare il numero triangolare n:
    - T[n] = 1 se n=1
    - T[n] = T[n-1] + n se n>1.

    Scrivere una funzione che prenda come input un array A e un intero n, e inserisca
    in A[i] il valore dell'i-esimo numero triangolare, per i=0,...,n-1.
    Scrivere la funzione in modo ricorsivo.

    Ad esempio, 10 è il quatro numero triangolare definito dalla somma 1+2+3+4 (n=4).
*/

// n = 4 -> 1, 3, 6, 10
// T[3] = 4 + T[2] = 4 + 6 = 10
// T[2] = 3 + T[1] = 3 + 3 = 6
// T[1] = 2 + T[0] = 2 + 1 = 3
// T[0] = 1
int triangolare(int a[], int n)
{
    if (n == 1)
        a[n-1] = 1;
    else
        a[n-1] = n + triangolare (a, n-1); 
    return a[n-1];
}

void print_array(int a[], int N)
{
    for (int i = 0; i < N; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main(void) {
    int n=20;
    int a[20];
    
    triangolare (a, n);
    
    print_array(a, n);
    return 0;
}