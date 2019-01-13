#ifndef MATHS_FA__H
#define MATHS_FA__H

#include "log_FA.h"

#define EPSILON 0.0000001f
#define EPSILON_DOUBLE 0.0000000000001f


//NOTE(Stanisz13): VECTORS
typedef struct
{
    union
    {
        struct
        {
            float x, y;
        };
        float mem[2];
    };
} fvec2;

typedef struct
{
    union
    {
        struct
        {
            double x, y;
        };
        double mem[2];
    };
} dvec2;

typedef struct
{
    union
    {
        struct
        {
            unsigned x, y;
        };
        unsigned mem[2];
    };
} uvec2;

typedef struct
{
    union
    {
        struct
        {
            int x, y;
        };
        int mem[2];
    };
} ivec2;

typedef struct
{
    union
    {
        struct
        {
            float x, y, z;
        };
        float mem[3];
    };
} fvec3;

typedef struct
{
    union
    {
        struct
        {
            double x, y, z;
        };
        double mem[3];
    };
} dvec3;

typedef struct
{
    union
    {
        struct
        {
            unsigned x, y, z;
        };
        unsigned mem[3];
    };
} uvec3;

typedef struct
{
    union
    {
        struct
        {
            int x, y, z;
        };
        int mem[3];
    };
} ivec3;

typedef struct
{
    union
    {
        struct
        {
            float x, y, z, w;
        };
        float mem[4];
    };
} fvec4;

typedef struct
{
    union
    {
        struct
        {
            double x, y, z, w;
        };
        double mem[4];
    };
} dvec4;

typedef struct
{
    union
    {
        struct
        {
            unsigned x, y, z, w;
        };
        unsigned mem[4];
    };
} uvec4;

typedef struct
{
    union
    {
        struct
        {
            int x, y, z, w;
        };
        int mem[4];
    };
} ivec4;

//NOTE(Stanisz13): MATRICES
//NOTE(Stanisz13): FLOAT
typedef struct
{
    union
    {
        struct
        {
            fvec2 col1, col2;
        };
        float mem[4];
    };
} fmat2;

typedef struct
{
    union
    {
        struct
        {
            fvec3 col1, col2, col3;
        };
        float mem[9];
    };
} fmat3;

typedef struct
{
    union
    {
        struct
        {
            fvec4 col1, col2, col3, col4;
        };
        float mem[16];
    };
} fmat4;

//NOTE(Stanisz13): RANDOM
typedef struct
{
    unsigned seed;
    
} RandomSeries;

//NOTE(Stanisz13): GLOBALS
RandomSeries randomSeries_FA;


//NOTE(Stanisz13): FUNCTIONS
//NOTE(Stanisz13): NUMERIC
float absFloat(const float v);
int absInt(const int v);
double absDouble(const double v);

float minFloat(const float v, const float w);
float maxFloat(const float v, const float w);
double minDouble(const double v, const double w);
double maxDouble(const double v, const double w);
int maxInt(const int v, const int w);
int minInt(const int v, const int w);
unsigned minUnsigned(const unsigned v, const unsigned w);
unsigned maxUnsigned(const unsigned v, const unsigned w);

//NOTE(Stanisz13): RANDOM
void setRandomSeed(const unsigned s);
void setRandomSeedTime();

unsigned getRandomUnsignedOnInterval(const unsigned a, const unsigned b);
float getRandomFloatOnInterval(const float a, const float b);
double getRandomDoubleOnInterval(const double a, const double b);
int getRandomIntOnInterval(const int a, const int b);

fvec2 getRandomFVec2OnInterval(const float a, const float b);
dvec2 getRandomDVec2OnInterval(const double a, const double b);
uvec2 getRandomUVec2OnInterval(const unsigned a, const unsigned b);
ivec2 getRandomIVec2OnInterval(const int a, const int b);
fvec3 getRandomFVec3OnInterval(const float a, const float b);
dvec3 getRandomDVec3OnInterval(const double a, const double b);
uvec3 getRandomUVec3OnInterval(const unsigned a, const unsigned b);
ivec3 getRandomIVec3OnInterval(const int a, const int b);
fvec4 getRandomFVec4OnInterval(const float a, const float b);
dvec4 getRandomDVec4OnInterval(const double a, const double b);
uvec4 getRandomUVec4OnInterval(const unsigned a, const unsigned b);
ivec4 getRandomIVec4OnInterval(const int a, const int b);

