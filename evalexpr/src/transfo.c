#include <ctype.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bigpointh.h"
#define CAPACITY 100

///////////////////////////////////////////////////////////////
////////////////////VERIFICATION EQUILIBRAGE///////////////////
///////////////////////////////////////////////////////////////

int Isequilibrer(char *input)
{
    int ouvert = 0;
    int fermer = 0;
    for (int i = 0; input[i] != '\0'; i++)
    {
        ouvert = (input[i] == '(') ? ouvert + 1 : ouvert;
        fermer = (input[i] == ')') ? fermer + 1 : fermer;
    }
    return (ouvert - fermer != 0) ? -1 : 1;
}

///////////////////////////////////////////////////////////////
/////////////// ///LOGIQUE DE PRIO DES OPE/////////////////////
///////////////////////////////////////////////////////////////

int Prioritylevel(char operateur)
{
    switch (operateur)
    {
    case '+':
        return 1;
    case '-':
        return 1;
    case '*':
        return 2;
    case '/':
        return 2;
    case '%':
        return 2;
    case '^':
        return 3;
    default:
        break;
    }
    return 0;
}

///////////////////////////////////////////////////////////////
////////////////////////TO STRING//////////////////////////////
///////////////////////////////////////////////////////////////

char *my_tostring(char c)
{
    char *str = malloc(2 * (sizeof(char)));
    if (str == NULL)
        return NULL;
    str[0] = c;
    str[1] = '\0';
    return str;
}

///////////////////////////////////////////////////////////////
////////////////////////MY_itoa////////////////////////////////
///////////////////////////////////////////////////////////////

char *my_itoa(int value, char *s)
{
    char *p = s;
    char *p1 = s;
    int signe = 0;
    if (value < 0)
    {
        value = -value;
        signe = 1;
    }

    else if (value == 0)
    {
        *p = '0';
        p++;
        *p = '\0';
        return s;
    }
    while (value > 0)
    {
        if (value % 10 == 0)
            *p = '0';
        else
            *p = (value % 10) + 48;
        p++;
        value /= 10;
    }
    if (signe == 1)
    {
        *p = '-';
        p++;
    }
    *p = '\0';
    p--;
    while (p1 <= p)
    {
        char temp = *p;
        *p = *p1;
        *p1 = temp;
        p--;
        p1++;
    }
    return s;
}

///////////////////////////////////////////////////////////////
////////////////////////VIDAGE ACCUMULATEUR////////////////////
///////////////////////////////////////////////////////////////

static void vidage_acc(char *token, int acc)
{
    if (acc != 0)
    {
        char *s = malloc(10 * sizeof(char));
        char *temp = my_itoa(acc, s);
        strcat(token, temp);
        strcat(token, " ");
        free(temp);
    }
}

///////////////////////////////////////////////////////////////
////////////////////////RECUPERATION TOKEN/////////////////////
///////////////////////////////////////////////////////////////

void IfIseq(char *input, char *token, char *soustoken)
{
    token[0] = '\0';
    soustoken[0] = '\0';
    int i = 0;
    int acc = 0;
    int bool = 0;
    while (input[i] != '\0')
    {
        if (isdigit(input[i]) == 0)
        {
            if (bool == 1)
            {
                char *s = malloc(10 * sizeof(char));
                char *temp = my_itoa(acc, s);
                strcat(token, temp);
                strcat(token, " ");
                free(temp);
            }
            char *temp = my_tostring(input[i]);
            strcat(token, temp);
            strcat(token, " ");
            free(temp);
            bool = 0;
            acc = 0;
            i++;
        }
        while (input[i] != '\0' && isdigit(input[i]) != 0)
        {
            acc = (bool == 1) ? acc * 10 + (input[i] - '0') : input[i] - '0';
            bool = 1;
            i++;
        }
        strcat(token, soustoken);
        strcat(token, " ");
        soustoken[0] = '\0';
    }
    vidage_acc(token, acc);
}

////////////////////////////////////////////////////////////////
/////////////////////////GESTION OP/////////////////////////////
////////////////////////////////////////////////////////////////

struct stackchar *gestion_ope(int i, char *res, char *token3,
                              struct stackchar *pile)
{
    if (Prioritylevel(token3[i]) == 3)
    {
        while (stackchar_len(pile) > 0
               && Prioritylevel(token3[i])
                   < Prioritylevel(stackchar_peek(pile)))
        {
            char *temp = my_tostring(stackchar_peek(pile));
            strcat(res, temp);
            strcat(res, " ");
            free(temp);
            pile = stackchar_pop(pile);
        }
    }
    else
    {
        while (stackchar_len(pile) > 0
               && Prioritylevel(token3[i])
                   <= Prioritylevel(stackchar_peek(pile)))
        {
            char *temp = my_tostring(stackchar_peek(pile));
            strcat(res, temp);
            strcat(res, " ");
            free(temp);
            pile = stackchar_pop(pile);
        }
    }
    pile = stackchar_push(pile, token3[i]);
    return pile;
}

