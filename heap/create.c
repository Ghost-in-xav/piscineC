#include <stdlib.h>

#include "heap.h"

struct heap *create_heap(void)
{
    struct heap *res = malloc(sizeof(struct heap));
    if (res == NULL)
        return NULL;
    res->size = 0;
    res->capacity = 8;
    res->array = malloc(8 * sizeof(int));
    if (res->array == NULL)
        return NULL;
    return res;
}
