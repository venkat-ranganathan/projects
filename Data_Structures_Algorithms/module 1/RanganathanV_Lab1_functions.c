#include "RanganathanV_Lab1.h"

//-----------------------------------------------------------------------------
// Function Name: PrintHeader
// Description: Prints school, student name, and lab number with dividers
//
//
//-----------------------------------------------------------------------------
void PrintHeader() {
    // move cursor down one line
    printf("\n");

    // print header to the screen
    printf("*********************************************************\n");
    printf("%s\n", SCHOOL);
    printf("%s\n", NAME);
    printf("%s\n", LAB);
    printf("*********************************************************\n");

    // move cursor down one line
    printf("\n");
}

//-----------------------------------------------------------------------------
// Function Name: PrintDivider
// Description: Prints a divider when called
//
//
//-----------------------------------------------------------------------------
void PrintDivider() {
    // print divider
    printf("*********************************************************\n");
}

//-----------------------------------------------------------------------------
// Function Name: PrintMenuAndSelection
// Description: declares a local selection variable, prints user menu, records user selection, checks if selection is valid; if not, loops selection request until user enters a valid selection; lastly returns (valid) user selection
//
//
//-----------------------------------------------------------------------------
int PrintMenuAndGetSelection() {
    // move cursor down one line
    printf("\n");
    
    // declare local variable
    int selection;

    // move cursor down one line
    printf("\n");

    // print menu to terminal
    printf("Select a shape to calculate for area calculation: \n");
    printf("1. Parallelogram\n");
    printf("2. Trapezium\n");
    printf("3. Ellipse\n");
    printf("0. Quit\n");



        // move cursor down one line
        printf("\n");

        // prompt user for an answer and store answer in a variable
        printf("Enter selection: ");
        scanf("%d", &selection);

        // loop selection if user selects invalid choice
        do {
            // added conditional to avoid triggering loop when user enters valid choice
            if (selection < 0 || selection > 3) {
                // move cursor down one line
                printf("\n");

                // error message
                PrintDivider();
                printf("\t\t\tInvalid choice.\n");
                PrintDivider();

                // move cursor down one line
                printf("\n");

                // print menu to terminal
                printf("Select a shape to calculate for area calculation: \n");
                printf("1. Parallelogram\n");
                printf("2. Trapezium\n");
                printf("3. Ellipse\n");
                printf("0. Quit\n");

                // prompt user for an answer and store answer in a variable
                printf("Enter selection: ");
                scanf("%d", &selection);
            }
        } while (selection < 0 || selection > 3);

    return selection;
}

//-----------------------------------------------------------------------------
// Function Name: ProcessSelection
// Description: Asks user to input values based on shape choice, updates variable values, and calcluates area for selected shape using conditionals
//
//
//-----------------------------------------------------------------------------
void ProcessSelection(int selection, int* valueA, int* valueB, int* valueC, double* area) {
    // move cursor down one line
    printf("\n");

    // check if user selected parallelogram
    if (selection == 1) {
        // promt user for length of base and vertical height
        printf("Enter the base and vertical height separated by a space: ");
        scanf("%d %d", valueA, valueB);

        // calculate the area; need to de-reference pointers to calculate values
        *area = *valueA * *valueB;
    }

    // check if user selected trapezium
    else if (selection == 2) {
        // prompt user of length of sides
        printf("Enter the length of side A, side B, and the height separated by a space: ");
        scanf("%d %d %d", valueA, valueB, valueC);

        // calculate the area; need to de-reference pointers to calculate values
        *area = (double) ((*valueA + *valueB) * *valueC) / 2;
    }

    // else assume user selects ellipse
    else {
        // prompt user for the minor and major axis
        printf("Enter the length of the minor and major axis separated by a space: ");
        scanf("%d %d", valueA, valueB);

         // calculate the area; need to de-reference pointers to calculate values
        *area = PI * *valueA * *valueB;
    }

}

//-----------------------------------------------------------------------------
// Function Name: PrintShape
// Description: Prints user-selected shape name using switch statement cases
//
//
//-----------------------------------------------------------------------------
void PrintShape(int selection) {
    // move cursor down one line
    printf("\n");

    // print divider
    PrintDivider();

    // move cursor down one line
    printf("\n");

    // print the shape name
    switch (selection)
    {
        case 1:
            // print shape to terminal
            printf("Shape: Parallelogram\n");
            break;
        case 2:
            // print shape to terminal
            printf("Shape: Trapezium\n");
            break;
        case 3:
            // print shape to terminal
            printf("Shape: Ellipse\n");
            break;
    }
}

//-----------------------------------------------------------------------------
// Function Name: PrintResults
// Description: Pass updated variable values from ProcessSelection function to PrintResults function, print variable values and calculated area for user-selected shape using conditionals
//
//
//-----------------------------------------------------------------------------
void PrintResults(int selection, int valueA, int valueB, int valueC, double area) {
    // print results
    if (selection == 1) {
        // print results for paralleogram
        printf("Length of the base: %d\n", valueA);
        printf("Length of the height: %d\n", valueB);
        printf("Area: %.3lf\n", area);
    }

    else if (selection == 2) {
        // print results for trapezeium
        printf("Length of side A: %d\n", valueA);
        printf("Length of side B: %d\n", valueB);
        printf("Length of the height: %d\n", valueC);
        printf("Area: %.3lf\n", area);
    }

    else {
        // print results of ellipse
        printf("Length of the major axis: %d\n", valueA);
        printf("Length of the major axis: %d\n", valueB);
        printf("Area: %.3lf\n", area);
    }

    // move cursor down one line
    printf("\n");
}