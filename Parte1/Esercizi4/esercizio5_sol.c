#include <stdio.h>

/*
    Dichiarare un array chiamato primes, e scrivere una funzione per inizializzare i 
    suoi valori con i numeri primi (un numero intero positivo è definito primo se ha 
    esattamente due divisori distinti) minori di 100 (considerare 2 come il primo 
    numero primo -> primes[0]=2).
    Nota: per calcolare il resto della divisione tra due numeri a e b -> resto = a%b
*/

int initialize(int a[])
{
    int j=0;
    for(int i = 2; i <= 100; i++){
        int c=0;
        for (int k = 2; k <= i; k++)
            if(i%k == 0) c+=1;
        if (c==1)
        {
            a[j]=i;
            j++;
        } 
    }
    return j;
}

void print_array( int a[], int n){
  printf("\nNumeri primi minori di 100:\n");
    for(int i=0; i<n; i++)
      printf("%d ", a[i]);
  printf("\n");
}

int main(){
    int primes[100];
    
    int num_elementi = initialize(primes);
    print_array(primes, num_elementi);
    return 0;
}