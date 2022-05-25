#include <stdio.h>

/*
    Dato un array A di 10 elementi, scrivere una funzione che modifichi l'array
    A stesso invertendone i valori.
    Esempio: A={1,2,3,4,5} -> A={5,4,3,2,1}
*/

void scambia(int *p, int *q)
{
    int tmp = *p;
    *p = *q;
    *q = tmp;
}

void reverse(int a[], int N)
{
    int start = 0;
    int end = N - 1;
    int temp;
    if (start < end)
    {
        scambia(a + start, a + end);
        // scambia(&a[start], &a[end]);
        start++;
        end--;

        reverse(a + 1, N - 2);
    }
}

void print_array(int a[], int N)
{
    for (int i = 0; i < N; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main()
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int N = 10;

    print_array(a, N);
    reverse(a, N);
    print_array(a, N);

    return 0;
}
