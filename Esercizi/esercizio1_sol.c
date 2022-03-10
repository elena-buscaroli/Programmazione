#include <stdio.h>

/*
    Calcolare la media aritmetica tra N numeri x_1,...,x_N inseriti da tastiera. Quando il numero inserito è uguale a 0, vogliamo interrompere l'inserimento dei numeri e visualizzare a schermo la media dei numeri inseriti.
    La media è calcolata come 1/N * \sum(x_i), per i=1,...,N.
*/


int main() {
    float s = 0;  // somma provvisoria
    int c = 0;  // numero di elementi

    int a = -1;  // variabile in cui salveremo il numero inserito da tastiera

    // utilizziamo un while loop, siccome il numero di iterazioni dipende da quanti valori verranno inseriti da tastiera; iteriamo finchè non viene inserito uno 0
    while (a != 0) {
        printf("Inserisci un numero: ");
        scanf("%d", &a);

        if (a != 0) {
            c += 1;
            s += a;
        }
    }

    float media = s / c;
    printf("Media=%f\n", media);
    
    return 0;
}

