
#include "null_terminated_arrays.h"

#include <stddef.h>
#include <stdio.h>

void reverse_array(const char **arr)
{
    const char **end = arr;
    const char **start = arr;

    // placement du pointeur sur null
    while (*end != NULL)
        end++;
    // placement du pointer sur le dernier string
    end--;

    // tant que tout le tableau n as pas ete parcouru
    while (start < end)
    {
        // SWAP des string dans les pointeurs
        const char *temp = *start;
        *start = *end;
        *end = temp;

        // incrementation des pointeurs
        start++;
        end--;
    }
}

void reverse_matrix(const char ***matrix)
{
    for (int i = 0; matrix[i] != NULL; i++)
        reverse_array(matrix[i]);

    const char ***end = matrix;
    const char ***start = matrix;

    // placement du pointeur sur null
    while (*end != NULL)
        end++;
    // placement du pointer sur le dernier string
    end--;

    // tant que tout le tableau n as pas ete parcouru
    while (start < end)
    {
        // SWAP des string dans les pointeurs
        const char **temp = *start;
        *start = *end;
        *end = temp;

        // incrementation des pointeurs
        start++;
        end--;
    }
}
/*
void print_matrix(const char ***matrix)
{
    for (int i = 0; matrix[i] != NULL; i++)
    {
        const char **arr = matrix[i];
        for (int j = 0; arr[j] != NULL; j++)
        {
            printf("%s ", arr[j]);
        }
        printf("\n");
    }
}

#include <stdlib.h>
int main()
{

    const char *matrix_data[][4] = { { "1", "2", "3", NULL },
                                     { "4", "5","6", NULL },
                                     { "6", "7", "8", NULL },
                                     {NULL} };

    const char ***matrix=malloc(sizeof(char**)*sizeof(char*));
    for (int i = 0; i < 3; i++)
    {
        matrix[i] = (const char **)matrix_data[i];
    }
    matrix[3] = NULL;

    printf(" de base:\n");
    print_matrix((const char ***)matrix);

    reverse_matrix((const char ***)matrix);

    printf("\napres \n");
    print_matrix((const char ***)matrix);

    return 0;
}
*/
