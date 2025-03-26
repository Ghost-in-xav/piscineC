#include <stdio.h>
#include <stdlib.h>

#include "heap.h"

void print_heap_rec(const struct heap *heap, size_t i)
{
    if (i == 0)
        printf("%d", heap->array[i]);
    else
        printf(" %d", heap->array[i]);
    if (2 * i + 1 < heap->size)
        print_heap_rec(heap, 2 * i + 1);
    if (2 * i + 2 < heap->size)
        print_heap_rec(heap, 2 * i + 2);
}

void print_heap(const struct heap *heap)
{
    print_heap_rec(heap, 0);
    putchar('\n');
}
