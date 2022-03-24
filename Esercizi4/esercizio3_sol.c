#include <stdio.h>

/*
    Dati due array A e B di interi di dimensione N, letti da tastiera, scrivere una funzione
    che prenda in input A, B e la loro dimensione, e ne ritorni il prodotto scalare A*B.
    Il prodotto scalare e definito come: A*B=sum(A[i]*B[i]), con i=1,...,N.
*/

int prodotto_scalare(int a[], int b[], int N)
{
    int prod = 0;
    for (int i = 0; i < N)
        prod += a[i] * b[i];
    return(prod);
}

int main()
{
    int dimensione = 10;
    int a[10];
    int b[10];

    int prod = prodotto_scalare(a, b);

    return 0;
}