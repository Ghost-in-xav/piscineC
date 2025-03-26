#include "my_calloc.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void *my_calloc(size_t n, size_t size)
{
    unsigned char *arr = malloc(n * size);
    if (arr == NULL)
        return NULL;
    for (size_t i = 0; i < n * size; i++)
        arr[i] = 0;
    return arr;
}
