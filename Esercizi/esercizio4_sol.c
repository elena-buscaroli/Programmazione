#include <stdio.h>

// Dati due interi n e k, calcolare la sommatoria k^i, con i=1,...,n -> k+k^2+k^3+...+k^n     // Per esempio: n=3 e k=3 -> risultato = k^1 + k^2 + k^3 = 3 + 9 + 27 = 39

int main() {
    int k = 3;  // dichiariamo e inizializziamo i valori di k e n
    int n = 3;

    int somma = 0;  // dichiaramo la variabile in cui salveremo il risultato finale

    // il primo ciclo for viene utilizzato per sommare n volte il valore di k^i
    for (int i = 1; i <= n; i++) {
        int ki = 1;  // dichiariamo e inizializziamo a 1 la variabile per calcolare l'i-esima potenza di k

        // il secondo ciclo for viene utilizzato per calcolare l'i-esima potenza di k, iterando per valori di z=1,...,i
        for (int z = 1; z <= i; z++) {
            ki = ki * k;  // ad ogni iterazione moltiplichiamo ki per k, cos+ da moltiplicare k per se stesso i volte
        }
        somma = somma + ki;  // aggiorniamo il risultato
    }
    printf("%d\n", somma);
    
    /*  SECONDA SOLUZIONE
        In questo caso sfruttiamo l'informazione che k^i = k^(i-1) * k per evitare di utilizzare il ciclo for più interno.
        All'inizio dell'iterazione i, la variabile p varrà k^(i-1). Eseguendo p = k * p, stiamo semplicemente eseguendo l'operazione p = k * k^(i-1).
    */
    int p = 1;  // variabile per 
    somma = 0;
    for (int i = 1; i <= n; i++) {
        p = k * p;
        somma = somma + p;
    }
    printf("%d\n", somma);
    
    return 0;
}
