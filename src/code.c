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