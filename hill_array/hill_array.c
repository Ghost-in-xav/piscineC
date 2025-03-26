#include "hill_array.h"

int top_of_the_hill(int tab[], size_t len)
{
    if (len == 0)
        return -1;

    int top = tab[0];
    size_t ind = 0;
    int check = tab[0];
    size_t comp = 0;
    while (comp < len)
    {
        if (tab[comp] < 0)
            return -1;
        if (tab[comp] > check && tab[comp] > top)
        {
            top = tab[comp];
            ind = comp;
            check = tab[comp];
        }
        else if (tab[comp] > check && tab[comp] < top)
            return -1;
        else if (tab[comp] < check)
            check = tab[comp];

        comp++;
    }
    return ind;
}

/*
#include <stddef.h>
#include <stdio.h>
int main(void)
{
    int tab1[] = { 1, 2, 3, 4, 6, 6, 4, 2, 0, -1 }; // Valid hill.
    printf("%d\n", top_of_the_hill(tab1, 10));
    int tab2[] = { 1, 2, 3, 4, 5, 6, 6, 6, 6, 6 }; // Valid hill.
    printf("%d\n", top_of_the_hill(tab2, 10));
    int tab3[] = { 1, 2, 3, 4, 6, 6, 4, 5, 0, 0 }; // Invalid hill.
    printf("%d\n", top_of_the_hill(tab3, 10));
    return 0;
}

*/
