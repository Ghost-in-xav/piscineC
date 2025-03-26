#include "levenshtein.h"

#include <stdio.h>
#include <stdlib.h>

size_t my_min(size_t a, size_t b)
{
    return a = (a > b) ? b : a;
}

size_t my_strlen(const char *s)
{
    size_t res = 0;
    while (*s != '\0')
    {
        res++;
        s++;
    }
    return res;
}

size_t chapeau_levenshtein(size_t **mat, const char *s1, const char *s2,
                           size_t lens1)
{
    size_t lens2 = my_strlen(s2);

    if (mat == NULL)
        return 69;

    mat[0][0] = 0;

    for (size_t i = 0; i < lens1 + 1; i++)
        mat[i][0] = i;

    for (size_t j = 0; j < lens2 + 1; j++)
        mat[0][j] = j;

    for (size_t i = 1; i < lens1 + 1; i++)
        for (size_t j = 1; j < lens2 + 1; j++)
        {
            mat[i][j] = my_min(
                mat[i - 1][j] + 1,
                my_min(mat[i][j - 1] + 1,
                       mat[i - 1][j - 1] + ((s1[i - 1] == s2[j - 1]) ? 0 : 1)));
        }

    return (mat[lens1][lens2]);
}

size_t levenshtein(const char *s1, const char *s2)
{
    size_t lens1 = my_strlen(s1);
    size_t lens2 = my_strlen(s2);

    size_t **mat = malloc((lens1 + 1) * sizeof(size_t *));
    for (size_t i = 0; i < lens1 + 1; i++)
        mat[i] = malloc((lens2 + 1) * sizeof(size_t));

    for (size_t i = 0; i < lens1 + 1; i++)
        for (size_t j = 0; j < lens2 + 1; j++)
            mat[i][j] = 0;

    size_t res = chapeau_levenshtein(mat, s1, s2, lens1);
    for (size_t i = 0; i < lens1 + 1; i++)
        free(mat[i]);
    free(mat);

    return res;
}
/*
int main(void)
{
    const char *mot2 = "doom";
    const char *mot1 = "tools";
    printf("%ld\n", levenshtein(mot1, mot2));
    return 0;
}
*/
