#include <stdio.h>
#include <math.h> // per utilizzare la funzione sqrt

/*
    Scrivere una funzione che prenda in ingresso le coordinate (x,y) di due punti del piano
    cartesiano e restituisca la loro distanza.
    La distanza tra due punti A e B con coordinate rispettivamente (x1,y1) e (x2,y2) viene calcolata come
    d(A,B)=sqrt((x2-x1)^2+(y2-y1)^2).
    Per calcolare la radice quadrata, si può utilizzare la funzione sqrt della libreria math.h.
*/

double distanza_cartesiana(double x1, double y1, double x2, double y2)
{
    double d = sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
    return d;
    // possiamo anche fare direttamente 
    // return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
}

int main()
{
    double x1, x2, y1, y2;
    scanf("%f", &x1);
    scanf("%f", &x2);
    scanf("%f", &y1);
    scanf("%f", &y2);
    printf("d=%f");
    return 0;
}
