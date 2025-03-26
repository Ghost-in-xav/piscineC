#include <criterion/criterion.h>
#include <stdio.h>

#include "./../src/tinyprintf.h"

Test(Basics, test)
{
    int res =
        tinyprintf("Affiche une chaine de caractere et encore une autre et "
                   "encore une autre, une petite dernier %s\n",
                   NULL);
    printf("res = %d\n", res);
    tinyprintf("%s [%x] %s", "Hello", 42, "world!");
    tinyprintf("%%s", "in your head");
    tinyprintf("Good morning ACOUILLE! %t Tinyprintf is cool", 12);
    tinyprintf("%c%c is %s... %d too.", '4', '2', "the answer", '*');
    tinyprintf("%s [%o] [%x] %c", "Hello", 42, 42, 88);
    tinyprintf("%s [%o] [%x] %c", NULL, 42, 42, 88);
    tinyprintf("%s [%u] [%x] %c", "Hello", -42, 42);
    tinyprintf("%s [%u] [%] %", "Hello", 42, 42);
    char *s = malloc(3 * sizeof(char));
    printf("pren le ton coverage de mort : %s\n", my_itoa(-1, s));
    free(s);
    char *s2 = malloc(3 * sizeof(char));
    printf("pren le ton coverage de mort : %s\n", my_itoa(0, s2));
    free(s2);

    char *s3 = malloc(3 * sizeof(char));
    printf("pren le ton coverage de mort : %s\n",
           my_itoa_base(0, s3, "0123456789"));
    free(s3);

    char *s4 = malloc(6 * sizeof(char));
    printf("pren le ton coverage de mort : %s\n",
           my_itoa_base(-10, s4, "01234"));
    free(s4);
}
