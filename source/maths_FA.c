#include "maths_FA.h"
#include <limits.h>
#include <float.h>
#include <time.h>

float absFloat(const float v)
{
    if (v < 0.0f)
    {
        return -v;
    }

    return v;
}

int absInt(const int v)
{
    if (v < 0)
    {
        return -v;
    }

    return v;
}

double absDouble(const double v)
{
    if (v < 0.0f)
    {
        return -v;
    }

    return v;
}

float minFloat(const float v, const float w)
{
    if (v - w < EPSILON)
    {
        return v;
    }

    return w;
}

float maxFloat(const float v, const float w)
{
    if (v - w > EPSILON)
    {
        return v;
    }

    return w;
}

double minDouble(const double v, const double w)
{
    if (v - w < EPSILON_DOUBLE)
    {
        return v;
    }

    return w;
}

double maxDouble(const double v, const double w)
{
    if (v - w > EPSILON_DOUBLE)
    {
        return v;
    }

    return w;
}

double maxDouble(const double v, const double w);

int maxInt(const int v, const int w)
{
    if (v > w)
    {
        return v;
    }

    return w;
}

int minInt(const int v, const int w)
{
    if (v < w)
    {
        return v;
    }

    return w;
}

unsigned minUnsigned(const unsigned v, const unsigned w)
{
    if (v < w)
    {
        return v;
    }

    return w;
}

unsigned maxUnsigned(const unsigned v, const unsigned w)
{
    if (v > w)
    {
        return v;
    }

    return w;
}

unsigned xorshift()
{
    unsigned x = randomSeries_FA.seed;

    x ^= x << 13;
    x ^= x >> 17;
    x ^= x << 5;

    randomSeries_FA.seed = x;

    return x;
}

void setRandomSeed(const unsigned s)
{
    randomSeries_FA.seed = s;
}

void setRandomSeedTime()
{
    randomSeries_FA.seed = (unsigned)time(0);
}

float getRandomFloatZeroOne()
{
    float res;

    unsigned r = xorshift();
    
    res = (float)r / UINT_MAX;

    return res;    
}

double getRandomDoubleZeroOne()
{
    double res;

    unsigned r = xorshift();

    res = (double)r / UINT_MAX;

    return res;
}

unsigned getRandomUnsignedOnInterval(const unsigned a, const unsigned b)
{
    unsigned res = xorshift();

    res = res % (b - a + 1);
    res += a;

    return res;
}

float getRandomFloatOnInterval(const float a, const float b)
{
    float res = getRandomFloatZeroOne();

    res *= absFloat(b - a);
    res += minFloat(a, b);

    return res;
}

double getRandomDoubleOnInterval(const double a, const double b)
{
    double res = getRandomDoubleZeroOne();

    res *= absDouble(b - a);
    res += minDouble(a, b);

    return res;
}

int getRandomIntOnInterval(const int a, const int b)
{
    int res = xorshift();
    res = absInt(res);

    res = res % absInt(b - a + 1);
    res += minInt(a, b);

    return res;
}

fvec2 getRandomFVec2OnInterval(const float a, const float b)
{
    fvec2 res;

    res.x = getRandomFloatOnInterval(a, b);
    res.y = getRandomFloatOnInterval(a, b);

    return res;
}

dvec2 getRandomDVec2OnInterval(const double a, const double b)
{
    dvec2 res;

    res.x = getRandomDoubleOnInterval(a, b);
    res.y = getRandomDoubleOnInterval(a, b);

    return res;
}

uvec2 getRandomUVec2OnInterval(const unsigned a, const unsigned b)
{
    uvec2 res;

    res.x = getRandomUnsignedOnInterval(a, b);
    res.y = getRandomUnsignedOnInterval(a, b);

    return res;
}

ivec2 getRandomIVec2OnInterval(const int a, const int b)
{
    ivec2 res;

    res.x = getRandomIntOnInterval(a, b);
    res.y = getRandomIntOnInterval(a, b);

    return res;
}

fvec3 getRandomFVec3OnInterval(const float a, const float b)
{
    fvec3 res;

    res.x = getRandomFloatOnInterval(a, b);
    res.y = getRandomFloatOnInterval(a, b);
    res.z = getRandomFloatOnInterval(a, b);
    
    return res;
}

