#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "dlist.h"

////////////////////////////////////////////////////////////////
///////////////////////Threshold 3//////////////////////////////
////////////////////////////////////////////////////////////////

void dlist_map_square(struct dlist *list)
{
    struct dlist_item *p = list->head;
    while (p != NULL)
    {
        p->data *= p->data;
        p = p->next;
    }
}

void dlist_reverse(struct dlist *list)
{
    struct dlist_item *start = list->head;
    struct dlist_item *end = list->tail;
    size_t startindex = 0;
    size_t endindex = list->size - 1;

    while (startindex < endindex)
    {
        int temp = start->data;
        start->data = end->data;
        end->data = temp;

        start = start->next;
        end = end->prev;
        startindex++;
        endindex--;
    }
}

struct dlist *dlist_split_at(struct dlist *list, size_t index)
{
    if (list->size == 0)
    {
        return dlist_init();
    }

    if (index >= list->size)
        return NULL;

    struct dlist *res = dlist_init();
    size_t count = 0;
    struct dlist_item *p = list->head;
    while (p != NULL)
    {
        if (count + 1 == index)
            break;
        p = p->next;
        count++;
    }

    while (list->tail != p)
    {
        int data_temp = dlist_get(list, list->size - 1);
        dlist_push_front(res, data_temp);
        int done = dlist_remove_at(list, list->size - 1);
        if (done == -1)
            return NULL;
    }

    return res;
}

void dlist_concat(struct dlist *list1, struct dlist *list2)
{
    while (list2->size > 0)
    {
        int res = dlist_get(list2, 0);
        dlist_remove_at(list2, 0);
        dlist_push_back(list1, res);
    }
}

////////////////////////////////////////////////////////////////
///////////////////////Threshold 4//////////////////////////////
////////////////////////////////////////////////////////////////

static int my_min(int a, int b)
{
    return a = (a > b) ? b : a;
}

static size_t chapeau_levenshtein(size_t **mat, const struct dlist *s1,
                                  const struct dlist *s2)
{
    size_t lens1 = s1->size;
    size_t lens2 = s2->size;

    if (mat == NULL)
        return 69;

    mat[0][0] = 0;

    for (size_t i = 0; i < lens1 + 1; i++)
        mat[i][0] = i;

    for (size_t j = 0; j < lens2 + 1; j++)
        mat[0][j] = j;

    for (size_t i = 1; i < lens1 + 1; i++)
        for (size_t j = 1; j < lens2 + 1; j++)
        {
            mat[i][j] = my_min(
                mat[i - 1][j] + 1,
                my_min(mat[i][j - 1] + 1,
                       mat[i - 1][j - 1]
                           + (dlist_get(s1, i - 1) == dlist_get(s2, j - 1)
                                  ? 0
                                  : 1)));
        }

    return (mat[lens1][lens2]);
}

unsigned int dlist_levenshtein(const struct dlist *list1,
                               const struct dlist *list2)
{
    size_t lens1 = list1->size;
    size_t lens2 = list2->size;

    size_t **mat = malloc((lens1 + 1) * sizeof(size_t *));
    for (size_t i = 0; i < lens1 + 1; i++)
        mat[i] = malloc((lens2 + 1) * sizeof(size_t));

    for (size_t i = 0; i < lens1 + 1; i++)
        for (size_t j = 0; j < lens2 + 1; j++)
            mat[i][j] = 0;

    size_t res = chapeau_levenshtein(mat, list1, list2);
    for (size_t i = 0; i < lens1 + 1; i++)
        free(mat[i]);
    free(mat);

    return res;
}
