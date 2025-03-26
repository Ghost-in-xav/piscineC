#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "fifo.h"

size_t fifo_size(struct fifo *fifo)
{
    return fifo->size;
}

void fifo_push(struct fifo *fifo, int elt)
{
    struct list *new = malloc(sizeof(struct list));
    new->data = elt;
    new->next = NULL;
    if (fifo_size(fifo) == 0)
    {
        fifo->head = new;
        fifo->tail = new;
    }
    else
    {
        fifo->tail->next = new;
        fifo->tail = new;
    }
    fifo->size += 1;
}

int fifo_head(struct fifo *fifo)
{
    return fifo->head->data;
}

void fifo_pop(struct fifo *fifo)
{
    if (fifo->head == NULL)
        return;
    struct list *temp = fifo->head;
    fifo->head = temp->next;
    free(temp);
    fifo->size -= 1;
}

void fifo_print(const struct fifo *fifo)
{
    struct list *p = fifo->head;
    while (p != fifo->tail)
    {
        printf("%d\n", p->data);
        p = p->next;
    }
    printf("%d\n", p->data);
}
