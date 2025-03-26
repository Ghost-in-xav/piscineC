#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "bigpointh.h"

int stackchar_len(struct stackchar *s)
{
    int res = 0;
    struct stackchar *p = s;
    while (p != NULL)
    {
        p = p->next;
        res++;
    }
    return res;
}

struct stackchar *stackchar_push(struct stackchar *s, char e)
{
    struct stackchar *res = malloc(sizeof(struct stackchar));
    res->data = e;
    if (s == NULL)
    {
        res->next = NULL;
        return res;
    }
    res->next = s;
    return res;
}

struct stackchar *stackchar_pop(struct stackchar *s)
{
    if (s == NULL)
        return NULL;
    struct stackchar *previous = s;
    s = s->next;
    free(previous);
    return s;
}

char stackchar_peek(struct stackchar *s)
{
    return s->data;
}
