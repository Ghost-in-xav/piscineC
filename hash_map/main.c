#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hash_map.h"

int main(void)
{
    // Initialize hash map with a size of 10
    struct hash_map *map = hash_map_init(10);
    if (!map)
    {
        fprintf(stderr, "Failed to initialize hash map.\n");
        return 1;
    }

    // Insert values
    bool updated;
    //  if (hash_map_insert(map, "key1", "grec", &updated))
    //  printf("Inserted key1: grec\n");

    // if (hash_map_insert(map, "key1", "pieton", &updated))
    //     printf("Inserted key1: pieton\n");

    // if (hash_map_insert(map, "key2", "écrémé", &updated))
    //  printf("Inserted key2: écrémé\n");

    if (hash_map_insert(map, "key3", "sublime", &updated))
        printf("Inserted key3: sublime\n");

    if (hash_map_insert(map, "key4", "patriarche", &updated))
        printf("Inserted key4: patriarche\n");

    if (hash_map_insert(map, "key6", "defenseur", &updated))
        printf("Inserted key6: defenseur\n");

    if (hash_map_insert(map, "key7", "le S", &updated))
        printf("Inserted key7: le\n");

    if (hash_map_insert(map, "key8", "l'ordre", &updated))
        printf("Inserted key8: l'ordre\n");

    if (hash_map_insert(map, "key10", "grec", &updated))
        printf("Inserted key10: grec\n");

    if (hash_map_insert(map, "key11", "elpueblo", &updated))
        printf("Inserted key11: elpueblo\n");

    if (hash_map_insert(map, "key12", "tchikita", &updated))
        printf("Inserted key12: tchikita\n");

    printf("Dumping hash map:\n");
    hash_map_dump(map);

    // Try to retrieve values
    const char *value = hash_map_get(map, "key1");
    if (value)
        printf("Retrieved key1: %s\n", value);
    else
        printf("key1 not found\n");

    value = hash_map_get(map, "key2");
    if (value)
        printf("Retrieved key2: %s\n", value);
    else
        printf("key2 not found\n");

    printf("Dumping hash map:\n");
    hash_map_dump(map);

    // Remove key2
    if (hash_map_remove(map, "key10"))
        printf("Removed key10\n");
    if (hash_map_remove(map, "key11"))
        printf("Removed key11\n");
    if (hash_map_remove(map, "key12"))
        printf("Removed key12\n");
    if (hash_map_remove(map, "key3"))
        printf("Removed key3\n");
    if (hash_map_remove(map, "key4"))
        printf("Removed key4\n");
    if (hash_map_remove(map, "key6"))
        printf("Removed key6\n");
    if (hash_map_remove(map, "key7"))
        printf("Removed key7\n");
    if (hash_map_remove(map, "key8"))
        printf("Removed key8\n");

    value = hash_map_get(map, "key10");
    if (value)
        printf("key10 still exists: %s\n", value);
    else
        printf("key10 not found after removal\n");

    // Dump all values
    printf("Dumping hash map:\n");
    hash_map_dump(map);

    // Free hash map
    hash_map_free(map);

    return 0;
}
