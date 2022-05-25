#include <stdio.h>

// Calcolare il coefficiente binomiale

int main() {

    int n = 10;
    int k = 6;

    int n_fact = 1;
    int k_fact = 1;
    int nk_fact = 1;

    for (int i = n; i > 0; i--) {
        if (i <= k) {
            k_fact *= i;
        }

        if (i <= (n-k)) {
            nk_fact *= i;
        }
        
        n_fact *= i;
    }

    float coeff_bin = n_fact / (k_fact * nk_fact);

    printf("Factorial of %d = %d\n", n, n_fact);
    printf("Factorial of %d = %d\n", k, k_fact);
    printf("Factorial of %d = %d\n", n-k, nk_fact);
    printf("Binomial coefficient of %d,%d = %f\n", n, k, coeff_bin);

    return 0;
}