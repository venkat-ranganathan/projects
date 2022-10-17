#include "lab1dev.h"

// This program should 1) Print a welcome message & 2) find the leftmost
// one in the binary representation of a given number

void welcome(char name[])
{
    printf("Hello, %s\n", name);
}

unsigned int leftmostOnePos(unsigned int number)
{
	if (number == 0)
		return 0;

	int msb = 1;
	number = number / 2;
	while (number != 0) 
	{
		number = number / 2;
		msb++;
	}

    //printf("left most one pos is: %i\n",msb+1);

	return msb;
  
}
