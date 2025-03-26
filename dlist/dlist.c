#include "dlist.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

////////////////////////////////////////////////////////////////
///////////////////////Threshold 1//////////////////////////////
////////////////////////////////////////////////////////////////

struct dlist *dlist_init(void)
{
    struct dlist *res = malloc(sizeof(struct dlist));
    if (res == NULL)
        return NULL;
    res->size = 0;
    res->head = NULL;
    res->tail = NULL;
    return res;
}

int dlist_push_front(struct dlist *list, int element)
{
    if (element < 0)
    {
        assert(element < 0);
        return 0;
    }
    struct dlist_item *new = malloc(sizeof(struct dlist_item));
    if (new == NULL)
        return 0;
    new->data = element;
    if (list->head == NULL && list->tail == NULL)
    {
        list->head = new;
        list->tail = new;
        new->next = NULL;
        new->prev = NULL;
        list->size++;
    }
    else
    {
        new->prev = NULL;
        new->next = list->head;
        list->head = new;
        new->next->prev = new;
        list->size++;
    }
    return 1;
}

void dlist_print(const struct dlist *list)
{
    if (list->size == 0)
        return;

    struct dlist_item *p = list->head;
    while (p != NULL)
    {
        printf("%d\n", p->data);
        p = p->next;
    }
}

int dlist_push_back(struct dlist *list, int element)
{
    if (element < 0)
    {
        assert(element < 0);
        return 0;
    }
    struct dlist_item *new = malloc(sizeof(struct dlist_item));
    if (new == NULL)
        return 0;
    new->data = element;

    if (list->head == NULL && list->tail == NULL)
    {
        list->head = new;
        list->tail = new;
        new->next = NULL;
        new->prev = NULL;
        list->size++;
    }
    else
    {
        new->prev = list->tail;
        list->tail->next = new;
        new->next = NULL;
        list->tail = new;
        list->size++;
    }
    return 1;
}

size_t dlist_size(const struct dlist *list)
{
    return list->size;
}

////////////////////////////////////////////////////////////////
///////////////////////Threshold 2//////////////////////////////
////////////////////////////////////////////////////////////////

int dlist_get(const struct dlist *list, size_t index)
{
    if (index >= list->size || list->size == 0)
        return -1;
    struct dlist_item *p = list->head;
    while (p != NULL)
    {
        if (index == 0)
            return p->data;
        p = p->next;
        index--;
    }
    return -1;
}

int dlist_insert_at(struct dlist *list, int element, size_t index)
{
    if (index > list->size)
        return 0;
    if (element < 0)
    {
        assert(element < 0);
        return 0;
    }

    if (index == 0)
        return dlist_push_front(list, element);

    if (index == list->size)
        return dlist_push_back(list, element);

    struct dlist_item *p = list->head;
    while (p != NULL && index > 0)
    {
        p = p->next;
        index--;
    }
    if (p != NULL)
    {
        struct dlist_item *new = malloc(sizeof(struct dlist_item));
        if (new == NULL)
            return 0;
        new->data = element;
        new->prev = p->prev;
        new->next = p;

        if (p->prev != NULL)
            p->prev->next = new;

        p->prev = new;

        list->size++;
        return 1;
    }
    return 0;
}

int dlist_find(const struct dlist *list, int element)
{
    if (element < 0)
        return -1;
    int index = 0;
    struct dlist_item *p = list->head;
    while (p != NULL)
    {
        if (p->data == element)
            return index;
        p = p->next;
        index++;
    }
    return -1;
}

static int remove_tail(struct dlist *list, struct dlist_item *p)
{
    int value = p->data;
    list->tail = p->prev;
    p->prev->next = NULL;
    free(p);
    list->size--;
    return value;
}

static int remove_head(struct dlist *list, struct dlist_item *p)
{
    int value = p->data;
    list->head = p->next;
    p->next->prev = NULL;
    free(p);
    list->size--;
    return value;
}

int dlist_remove_at(struct dlist *list, size_t index)
{
    if (index >= list->size || list->size == 0)
        return -1;
    struct dlist_item *p = list->head;
    while (p != NULL)
    {
        if (index == 0)
        {
            int value = p->data;
            /////////////////un seul element/////////
            if (p->next == NULL && p->prev == NULL)
            {
                list->head = NULL;
                list->tail = NULL;
                free(p);
                list->size = 0;
                return value;
            }
            /////////////tail////////
            if (p->next == NULL)
                return remove_tail(list, p);

            ////////////head/////////
            if (p->prev == NULL)
                return remove_head(list, p);
            ////////////autre cas////////////////

            p->next->prev = p->prev;
            p->prev->next = p->next;
            free(p);
            list->size--;
            return value;
        }

        p = p->next;
        index--;
    }
    return -1;
}

void dlist_clear(struct dlist *list)
{
    if (list->size == 0)
        return;
    if (list->size == 1)
    {
        free(list->head);
        list->size--;
        list->head = NULL;
        list->tail = NULL;
        return;
    }
    struct dlist_item *p = list->head;
    struct dlist_item *temp = p;
    p = p->next;
    p->prev = temp;
    while (p->next != NULL)
    {
        free(p->prev);
        list->size--;
        struct dlist_item *temp2 = p;
        p = p->next;
        p->prev = temp2;
    }
    free(p->prev);
    list->size--;
    free(p);
    list->size--;
    list->head = NULL;
    list->tail = NULL;
}
