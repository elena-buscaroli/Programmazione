#include <stdio.h>

int main()
{
    // dichiaro le variabili intere v1 e v2
    int v1;
    int v2;

    // dichiaro i pointers p1 e p2
    int *p1;
    int *p2;

    // 1. stampare i valori di v1 e v2
    printf("Valore di v1: %d\n", v1);
    printf("Valore di v2: %d\n", v2);
    printf("\n\n");

    // 2. stampare indirizzi di v1 e v2
    printf("Indirizzo di v1: %p\n", &v1);
    printf("Indirizzo di v2: %p\n", &v2);
    printf("\n\n");

    // 3. assegnare valori diversi a v1 e v2 e stamparli
    v1 = 5;
    v2 = 10;
    printf("Valore di v1: %d\n", v1);
    printf("Valore di v2: %d\n", v2);
    printf("\n\n");

    // 4. stampare i valori delle variabili puntate da p1 e p2
//    printf("Valore di p1: %d\n", *p1);
//    printf("Valore di p2: %d\n", *p2);
//    printf("\n\n");

    // 5. stampare indirizzi di p1 e p2
    printf("Indirizzo di p1: %p\n", &p1);
    printf("Indirizzo di p2: %p\n", &p2);
    printf("\n\n");

    // 6. assegno indirizzi ai pointers p1 e p2
    p1 = &v1;
    p2 = &v2;
    printf("assegnazione indirizzi eseguita.\n");
    printf("\n\n");

    // 7. stampare indirizzi salvati in p1 e p2
    printf("Indirizzo contenuto in p1: %p\n", p1);
    printf("Indirizzo contenuto in p2: %p\n", p2);
    printf("\n\n");

    // 8. stampare i valori delle variabili puntate da p1 e p2
    printf("Valore puntato da p1: %d\n", *p1);
    printf("Valore puntato da p2: %d\n", *p2);
    printf("\n\n");

    // 9. incrementare v1 e stampare il suo valore
    v1++; // v1 = v1 + 1
    printf("Valore incrementato di v1: %d\n", v1);
    printf("\n\n");

    // 10. stampare l'indirizzo contenuto da p1
    printf("Indirizzo contenuto in p1: %p\n", p1);
    printf("\n\n");

    // 11. stampare il valore della variabile puntata da p1
    printf("Valore puntato da p1: %d\n", *p1);
    printf("\n\n");

    // 12. assegnare a p2 l'indirizzo di v
    p2 = &v1;
    printf("assegnazione indirizzo eseguita.\n");
    printf("\n\n");

    // 13. stampare il valore della variabile puntata da p2
    printf("Valore puntato da p2: %d\n", *p2);
    printf("\n\n");

    // 14. incrementare il valore della variabile puntata da p1, attraverso p1 stesso
    (*p1)++; // oppure *p1 = *p1 + 1, oppure *p1 += 1;
    printf("incrementato eseguito\n");
    printf("\n\n");

    // 15. stampare il valore della variabile puntata da p2
    printf("Valore puntato da p2: %d\n", *p2);
    printf("\n\n");

    // 16. dichiarare e inizializzare il pointer a pointer p3
    int **p3 = &p2;
    printf("assegnazione eseguita\n");
    printf("\n\n");

    // 17. stampare il valore della variabile puntata da p3 (puntata a sua volta da p2), tramite p3 stesso
    printf("Valore puntato da p3: %d\n", **p3);
    printf("\n\n");

    // 18. decrementare e stampare il valore della variabile puntata da p3 (puntata a sua volta da p2), tramite p3 stesso
    (**p3)--;
    printf("Valore puntato da p3: %d\n", **p3);
    return 0;
}
