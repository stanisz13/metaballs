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
} FVec2;

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
} DVec2;

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
} UVec2;

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
} IVec2;

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
} FVec3;

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
} DVec3;

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
} UVec3;

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
} IVec3;

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
} FVec4;

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
} DVec4;

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
} UVec4;

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
} IVec4;

//NOTE(Stanisz13): MATRICES
//NOTE(Stanisz13): FLOAT
typedef struct
{
    union
    {
        struct
        {
            FVec2 col1, col2;
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
            FVec3 col1, col2, col3;
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
            FVec4 col1, col2, col3, col4;
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

FVec2 getRandomFVec2OnInterval(const float a, const float b);
DVec2 getRandomDVec2OnInterval(const double a, const double b);
UVec2 getRandomUVec2OnInterval(const unsigned a, const unsigned b);
IVec2 getRandomIVec2OnInterval(const int a, const int b);
FVec3 getRandomFVec3OnInterval(const float a, const float b);
DVec3 getRandomDVec3OnInterval(const double a, const double b);
UVec3 getRandomUVec3OnInterval(const unsigned a, const unsigned b);
IVec3 getRandomIVec3OnInterval(const int a, const int b);
FVec4 getRandomFVec4OnInterval(const float a, const float b);
DVec4 getRandomDVec4OnInterval(const double a, const double b);
UVec4 getRandomUVec4OnInterval(const unsigned a, const unsigned b);
IVec4 getRandomIVec4OnInterval(const int a, const int b);

//NOTE(Stanisz13): VECTORS
FVec2 scaleFVec2ByConstant(const FVec2 v, const float s);
DVec2 scaleDVec2ByConstant(const DVec2 v, const double s);
UVec2 scaleUVec2ByConstant(const UVec2 v, const unsigned s);
IVec2 scaleIVec2ByConstant(const IVec2 v, const int s);
FVec3 scaleFVec3ByConstant(const FVec3 v, const float s);
DVec3 scaleDVec3ByConstant(const DVec3 v, const double s);
UVec3 scaleUVec3ByConstant(const UVec3 v, const unsigned s);
IVec3 scaleIVec3ByConstant(const IVec3 v, const int s);
FVec4 scaleFVec4ByConstant(const FVec4 v, const float s);
DVec4 scaleDVec4ByConstant(const DVec4 v, const double s);
UVec4 scaleUVec4ByConstant(const UVec4 v, const unsigned s);
IVec4 scaleIVec4ByConstant(const IVec4 v, const int s);

FVec2 addFVec2(const FVec2 v, const FVec2 w);
DVec2 addDVec2(const DVec2 v, const DVec2 w);
UVec2 addUVec2(const UVec2 v, const UVec2 w);
IVec2 addIVec2(const IVec2 v, const IVec2 w);
FVec3 addFVec3(const FVec3 v, const FVec3 w);
DVec3 addDVec3(const DVec3 v, const DVec3 w);
UVec3 addUVec3(const UVec3 v, const UVec3 w);
IVec3 addIVec3(const IVec3 v, const IVec3 w);
FVec4 addFVec4(const FVec4 v, const FVec4 w);
DVec4 addDVec4(const DVec4 v, const DVec4 w);
UVec4 addUVec4(const UVec4 v, const UVec4 w);
IVec4 addIVec4(const IVec4 v, const IVec4 w);

FVec2 hadamardFVec2(const FVec2 v, const FVec2 w);
DVec2 hadamardDVec2(const DVec2 v, const DVec2 w);
UVec2 hadamardUVec2(const UVec2 v, const UVec2 w);
IVec2 hadamardIVec2(const IVec2 v, const IVec2 w);
FVec3 hadamardFVec3(const FVec3 v, const FVec3 w);
DVec3 hadamardDVec3(const DVec3 v, const DVec3 w);
UVec3 hadamardUVec3(const UVec3 v, const UVec3 w);
IVec3 hadamardIVec3(const IVec3 v, const IVec3 w);
FVec4 hadamardFVec4(const FVec4 v, const FVec4 w);
DVec4 hadamardDVec4(const DVec4 v, const DVec4 w);
UVec4 hadamardUVec4(const UVec4 v, const UVec4 w);
IVec4 hadamardIVec4(const IVec4 v, const IVec4 w);

float dotProductFVec2(const FVec2 v, const FVec2 w);
double dotProductDVec2(const DVec2 v, const DVec2 w);
unsigned dotProductUVec2(const UVec2 v, const UVec2 w);
int dotProductIVec2(const IVec2 v, const IVec2 w);
float dotProductFVec3(const FVec3 v, const FVec3 w);
double dotProductDVec3(const DVec3 v, const DVec3 w);
unsigned dotProductUVec3(const UVec3 v, const UVec3 w);
int dotProductIVec3(const IVec3 v, const IVec3 w);
float dotProductFVec4(const FVec4 v, const FVec4 w);
double dotProductDVec4(const DVec4 v, const DVec4 w);
unsigned dotProductUVec4(const UVec4 v, const UVec4 w);
int dotProductIVec4(const IVec4 v, const IVec4 w);

float lengthFVec2(const FVec2 v);
double lengthDVec2(const DVec2 v);
float lengthUVec2(const UVec2 v);
float lengthIVec2(const IVec2 v);

//NOTE(Stanisz13): MATRICES

float* accessFMat2(fmat2* m, const unsigned x, const unsigned y);
float* accessFMat3(fmat3* m, const unsigned x, const unsigned y);
float* accessFMat4(fmat4* m, const unsigned x, const unsigned y);

fmat2 setFMat2ByElements(const float* data);
fmat3 setFMat3ByElements(const float* data);
fmat4 setFMat4ByElements(const float* data);

fmat2 setFMat2ByVectors(const FVec2 a, const FVec2 b);
fmat3 setFMat3ByVectors(const FVec3 a, const FVec3 b, const FVec3 c);
fmat4 setFMat4ByVectors(const FVec4 a, const FVec4 b, const FVec4 c, const FVec4 d);

fmat2 mulFMat2(const fmat2 a, const fmat2 b);
fmat3 mulFMat3(const fmat3 a, const fmat3 b);
fmat4 mulFMat4(const fmat4 a, const fmat4 b);

#endif
