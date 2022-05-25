#include <stdio.h>

/*
    Scrivere una funzione ricorsiva che riceva in input due numeri naturali a e b,
    ne calcoli l’MCD, seguendo la successione di ricorrenza:
        - passo base: a_0=a, b_0=b
        - step ricorsivo: a(n+1)=b_n, b(n+1) è il resto della divisione a_n/b_n.
*/
int MCD(int a, int b)
{
    int r = a % b; // variabile per salvare il resto della divisione tra a e b
    if (r == 0) return b; // se il resto della divisione tra a e b è 0, torno il valore di b
    else return MCD(b, r); // calcoliamo l'MCD tra a(n+1)=b_n e b(n+1)=r
}
 

int main() 
{
    int n, m;
    printf("\nInserire il valore di n: ");
    scanf("%d", &n);
    
    printf("\nInserire il valore di m: ");
    scanf("%d", &m);
  
    printf("\nMCD tra %d e %d : %d", n, m, MCD(n,m));

    return 0;
}