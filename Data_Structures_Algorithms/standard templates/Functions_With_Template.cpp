

#include <stdio.h>

using namespace std;

template <class dataType>
dataType DoubleTheValue(dataType value);

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
	intValue = DoubleTheValue<int>(intValue);
	shortValue = DoubleTheValue<short>(shortValue);
	floatValue = DoubleTheValue<float>(floatValue);
	doubleValue = DoubleTheValue<double>(doubleValue);

	// Print results to the screen
	printf("Data After they are doubled\n\n");
	printf("Integer: %d\n", intValue);
	printf("Short: %d\n", shortValue);
	printf("Float: %f\n", floatValue);
	printf("Double: %lf\n\n", doubleValue);

	return 0;
}

template <class dataType>
dataType DoubleTheValue(dataType value)
{
	return value * 2;
}

/*
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
*/