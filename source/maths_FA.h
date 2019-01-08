#ifndef MATHS_FA__H
#define MATHS_FA__H

typedef struct
{
    unsigned seed;
    
} RandomSeries;

RandomSeries randomSeries_FA;

unsigned getRandomUnsignedOnInterval(const unsigned a, const unsigned b);

float getRandomFloatOnInterval(const float a, const float b);

#endif
