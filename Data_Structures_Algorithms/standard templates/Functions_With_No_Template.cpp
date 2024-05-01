

#include <stdio.h>

using namespace std;

double DoubleTheValue(double value);
int    DoubleTheValue(int value);
short  DoubleTheValue(short value);
float  DoubleTheValue(float value);

int main(void)
{
	int intValue = 5;
	short shortValue = 20;
	float floatValue = 30.5;
	double doubleValue = 40.10;
	
	// Print results to the screen
	printf("\nData BEFORE they are doubled\n\n");
	printf("Integer: %d\n", intValue);
	printf("Short: %d\n", shortValue);
	printf("Float: %f\n", floatValue);
	printf("Double: %lf\n\n", doubleValue);

	// Double each value by calling the function DoubleTheValue
	intValue = DoubleTheValue(intValue);
	shortValue = DoubleTheValue(shortValue);
	floatValue = DoubleTheValue(floatValue);
	doubleValue = DoubleTheValue(doubleValue);

	// Print results to the screen
	printf("Data After they are doubled\n\n");
	printf("Integer: %d\n", intValue);
	printf("Short: %d\n", shortValue);
	printf("Float: %f\n", floatValue);
	printf("Double: %lf\n\n", doubleValue);

	return 0;
}

double DoubleTheValue(double value) 
{
	return value * 2;
}

int DoubleTheValue(int value)
{
	return value * 2;
}

short DoubleTheValue(short value)
{
	return value * 2;
}

float DoubleTheValue(float value)
{
	return value * 2;
}