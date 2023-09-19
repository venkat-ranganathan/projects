// header guards
#ifndef STRUCTURES_H
#define STRUCTURES_H

// preprocessor directives
#include <stdio.h>
#include <strings.h>

// declare structure in header file
struct pointType
{
    int x, y, z;
};

struct playerScoreType
{
    char name[30];
    int scores[10];
};

struct dataType
{
    int red;
    char blue[2];
};

// close header guard
#endif