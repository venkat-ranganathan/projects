// preprocessor directives
#include <stdio.h>

// main function, adding void in the () is optional
int main(void)
{
    // cypher basic encryption using ASCII table values for characters
    /*

    H E L L O  W O R L D

    CASE-SENSITIVE ASCII values:
    H = 72; E = 69; L = 76; L = 76; O = 79; SPACE = 32; W = 87; O = 79; R = 82; L = 76; D = 68

    The encryption will add each ASCII value of the letters to the "key"

    RESULT:

    CASE-SENSITIVE ASCII values PLUS key:

    R = 82; O = 79; V = 86; V = 86; Y = 89; * = 42; a = 97; Y = 89; \ = 92; V = 86; N = 78

    */

    // declare char string with 30 elements
    char string[30];
    char oneCharacter;
    int key;
    int counter = 0;

    int iTemp;
    char cTemp;

    // get string
    printf("Enter a string to encrypt: ");
    scanf("%s", string);

    // get key
    printf("Enter key: ");
    scanf("%d", &key);

    // print label
    printf("Encrypted string: \n");

    // set single character as first element of string
    oneCharacter = string[counter];

    // repeat until encountering null terminator, '\0'
    while (oneCharacter != '\0')
    {
        // converts character into a temporary integer
        // iTemp = (int)(oneCharacter);

        // subtracts temporary integer of character from key
        // iTemp -= key;

        // converts temporary integer back to a character
        // cTemp = (char)iTemp;

        // does the same thing as above in a single line
        oneCharacter += key;

        // prints encrypted character
        printf("%c", oneCharacter);

        // changer; ++counter, increments first
        oneCharacter = string[++counter];
    }

    printf("\n");

    return 0;
}