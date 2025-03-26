#include "traffic_lights.h"

#include <stddef.h>
#include <stdio.h>

void init(unsigned char *lights)
{
    *lights = ~(*lights) & (*lights);
}

void turn_on(unsigned char *lights, unsigned char light_num)
{
    unsigned char allumer = 1 << (light_num - 1);
    *lights |= allumer;
}

void turn_off(unsigned char *lights, unsigned char light_num)
{
    unsigned char eteint = 1 << (light_num - 1);
    *lights = *lights & (~eteint);
}

void next_step(unsigned char *lights)
{
    *lights = (*lights << 1) | (*lights >> (4 - 1));
}

void reverse(unsigned char *lights)
{
    *lights = ~(*lights);
}

void swap(unsigned char *lights_1, unsigned char *lights_2)
{
    unsigned char temp = 0;
    init(&temp);
    *(&temp) |= *lights_1;
    *lights_1 &= (~(*lights_1));
    *lights_1 |= *lights_2;
    init(lights_2);
    *lights_2 |= *(&temp);
}
