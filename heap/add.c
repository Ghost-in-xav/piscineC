#include <stdio.h>
#include <stdlib.h>

#include "heap.h"

void swap(int *tab, size_t a, size_t b)
{
    int temp = tab[a];
    tab[a] = tab[b];
    tab[b] = temp;
}

void a_ta_place(struct heap *heap, size_t i)
{
    while (i > 0 && heap->array[i] > heap->array[(i - 1) / 2])
    {
        swap(heap->array, i, (i - 1) / 2);
        i = (i - 1) / 2;
    }
}

void add(struct heap *heap, int val)
{
    if (heap->size == heap->capacity)
    {
        heap->capacity = heap->capacity * 2;
        heap->array = realloc(heap->array, heap->capacity * sizeof(int));
    }

    heap->array[heap->size] = val;
    heap->size++;
    a_ta_place(heap, heap->size - 1);
}
