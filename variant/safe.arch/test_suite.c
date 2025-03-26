#include <criterion/criterion.h>
#include <stdio.h>

#include "variant.h"

Test(VariantSum, test_variant_sum)
{
    // Cas 1: Tableau avec un seul élément
    struct variant v1 = { TYPE_INT, { .int_v = 42 } };
    struct variant single_int_array[] = { v1 };
    float sum = variant_sum(single_int_array, 1);
    cr_assert(sum == 42.0f, "Test 1: Somme attendue: 42.0, Somme obtenue: %.2f",
              sum);

    // Cas 2: Tableau avec un seul élément
    struct variant v2 = { TYPE_FLOAT, { .float_v = 3.14f } };
    struct variant single_float_array[] = { v2 };
    sum = variant_sum(single_float_array, 1);
    cr_assert(sum == 3.14f, "Test 2: Somme attendue: 3.14, Somme obtenue: %.2f",
              sum);

    // Cas 3: Tableau avec plusieurs
    struct variant v3 = { TYPE_INT, { .int_v = 10 } };
    struct variant v4 = { TYPE_INT, { .int_v = 20 } };
    struct variant int_array[] = { v1, v3, v4 };
    sum = variant_sum(int_array, 3);
    cr_assert(sum == 42.0f + 10.0f + 20.0f,
              "Test 3: Somme attendue: 72.0, Somme obtenue: %.2f", sum);

    // Cas 4: Tableau avec plusieurs
    struct variant v5 = { TYPE_FLOAT, { .float_v = 2.71f } };
    struct variant float_array[] = { v2, v5 };
    sum = variant_sum(float_array, 2);
    cr_assert(sum == 3.14f + 2.71f,
              "Test 4: Somme attendue: 5.85, Somme obtenue: %.2f", sum);

    // Cas 5: Tableau avec mélange int et float
    struct variant mixed_array[] = { v1, v2, v3, v5 };
    sum = variant_sum(mixed_array, 4);
    cr_assert(sum == 42.0f + 3.14f + 10.0f + 2.71f,
              "Test 5: Somme attendue: 57.85, Somme obtenue: %.2f", sum);
    /*								 // Cas 6: Tableau vide
    struct variant empty_array[] = {}; sum = variant_sum(empty_array, 0);
    cr_assert(sum == 0.0f, "Test 6: Somme attendue: 0.0, Somme obtenue: %.2f",
    sum);
    */
    // Cas 7: Tableau avec uniquement des non-numériques (char, string)
    struct variant v6 = { TYPE_CHAR, { .char_v = 'A' } };
    struct variant v7 = { TYPE_STRING, { .str_v = "Hello" } };
    struct variant non_numeric_array[] = { v6, v7 };
    sum = variant_sum(non_numeric_array, 2);
    cr_assert(sum == 0.0f, "Test 7: Somme attendue: 0.0, Somme obtenue: %.2f",
              sum);

    // Cas 8: Tableau mélange non-numériques et numériques
    struct variant mixed_non_numeric_array[] = { v1, v6, v7, v5 };
    sum = variant_sum(mixed_non_numeric_array, 4);
    cr_assert(sum == 42.0f + 2.71f,
              "Test 8: Somme attendue: 44.71, Somme obtenue: %.2f", sum);

    // Cas 9: Tableau avec des doublons d'int
    struct variant v8 = { TYPE_INT, { .int_v = 42 } };
    struct variant int_duplicate_array[] = { v1, v8 };
    sum = variant_sum(int_duplicate_array, 2);
    cr_assert(sum == 42.0f + 42.0f,
              "Test 9: Somme attendue: 84.0, Somme obtenue: %.2f", sum);

    // Cas 10: Test half len et full len (cas moulinette)
    struct variant half_len_array[] = { v1, v2, v6 };
    struct variant full_len_array[] = { v1, v2, v3, v5, v6, v7 };
    sum = variant_sum(half_len_array, 3);
    cr_assert(sum == 42.0f + 3.14f,
              "Test 10a (half len): Somme attendue: 45.14, Somme obtenue: %.2f",
              sum);
    sum = variant_sum(full_len_array, 6);
    cr_assert(sum == 42.0f + 3.14f + 10.0f + 2.71f,
              "Test 10b (full len): Somme attendue: 57.85, Somme obtenue: %.2f",
              sum);
}

/*
Test(Basics, test)
{
    // Initialisation de quelques variants pour les tests
    struct variant v1 = { TYPE_INT, { .int_v = 42 } };
    struct variant v2 = { TYPE_FLOAT, { .float_v = 3.14f } };
    struct variant v3 = { TYPE_CHAR, { .char_v = 'A' } };
    struct variant v4 = { TYPE_STRING, { .str_v = "Hello, World!" } };
    struct variant v6 = { TYPE_STRING, { .str_v = "Hello, World!" } };

    struct variant array[] = { v1, v2, v3, v4 };

    // Test de la fonction variant_display
    printf("Test de variant_display:\n");
    variant_display(&v1);
    variant_display(&v2);
    variant_display(&v3);
    variant_display(&v4);

    // Test de la fonction variant_equal
    printf("\nTest de variant_equal:\n");
    struct variant v5 = { TYPE_INT, { .int_v = 42 } };
    printf("v1 et v5 sont-ils égaux ? %s\n",
           variant_equal(&v1, &v5) ? "Oui" : "Non");

    printf("v4 et v6 sont-ils égaux ? %s\n",
           variant_equal(&v4, &v6) ? "Oui" : "Non");

    // Test de la fonction variant_find
    printf("\nTest de variant_find:\n");
    union type_any search_value = { .int_v = 42 };
    int found_index = variant_find(array, 4, TYPE_INT, search_value);
    if (found_index >= 0)
    {
        printf("Valeur trouvée à l'index : %d\n", found_index);
    }
    else
    {
        printf("Valeur non trouvée.\n");
    }

    // Test de la fonction variant_sum
    printf("\nTest de variant_sum:\n");
    float sum = variant_sum(array, 4);
    printf("Somme des variants de type numérique : %.2f\n", sum);
}
*/
