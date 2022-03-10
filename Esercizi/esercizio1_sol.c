#include <stdio.h>

// Calcolare la media aritmetica tra N numeri x_1,...,x_N inseriti da tastiera                // La media è calcolata come media = 1/N \sum(x_i), per i=1,...,N

int main() {
    float s = 0;  // somma provvisoria
    int c = 0;  // numero di elementi

    int a = -1; 

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

