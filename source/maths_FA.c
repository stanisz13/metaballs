#include "maths_FA.h"
#include <limits.h>
#include <float.h>

unsigned xorshift()
{
    unsigned x = randomSeries_FA.seed;

    x ^= x << 13;
    x ^= x >> 17;
    x ^= x << 5;

    randomSeries_FA.seed = x;

    return x;
}

unsigned getRandomUnsignedOnInterval(const unsigned a, const unsigned b)
{
    unsigned res = xorshift();

    res = res % (b - a + 1);
    res += a;

    return res;
}

float getRandomFloatZeroOne()
{
    float res;

    unsigned r = xorshift();
    
    res = (float)r / UINT_MAX;

    return res;    
}

float getRandomFloatOnInterval(const float a, const float b)
{
    float res = getRandomFloatZeroOne();

    res *= (b - a);
    res += a;

    return res;
}
