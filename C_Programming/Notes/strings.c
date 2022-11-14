// preprocessor directive
#include <stdio.h>
#include <string.h>

// function prototype
int myStrCmp(char str1[], char str2[]);
int myStrLength(char str[]);
int myATOI(char str1[]);

// main function
int main(void)
{
    char str1[] = "My Dog\0";
    char str2[] = "ayaaa";

    int result = strcmp(str1, str2);

    printf("strcmp result = %d\n", result);

    result = myStrCmp(str1, str2);

    printf("myStrCmp result = %d\n", result);

    result = strlen(str1);

    printf("My strlen result = %d\n", result);

    result = myStrLength(str1);

    printf("myStrLength result = %d\n", result);

    result = myATOI(str1);

    printf("ATOI is = %d\n", result);

    return 0;
}

/*

str1        str2        return value

aaaa        aaaa        0
aaaa        zaaa        -25 (a = 97, z = 122; so 97 - 122 = -25)


*/

int myStrCmp(char str1[], char str2[])
{
    int returnValue;

    int index = 0;

    while ((str1[index] == str2[index]) && (str1[index] != '\0') && (str2[index] != '\0'))
    {
        // increase index
        index++;
    }

    returnValue = str1[index] - str2[index];

    return returnValue;
}

// upper case letter ranges
const int LOWER_UPPER_CASE_LIMIT = 65;
const int UPPER_UPPER_CASE_LIMIT = 90;

// lower case letter ranges
const int LOWER_LOWER_CASE_LIMIT = 97;
const int UPPER_LOWER_CASE_LIMIT = 122;

int myStrLength(char str1[])
{
    int returnValue;
    int index = 0;
    int counter = 0;
    int countUpperCaseLetters = 0;
    int countLowerCaseLetters = 0;
    int countAllLetters;

    while (str1[index] != '\0')
    {
        if (str1[index] >= LOWER_UPPER_CASE_LIMIT && str1[index] <= UPPER_UPPER_CASE_LIMIT)
        {
            countUpperCaseLetters++;
        }

        if (str1[index] >= LOWER_LOWER_CASE_LIMIT && str1[index] <= UPPER_LOWER_CASE_LIMIT)
        {
            countLowerCaseLetters;
        }

        countAllLetters = countLowerCaseLetters + countUpperCaseLetters;

        counter++;
        index++;
    }

    printf("Uppercase Letters = %d\n", countUpperCaseLetters);
    printf("Lowercase Letters = %d\n", countLowerCaseLetters);
    printf("Total Letters = %d\n", countAllLetters);

    return counter;
}

int myATOI(char str1[])
{
    // convert string to integer

    int index = 0;
    int number;
    int isNegative = 0;

    if (str1[0] == '-')
    {
        isNegative = 1;

        index++;
    }

    while (str1[index] != '\0')
    {
        number = (number * 10) + str1[index] - 48;

        index++;
    }

    if (isNegative)
    {
        number *= -1;
    }

    return number;
}