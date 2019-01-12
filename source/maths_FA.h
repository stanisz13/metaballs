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

//NOTE(Stanisz13): MATRICES
//NOTE(Stanisz13): FLOAT
typedef struct
{
    fvec2 a;
    fvec2 b;
} fmat2x2;

typedef struct
{
    fvec3 a;
    fvec3 b;
} fmat2x3;

typedef struct
{
    fvec4 a;
    fvec4 b;
} fmat2x4;

typedef struct
{
    fvec2 a;
    fvec2 b;
    fvec2 c;
} fmat3x2;

typedef struct
{
    fvec3 a;
    fvec3 b;
    fvec3 c;
} fmat3x3;

typedef struct
{
    fvec4 a;
    fvec4 b;
    fvec4 c;
} fmat3x4;

typedef struct
{
    fvec2 a;
    fvec2 b;
    fvec2 c;
    fvec2 d;
} fmat4x2;

typedef struct
{
    fvec3 a;
    fvec3 b;
    fvec3 c;
    fvec3 d;
} fmat4x3;

typedef struct
{
    fvec4 a;
    fvec4 b;
    fvec4 c;
    fvec4 d;
} fmat4x4;
//NOTE(Stanisz13): DOUBLE
typedef struct
{
    dvec2 a;
    dvec2 b;
} dmat2x2;

typedef struct
{
    dvec3 a;
    dvec3 b;
} dmat2x3;

typedef struct
{
    dvec4 a;
    dvec4 b;
} dmat2x4;

typedef struct
{
    dvec2 a;
    dvec2 b;
    dvec2 c;
} dmat3x2;

typedef struct
{
    dvec3 a;
    dvec3 b;
    dvec3 c;
} dmat3x3;

typedef struct
{
    dvec4 a;
    dvec4 b;
    dvec4 c;
} dmat3x4;

typedef struct
{
    dvec2 a;
    dvec2 b;
    dvec2 c;
    dvec2 d;
} dmat4x2;

typedef struct
{
    dvec3 a;
    dvec3 b;
    dvec3 c;
    dvec3 d;
} dmat4x3;

typedef struct
{
    dvec4 a;
    dvec4 b;
    dvec4 c;
    dvec4 d;
} dmat4x4;
//NOTE(Stanisz13): UNSIGNED INT
typedef struct
{
    uvec2 a;
    uvec2 b;
} umat2x2;

typedef struct
{
    uvec3 a;
    uvec3 b;
} umat2x3;

typedef struct
{
    uvec4 a;
    uvec4 b;
} umat2x4;

typedef struct
{
    uvec2 a;
    uvec2 b;
    uvec2 c;
} umat3x2;

typedef struct
{
    uvec3 a;
    uvec3 b;
    uvec3 c;
} umat3x3;

typedef struct
{
    uvec4 a;
    uvec4 b;
    uvec4 c;
} umat3x4;

typedef struct
{
    uvec2 a;
    uvec2 b;
    uvec2 c;
    uvec2 d;
} umat4x2;

typedef struct
{
    uvec3 a;
    uvec3 b;
    uvec3 c;
    uvec3 d;
} umat4x3;

typedef struct
{
    uvec4 a;
    uvec4 b;
    uvec4 c;
    uvec4 d;
} umat4x4;
//NOTE(Stanisz13): INT
typedef struct
{
    ivec2 a;
    ivec2 b;
} imat2x2;

typedef struct
{
    ivec3 a;
    ivec3 b;
} imat2x3;

typedef struct
{
    ivec4 a;
    ivec4 b;
} imat2x4;

typedef struct
{
    ivec2 a;
    ivec2 b;
    ivec2 c;
} imat3x2;

typedef struct
{
    ivec3 a;
    ivec3 b;
    ivec3 c;
} imat3x3;

typedef struct
{
    ivec4 a;
    ivec4 b;
    ivec4 c;
} imat3x4;

typedef struct
{
    ivec2 a;
    ivec2 b;
    ivec2 c;
    ivec2 d;
} imat4x2;

typedef struct
{
    ivec3 a;
    ivec3 b;
    ivec3 c;
    ivec3 d;
} imat4x3;

typedef struct
{
    ivec4 a;
    ivec4 b;
    ivec4 c;
    ivec4 d;
} imat4x4;

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
//NOTE(Stanisz13): FLOAT
fmat2x2 mulFMat2x2by2x2(const fmat2x2 a, const fmat2x2 b);
fmat2x2 mulFMat2x3by3x2(const fmat2x3 a, const fmat3x2 b);
fmat2x2 mulFMat2x4by4x2(const fmat2x4 a, const fmat4x2 b);

fmat2x3 mulFMat2x2by2x3(const fmat2x2 a, const fmat2x3 b);
fmat2x3 mulFMat2x3by3x3(const fmat2x3 a, const fmat3x3 b);
fmat2x3 mulFMat2x4by4x3(const fmat2x4 a, const fmat4x3 b);

