#include <stdio.h>

int main()
{
    /*

    Loops have three parts:

    know three parts: initialization, test, changer

    int counter;

    // initialization

    counter = 0;

    // test

    while & for loops is a pre-test loop (checks test before running loop code)

    while(counter < 32)

    // changer

    counter++;

    */

    /*

    for loop structure:

    for(initializaiton; test; changer)
    {

    }

    Starts at initialization, then goes to test, then changer

    If test passes, it executes code
    If test fails, breaks out of loop and continues with rest of code

    */

    for (int counter = 0; counter < 5; counter++)
    {
        int red = 2 * counter;

        // prints the value of red on the left and the current counter value on the right
        printf("%d %d\n", red, counter);

        // Know Loop Control Variable (LCV) which is the counter < 5 part in this loop, LCV controls the loop

        /*

        test            counter     red     output
        0 < 5, True     0           0       0 0
        1 < 5, True     1           2       2 1
        2 < 5, True     2           4       4 2
        3 < 5, True     3           6       6 3
        4 < 5, True     4           8       8 4
        5 < 5, FALSE    5           code breaks out of loop

        */
    }

    printf("\n");

    // -=2 decreases counter value by 2 each time
    for (int counter = 6; counter > 0; counter -= 2)
    {
        /*
        Logical shift left 2 bits
        counter is 00000110 -> 00011000
        so counter goes from 6 to 24

        LSL 2 will just mutiply the counter value by 4, since the second bit value is 4
        */
        int blue = counter << 2;

        int red = counter * 5;

        printf("%d %d\n", blue, red);

        /*
        counter     blue        red     test
        6           24          30      6 > 0, true
        4           16          20      4 > 0, true
        2           8           10      2 > 0, true
        0                               0 > 0, FALSE
        */
    }

    /*

    Input: 10 20 30 -1 5 7

    // initialization
    scanf("%d", &number);

    // test, number is the control variable
    while(number != -1)
    {
        // number * 2 part below prints out the value, but doesn't change the value of number variable
        printf("%d %d\n", number, number *2);

        // changer
        scanf("%d", &number);
    }

    number      output      test
    10          10 20       10 != -1, True
    20          20 40       20 != -1, True
    30          30 60       30 != -1, True
    -1                      -1 != -1, FALSE; loop breaks

    */

    /*

    do-while loop; post-test loop

    do part executes at least once

    do
    {
        // initialization and changer can be on same line of code
    }

    while(test);
    */
    return 0;
}