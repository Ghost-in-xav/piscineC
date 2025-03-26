#include "tinyprintf.h"

#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

/////////////////////////////////////////////////////////////////////////////////////////ITOA///////////////////////////////////////////////////////////////////////////////////////////////////

char *my_itoa(long value, char *s)
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

/////////////////////////////////////////////////////////////////////////////////////////ITOA_BASE//////////////////////////////////////////////////////////////////////////////////////////////

char *my_itoa_base(long n, char *s, const char *base)
{
    int taille_base = 0;
    int buffer[32] = { 0 };
    int count = 0;
    char *p = s;
    if (n == 0)
    {
        *p = base[0];
        p++;
        *p = '\0';
        return s;
    }

    for (int i = 0; base[i] != '\0'; i++)
        taille_base++;

    if (taille_base == 10 && n < 0)
    {
        n = -n;
        *p = '-';
        p++;
    }

    while (n > 0)
    {
        buffer[count] = n % taille_base;
        n /= taille_base;
        count++;
    }

    for (int i = count - 1; i >= 0; i--)
    {
        *p = (base[buffer[i]]);
        p++;
    }
    *p = '\0';
    return s;
}

/////////////////////////////////////////////////////////////////////////////////////////D_CASE/////////////////////////////////////////////////////////////////////////////////////////////////

// Fonction qui traite le cas %d
int d_case(va_list argument)
{
    int to_return = 0;
    int signed_decimal_arg = va_arg(argument, int);
    char *temp = malloc(100 * sizeof(char));
    temp = my_itoa(signed_decimal_arg, temp);
    for (int i = 0; temp[i] != '\0'; i++)
    {
        putchar(temp[i]);
        to_return++;
    }
    free(temp);
    return to_return;
}

/////////////////////////////////////////////////////////////////////////////////////////U_CASE/////////////////////////////////////////////////////////////////////////////////////////////////

// Fonction qui traite le cas %u
int u_case(va_list argument)
{
    int to_return = 0;
    unsigned int unsigned_decimal_arg = va_arg(argument, int);

    char *temp = malloc(100 * sizeof(char));
    temp = my_itoa(unsigned_decimal_arg, temp);
    for (int i = 0; temp[i] != '\0'; i++)
    {
        putchar(temp[i]);
        to_return++;
    }
    free(temp);
    return to_return;
}

/////////////////////////////////////////////////////////////////////////////////////////S_CASE/////////////////////////////////////////////////////////////////////////////////////////////////

// Fonction qui traite le cas %s
int s_case(va_list argument)
{
    int nb_char_return = 0;
    char *arg = va_arg(argument, char *);
    if (arg == NULL)
    {
        char *p;
        char buffer[] = "(null)";
        for (p = buffer; *p != '\0'; p++)
        {
            putchar(*p);
            nb_char_return += 1;
        }
        return nb_char_return;
    }
    if (*arg == '\0')
        return nb_char_return;
    while (*arg != '\0')
    {
        putchar(*arg);
        arg++;
        nb_char_return += 1;
    }
    return nb_char_return;
}

/////////////////////////////////////////////////////////////////////////////////////////C_CASE/////////////////////////////////////////////////////////////////////////////////////////////////

// Fonction qui vas gerer le cas de %c
int c_case(va_list argument)
{
    char arg = va_arg(argument, int);
    putchar(arg);
    return 1;
}

/////////////////////////////////////////////////////////////////////////////////////////O_CASE/////////////////////////////////////////////////////////////////////////////////////////////////

// Fonction qui vas gere les cas %o
int o_case(va_list argument)
{
    char base_8[] = "01234567";
    int nb_char_return = 0;
    unsigned int octal = va_arg(argument, unsigned int);
    char *temp = malloc(100 * sizeof(char));
    temp = my_itoa_base(octal, temp, base_8);
    for (int i = 0; temp[i] != '\0'; i++)
    {
        putchar(temp[i]);
        nb_char_return++;
    }
    free(temp);
    return nb_char_return;
}

/////////////////////////////////////////////////////////////////////////////////////////X_CASE/////////////////////////////////////////////////////////////////////////////////////////////////

// Fonction qui vas gere les cas %x
int x_case(va_list argument)
{
    char base_16[] = "0123456789abcdef";
    int to_return = 0;
    unsigned int hexa = va_arg(argument, unsigned int);
    char *temp = malloc(100 * sizeof(char));
    temp = my_itoa_base(hexa, temp, base_16);
    for (int i = 0; temp[i] != '\0'; i++)
    {
        putchar(temp[i]);
        to_return++;
    }
    free(temp);
    return to_return;
}

////////////////////////////////////////////////////////////////////////////////////SWITCH_TINYPRINTF///////////////////////////////////////////////////////////////////////////////////////////

int switch_tiny(const char *p, int nb_char_return, va_list argument)
{
    switch (*p)
    {
    case '%':
        putchar('%');
        nb_char_return += 1;
        break;
    case 'd':
        nb_char_return += d_case(argument);
        break;
    case 'u':
        nb_char_return += u_case(argument);
        break;
    case 's':
        nb_char_return += s_case(argument);
        break;
    case 'c':
        nb_char_return += c_case(argument);
        break;
    case 'o':
        nb_char_return += o_case(argument);
        break;
    case 'x':
        nb_char_return += x_case(argument);
        break;
    default:
        putchar('%');
        putchar(*p);
        if (*p != '\0')
            nb_char_return += 2;
        else
            nb_char_return += 1;
    }

    return nb_char_return;
}
/////////////////////////////////////////////////////////////////////////////////////////TINYPRINTF/////////////////////////////////////////////////////////////////////////////////////////////

int tinyprintf(const char *format, ...)
{
    // nombre de charactere renvoyer
    int nb_char_return = 0;

    if (format == NULL || *format == '\0')
        return 0;

    // initialisation pour l obtention des arguments
    va_list argument;
    va_start(argument, format); /*initialisation*/

    // initialisation du pointeur de deplacement
    const char *p = format;

    if (*p != '%')
    {
        putchar(*p);
        nb_char_return++;
    }
    // initialisation de la boucle parcourant format
    while (*p != '\0')
    {
        // si le symbole courrant est un pourcentage
        if (*p == '%')
        {
            p++;
            nb_char_return = switch_tiny(p, nb_char_return, argument);
        }
        // Si le caractere n'est pas un %:
        if (*p != '\0')
            p++;
        if (p != NULL && *p != '\0' && *p != '%')
        {
            putchar(*p);
            nb_char_return += 1;
        }
    }

    va_end(argument);
    return nb_char_return;
}

/////////////////////////////////////////////////////////////////////////////////////////END////////////////////////////////////////////////////////////////////////////////////////////////////
