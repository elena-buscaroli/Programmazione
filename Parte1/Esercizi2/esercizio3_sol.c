#include <stdio.h>
#include <math.h> // per utilizzare la funzione sqrt

/*
    Scrivere una funzione che prenda in ingresso le coordinate (x,y) di due punti del piano
    cartesiano e restituisca la loro distanza.
    La distanza tra due punti A e B con coordinate rispettivamente (x1,y1) e (x2,y2) viene calcolata come
    d(A,B)=sqrt((x2-x1)^2+(y2-y1)^2).
    Per calcolare la radice quadrata, si può utilizzare la funzione sqrt della libreria math.h.
*/

float distanza_cartesiana(float x1, float y1, float x2, float y2)
{
    float d = sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
    return d;
    // possiamo anche fare direttamente 
    // return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
}

int main()
{
    float x1, x2, y1, y2;
    printf("x1: \n");
    scanf("%f", &x1);
    printf("y1: \n");
    scanf("%f", &y1);
    printf("x2: \n");
    scanf("%f", &x2);
    printf("y2: \n");
    scanf("%f", &y2);
    
    printf("d=%f\n", distanza_cartesiana(x1, y1, x2, y2));
    return 0;
}
