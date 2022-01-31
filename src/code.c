#include <stdint.h>
#include "code.h"

int mult(uint64_t x, uint64_t y)
{
    return x * y;
}

int divide(uint64_t x, uint64_t y)
{

    return (y == 0) ? 0 : x / y;
}

uint64_t factorial(uint64_t num)
{
    uint64_t ret;

    if (num == 0 || num == 1)
        ret = 1;
    else
        ret = factorial(num - 1) * num;

    return ret;
}