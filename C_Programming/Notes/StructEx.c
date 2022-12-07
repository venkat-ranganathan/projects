
// Include for printing data to the screen
#include <stdio.h>

// Inlude for the srand and rand function
#include <stdlib.h>

// Include for the time function
#include <time.h>

struct dataType
{
	// Declare three integers inside our structure
	int first, second, third;
};

// ProtoTypes
void FillData(struct dataType *pData);
double FindAverage(struct dataType data);
int FindMin(struct dataType data);
int FindMax(struct dataType data);
int AboveAverage(struct dataType data, double average);
void PrintResults(struct dataType data, int min, int max, int numberAboveAverage, double average);

int main(void)
{
	// Create a structure of type dataType
	struct dataType data;

	double average;
	int min;
	int max;
	int numberAboveAverage;

	time_t myTime;

	// Initializes random number generator to the clock
	srand((unsigned int)time(&myTime));

	for (int counter = 0; counter < 5; counter++)
	{
		// Assign random data to the values of data
		FillData(&data);

		// Find the average of the three members of the structure
		average = FindAverage(data);

		// Find the smallest value of the three members of the structure
		min = FindMin(data);

		// Find the largest value of the three members of the structure
		max = FindMax(data);

		// Find the average of the three members of the structure
		numberAboveAverage = AboveAverage(data, average);

		// Print all the results
		PrintResults(data, min, max, numberAboveAverage, average);
	}

	return 0;
}

void PrintResults(struct dataType data, int min, int max, int numberAboveAverage, double average)
{
	// Print a divider
	printf("-----------------------------------------\n");

	// Print all the data to the screen
	printf("Numbers:\n");
	printf("   First : %d\n", data.first);
	printf("   Second: %d\n", data.second);
	printf("   Third : %d\n\n", data.third);
	printf("Average       = %lf\n", average);
	printf("Min           = %d\n", min);
	printf("Max           = %d\n", max);
	printf("Above Average = %d\n", numberAboveAverage);

	// Print a divider
	printf("-----------------------------------------\n\n");
}

int AboveAverage(struct dataType data, double average)
{
	int numberAboveAverage = 0;

	// Check to see if the first integer is greater than the average
	if (data.first > average)
	{
		// Increase the counter by 1
		numberAboveAverage++;
	}

	// Check to see if the second integer is greater than the average
	if (data.second > average)
	{
		// Increase the counter by 1
		numberAboveAverage++;
	}

	// Check to see if the third integer is greater than the average
	if (data.third > average)
	{
		// Increase the counter by 1
		numberAboveAverage++;
	}

	// Pass the counter back to where the function was called from
	return numberAboveAverage;
}

int FindMax(struct dataType data)
{
	// Assume the first integer is the largest
	int max = data.first;

	// Check to see if the second integer is larger than max
	if (data.second > max)
	{
		// Assign max a new value
		max = data.second;
	}

	// Check to see if the third integer is larger than max
	if (data.third > max)
	{
		// Assign max a new value
		max = data.third;
	}

	// Pass the max back to where the function was called from
	return max;
}

int FindMin(struct dataType data)
{
	// Assume the first integer is the smallest
	int smallest = data.first;

	// Check to see if the second integer is smaller than smallest
	if (data.second < smallest)
	{
		// Assign smallest a new value
		smallest = data.second;
	}

	// Check to see if the third integer is smaller than smallest
	if (data.third < smallest)
	{
		// Assign smallest a new value
		smallest = data.third;
	}

	// Pass the smallest back to where the function was called from
	return smallest;
}

double FindAverage(struct dataType data)
{
	int sum = 0;

	// Add the three numbers and assign them to sum
	sum += data.first;
	sum += data.second;
	sum += data.third;

	// Pass the average back to where the function was called from
	return (double)sum / 3;
}

void FillData(struct dataType *pData)
{
	// Create three random numbers
	pData->first = rand() % 100;
	pData->second = rand() % 100;
	pData->third = rand() % 100;
}