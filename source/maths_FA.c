#include "maths_FA.h"
#include <limits.h>
#include <float.h>
#include <time.h>
#include <string.h>

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

FVec2 getRandomFVec2OnInterval(const float a, const float b)
{
    FVec2 res;

    res.x = getRandomFloatOnInterval(a, b);
    res.y = getRandomFloatOnInterval(a, b);

    return res;
}

DVec2 getRandomDVec2OnInterval(const double a, const double b)
{
    DVec2 res;

    res.x = getRandomDoubleOnInterval(a, b);
    res.y = getRandomDoubleOnInterval(a, b);

    return res;
}

UVec2 getRandomUVec2OnInterval(const unsigned a, const unsigned b)
{
    UVec2 res;

    res.x = getRandomUnsignedOnInterval(a, b);
    res.y = getRandomUnsignedOnInterval(a, b);

    return res;
}

IVec2 getRandomIVec2OnInterval(const int a, const int b)
{
    IVec2 res;

    res.x = getRandomIntOnInterval(a, b);
    res.y = getRandomIntOnInterval(a, b);

    return res;
}

FVec3 getRandomFVec3OnInterval(const float a, const float b)
{
    FVec3 res;

    res.x = getRandomFloatOnInterval(a, b);
    res.y = getRandomFloatOnInterval(a, b);
    res.z = getRandomFloatOnInterval(a, b);
    
    return res;
}

DVec3 getRandomDVec3OnInterval(const double a, const double b)
{
    DVec3 res;

    res.x = getRandomDoubleOnInterval(a, b);
    res.y = getRandomDoubleOnInterval(a, b);
    res.z = getRandomDoubleOnInterval(a, b);
    
    return res;
}

UVec3 getRandomUVec3OnInterval(const unsigned a, const unsigned b)
{
    UVec3 res;

    res.x = getRandomUnsignedOnInterval(a, b);
    res.y = getRandomUnsignedOnInterval(a, b);
    res.z = getRandomUnsignedOnInterval(a, b);
    
    return res;
}

IVec3 getRandomIVec3OnInterval(const int a, const int b)
{
    IVec3 res;

    res.x = getRandomIntOnInterval(a, b);
    res.y = getRandomIntOnInterval(a, b);
    res.z = getRandomIntOnInterval(a, b);
    
    return res;
}

FVec4 getRandomFVec4OnInterval(const float a, const float b)
{
    FVec4 res;

    res.x = getRandomFloatOnInterval(a, b);
    res.y = getRandomFloatOnInterval(a, b);
    res.z = getRandomFloatOnInterval(a, b);
    res.w = getRandomFloatOnInterval(a, b);
    
    return res;
}

DVec4 getRandomDVec4OnInterval(const double a, const double b)
{
    DVec4 res;

    res.x = getRandomDoubleOnInterval(a, b);
    res.y = getRandomDoubleOnInterval(a, b);
    res.z = getRandomDoubleOnInterval(a, b);
    res.w = getRandomDoubleOnInterval(a, b);
    
    return res;
}

UVec4 getRandomUVec4OnInterval(const unsigned a, const unsigned b)
{
    UVec4 res;

    res.x = getRandomUnsignedOnInterval(a, b);
    res.y = getRandomUnsignedOnInterval(a, b);
    res.z = getRandomUnsignedOnInterval(a, b);
    res.w = getRandomUnsignedOnInterval(a, b);
    
    return res;
}

IVec4 getRandomIVec4OnInterval(const int a, const int b)
{
    IVec4 res;

    res.x = getRandomIntOnInterval(a, b);
    res.y = getRandomIntOnInterval(a, b);
    res.z = getRandomIntOnInterval(a, b);
    res.w = getRandomIntOnInterval(a, b);
    
    return res;
}

FVec2 scaleFVec2ByConstant(const FVec2 v, const float s)
{
    FVec2 res = v;

    res.x *= s;
    res.y *= s;

    return res;
}

DVec2 scaleDVec2ByConstant(const DVec2 v, const double s)
{
    DVec2 res = v;

    res.x *= s;
    res.y *= s;

    return res;
}

UVec2 scaleUVec2ByConstant(const UVec2 v, const unsigned s)
{
    UVec2 res = v;

    res.x *= s;
    res.y *= s;

    return res;
}

IVec2 scaleIVec2ByConstant(const IVec2 v, const int s)
{
    IVec2 res = v;

    res.x *= s;
    res.y *= s;

    return res;
}

FVec3 scaleFVec3ByConstant(const FVec3 v, const float s)
{
    FVec3 res = v;

    res.x *= s;
    res.y *= s;

    return res;
}

DVec3 scaleDVec3ByConstant(const DVec3 v, const double s)
{
    DVec3 res = v;

    res.x *= s;
    res.y *= s;

    return res;
}

