#include "complex.h"

#include <stdio.h>

void print_complex(struct complex a)
{
    printf("complex(%.2f %c %.2fi)\n", a.real, ((a.img < 0) ? '-' : '+'),
           (a.img < 0) ? -a.img : a.img);
}

struct complex neg_complex(struct complex a)
{
    a.real = -a.real;
    a.img = -a.img;
    return a;
}

struct complex add_complex(struct complex a, struct complex b)
{
    struct complex res;
    res.real = a.real + b.real;
    res.img = a.img + b.img;
    return res;
}

struct complex sub_complex(struct complex a, struct complex b)
{
    struct complex res;
    res.real = a.real - b.real;
    res.img = a.img - b.img;
    return res;
}

struct complex mul_complex(struct complex a, struct complex b)
{
    struct complex res;
    res.real = a.real * b.real - a.img * b.img;
    res.img = a.real * b.img + b.real * a.img;
    return res;
}

struct complex div_complex(struct complex a, struct complex b)
{
    struct complex res;
    res.real =
        (a.real * b.real + a.img * b.img) / (b.real * b.real + b.img * b.img);
    res.img =
        (a.img * b.real - a.real * b.img) / (b.real * b.real + b.img * b.img);
    return res;
}
