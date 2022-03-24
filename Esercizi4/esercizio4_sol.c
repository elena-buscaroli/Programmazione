#include <stdio.h>

/*
    Leggere un array di 10 numeri interi e scrivere una
    funzione che prenda come input l'array inserito, la sua
    dimensione e una variabile "check", inizializzata nel main
    a 0 e passata alla funzione tramite puntatore, che sarà
    uguale a 0 se la sequenza inserita è palindroma, o 1
    viceversa → se non cambia ad essere letta dalla prima 
    cella all'ultima o viceversa.
    Esempio: la sequenza 12321 è palindroma.
*/

void pal(int a[], int dim, int *check)
{
    int i = 0;
    while(i < dim/2 && *check==0)
        {
            if (a[i] != a[dim-i-1])
                *check = 1;
            i++;
        }
}

int main()
{
    int check = 0;
    int a[10] = {1,2,3,4,5,3,4,3,2,1}; 
    int dim = 10;
    pal(a, dim, &check);

    if (check == 0)
        printf("La sequenza è palindroma\n");
    else
        printf("La sequenza non è palindroma\n");
    
    return 0;
}