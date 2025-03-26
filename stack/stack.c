#include "stack.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

struct stack *stack_push(struct stack *s, int e)
{
    struct stack *res = malloc(sizeof(struct stack));
    res->data = e;
    if (s == NULL)
    {
        res->next = NULL;
        return res;
    }
    res->next = s;
    return res;
}

struct stack *stack_pop(struct stack *s)
{
    if (s == NULL)
        return NULL;
    struct stack *previous = s;
    s = s->next;
    free(previous);
    return s;
}

int stack_peek(struct stack *s)
{
    return s->data;
}