UVec3 scaleUVec3ByConstant(const UVec3 v, const unsigned s)
{
    UVec3 res = v;

    res.x *= s;
    res.y *= s;

    return res;
}

IVec3 scaleIVec3ByConstant(const IVec3 v, const int s)
{
    IVec3 res = v;

    res.x *= s;
    res.y *= s;

    return res;
}

FVec4 scaleFVec4ByConstant(const FVec4 v, const float s)
{
    FVec4 res = v;

    res.x *= s;
    res.y *= s;

    return res;
}

DVec4 scaleDVec4ByConstant(const DVec4 v, const double s)
{
    DVec4 res = v;

    res.x *= s;
    res.y *= s;

    return res;
}

UVec4 scaleUVec4ByConstant(const UVec4 v, const unsigned s)
{
    UVec4 res = v;

    res.x *= s;
    res.y *= s;

    return res;
}

IVec4 scaleIVec4ByConstant(const IVec4 v, const int s)
{
    IVec4 res = v;

    res.x *= s;
    res.y *= s;

    return res;
}

FVec2 addFVec2(const FVec2 v, const FVec2 w)
{
    FVec2 res = v;
    res.x += w.x;
    res.y += w.y;

    return res;
}

DVec2 addDVec2(const DVec2 v, const DVec2 w)
{
    DVec2 res = v;
    res.x += w.x;
    res.y += w.y;

    return res;
}

UVec2 addUVec2(const UVec2 v, const UVec2 w)
{
    UVec2 res = v;
    res.x += w.x;
    res.y += w.y;

    return res;
}

IVec2 addIVec2(const IVec2 v, const IVec2 w)
{
    IVec2 res = v;
    res.x += w.x;
    res.y += w.y;

    return res;
}

FVec3 addFVec3(const FVec3 v, const FVec3 w)
{
    FVec3 res = v;
    res.x += w.x;
    res.y += w.y;
    res.z += w.z;
    
    return res;
}
DVec3 addDVec3(const DVec3 v, const DVec3 w)
{
    DVec3 res = v;
    res.x += w.x;
    res.y += w.y;
    res.z += w.z;
    
    return res;
}

UVec3 addUVec3(const UVec3 v, const UVec3 w)
{
    UVec3 res = v;
    res.x += w.x;
    res.y += w.y;
    res.z += w.z;
    
    return res;
}

IVec3 addIVec3(const IVec3 v, const IVec3 w)
{
    IVec3 res = v;
    res.x += w.x;
    res.y += w.y;
    res.z += w.z;
    
    return res;
}

FVec4 addFVec4(const FVec4 v, const FVec4 w)
{
    FVec4 res = v;
    res.x += w.x;
    res.y += w.y;
    res.z += w.z;
    res.w += w.w;
    
    return res;
}

DVec4 addDVec4(const DVec4 v, const DVec4 w)
{
    DVec4 res = v;
    res.x += w.x;
    res.y += w.y;
    res.z += w.z;
    res.w += w.w;
    
    return res;

}

UVec4 addUVec4(const UVec4 v, const UVec4 w)
{
    UVec4 res = v;
    res.x += w.x;
    res.y += w.y;
    res.z += w.z;
    res.w += w.w;
    
    return res;

}

IVec4 addIVec4(const IVec4 v, const IVec4 w)
{
    IVec4 res = v;
    res.x += w.x;
    res.y += w.y;
    res.z += w.z;
    res.w += w.w;
    
    return res;
}

FVec2 hadamardFVec2(const FVec2 v, const FVec2 w)
{
    FVec2 res = v;
    res.x *= w.x;
    res.y *= w.y;

    return res;
}

DVec2 hadamardDVec2(const DVec2 v, const DVec2 w)
{
    DVec2 res = v;
    res.x *= w.x;
    res.y *= w.y;

    return res;
}

UVec2 hadamardUVec2(const UVec2 v, const UVec2 w)
{
    UVec2 res = v;
    res.x *= w.x;
    res.y *= w.y;

    return res;
}

IVec2 hadamardIVec2(const IVec2 v, const IVec2 w)
{
    IVec2 res = v;
    res.x *= w.x;
    res.y *= w.y;

    return res;
}

FVec3 hadamardFVec3(const FVec3 v, const FVec3 w)
{
    FVec3 res = v;
    res.x *= w.x;
    res.y *= w.y;
    res.z *= w.z;
    
    return res;
}

DVec3 hadamardDVec3(const DVec3 v, const DVec3 w)
{
    DVec3 res = v;
    res.x *= w.x;
    res.y *= w.y;
    res.z *= w.z;
    
    return res;
}

