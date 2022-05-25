#include <stdio.h>

/*
    Letti in input due array A e B, rispettivamente di N ed M elementi,
    scrivere una funzione che salvi in un terzo array C tutti gli elementi
    presenti in B, ma non in A, e che ritorni la lunghezza di C.
*/

void initialize_array(int a[], int dim)
{
    for (int i = 0; i < dim; i++)
    {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }
}

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

void print_array(int c[], int dim)
{
    for (int i = 0; i < dim; i++)
        printf("A[%d] = %d ", i, c[i]);
    printf("\n");
}

int main()
{
    int N = 5;
    int M = 6;

    int a[10]; // inizializzazione array
    int b[15]; // inizializzazione array
    int c[15];

    printf("Inserire i valori di A\n");
    initialize_array(a, N);

    printf("Inserire i valori di B\n");
    initialize_array(b, M);

    int k = create_subset(a, b, c, N, M);

    print_array(c, k);

    return 0;
}