//NOTE(Stanisz13): VECTORS
fvec2 scaleFVec2ByConstant(const fvec2 v, const float s);
dvec2 scaleDVec2ByConstant(const dvec2 v, const double s);
uvec2 scaleUVec2ByConstant(const uvec2 v, const unsigned s);
ivec2 scaleIVec2ByConstant(const ivec2 v, const int s);
fvec3 scaleFVec3ByConstant(const fvec3 v, const float s);
dvec3 scaleDVec3ByConstant(const dvec3 v, const double s);
uvec3 scaleUVec3ByConstant(const uvec3 v, const unsigned s);
ivec3 scaleIVec3ByConstant(const ivec3 v, const int s);
fvec4 scaleFVec4ByConstant(const fvec4 v, const float s);
dvec4 scaleDVec4ByConstant(const dvec4 v, const double s);
uvec4 scaleUVec4ByConstant(const uvec4 v, const unsigned s);
ivec4 scaleIVec4ByConstant(const ivec4 v, const int s);

fvec2 addFVec2(const fvec2 v, const fvec2 w);
dvec2 addDVec2(const dvec2 v, const dvec2 w);
uvec2 addUVec2(const uvec2 v, const uvec2 w);
ivec2 addIVec2(const ivec2 v, const ivec2 w);
fvec3 addFVec3(const fvec3 v, const fvec3 w);
dvec3 addDVec3(const dvec3 v, const dvec3 w);
uvec3 addUVec3(const uvec3 v, const uvec3 w);
ivec3 addIVec3(const ivec3 v, const ivec3 w);
fvec4 addFVec4(const fvec4 v, const fvec4 w);
dvec4 addDVec4(const dvec4 v, const dvec4 w);
uvec4 addUVec4(const uvec4 v, const uvec4 w);
ivec4 addIVec4(const ivec4 v, const ivec4 w);

fvec2 hadamardFVec2(const fvec2 v, const fvec2 w);
dvec2 hadamardDVec2(const dvec2 v, const dvec2 w);
uvec2 hadamardUVec2(const uvec2 v, const uvec2 w);
ivec2 hadamardIVec2(const ivec2 v, const ivec2 w);
fvec3 hadamardFVec3(const fvec3 v, const fvec3 w);
dvec3 hadamardDVec3(const dvec3 v, const dvec3 w);
uvec3 hadamardUVec3(const uvec3 v, const uvec3 w);
ivec3 hadamardIVec3(const ivec3 v, const ivec3 w);
fvec4 hadamardFVec4(const fvec4 v, const fvec4 w);
dvec4 hadamardDVec4(const dvec4 v, const dvec4 w);
uvec4 hadamardUVec4(const uvec4 v, const uvec4 w);
ivec4 hadamardIVec4(const ivec4 v, const ivec4 w);

//NOTE(Stanisz13): MATRICES

float* accessFMat2(fmat2* m, const unsigned x, const unsigned y);
float* accessFMat3(fmat3* m, const unsigned x, const unsigned y);
float* accessFMat4(fmat4* m, const unsigned x, const unsigned y);

fmat2 setFMat2ByElements(const float* data);
fmat3 setFMat3ByElements(const float* data);
fmat4 setFMat4ByElements(const float* data);

fmat2 setFMat2ByVectors(const fvec2 a, const fvec2 b);
fmat3 setFMat3ByVectors(const fvec3 a, const fvec3 b, const fvec3 c);
fmat4 setFMat4ByVectors(const fvec4 a, const fvec4 b, const fvec4 c, const fvec4 d);

fmat2 mulFMat2(const fmat2 a, const fmat2 b);
fmat3 mulFMat3(const fmat3 a, const fmat3 b);
fmat4 mulFMat4(const fmat4 a, const fmat4 b);

#endif
