// preprocessor directives
#include "lab6strings.h"

// change the case of all alphabet letters in the string “str1”.
// The modified string should be stored in the string “str2”.
// The function should count the number of alphabet letters changed in “str2” and return it.
unsigned int strCase(char str1[], char str2[])
{
    // declare index as integer, will be used as changer
    int index = 0;
    int count = 0;

    // copy a given string "str1" (array of characters) to another "str2" (array of characters)
    // use for loop to cycle from 0 until the size of the array is reached
    for (int i = 0; i <= strlen(str1); i++)
    {
        // store each element of str1 into corresponding element of str2
        str2[i] = str1[i];
    }

    // if pStart element of string array is null terminator ('\0'), return 0
    if (str1[0] == '\0')
    {
        return 0;
    }

    // else goes through the elements of the string array and swaps letter cases
    else
    {

        // while loop to search through elements of string
        while (str1[index] != '\0')
        {
            // str2[index] = str1[index];

            // pStart conditional swaps uppercase letter to lowercase
            if (str2[index] >= 'A' && str2[index] <= 'Z')
            {
                // swaps uppercase to lowercase
                str2[index] += 32;

                // increment count to record case was changed
                count++;
            }

            // second conditional swaps lowercase letter to uppercase
            else if (str2[index] >= 'a' && str2[index] <= 'z')
            {
                // swaps lowercase to uppercase
                str2[index] -= 32;

                // increment count to record case was changed
                count++;
            }

            // move onto next element in array
            index++;
        }

        // returns number of letter cases changed
        return count;
    }
}

// Uses pointer arithmetic instead of array syntax to reverse a given string "str1”
// if it only consists of alphabet letters (a-z and A-Z). The reversed string should
// be saved back in the same string, “str1”.
unsigned int wordReverse(char *str1)
{
    // declare character variables: pointer copy to store str1, pointer start, pointer end, and temporary character, ch
    char *pCopy, *pStart, *pEnd, ch;

    // set pointer variables to be equal to str1 to start
    pCopy = pStart = pEnd = str1;

    // return 0 if string is empty
    if (str1[0] == 0)
    {
        return 0;
    }

    // loop while *pCopy until end of string is reached
    while (*pCopy != '\0')
    {
        // return 0 if character is NOT a lowercase or uppercase letter
        // used decimal values for lowercase and uppercase letters, respectively
        if (!((*pCopy >= 97 && *pCopy <= 122) || (*pCopy >= 65 && *pCopy <= 90)))
        {
            return 0;
        }

        // increment pCopy to move into to next element
        pCopy++;
    }

    // Used for loop to set pEnd to be the end of the string
    // subtract by 2 to remove null terminator at end of original string
    for (int i = 0; i <= strlen(str1) - 2; i++)
    {
        // increment pEnd to move onto next element
        pEnd++;
    }

    // Use for loop to simulatenously swap first half and last half characters of string, hence dividing string length by 2
    // and subtracting by 1 to account for null terminator
    for (int i = 0; i <= strlen(str1) / 2 - 1; i++)
    {
        // store first element of string into temporary character variable, ch
        ch = *pStart;

        // set pStart equal to first element in pEnd
        *pStart = *pEnd;

        // set pEnd equal to where first element of pStart is stored in ch
        *pEnd = ch;

        // increment pStart to move right towards next element
        pStart++;

        // decremenet pEnd to move left towards next element
        pEnd--;
    }

    // return 1 if string has only upper or lowercase characters and we reversed the order of the string
    return 1;
}