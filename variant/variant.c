#include "variant.h"

#include <stdio.h>
#include <string.h>

void variant_display(const struct variant *e)
{
    switch (e->type)
    {
    case TYPE_INT:
        printf("%d\n", e->value.int_v);
        break;
    case TYPE_FLOAT:
        printf("%f\n", e->value.float_v);
        break;
    case TYPE_CHAR:
        printf("%c\n", e->value.char_v);
        break;
    case TYPE_STRING:
        printf("%s\n", e->value.str_v);
        break;
    }
}

bool variant_equal(const struct variant *left, const struct variant *right)
{
    if (left == NULL && left == right)
        return true;
    if (left->type == right->type)
    {
        switch (left->type)
        {
        case (TYPE_INT):
            return (left->value.int_v == right->value.int_v) ? true : false;
            break;
        case (TYPE_FLOAT):
            return (left->value.float_v == right->value.float_v) ? true : false;
            break;
        case (TYPE_CHAR):
            return (left->value.char_v == right->value.char_v) ? true : false;
            break;
        case (TYPE_STRING):
            return (strcmp(left->value.str_v, right->value.str_v) == 0) ? true
                                                                        : false;
            break;
        }
    }
    return false;
}

int variant_find(const struct variant *array, size_t len, enum type type,
                 union type_any value)
{
    for (size_t i = 0; i < len; i++)
    {
        variant_display(&array[i]);
        if (array[i].type == type)
        {
            switch (array[i].type)
            {
            case (TYPE_INT):
                if (array[i].value.int_v == value.int_v)
                    return i;
                break;
            case (TYPE_FLOAT):
                if (array[i].value.float_v == value.float_v)
                    return i;
                break;
            case (TYPE_CHAR):
                if (array[i].value.char_v == value.char_v)
                    return i;
                break;
            case (TYPE_STRING):
                if (array[i].value.str_v == value.str_v)
                    return i;
                break;
            }
        }
    }
    return -1;
}

float variant_sum(const struct variant *array, size_t len)
{
    float res = 0;
    for (size_t i = 0; i < len; i++)
    {
        if (array[i].type == TYPE_FLOAT || array[i].type == TYPE_INT)
        {
            switch (array[i].type)
            {
            case (TYPE_INT):
                res += array[i].value.int_v;
                break;
            case (TYPE_FLOAT):
                res += array[i].value.float_v;
                break;
            default:
                printf("flemme");
                break;
            }
        }
    }
    return res;
}
