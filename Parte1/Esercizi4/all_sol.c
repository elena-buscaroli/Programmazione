#include <stdio.h>

void initialize_array(int a[], int dim)
{
    for (int i = 0; i < dim; i++)
    {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }
}

/*
    Esercizio 1
*/

void somma(int a[], int b[], int c[], int dim)
{
    printf("\nSomma di A e B in C.\n");
    printf("C: ");
    for (int i = 0; i < dim; i++)
    {
        c[i] = a[i] + b[i];
        printf("%d ", c[i]);
    }
    printf("\n");
}

void prodotto(int a[], int b[], int c[], int dim)
{
    printf("\nProdotto di A e B in C.\n");
    printf("C: ");
    for (int i = 0; i < dim; i++)
    {
        c[i] = a[i] * b[i]; // prodotto salvato in c, posizione i
        printf("%d ", c[i]);
    }
    printf("\n");
}

void maggiore(int a[], int b[], int c[], int dim)
{
    printf("\nConfrontare gli elementi di A e B e salvare il maggiore in C.\n");
    printf("C: ");
    for (int i = 0; i < dim; i++)
    {
        if (a[i] < b[i])
            c[i] = b[i];
        else
            c[i] = a[i];
        printf("%d ", c[i]);
    }
    printf("\n");
}

void max_min_media(int c[], int dim, int *min, int *max, float *media)
{
    printf("\nDeterminare valore massimo, minimo e media in C.\n");
    *min = *max = c[0]; // definiamo i valori iniziali (utile per il min)
    for (int i = 1; i < dim; i++)
    {
        if (c[i] < *min)
            *min = c[i]; // nel caso del minimo
        if (c[i] > *max)
            *max = c[i]; // nel caso del massimo
        *media += c[i];  // per ora limitiamoci a sommarli tutti
    }
    *media = *media / dim;
}

/*
    Esercizio 2
*/

int create_subset(int a[], int b[], int c[], int N, int M)
{
    int k = 0;
    for (int i = 0; i < M; i++)
    {
        int is_present = 0;
        for (int j = 0; j < N; j++)
        {
            if (b[i] == a[j])
                is_present = 1;
        }
        if (is_present == 0)
        {
            c[k] = b[i];
            k++;
        }
    }
    return k;
}

/*
    Esercizio 3
*/
int prodotto_scalare(int A[], int B[], int dim)
{
    int prod = 0;
    for (int i = 0; i < dim; i++)
    {
        prod += A[i] * B[i];
    }
    return prod;
}

/*
    Esercizio 4
*/

void is_palindrome(int *check, int array[], int N)
{
    // esempio: 12321 -> a[0] == a[N-i-1] = a[5-0-1] = a[4]
    for (int i = 0; i < (N / 2 + 1); i++)
    {
        if (array[i] != array[N - i - 1])
        {
            *check = 1;
            i = N;
        }
    }
}

/*
    Esercizio 5
*/

int fill_primes(int primes[])
{
    int i = 2;
    int idx = 0;
    while (i < 100)
    {
        int count = 0; // count per contare il numero di divisori
        for (int j = 1; j <= i; j++)
        {
            if (i % j == 0)
                count++;
        }
        if (count == 2)
        {
            primes[idx] = i;
            idx++;
        }
        i++;
    }
    return idx;
}