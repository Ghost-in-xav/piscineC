#include "str_revert.h"

#include <stdio.h>

void swap(char str[], int i, int j)
{
    char temp = str[i];
    str[i] = str[j];
    str[j] = temp;
}

int longueur(char str[])
{
    int taille = 0;
    while (str[taille] != '\0')
        taille++;
    ;
    return taille;
}

void str_revert(char str[])
{
    int len = longueur(str);
    if (len == 0 || len == 1)
        return;
    for (int i = 0; i < len / 2; i++)
        swap(str, i, len - i - 1);
}
