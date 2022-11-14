
#include <stdio.h>
#include <string.h>

// Upper case letter ranges
const int LOWER_UPPER_CASE_LIMIT = 65;
const int UPPER_UPPER_CASE_LIMIT = 90;

// Lower case letter ranges
const int LOWER_LOWER_CASE_LIMIT = 97;
const int UPPER_LOWER_CASE_LIMIT = 122;

const int STRING_SIZE = 30;

// Prototype
int myStrCmp(char str1[], char str2[]);
int myStrLen(char str[]);
int myATOI(char str1[]);
void countLetters(char str1[]);

int main(void)
{
	char str1[STRING_SIZE];
	char compareA[STRING_SIZE];
	char compareB[STRING_SIZE];

	int result;

	strcpy(str1, "-123");
	strcpy(compareA, "Marry Poppins");
	strcpy(compareB, "marry poppins");

	result = myATOI(str1);

	printf("ATOI result = %d\n", result);

	result = myStrLen(str1);

	printf("StrLen result = %d\n", result);

	result = myStrCmp(compareA, compareB);

	printf("String compare result = %d\n", result);

	countLetters("The cow jumped Over The Moon");

	return 0;
}

int myATOI(char str1[])
{
	int index = 0;

	int number = 0;

	int isNegative = 0;

	if (str1[0] == '-')
	{
		// Set flag to 1 for true
		isNegative = 1;

		// Incrament the index by 1
		index++;
	}

	while (str1[index] != '\0')
	{
		// Multiply number by 10 and add the ones digit
		number = (number * 10) + str1[index] - 48;

		// Incrament the index by 1
		index++;
	}

	// Use flag to check to see if the number is negative
	if (isNegative)
	{
		// Make the return value a negative number
		number *= -1;
	}

	return number;
}

int myStrLen(char str1[])
{
	int count = 0;

	while (str1[count] != '\0')
	{
		count++;
	}

	return count;
}

void countLetters(char str1[])
{
	int index = 0;

	int countUpperCaseLetters = 0;
	int countLowerCaseLetters = 0;
	int countAllLetters;

	while (str1[index] != '\0')
	{
		if (str1[index] >= LOWER_UPPER_CASE_LIMIT && str1[index] <= UPPER_UPPER_CASE_LIMIT)
		{
			// Increase upper case letter count
			countUpperCaseLetters++;
		}

		if (str1[index] >= LOWER_LOWER_CASE_LIMIT && str1[index] <= UPPER_LOWER_CASE_LIMIT)
		{
			// Increase lower case letter count
			countLowerCaseLetters++;
		}

		index++;
	}

	// Calculate all letters
	countAllLetters = countLowerCaseLetters + countUpperCaseLetters;

	printf("Uppercase Letters = %d\n", countUpperCaseLetters);
	printf("Lowercase Letters = %d\n", countLowerCaseLetters);
	printf("Total Letters = %d\n", countAllLetters);
}

int myStrCmp(char str1[], char str2[])
{
	int returnValue;

	int index;

	// If the current letter of each array is equal an neither string is at the end
	while ((str1[index] == str2[index]) && (str1[index] != '\0') && str2[index] != '\0')
	{
		// Increase index by 1
		index++;
	}

	// Calcualte the return value
	returnValue = str1[index] - str2[index];

	return returnValue;
}