dvec3 getRandomDVec3OnInterval(const double a, const double b)
{
    dvec3 res;

    res.x = getRandomDoubleOnInterval(a, b);
    res.y = getRandomDoubleOnInterval(a, b);
    res.z = getRandomDoubleOnInterval(a, b);
    
    return res;
}

uvec3 getRandomUVec3OnInterval(const unsigned a, const unsigned b)
{
    uvec3 res;

    res.x = getRandomUnsignedOnInterval(a, b);
    res.y = getRandomUnsignedOnInterval(a, b);
    res.z = getRandomUnsignedOnInterval(a, b);
    
    return res;
}

ivec3 getRandomIVec3OnInterval(const int a, const int b)
{
    ivec3 res;

    res.x = getRandomIntOnInterval(a, b);
    res.y = getRandomIntOnInterval(a, b);
    res.z = getRandomIntOnInterval(a, b);
    
    return res;
}

fvec4 getRandomFVec4OnInterval(const float a, const float b)
{
    fvec4 res;

    res.x = getRandomFloatOnInterval(a, b);
    res.y = getRandomFloatOnInterval(a, b);
    res.z = getRandomFloatOnInterval(a, b);
    res.w = getRandomFloatOnInterval(a, b);
    
    return res;
}

dvec4 getRandomDVec4OnInterval(const double a, const double b)
{
    dvec4 res;

    res.x = getRandomDoubleOnInterval(a, b);
    res.y = getRandomDoubleOnInterval(a, b);
    res.z = getRandomDoubleOnInterval(a, b);
    res.w = getRandomDoubleOnInterval(a, b);
    
    return res;
}

uvec4 getRandomUVec4OnInterval(const unsigned a, const unsigned b)
{
    uvec4 res;

    res.x = getRandomUnsignedOnInterval(a, b);
    res.y = getRandomUnsignedOnInterval(a, b);
    res.z = getRandomUnsignedOnInterval(a, b);
    res.w = getRandomUnsignedOnInterval(a, b);
    
    return res;
}

ivec4 getRandomIVec4OnInterval(const int a, const int b)
{
    ivec4 res;

    res.x = getRandomIntOnInterval(a, b);
    res.y = getRandomIntOnInterval(a, b);
    res.z = getRandomIntOnInterval(a, b);
    res.w = getRandomIntOnInterval(a, b);
    
    return res;
}

fvec2 scaleFVec2ByConstant(const fvec2 v, const float s)
{
    fvec2 res = v;

    res.x *= s;
    res.y *= s;

    return res;
}

dvec2 scaleDVec2ByConstant(const dvec2 v, const double s)
{
    dvec2 res = v;

    res.x *= s;
    res.y *= s;

    return res;
}

uvec2 scaleUVec2ByConstant(const uvec2 v, const unsigned s)
{
    uvec2 res = v;

    res.x *= s;
    res.y *= s;

    return res;
}

ivec2 scaleIVec2ByConstant(const ivec2 v, const int s)
{
    ivec2 res = v;

    res.x *= s;
    res.y *= s;

    return res;
}

fvec3 scaleFVec3ByConstant(const fvec3 v, const float s)
{
    fvec3 res = v;

    res.x *= s;
    res.y *= s;

    return res;
}

dvec3 scaleDVec3ByConstant(const dvec3 v, const double s)
{
    dvec3 res = v;

    res.x *= s;
    res.y *= s;

    return res;
}

uvec3 scaleUVec3ByConstant(const uvec3 v, const unsigned s)
{
    uvec3 res = v;

    res.x *= s;
    res.y *= s;

    return res;
}

ivec3 scaleIVec3ByConstant(const ivec3 v, const int s)
{
    ivec3 res = v;

    res.x *= s;
    res.y *= s;

    return res;
}

fvec4 scaleFVec4ByConstant(const fvec4 v, const float s)
{
    fvec4 res = v;

    res.x *= s;
    res.y *= s;

    return res;
}

dvec4 scaleDVec4ByConstant(const dvec4 v, const double s)
{
    dvec4 res = v;

    res.x *= s;
    res.y *= s;

    return res;
}

uvec4 scaleUVec4ByConstant(const uvec4 v, const unsigned s)
{
    uvec4 res = v;

    res.x *= s;
    res.y *= s;

    return res;
}

ivec4 scaleIVec4ByConstant(const ivec4 v, const int s)
{
    ivec4 res = v;

    res.x *= s;
    res.y *= s;

    return res;
}