///////////////////////////////////////////////////////////////
//////////////////////if_final_gestion_c////////////////////////
///////////////////////////////////////////////////////////////

static char * final(int acc, char *res)
{
    char *s = malloc(10 * sizeof(char));
    char *temp = my_itoa(acc, s);
    strcat(res, temp);
    strcat(res, " ");
    free(temp);
    return res;
}

///////////////////////////////////////////////////////////////
//////////////////////if bool ==1 /////////////////////////////
///////////////////////////////////////////////////////////////

static char *bool_1(int acc, char *res)
{
    char *s = malloc(10 * sizeof(char));
    char *temp = my_itoa(acc, s);
    strcat(res, temp);
    strcat(res, " ");
    free(temp);
    return res;
}

///////////////////////////////////////////////////////////////
//////////////////////place_needed /////////////////////////////
///////////////////////////////////////////////////////////////

struct stackchar *place_needed(int i, char *res, char *token3,
                               struct stackchar *pile)
{
    pile = gestion_ope(i + 1, res, token3, pile);
    pile = gestion_ope(i, res, token3, pile);
    return pile;
}

///////////////////////////////////////////////////////////////
//////////////////////GESTION DES CHAR/////////////////////////
///////////////////////////////////////////////////////////////

struct stackchar *gestion_char(struct stackchar *pile, char *res, char *token3)
{
    int acc = 0;
    int bool = 0;

    for (int i = 0; token3[i] != '\0'; i++)
    {
        if (token3[i] == '\n')
            continue;
        if (isdigit(token3[i]) != 0)
        {
            acc = (bool == 1) ? acc * 10 + (token3[i] - '0') : token3[i] - '0';
            bool = 1;
        }
        else
        {
            res = (bool == 1) ? bool_1(acc, res) : res;
            acc = bool = 0;
            if (token3[i] == '(')
                pile = stackchar_push(pile, token3[i]);
            else if (token3[i] == ')')
            {
                while (stackchar_peek(pile) != '(')
                {
                    char *temp = my_tostring(stackchar_peek(pile));
                    strcat(strcat(res, temp), " ");
                    free(temp);
                    pile = stackchar_pop(pile);
                }
                pile = stackchar_pop(pile);
            }
            else
            {
                if (token3[i + 1] == '-')
                {
                    pile = place_needed(i, res, token3, pile);
                    i++;
                }
                else
                    pile = gestion_ope(i, res, token3, pile);
            }
        }
    }
    if (acc != 0)
        final(acc, res);
    return pile;
}

///////////////////////////////////////////////////////////////
///////////////////////VIDANGE PILE////////////////////////////
///////////////////////////////////////////////////////////////

struct stackchar *vidange(char *res, struct stackchar *pile)
{
    while (stackchar_len(pile) > 0)
    {
        char *temp = my_tostring(stackchar_peek(pile));
        strcat(res, temp);
        strcat(res, " ");
        free(temp);
        pile = stackchar_pop(pile);
    }
    return pile;
}

///////////////////////////////////////////////////////////////
//////////////////////////FCT PRINCIPAL////////////////////////
///////////////////////////////////////////////////////////////

char *convertir(char *input)
{
    char *res = malloc(CAPACITY * sizeof(char));
    res[0] = '\0';
    char *token = malloc(CAPACITY * sizeof(char));
    char *soustoken = malloc(CAPACITY * sizeof(char));
    if (Isequilibrer(input))
    {
        ///////////////GESTION TOKEN/////////////////////
        IfIseq(input, token, soustoken);

        char *token2;
        char *token3 = malloc(CAPACITY * sizeof(char));
        token3[0] = '\0';

        token2 = strtok(token, " ");
        while (token2 != NULL)
        {
            strcat(token3, token2);
            token2 = strtok(NULL, " ");
        }
        struct stackchar *pile = NULL;

        ///////////////GESTION CHAR/////////////////////
        pile = gestion_char(pile, res, token3);

        //////////////VIDANGE PILE/////////////////////
        pile = vidange(res, pile);

        free(pile);
        free(token);
        free(soustoken);
        free(token3);
    }
    else
        exit(2);

    return res;
}

//////////////////////////////////////////////////////////////////////////////////////////////END///////////////////////////////////////////////////////////////////////////////////////////////