UVec3 hadamardUVec3(const UVec3 v, const UVec3 w)
{
    UVec3 res = v;
    res.x *= w.x;
    res.y *= w.y;
    res.z *= w.z;
    
    return res;
}

IVec3 hadamardIVec3(const IVec3 v, const IVec3 w)
{
    IVec3 res = v;
    res.x *= w.x;
    res.y *= w.y;
    res.z *= w.z;
    
    return res;
}

FVec4 hadamardFVec4(const FVec4 v, const FVec4 w)
{
    FVec4 res = v;
    res.x *= w.x;
    res.y *= w.y;
    res.z *= w.z;
    res.w *= w.w;
    
    return res;
}

DVec4 hadamardDVec4(const DVec4 v, const DVec4 w)
{
    DVec4 res = v;
    res.x *= w.x;
    res.y *= w.y;
    res.z *= w.z;
    res.w *= w.w;
    
    return res;
}

UVec4 hadamardUVec4(const UVec4 v, const UVec4 w)
{
    UVec4 res = v;
    res.x *= w.x;
    res.y *= w.y;
    res.z *= w.z;
    res.w *= w.w;
    
    return res;
}

IVec4 hadamardIVec4(const IVec4 v, const IVec4 w)
{
    IVec4 res = v;
    res.x *= w.x;
    res.y *= w.y;
    res.z *= w.z;
    res.w *= w.w;
    
    return res;
}

float* accessFMat2(fmat2* m, const unsigned x, const unsigned y)
{
    float* res = 0;

    res = m->mem + x * 2 + y;
    
    return res;
}

float* accessFMat3(fmat3* m, const unsigned x, const unsigned y)
{
    float* res = 0;

    res = m->mem + x * 3 + y;

    return res;
}

float* accessFMat4(fmat4* m, const unsigned x, const unsigned y)
{
    float* res= 0;

    res = m->mem + x * 4 + y;

    return res;
}

fmat2 setFMat2ByElements(const float* data)
{
    fmat2 res;

    memcpy(res.mem, data, sizeof(res.mem));
    
    return res;
}

fmat3 setFMat3ByElements(const float* data)
{
    fmat3 res;

    memcpy(res.mem, data, sizeof(res.mem));
    
    return res;
}

fmat4 setFMat4ByElements(const float* data)
{
    fmat4 res;

    memcpy(res.mem, data, sizeof(res.mem));
    
    return res;
}

fmat2 setFMat2ByVectors(const FVec2 a, const FVec2 b)
{
    fmat2 res;

    res.col1 = a;
    res.col2 = b;
    
    return res;
}

fmat3 setFMat3ByVectors(const FVec3 a, const FVec3 b, const FVec3 c)
{
    fmat3 res;

    res.col1 = a;
    res.col2 = b;
    res.col3 = c;

    return res;
}

fmat4 setFMat4ByVectors(const FVec4 a, const FVec4 b, const FVec4 c, const FVec4 d)
{
    fmat4 res;

    res.col1 = a;
    res.col2 = b;
    res.col3 = c;
    res.col4 = d;
    
    return res;
}

fmat2 mulFMat2(fmat2 a, fmat2 b)
{
    fmat2 res = {};

    for (unsigned i = 0; i < 2; ++i)
    {
        for (unsigned j = 0; j < 2; ++j)
        {
            float* curResElem = accessFMat2(&res, i, j);
            for (unsigned k = 0; k < 2; ++k)
            {
                float* curAElem = accessFMat2(&a, k, j);
                float* curBElem = accessFMat2(&b, i, k);
                *curResElem += *curAElem * *curBElem;
            }
        }
    }
    return res;
}

fmat3 mulFMat3(fmat3 a, fmat3 b)
{
    fmat3 res = {};

    for (unsigned i = 0; i < 3; ++i)
    {
        for (unsigned j = 0; j < 3; ++j)
        {
            float* curResElem = accessFMat3(&res, i, j);

            for (unsigned k = 0; k < 3; ++k)
            {
                float* curAElem = accessFMat3(&a, k, j);
                float* curBElem = accessFMat3(&b, i, k);
                
                *curResElem += *curAElem * *curBElem;
            }
        }
    }
    return res;
}

fmat4 mulFMat4(fmat4 a, fmat4 b)
{
    fmat4 res = {};

    for (unsigned i = 0; i < 4; ++i)
    {
        for (unsigned j = 0; j < 4; ++j)
        {
            float* curResElem = accessFMat4(&res, i, j);

            for (unsigned k = 0; k < 4; ++k)
            {
                float* curAElem = accessFMat4(&a, k, j);
                float* curBElem = accessFMat4(&b, i, k);
                
                *curResElem += *curAElem * *curBElem;
            }
        }
    }
    return res;
}

