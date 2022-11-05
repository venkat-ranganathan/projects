
#include <stdio.h>

int main(void)
{
	// Create an array with 10 elements
	int myArray[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	// Create two integer pointers
	int *pStart;
	int *pEnd;

	// Start sum at 0
	int sum = 0;

	// Notice there are two primers, seperated by a comma

	for (pStart = myArray, pEnd = &myArray[9]; pStart <= pEnd; pStart++)
	{
		// Add the value pointed to by pStart to the sum
		sum += *pStart;
	}

	// Print the result to the screen
	printf("The sum is %d\n", sum);

	return 0;
}