#include <stddef.h>

unsigned char rol(unsigned char value, unsigned char roll)
{
    roll %= 8;
    return ((value << roll) | (value >> (8 - roll)));
}
