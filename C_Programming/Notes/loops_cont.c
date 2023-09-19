// pre-processor directive
#include <stdio.h>

// function prototype
void printMenu(void);
int getUserChoice(void);
void getTwoNumbers(int *number1, int *number2);
double executeOperation(int selection, int number1, int number2);
void printResults(double answer);

int main()
{
    int choice;
    int number1;
    int number2;

    double answer;

    // do-while is a post-test loop
    do
    {
        // print a menu
        printMenu();

        // get choice from user
        choice = getUserChoice();

        if (choice != 0)
        {

            // get two numbers
            getTwoNumbers(&number1, &number2);

            // execute operation
            answer = executeOperation(choice, number1, number2);

            // print results
            printResults(answer);
        }

    } while (choice != 0);

    return 0;
}

void printMenu(void)
{
    printf("\t1) Addition\n");
    printf("\t2) Subtraction\n");
    printf("\t3) Multiplication\n");
    printf("\t4) Division\n");

    printf("\n\t0) Quit\n");

    printf("\n\tEnter selection: ");
}

int getUserChoice(void)
{
    int choice;

    scanf("%d", &choice);

    return choice;
}

// using pointer because you want to both send the value and call it back
// i.e. variables are both inputs and outputs
void getTwoNumbers(int *number1, int *number2)
{
    // prompt user for number
    printf("\tEnter first number: ");
    scanf("%d", number1);

    printf("\tEnter second number: ");
    scanf("%d", number2);
    printf("\n");
}

double executeOperation(int selection, int number1, int number2)
{
    double answer;

    switch (selection)
    {
    case 1:
        answer = number1 + number2;
        break;

    case 2:
        answer = number1 - number2;
        break;

    case 3:
        answer = number1 * number2;
        break;

    case 4:
        /*         if (number2 != 0)
                {
                    answer = number1 / number2;
                }
                else
                {
                    answer = 0;
                } */

        // works same as if statement but more compact
        answer = (number2 != 0) ? (number1 / number2) : 0;

        break;

    default:
        printf("\nInvalid selection\n");
        break;
    }

    // make sure to return result at the end of a function
    return answer;
}

void printResults(double answer)
{
    printf("Result = %.3lf\n\n", answer);
}