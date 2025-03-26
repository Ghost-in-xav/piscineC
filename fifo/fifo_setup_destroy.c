
#include <stddef.h>
#include <stdlib.h>

#include "fifo.h"

struct fifo *fifo_init(void)
{
    struct fifo *res = malloc(sizeof(struct fifo));
    res->head = NULL;
    res->tail = NULL;
    res->size = 0;
    return res;
}

void fifo_clear(struct fifo *fifo)
{
    if (fifo->head == NULL)
        return;

    struct list *p = fifo->head;

    while (p != fifo->tail)
    {
        struct list *p1 = p->next;
        free(p);
        p = p1;
    }
    free(fifo->tail);
    fifo->size = 0;
    fifo->head = NULL;
    fifo->tail = NULL;
}

void fifo_destroy(struct fifo *fifo)
{
    if (fifo->size != 0)
        fifo_clear(fifo);
    free(fifo);
}
