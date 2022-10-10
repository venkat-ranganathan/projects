// preprocessor directive
#include <stdio.h>

// function prototype
void loop(int number);

// main function
int main()
{
    // declare number as an int with value 100 for no reason other than I made a function to pass it to
    int number = 100;

    // pass number to loop function
    loop(number);

    return 0;
}

// loop function
void loop(int number)
{
    // counts down from 100 to 1
    for (int i = number; i > 0; i--)
    {
        // prints value of 'i' separated by a space
        printf("%d ", i);

        // new line after every 10 entries
        if (i % 10 == 1)
        {
            printf("\n");
        }
    }
}

/*

I picked a for statement as my loop (as opposed to while / do-while)
because it was the first thing that came into my mind when I thought
about creating a loop

I also generally avoid using a while loop because it's a pain if I forget to add a break
because it'll run forever and I'll have to close the terminal so it doesn't crash my terminal/IDE
or drain my laptop's battery

*/