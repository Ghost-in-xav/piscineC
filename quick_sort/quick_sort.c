
#include <stddef.h>
#include <stdio.h>

// classic swap
void swap(int *tab, int a, int b)
{
    int temp = tab[a];
    tab[a] = tab[b];
    tab[b] = temp;
}

void quicksort(int *tab, int len)
{
    if (len <= 1 || tab == NULL)
        return;

    // ont prend le dernier chiffre de l array
    int pivot = tab[len - 1];
    int i = 0;
    int index = len - 1;
    int *p = tab;

    for (int j = 0; j < len - 1; j++)
    {
        if (tab[j] < pivot)
        {
            swap(tab, i, j);
            i++;
        }
    }

    swap(tab, i, len - 1);
    index = i;
    // pointeur au niveau du pivot
    for (int j = 0; j < index + 1; j++)
        p++;
    // la on a le pivot et on vas donc regarder a droite et a gauche

    // gauche
    quicksort(tab, index);
    // droite
    quicksort(p, len - index - 1);
}
