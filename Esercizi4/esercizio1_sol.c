#include <stdio.h> // scanf, printf

/*
	Considerare due array statici A e B dimensione N, ed inizializzati tramite input da tastiera. Creare tre funzioni che facciano le seguenti operazioni:
	1.  Per ogni indice i, sommare e moltiplicare A[i] e B[i] salvare i risultati in un terzo array C, all'indice i (usando lo stesso array di supporto, sovrascrivendo il valore per ogni operazione che deve essere eseguita) -> la funzione prenda come input i tre array A,B,C e la loro dimensione;
	2.  confrontare gli elementi A[i] e B[i] dei due array e salvare l'elemento maggiore in C[i] -> la funzione prenda come input i tre array A,B,C e la loro dimensione;
	3.  determinare la media, il valore massimo ed il valore minimo dell'array C risultante dal punto precedente -> la funzione prenda come input l’array C, la sua dimensione e tre
variabili min,max,mean, inizializzate nel main e passate alla funzione come puntatori.
*/

void initialize_array(int a[], int dim)
{
    for (int i = 0; i < dim; i++)
    {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }
}

void print_array(int a[], int dim)
{
    printf("Array: ");
    for (int i = 0; i < dim; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void somma(int a[], int b[], int c[], int dim)
{
    printf("\nSomma di A e B in C.\n");
    for (int i = 0; i < dim; i++)
        c[i] = a[i] + b[i];
}

void prodotto(int a[], int b[], int c[], int dim)
{
    printf("\nProdotto di A e B in C.\n");
    for (int i = 0; i < dim; i++)
        c[i] = a[i] * b[i]; // prodotto salvato in c, posizione i
}


void maggiore(int a[], int b[], int c[], int dim)
{
    printf("\nConfrontare gli elementi di A e B e salvare il maggiore in C.\n");
    for (int i = 0; i < dim; i++)
    {
        if (a[i] < b[i])
            c[i] = b[i];
        else
            c[i] = a[i];
    }
}


void max_min_media(int a[], int N, int *min, int *max, float *media)
{
    float somma = 0;
    for (int i = 0; i < N; i++)
        somma += a[i];
    *media = somma / N;
    printf("Media di C: %f\n", *media);
}


void mmm(int a[], int n, int* min, int* max, float* mean){
  *min = a[1];
  *max = a[1];
  float k=0;
  
  for (int i=0; i<n; i++){
    if (a[i]< *min)
      *min=a[i];
    if (a[i]> *max)
      *max=a[i];
    k+=a[i];
  }
  *mean = k/n;
}



int main()
{
    int dimensione = 5;
    int a[5];
    int b[5];
    int c[5];
    printf("Inserire i valori dell'array A.\n");
    initialize_array(a, dimensione);
    printf("\nInserire i valori dell'array B.\n");
    initialize_array(b, dimensione);

    somma(a, b, c, dimensione);
    print_array(c, dimensione);
    prodotto(a, b, c, dimensione);
    print_array(c, dimensione);
    maggiore(a, b, c, dimensione);
    print_array(c, dimensione);

    int min, max;
    float media = 0.0;
    max_min_media(c, dimensione, &min, &max, &media);
    mmm(c, dimensione, &min, &max, &media);
    return 0;
}
