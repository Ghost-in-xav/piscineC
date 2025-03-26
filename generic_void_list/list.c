#include "list.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct list *list_prepend(struct list *list, const void *value,
                          size_t data_size)
{
    struct list *res = malloc(sizeof(struct list));
    if (data_size == 0)
        res->data = NULL;
    else
    {
        res->data = malloc(data_size * sizeof(void *));
        if (res->data == NULL)
            return NULL;
        memcpy(res->data, value, data_size);
    }
    res->next = list;
    return res;
}

size_t list_length(struct list *list)
{
    size_t res = 0;
    struct list *p = list;
    while (p != NULL)
    {
        res++;
        p = p->next;
    }
    return res;
}

void list_destroy(struct list *list)
{
    if (list == NULL)
        return;

    struct list *previous = list;
    free(previous->data);
    list = list->next;
    while (list != NULL)
    {
        free(list->data);
        free(previous);
        previous = list;
        list = list->next;
    }
    free(previous);
}
