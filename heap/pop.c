#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "heap.h"

void swap2(int *tab, size_t a, size_t b)
{
    int temp = tab[a];
    tab[a] = tab[b];
    tab[b] = temp;
}

void a_ta_place2(struct heap *heap, size_t i)
{
    size_t fg = 2 * i + 1;
    size_t fd = 2 * i + 2;
    size_t max = i;

    if (fg < heap->size && heap->array[fg] > heap->array[max])
        max = fg;
    if (fd < heap->size && heap->array[fd] > heap->array[max])
        max = fd;

    if (max != i)
    {
        swap2(heap->array, i, max);
        a_ta_place2(heap, max);
    }
}

int pop(struct heap *heap)
{
    if (heap == NULL || heap->size == 0)
    {
        assert(heap->size == 0);
        assert(heap == NULL);
        return 0;
    }
    int res = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    heap->array[heap->size - 1] = -666;
    heap->size--;

    if (heap->size < (heap->capacity / 2) && (heap->capacity != 8))
    {
        heap->array = realloc(heap->array, (heap->capacity / 2) * sizeof(int));
        heap->capacity = heap->capacity / 2;
    }
    a_ta_place2(heap, 0);
    return res;
}
