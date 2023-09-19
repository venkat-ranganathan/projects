// use this to do last lab

// preprocessor directive
#include <stdio.h>  // needed for printf
#include <stdlib.h> // needed for srand
#include <time.h>   // needed for time_h

// structure definition
struct dataType
{
    int first, second, third;
};

// function prototype
void fillData(struct dataType *pData);
double findAverage(struct dataType data);
int findMin(struct dataType data);
int findMax(struct dataType data);
int aboveAverage(struct dataType data, double average);
void printResults(struct dataType data, int min, int max, int numberAboveAverage, double average);

int main()
{
    // declare structure dataType variable
    struct dataType data;

    // declare variables
    double average;
    int min, max, numberAboveAverage;

    for (int counter = 0; counter < 5; counter++)
    {
        // call fillData function and pass data from structure to it
        fillData(&data);

        // set variables equal to function to find its corresponding value
        average = findAverage(data);
        min = findMin(data);
        max = findMax(data);
        numberAboveAverage = aboveAverage(data, average);

        // passes all generated data for variables to printResults function
        printResults(data, min, max, numberAboveAverage, average);
    }

    return 0;
}

void printResults(struct dataType data, int min, int max, int numberAboveAverage, double average)
{
    printf("-------------------------------------------------\n");
    printf("The first number is: %d\n", data.first);
    printf("The second number is: %d\n", data.second);
    printf("The third number is: %d\n\n", data.third);

    printf("The average is: %lf\n", average);

    printf("The min value is: %d\n", min);
    printf("The max value is: %d\n", max);
    printf("The number above the average is: %d\n\n", max);
}
// finds value above the average
int aboveAverage(struct dataType data, double average)
{
    int numberAboveAverage = 0;

    if (data.first > average)
    {
        numberAboveAverage++;
    }
    if (data.second > average)
    {
        numberAboveAverage++;
    }
    if (data.third > average)
    {
        numberAboveAverage++;
    }

    return numberAboveAverage;
}

// finds max value
int findMax(struct dataType data)
{
    // set first data as largest to start
    int largest = data.first;

    if (data.second > largest)
    {
        largest = data.second;
    }

    if (data.third > largest)
    {
        largest = data.third;
    }

    return largest;
}

// finds min value
int findMin(struct dataType data)
{
    // set first data as smallest to start
    int smallest = data.first;

    if (data.second < smallest)
    {
        smallest = data.second;
    }

    if (data.third < smallest)
    {
        smallest = data.third;
    }

    return smallest;
}

// finds average
double findAverage(struct dataType data)
{
    int sum = 0;

    sum += data.first;
    sum += data.second;
    sum += data.third;

    return (double)sum / 3;
}

// generates random numbers for first, second, and third variables
void fillData(struct dataType *pData)
{
    int randomNumber;
    time_t t;

    // Initializes random number generator to the clock
    srand((unsigned int)time(&t));

    // generate random number between 0 and 100
    pData->first = rand() & 100;
    pData->second = rand() & 100;
    pData->third = rand() & 100;
}