fmat2x4 mulFMat2x2by2x4(const fmat2x2 a, const fmat2x4 b);
fmat2x4 mulFMat2x3by3x4(const fmat2x3 a, const fmat3x4 b);
fmat2x4 mulFMat2x4by4x4(const fmat2x4 a, const fmat4x4 b);

fmat3x2 mulFMat3x2by2x2(const fmat3x2 a, const fmat2x2 b);
fmat3x2 mulFMat3x3by3x2(const fmat3x3 a, const fmat3x2 b);
fmat3x2 mulFMat3x4by4x2(const fmat3x4 a, const fmat4x2 b);

fmat4x2 mulFMat4x2by2x2(const fmat4x2 a, const fmat2x2 b);
fmat4x2 mulFMat4x3by3x2(const fmat4x3 a, const fmat3x2 b);
fmat4x2 mulFMat4x4by4x2(const fmat4x4 a, const fmat4x2 b);

fmat3x3 mulFMat3x2by2x3(const fmat3x2 a, const fmat2x3 b);
fmat3x3 mulFMat3x3by3x3(const fmat3x3 a, const fmat3x3 b);
fmat3x3 mulFMat3x4by4x3(const fmat3x4 a, const fmat4x3 b);

fmat3x4 mulFMat3x2by2x4(const fmat3x2 a, const fmat2x4 b);
fmat3x4 mulFMat3x3by3x4(const fmat3x3 a, const fmat3x4 b);
fmat3x4 mulFMat3x4by4x4(const fmat3x4 a, const fmat4x4 b);

fmat4x3 mulFMat4x2by2x3(const fmat4x2 a, const fmat2x3 b);
fmat4x3 mulFMat4x3by3x3(const fmat4x3 a, const fmat3x3 b);
fmat4x3 mulFMat4x4by4x3(const fmat4x4 a, const fmat4x3 b);

fmat4x4 mulFMat4x2by2x4(const fmat4x2 a, const fmat2x4 b);
fmat4x4 mulFMat4x3by3x4(const fmat4x3 a, const fmat3x4 b);
fmat4x4 mulFMat4x4by4x4(const fmat4x4 a, const fmat4x4 b);

//NOTE(Stanisz13): DOUBLE
dmat2x2 mulDMat2x2by2x2(const dmat2x2 a, const dmat2x2 b);
dmat2x2 mulDMat2x3by3x2(const dmat2x3 a, const dmat3x2 b);
dmat2x2 mulDMat2x4by4x2(const dmat2x4 a, const dmat4x2 b);

dmat2x3 mulDMat2x2by2x3(const dmat2x2 a, const dmat2x3 b);
dmat2x3 mulDMat2x3by3x3(const dmat2x3 a, const dmat3x3 b);
dmat2x3 mulDMat2x4by4x3(const dmat2x4 a, const dmat4x3 b);

dmat2x4 mulDMat2x2by2x4(const dmat2x2 a, const dmat2x4 b);
dmat2x4 mulDMat2x3by3x4(const dmat2x3 a, const dmat3x4 b);
dmat2x4 mulDMat2x4by4x4(const dmat2x4 a, const dmat4x4 b);

dmat3x2 mulDMat3x2by2x2(const dmat3x2 a, const dmat2x2 b);
dmat3x2 mulDMat3x3by3x2(const dmat3x3 a, const dmat3x2 b);
dmat3x2 mulDMat3x4by4x2(const dmat3x4 a, const dmat4x2 b);

dmat4x2 mulDMat4x2by2x2(const dmat4x2 a, const dmat2x2 b);
dmat4x2 mulDMat4x3by3x2(const dmat4x3 a, const dmat3x2 b);
dmat4x2 mulDMat4x4by4x2(const dmat4x4 a, const dmat4x2 b);

dmat3x3 mulDMat3x2by2x3(const dmat3x2 a, const dmat2x3 b);
dmat3x3 mulDMat3x3by3x3(const dmat3x3 a, const dmat3x3 b);
dmat3x3 mulDMat3x4by4x3(const dmat3x4 a, const dmat4x3 b);

dmat3x4 mulDMat3x2by2x4(const dmat3x2 a, const dmat2x4 b);
dmat3x4 mulDMat3x3by3x4(const dmat3x3 a, const dmat3x4 b);
dmat3x4 mulDMat3x4by4x4(const dmat3x4 a, const dmat4x4 b);

dmat4x3 mulDMat4x2by2x3(const dmat4x2 a, const dmat2x3 b);
dmat4x3 mulDMat4x3by3x3(const dmat4x3 a, const dmat3x3 b);
dmat4x3 mulDMat4x4by4x3(const dmat4x4 a, const dmat4x3 b);

dmat4x4 mulDMat4x2by2x4(const dmat4x2 a, const dmat2x4 b);
dmat4x4 mulDMat4x3by3x4(const dmat4x3 a, const dmat3x4 b);
dmat4x4 mulDMat4x4by4x4(const dmat4x4 a, const dmat4x4 b);

//NOTE(Stanisz13): UNSIGNED INT
umat2x2 mulUMat2x2by2x2(const umat2x2 a, const umat2x2 b);
umat2x2 mulUMat2x3by3x2(const umat2x3 a, const umat3x2 b);
umat2x2 mulUMat2x4by4x2(const umat2x4 a, const umat4x2 b);

