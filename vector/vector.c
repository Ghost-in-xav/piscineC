#include "vector.h"

#include <stdio.h>
#include <stdlib.h>

struct vector *vector_init(size_t n)
{
    struct vector *res = malloc(sizeof(struct vector));
    if (res == NULL)
        NULL;
    res->data = malloc(n * sizeof(int));
    if (res->data == NULL)
        return NULL;
    res->capacity = n;
    res->size = 0;
    return res;
}

void vector_destroy(struct vector *v)
{
    if (v != NULL)
    {
        free(v->data);
        free(v);
    }
}

struct vector *vector_resize(struct vector *v, size_t n)
{
    if (v != NULL)
    {
        if (n < v->size)
        {
            int *temp = calloc(n, n * sizeof(int));
            if (temp == NULL)
                return NULL;
            for (size_t i = 0; i < n; i++)
                temp[i] = v->data[i];
            free(v->data);
            v->data = temp;
            v->capacity = n;
            v->size = n;
        }
        else if (n > v->size)
        {
            int *temp = realloc(v->data, n * sizeof(int));
            if (temp == NULL)
                return NULL;
            v->data = temp;
            v->capacity = n;
        }
    }
    return v;
}

struct vector *vector_append(struct vector *v, int elt)
{
    if (v != NULL)
    {
        if (v->size == v->capacity)
            v = vector_resize(v, v->capacity * 2);
        v->data[v->size] = elt;
        v->size++;
    }

    return v;
}

void vector_print(const struct vector *v)
{
    if (v != NULL && v->size != 0)
    {
        for (size_t i = 0; i < v->size - 1; i++)
            printf("%d,", v->data[i]);
        printf("%d", v->data[v->size - 1]);
    }
    putchar('\n');
}

struct vector *vector_reset(struct vector *v, size_t n)
{
    if (v != NULL)
    {
        vector_destroy(v);
        return vector_init(n);
    }
    return NULL;
}

struct vector *vector_insert(struct vector *v, size_t i, int elt)
{
    if (v != NULL && i <= v->capacity)
    {
        if (v->size == v->capacity)
            v = vector_resize(v, v->capacity * 2);

        for (size_t j = v->size; j > i; j--)
        {
            v->data[j] = v->data[j - 1];
        }
        v->data[i] = elt;
        v->size++;
        return v;
    }
    return NULL;
}

struct vector *vector_remove(struct vector *v, size_t i)
{
    if (v != NULL && i <= v->capacity)
    {
        for (size_t j = i; j < v->size - 1; j++)
        {
            v->data[j] = v->data[j + 1];
        }
        v->size--;
        if (v->size < v->capacity / 2)
        {
            v = vector_resize(v, v->capacity / 2);
        }
        return v;
    }
    return NULL;
}
