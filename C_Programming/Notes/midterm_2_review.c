// preprocesor directive
#include <stdio.h>

int main()
{
    // int variable, called primer
    int counter = 0;

    int red = 3;

    // pre-test loop (test condition before executing code insde {})

    // "counter < 3" is called thet test
    while (counter < 3)
    {
        if ((counter + 1) % 2 == 0)
        {
            red *= 2;
        }
    }

    /*
    int primer = x;

    while (test)
    {
        changer
    }
    */

    // the variable++ is called the changer
    counter++;

    // for loop also pre-test loop
    int count = 10;

    // for(primer; test; changer){}
    for (int i = 0; i < count; i++)
    {
        /* code */
    }

    // post-test loop, do-while
    // primer and changer can be on same line of code
    do
    {
        /* priemr & changer */
    } while (/* test */);

    // know bit manipulation
}