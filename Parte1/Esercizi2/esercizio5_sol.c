#include <stdio.h>

/*
    Scrivere una funzione che riceva in ingresso il prezzo iniziale di un articolo (di tipo float) e
    il valore percentuale di sconto (di tipo int), e restituisca il prezzo scontato.
*/

float prezzo_scontato(float prezzo_iniziale, int sconto)
{
    double prezzo_sconto = prezzo_iniziale * sconto / 100;
    double prezzo_finale = prezzo_iniziale - prezzo_sconto;
    return prezzo_finale;
}

int main()
{
    float prezzo_iniz = 100;
    int sconto = 20;

    float prezzo_fin = prezzo_scontato(prezzo_iniz, sconto);

    printf("Prezzo finale: %f\n", prezzo_fin);
    return 0;
}