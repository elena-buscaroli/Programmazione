#include <stdio.h>

/*
    Scrivere un programma che, preso un intero positivo da tastiera, stampi la successione di Fibonacci fino al numero inserito.
    L'n-esimo elemento della successione di Fibonacci è definito come:
	0 se i = 0;
	1 se i = 1;
	F_(n-1) + F_(n-2) se i>1;
*/

int main() {

    int n;
    printf("Inserire fino a che indice della sequenza si vuole visualizzare: \n");
    scanf("%d", &n);
    
    int f_i_2 = 0; // valore della sequenza all'indice i-2
    int f_i_1 = 1; // valore della sequenza all'indice i-1
    printf("F(0)=%d\n", f_i_2);
    printf("F(1)=%d\n", f_i_1);

    int f_i; // valore della sequenza all'indice i
    for (int i=2; i <= n; i++) {
        f_i = f_i_2 + f_i_1; // f_i è uguale alla somma dei due elementi precedenti
        printf("F(%d)=%d\n", i, f_i);
        f_i_2 = f_i_1; // aggiorno il valore all'indice i-2
        f_i_1 = f_i; // aggiorno il valore all'indice i-1
    }

    return 0;
}
