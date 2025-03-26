#include "my_c_tail.h"

#include <stdio.h>
#include <unistd.h>

void stdintail(unsigned int n)
{
    if (n <= 0)
        return;
    unsigned int nb_ligne = 0;
    char buffer[50000];
    int taille = read(STDIN_FILENO, buffer, 50000);
    for (int i = 0; i < taille; i++)
    {
        if (buffer[i] == '\n')
            nb_ligne++;
    }
    if (nb_ligne <= n)
        write(STDOUT_FILENO, buffer, taille);
    else
    {
        char res[50000] = { '\0' };
        int compt = 0;
        for (int i = 0; i < taille; i++)
        {
            if (buffer[i] == '\n')
                nb_ligne--;
            if (nb_ligne == n)
            {
                for (int j = i + 1; j < taille; j++)
                {
                    res[compt] = buffer[j];
                    compt++;
                }
                break;
            }
        }
        write(STDOUT_FILENO, res, compt);
    }
}
