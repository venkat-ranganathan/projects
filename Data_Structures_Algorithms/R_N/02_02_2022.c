#include <stdio.h>

void foo(int *c)
{
	//counter++;	// invalid, counter undefined in this scope
	*c = *c + 1;	//(*c)++;	// valid, pointer "*c" references "counter" variable in main()
	printf("counter = %d\n", *c);	// original "counter" variable is modified
}

int main()
{
	// example: increment counter
	int counter = 0;
	int y = 2;

	counter++;	// valid

	// nested scope
	{
		counter++; // valid
	}

	// nested scope
	if(y == 2)
	{
		counter++;	// valid
	}

	// nested scope
	for(int i = 0; i < 10; i++)
	{
		// increment counter in function
		foo(&counter);
	}
}

