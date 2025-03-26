#include "is_set.h"

#include <stdio.h>

unsigned int is_set(unsigned int value, unsigned char n)
{
    unsigned int flag_unset = 1 << (n - 1);
    return ((value & flag_unset) == 0) ? 0 : 1;
}
