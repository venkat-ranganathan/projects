//
#include <stdio.h>

// structure definition should go inside header file
struct pointType
{
    int x, y;
};

// inside main or function

int main()
{
    struct pointType point;

    point.x = 16;
    point.y = 80;

    // address of pointer
    struct pointType *pPoint;

    // setting pointer as address of point
    pPoint = &point;

    // THIS WILL NOT WORK
    // because combining dereference (*) and member operator (.)
    // member operator occurs first, then dereferencing happens
    // *pPoint.x = 8;

    // correct way
    (*pPoint).x = 8;
    (*pPoint).y = 200;

    // called member by pointer operator
    // better way, dereferences first, then does member operator
    // only works on a pointer
    pPoint->x = 8;
    pPoint->y = 200;

    return 0;
}
