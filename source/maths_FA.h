#ifndef MATHS_FA__H
#define MATHS_FA__H

#include "log_FA.h"

#define EPSILON 0.0000001f
#define EPSILON_DOUBLE 0.0000000000001f

//NOTE(Stanisz13): VECTORS
typedef struct
{
    float x, y;
} fvec2;

typedef struct
{
    double x, y;
} dvec2;

typedef struct
{
    unsigned x, y;
} uvec2;

typedef struct
{
    int x, y;
} ivec2;

typedef struct
{
    float x, y, z;
} fvec3;

typedef struct
{
    double x, y, z;
} dvec3;

typedef struct
{
    unsigned x, y, z;
} uvec3;

typedef struct
{
    int x, y, z;
} ivec3;

typedef struct
{
    float x, y, z, w;
} fvec4;

typedef struct
{
    double x, y, z, w;
} dvec4;

typedef struct
{
    unsigned x, y, z, w;
} uvec4;

typedef struct
{
    int x, y, z, w;
} ivec4;

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

unsigned getRandomUnsignedOnInterval(const unsigned a, const unsigned b);

float getRandomFloatOnInterval(const float a, const float b);

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

#endif
