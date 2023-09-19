/*

ex: int data1;

int = data type

data1 = variable

*/

/*

sttucture example:

// struct is a keyword
struct data_type
{

} data; // structure can work withou data; data is a globar variable if you put it into header file (avoid doing that)

*/

/*

// declare structure in header file (declared in int main for this example)
struct pointType
{
    int x, y, z;
};

*/

// preprocessor directives
#include "structures.h"

int main()
{
    // declare structure; pointType = data type; myPoint = data
    struct pointType myPoint;
    struct playerScoreType player;
    struct dataType data[2];

    // function prototype
    void foo(struct dataType data);

    // myPoint.x is an integer
    // the period (.) is called the "member operator"
    myPoint.x = 0;
    myPoint.y = 0;
    myPoint.z = 0;

    // declare 30 structures, numbered from 0 to 29
    struct pointType pointArray[30];

    // assign value to element of array for x
    pointArray[0].x = 5;
    pointArray[1].x = 15;

    for (int index = 0; index < 30; index++)
    {
        // zero out all values of array elements for x, y, and z
        pointArray[index].x = 0;
        pointArray[index].y = 0;
        pointArray[index].z = 0;
    }

    // declare structure, data type, and data array
    struct playerScoreType players[20];

    // copy player name; name is array variable declared inside structure
    strcpy(player.name, "Joe");

    for (int index = 0; index < 10; index++)
    {
        // player is the data type; scores is array variable declared inside structure
        player.scores[index] = 0;
    }

    for (int pIndex = 0; pIndex < 20; pIndex++)
    {
        strcpy(players[pIndex].name, "~");

        for (int sIndex = 0; sIndex < 10; sIndex++)
        {
            // zero out all scores (o to 10) for every player (0 to 20)
            players[pIndex].scores[sIndex] = 0;
        }
    }

    for (int index = 0; index < 2; index++)
    {
        // call function
        // data is array, [] is the array index
        foo(data[index]);
    }

    return 0;
}

// struct needs to be delcared inside function ()
// everything inside () is one struture of data
void foo(struct dataType data)
{
    data.red = 0;
    data.blue[0] = 0;
    data.blue[1] = 0;
}