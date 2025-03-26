
#include "hash_map.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct hash_map *hash_map_init(size_t size)
{
    if (size == 0)
        return NULL;
    struct hash_map *res = malloc(sizeof(struct hash_map));
    if (res == NULL)
        return NULL;
    res->data = calloc(size, sizeof(struct pair_list *));
    res->size = size;
    return res;
}

bool deja_present(struct hash_map *hash_map, const char *key, char *value,
                  bool *updated)
{
    size_t index = hash(key) % hash_map->size;
    struct pair_list *p = hash_map->data[index];
    while (p != NULL && p->key != NULL)
    {
        if (strcmp(p->key, key) == 0)
        {
            p->value = value;
            *updated = true;
            return true;
        }
        p = p->next;
    }
    return false;
}

bool hash_map_insert(struct hash_map *hash_map, const char *key, char *value,
                     bool *updated)
{
    if (hash_map != NULL && hash_map->size != 0)
    {
        size_t index = hash(key) % hash_map->size;
        // Sideja present
        if (deja_present(hash_map, key, value, updated))
            return true;

        struct pair_list *place = malloc(sizeof(struct pair_list));
        if (place == NULL)
            return false;

        place->key = key;
        place->value = value;
        place->next = hash_map->data[index];
        hash_map->data[index] = place;
        *updated = false;
        return true;
    }
    return false;
}

void hash_map_free(struct hash_map *hash_map)
{
    if (hash_map != NULL)
    {
        for (size_t i = 0; i < hash_map->size; i++)
        {
            struct pair_list *p = hash_map->data[i];
            while (p != NULL)
            {
                struct pair_list *temp = p->next;
                free(p);
                p = temp;
            }
        }
        free(hash_map->data);
        free(hash_map);
    }
}

void hash_map_dump(struct hash_map *hash_map)
{
    if (hash_map != NULL)
    {
        for (size_t i = 0; i < hash_map->size; i++)
        {
            struct pair_list *p = hash_map->data[i];
            while (p != NULL)
            {
                if (p->next == NULL)
                    printf("%s: %s", p->key, p->value);
                else
                    printf("%s: %s, ", p->key, p->value);
                p = p->next;
            }
            printf("\n");
        }
    }
}

const char *hash_map_get(const struct hash_map *hash_map, const char *key)
{
    if (hash_map != NULL && hash_map->size != 0 && key != NULL)
    {
        size_t index = hash(key) % hash_map->size;
        struct pair_list *place = hash_map->data[index];
        while (place != NULL)
        {
            if (strcmp(place->key, key) == 0)
                return place->value;
            place = place->next;
        }
    }

    return NULL;
}

bool hash_map_remove(struct hash_map *hash_map, const char *key)
{
    if (hash_map == NULL || key == NULL || hash_map->size == 0)
        return false;

    size_t index = hash(key) % hash_map->size;
    struct pair_list *p = hash_map->data[index];
    struct pair_list *prev = p;
    if (p != NULL && strcmp(p->key, key) == 0)
    {
        hash_map->data[index] = p->next;
        free(p);
        return true;
    }
    while (p != NULL)
    {
        if (strcmp(p->key, key) == 0)
        {
            prev->next = p->next;
            free(p);
            return true;
        }
        prev = p;
        p = p->next;
    }
    return false;
}
