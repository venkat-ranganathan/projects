#include <stdio.h> // pre-processor directive

// list of printf modulus specifiers
// https://www.tutorialspoint.com/format-specifiers-in-c

int main()
{
    int red;
    int blue;
    double sum;
    double number;
    char letter;

    red = 3;
    blue = 32;

    letter = 'A';

    // if you want to treat a variable of one data type as another, you can add (n)variable_name,
    // where n is the data type you want, i.e. if the variable_name is declared as an int and you want to treat
    // it as a float, you can write (float)variable_name

    sum = (double)blue / red;

    // %f lets printf know to expect a double variable input
    // you can set %nf to set the number of decimal places, so if n = 3,
    // then the result will set the answer to 3 decimal places

    printf("\nDivision of %d", blue);
    printf(" by %d\n", red);
    printf("Results in the sum: %.3f\n\n", sum);

    // Can print out the Hex value of the variable "letter" by setting printf() modulus as an int

    printf("This is the integer value of a char: %d\n", letter);

    // if you want to print a double quote inside a string, add "\"string\""

    printf(" \"Hello World\" \n");

    // if you want user input, use scanf, and if you use scanf, you need the ampersand, &, before the variable
    // the input will be stored in
    // printf specifier for double is %lf

    printf("Enter a number with decimals: ");
    scanf("%lf", &number);
    printf("This is what was entered %lf\n", number);

    return 0;
}