umat2x3 mulUMat2x2by2x3(const umat2x2 a, const umat2x3 b);
umat2x3 mulUMat2x3by3x3(const umat2x3 a, const umat3x3 b);
umat2x3 mulUMat2x4by4x3(const umat2x4 a, const umat4x3 b);

umat2x4 mulUMat2x2by2x4(const umat2x2 a, const umat2x4 b);
umat2x4 mulUMat2x3by3x4(const umat2x3 a, const umat3x4 b);
umat2x4 mulUMat2x4by4x4(const umat2x4 a, const umat4x4 b);

umat3x2 mulUMat3x2by2x2(const umat3x2 a, const umat2x2 b);
umat3x2 mulUMat3x3by3x2(const umat3x3 a, const umat3x2 b);
umat3x2 mulUMat3x4by4x2(const umat3x4 a, const umat4x2 b);

umat4x2 mulUMat4x2by2x2(const umat4x2 a, const umat2x2 b);
umat4x2 mulUMat4x3by3x2(const umat4x3 a, const umat3x2 b);
umat4x2 mulUMat4x4by4x2(const umat4x4 a, const umat4x2 b);

umat3x3 mulUMat3x2by2x3(const umat3x2 a, const umat2x3 b);
umat3x3 mulUMat3x3by3x3(const umat3x3 a, const umat3x3 b);
umat3x3 mulUMat3x4by4x3(const umat3x4 a, const umat4x3 b);

umat3x4 mulUMat3x2by2x4(const umat3x2 a, const umat2x4 b);
umat3x4 mulUMat3x3by3x4(const umat3x3 a, const umat3x4 b);
umat3x4 mulUMat3x4by4x4(const umat3x4 a, const umat4x4 b);

umat4x3 mulUMat4x2by2x3(const umat4x2 a, const umat2x3 b);
umat4x3 mulUMat4x3by3x3(const umat4x3 a, const umat3x3 b);
umat4x3 mulUMat4x4by4x3(const umat4x4 a, const umat4x3 b);

umat4x4 mulUMat4x2by2x4(const umat4x2 a, const umat2x4 b);
umat4x4 mulUMat4x3by3x4(const umat4x3 a, const umat3x4 b);
umat4x4 mulUMat4x4by4x4(const umat4x4 a, const umat4x4 b);

//NOTE(Stanisz13): INT
imat2x2 mulIMat2x2by2x2(const imat2x2 a, const imat2x2 b);
imat2x2 mulIMat2x3by3x2(const imat2x3 a, const imat3x2 b);
imat2x2 mulIMat2x4by4x2(const imat2x4 a, const imat4x2 b);

imat2x3 mulIMat2x2by2x3(const imat2x2 a, const imat2x3 b);
imat2x3 mulIMat2x3by3x3(const imat2x3 a, const imat3x3 b);
imat2x3 mulIMat2x4by4x3(const imat2x4 a, const imat4x3 b);

imat2x4 mulIMat2x2by2x4(const imat2x2 a, const imat2x4 b);
imat2x4 mulIMat2x3by3x4(const imat2x3 a, const imat3x4 b);
imat2x4 mulIMat2x4by4x4(const imat2x4 a, const imat4x4 b);

imat3x2 mulIMat3x2by2x2(const imat3x2 a, const imat2x2 b);
imat3x2 mulIMat3x3by3x2(const imat3x3 a, const imat3x2 b);
imat3x2 mulIMat3x4by4x2(const imat3x4 a, const imat4x2 b);

imat4x2 mulIMat4x2by2x2(const imat4x2 a, const imat2x2 b);
imat4x2 mulIMat4x3by3x2(const imat4x3 a, const imat3x2 b);
imat4x2 mulIMat4x4by4x2(const imat4x4 a, const imat4x2 b);

imat3x3 mulIMat3x2by2x3(const imat3x2 a, const imat2x3 b);
imat3x3 mulIMat3x3by3x3(const imat3x3 a, const imat3x3 b);
imat3x3 mulIMat3x4by4x3(const imat3x4 a, const imat4x3 b);

imat3x4 mulIMat3x2by2x4(const imat3x2 a, const imat2x4 b);
imat3x4 mulIMat3x3by3x4(const imat3x3 a, const imat3x4 b);
imat3x4 mulIMat3x4by4x4(const imat3x4 a, const imat4x4 b);

imat4x3 mulIMat4x2by2x3(const imat4x2 a, const imat2x3 b);
imat4x3 mulIMat4x3by3x3(const imat4x3 a, const imat3x3 b);
imat4x3 mulIMat4x4by4x3(const imat4x4 a, const imat4x3 b);

imat4x4 mulIMat4x2by2x4(const imat4x2 a, const imat2x4 b);
imat4x4 mulIMat4x3by3x4(const imat4x3 a, const imat3x4 b);
imat4x4 mulIMat4x4by4x4(const imat4x4 a, const imat4x4 b);


#endif
