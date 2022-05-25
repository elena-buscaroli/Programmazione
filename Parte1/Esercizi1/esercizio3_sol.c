#include <stdio.h>

// Prendere un numero da tastiera e stampare i quadrati perfetti fino al quadrato del numero stesso

int main() {
    int n;
    printf("Inserire un numero intero: ");
    scanf("%d", &n);

    int isq;

    if (n > 0) {
        int i = 1;
        while (i < n) {
            isq = i*i;
            printf("%d**2 = %d\n", i, isq);
            i += 1;
        }
    }
    
    return 0;
}
