#include <stdio.h>

/*
    Scrivere una funzione ricorsiva riceva in ingresso un intero N e che ritorni
    il valore dell’N-esimo elemento della successione di Fibonacci.
    L'n-esimo elemento della successione di Fibonacci è definito come:
        - 0 se i=0;
        - 1 se i=1;
        - F(n-1)+F(n-2) se i>1.
*/


/* Soluzione svolte a lezioni */
int fib (int n)
{
    if (n==0) 
        return 0;
    if (n==1) 
        return 1;
    return fib(n-1) + fib(n-2);
}

int F (int n)
{
  if (n==0) return 0;
  if (n==1) return 1;
  return F(n-1) + F(n-2);
}


int main(void) 
{
    int n = 12;
    printf("fib:%d\n", fib(n));
    printf("fib:%d\n", F(n));
}
