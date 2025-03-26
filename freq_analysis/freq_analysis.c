// #include "freq_analysis.h"

#include <stdio.h>

struct association
{
    char letter;
    char assoc;
};

int maxy(int buffer[])
{
    int max = buffer[0];
    int indice_max = 0;
    for (int i = 0; i < 26; i++)
    {
        if (buffer[i] > max)
        {
            max = buffer[i];
            indice_max = i;
        }
    }
    buffer[indice_max] = 0;
    return indice_max;
}

void freq_analysis(const char text[], const char table[])
{
    int buffer[26] = { 0 }; // initialisation du buffer
    int len = 0;
    // remplissage du buffer avec les occurences
    for (int i = 0; text[i] != '\0'; i++)
        buffer[text[i] - 'A'] += 1;

    // obtention longueur table
    for (int i = 0; table[i] != '\0'; i++)
        len++;
    // parcours buffer association pour initialiser les lettre et la valeur
    // default de l assoc
    struct association assoc_table[26];
    for (int i = 0; i < 26; i++)
    {
        assoc_table[i].letter = i + 'A';
        assoc_table[i].assoc = '\0';
    }

    // remplissace des vrais association
    for (int i = 0; i < len; i++)
    {
        int max = maxy(buffer);
        assoc_table[max].assoc = table[i];
    }

    for (int i = 0; i < 26; i++)
    {
        if (assoc_table[i].assoc != '\0')
            printf("%c %c\n", assoc_table[i].letter, assoc_table[i].assoc);
    }
}
