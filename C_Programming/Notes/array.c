
// Include for input and output to and from the screen
#include <stdio.h>

void InitializeArray(int array[]);

void PrintArray(int array[]);

void AddTenToEachElement(int numbers[]);

int TotalArray(int numbers[]);

void PrintTotal(int total);

double CalculateAverage(int numbers[]);

void PrintAverage(double average);

#define SIZE 5

int main(void)
{
	int numbers[SIZE];
	
	int total;
	double average;
	
	InitializeArray(numbers);
	
	PrintArray(numbers);
	
	AddTenToEachElement(numbers);
	
	PrintArray(numbers);
	
	total = TotalArray(numbers);
	
	PrintTotal(total);
	
	average = CalculateAverage(numbers);
	
	PrintAverage(average);
	
	return 0;
}

void InitializeArray(int array[])
{
	// Local variable, only visible in the function
	int counter = 0;
	
	while (counter < SIZE) // Test will be true when counter = 0, 1, 2, 4
	{
		// Prompt the user for a value and store in the array
		printf("Enter value for element %d: ", counter);
		scanf("%d",&array[counter]);
		
		// Changer
		counter++;
	}
}

void PrintArray(int array[])
{
	int counter = 0;
	
	// Print header to the screen
	printf("     NUMBERS\n");
	printf("     -------\n");
	
	while(counter < SIZE)
	{
		// Print one element of the array to the screen
		printf("\t%d\n", array[counter]);
		
		// Changer
		counter++;
	}	
	
	// Move the cursor down one more line
	printf("\n");
}

void AddTenToEachElement(int numbers[])
{
	int counter = 0;
	
	while (counter < SIZE)
	{
		// Add 10 to element of the array
		numbers[counter] += 10;
		
		// Changer
		counter++;
	}
}

int TotalArray(int numbers[])
{
	int total = 0;
	
	int counter = 0;
	
	while (counter < SIZE)
	{
		// Add element of the array to total
		total += numbers[counter];
		
		// Changer
		counter++;
	}
	
	return total;
}

void PrintTotal(int total)
{
	// Print the total to the screen
	printf("Total: %d\n\n", total);
}

double CalculateAverage(int numbers[])
{
	double average = 0;
	
	int total; 
	
	if (SIZE != 0)
	{  
		// Get the total of the array
		total = TotalArray(numbers);
		
		// Calculate average
		average = (double)total / SIZE;
	}
	
	return average;
}

void PrintAverage(double average)
{
	// Print the average to the screen
	printf("Average: %0.2lf\n\n", average);
}