#include "array_max_min.h"

void array_max_min(int tab[], size_t len, int *max, int *min)
{
    if (tab == NULL || len == 0)
        return;
    *min = tab[0];
    *max = tab[0];
    for (size_t i = 0; i < len; i++)
    {
        if (tab[i] > *max)
            *max = tab[i];
        if (tab[i] < *min)
            *min = tab[i];
    }
}
/*
#include <stdio.h>

int main(void)
{
    int max = 0;
    int min = 0;
    int tab[] = { 100, 3, 1, 42, 53, 3, 200 };
    size_t len = 7;
    array_max_min(tab, len, &max, &min);
    printf("max : %d\n", max);
    printf("min : %d\n", min);
    return 0;
}
*/
