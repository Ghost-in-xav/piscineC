#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if (argc < 2)
        return 0;
    char buffer[65536];
    size_t size = 65536;
    ssize_t ptr1 = read(STDIN_FILENO, buffer, size);

    int x = atoi(argv[1]);
    int entier = x;
    while (entier < -10)
        entier += 10;
    while (x < -26)
        x += 26;
    entier = (x > 10) ? entier % 10 : entier;
    x = (x < 0) ? ((26 + x) % 26) : x;

    while (ptr1 > 0)
    {
        for (ssize_t i = 0; i < ptr1; i++)
        {
            char ch1 = buffer[i];
            if (ch1 >= 'A' && 'Z' >= ch1)
                ch1 = (((ch1 - 'A') + x) % 26) + 'A';
            else if (ch1 >= 'a' && 'z' >= ch1)
                ch1 = (((ch1 - 'a') + x) % 26) + 'a';
            else if (ch1 >= '0' && '9' >= ch1)
            {
                ch1 = (((ch1 - '0') + entier) % 10);
                ch1 = (ch1 < 0) ? ch1 + 10 + '0' : ch1 + '0';
            }

            buffer[i] = ch1;
        }
        write(STDOUT_FILENO, buffer, ptr1);
        ptr1 = read(STDIN_FILENO, buffer, size);
    }
    return 0;
}
