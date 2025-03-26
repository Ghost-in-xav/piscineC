#include "insertion_sort.h"

#include <stdio.h>
#include <stdlib.h>

int leny(void **array)
{
    int res = 0;
    for (int i = 0; array[i] != NULL; i++)
        res++;
    return res;
}

void insertion_sort(void **array, f_cmp comp)
{
    int taille = leny(array);
    for (int i = 1; i < taille; i++)
    {
        char *curr = array[i];
        int j = i;
        // while dans lequel tout est decaler d un cran
        while (j > 0 && comp(array[j - 1], curr) > 0)
        {
            array[j] = array[j - 1];
            j--;
        }
        array[j] = curr;
    }
}
