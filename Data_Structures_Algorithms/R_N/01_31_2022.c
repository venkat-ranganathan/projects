#include <stdio.h>

// global variable
int max = 0;

// compare two integers
int compare(int a, int b)
{
	if(a > b)
		return a;	// max = a;
	else
		return b;	// max = b
}

// pass by value
void increment_value(int q)
{
	q++;
}

// pass by reference
void increment_ref(int *q)
{
	(*q)++; 	// *q = *q + 1;
}

int main()
{
	// local variables
	int x = 10;
	int y = 12;
	int z = 5;

	// example: print message
	printf("Hello, World!\n");
	
	// example: global variable scope and usage, use format specifier in printf
	max = compare(x, y);
	printf("max = %d\n", max);

	// example: pass by value and by reference
	printf("original z = %d\n", z);
	increment_value(z);
	printf("increment value = %d\n", z);
	increment_ref(&z);
	printf("increment ref = %d\n", z);

	// example: bitwise operation
	x = 5;
	x = x & 1;
	printf("x = %d\n", x);
	/*
	5 => 0101
	1 => 0001
	     0001
	*/
	x = 5;
	x = x & 4;
	printf("x = %d\n", x);
	/*
	5 => 0101
	4 => 0100
	     0100
	*/

	// example: break and continue statements
	for(int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if(j == 3)
			{
				// this will terminate inner loop, not outer loop
				break;
			}
		}

		if(i == 5)
		{
			// this will skip any following statements, and execute the next loop iteration
			continue;
		}

		i++;
	}
}

