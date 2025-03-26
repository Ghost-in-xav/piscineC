#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void sieve(int n)
{
    int number_primes = 0;
    if (n <= 2)
        return;
    int *tab = malloc(n * sizeof(int));
    if (tab == NULL)
        return;
    for (int i = 2; i < n; i++)
    {
        if (i % 2 == 0)
            tab[i] = 0;
        else
            tab[i] = 1;
    }
    tab[0] = 0;
    tab[1] = 0;
    tab[2] = 1;
    int i = 3;
    while (i * i < n)
    {
        if (tab[i] == 1)
        {
            for (int j = i * i; j < n; j += 2 * i)
                tab[j] = 0;
        }
        i += 1;
    }
    for (int i = 0; i < n; i++)
    {
        if (tab[i] == 1)
            number_primes += 1;
    }
    free(tab);
    printf("%d\n", number_primes);
}
/*
int main(void)
{
  sieve(2);
  return 0;
}

*/
