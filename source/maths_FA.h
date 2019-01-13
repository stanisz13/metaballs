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
} FMat2;

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
} FMat3;

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
} FMat4;

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
FVec2 scaleFVec2(const FVec2 v, const float s);
DVec2 scaleDVec2(const DVec2 v, const double s);
UVec2 scaleUVec2(const UVec2 v, const unsigned s);
IVec2 scaleIVec2(const IVec2 v, const int s);
FVec3 scaleFVec3(const FVec3 v, const float s);
DVec3 scaleDVec3(const DVec3 v, const double s);
UVec3 scaleUVec3(const UVec3 v, const unsigned s);
IVec3 scaleIVec3(const IVec3 v, const int s);
FVec4 scaleFVec4(const FVec4 v, const float s);
DVec4 scaleDVec4(const DVec4 v, const double s);
UVec4 scaleUVec4(const UVec4 v, const unsigned s);
IVec4 scaleIVec4(const IVec4 v, const int s);

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

float lengthSquaredFVec2(const FVec2 v);
double lengthSquaredDVec2(const DVec2 v);
unsigned lengthSquaredUVec2(const UVec2 v);
unsigned lengthSquaredIVec2(const IVec2 v);
float lengthSquaredFVec3(const FVec3 v);
double lengthSquaredDVec3(const DVec3 v);
unsigned lengthSquaredUVec3(const UVec3 v);
unsigned lengthSquaredIVec3(const IVec3 v);
float lengthSquaredFVec4(const FVec4 v);
double lengthSquaredDVec4(const DVec4 v);
unsigned lengthSquaredUVec4(const UVec4 v);
unsigned lengthSquaredIVec4(const IVec4 v);

float lengthFVec2(const FVec2 v);
double lengthDVec2(const DVec2 v);
float lengthUVec2(const UVec2 v);
float lengthIVec2(const IVec2 v);
float lengthFVec3(const FVec3 v);
double lengthDVec3(const DVec3 v);
float lengthUVec3(const UVec3 v);
float lengthIVec3(const IVec3 v);
float lengthFVec4(const FVec4 v);
double lengthDVec4(const DVec4 v);
float lengthUVec4(const UVec4 v);
float lengthIVec4(const IVec4 v);

//NOTE(Stanisz13): MATRICES

float* accessFMat2(FMat2* m, const unsigned x, const unsigned y);
float* accessFMat3(FMat3* m, const unsigned x, const unsigned y);
float* accessFMat4(FMat4* m, const unsigned x, const unsigned y);

FMat2 setFMat2ByElements(const float* data);
FMat3 setFMat3ByElements(const float* data);
FMat4 setFMat4ByElements(const float* data);

FMat2 setFMat2ByVectors(const FVec2 a, const FVec2 b);
FMat3 setFMat3ByVectors(const FVec3 a, const FVec3 b, const FVec3 c);
FMat4 setFMat4ByVectors(const FVec4 a, const FVec4 b, const FVec4 c, const FVec4 d);

FMat2 addFMat2(const FMat2 a, const FMat2 b);
FMat2 addFMat3(const FMat3 a, const FMat3 b);
FMat2 addFMat4(const FMat4 a, const FMat4 b);

FMat2 scaleFMat2(const FMat2 a, const float b);
FMat2 scaleFMat3(const FMat3 a, const float b);
FMat2 scaleFMat4(const FMat4 a, const float b);

FMat2 mulFMat2(const FMat2 a, const FMat2 b);
FMat3 mulFMat3(const FMat3 a, const FMat3 b);
FMat4 mulFMat4(const FMat4 a, const FMat4 b);

#endif
