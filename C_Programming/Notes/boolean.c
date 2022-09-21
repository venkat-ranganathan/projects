/* Every test evaluates true or false

Examples:
    (age >= 18)
    (age >= 16)
    (value == 100)
    (someChar != 'J') <-- characters need to be in single quotes

Relational Operators:

> Greater Than, < Less Than, >= Greater than or equal to, <= Less than or equal to, == Equal to, != Not equal to

Logical Operators:

&& AND, || OR, ! NOT, ^ XOR

Examples of compound test:

(age >= 18 && value != 7)
(selection > 0 && selection < 4)
(selection < 1 || selection > 3)

*/

#include <stdio.h>
#include <stdlib.h>

// Include for toupper(int characterName);

#include <ctype.h>

int main()
{
    int value = 10;

    /*

    if (value == 10)
    {
        printf("value is equal to 10\n");
    }

    // simple if-else

    if (value == 16)
    {
        printf("value is equal to 16\n");
    }

    else if (value == 8)
    {
        printf("value is equal to 8\n");
    }

    else
    {
        printf("value is not equal to 8 or 16\n");
    }

    */

    switch (value)
    {
    case 10:
        printf("value is equal to 10\n");
        break;

    default:
        printf("value is not equal to 10\n");
        break;
        // don't need a break after DEFAULT switch case, but should use one
    }

    int vowelCounter = 0;
    int letterEcounter = 0;

    char character;

    printf("Enter a letter: ");
    scanf("%s", &character);

    // converts lower case to upper case

    character = toupper(character);

    switch (character)
    {

    case 'A':
        vowelCounter++;
        break;

    case 'E':
        vowelCounter++;
        letterEcounter++;
        break;

    case 'I':
        vowelCounter++;
        break;

    case 'O':
        vowelCounter++;
        break;

    case 'U':
        vowelCounter++;
        break;

    case 'Y':
        vowelCounter++;
        break;

    default:
        break;
    }

    printf("The number of vowels is: %d\n", vowelCounter);
    printf("The number of Es is: %d\n", letterEcounter);

    // Unsigned int can't be negative

    unsigned int cholesterol;

    // if you want 'n' characers, you need to n+1 total characters because the last character is the null operator

    char message[21];
    /*

    0-90: Low
    91-110: Medium
    111... High

    */

    printf("Enter your cholesterol level: ");
    scanf("%d", &cholesterol);

    if (cholesterol >= 0 && cholesterol <= 90)
    {
        printf("Low\n");
    }

    else if (cholesterol >= 91 && cholesterol <= 110)
    {
        printf("Medium\n");
    }

    else if (cholesterol > 110)
    {
        printf("High\n");
    }

    else
    {
        printf("Invalid input\n");
    }

    int A = 157;
    int B = 115;

    // bitwise AND with 157 & 115

    int ans = A & B;

    int X = 118;

    // but only want to check bits 3 and 4
    // bits 3 and 4 are 24

    const int MASK_34 = 24;

    int code = X & MASK_34;

    // LSR 3 places

    code = code >> 3;

    printf("Code = %d\n", code);

    return 0;
}

// Bit Manipulation

// Every integer is 4 bytes

/* if you want only the last 3 bits of an 8 bit number bitwise AND against the original number
and set the bits you want to value 1

i.e.

1110110 <-- only want first 3 bits of 8 bit vaue
0000111 <-- bitwise and

--------
0000110 <-- result with only the first 3 bits you want

i.e. if you want two bits in middle of 8-bit value

1110110 <-- only want first 3 bits of 8 bit vaue
0011000 <-- bitwise and

--------
0010000 <-- result with only the 2 bits you want

now if you want the value to result in the number value, and not the bit value

LSR 3 spaces

ANS >> 3;

*/
