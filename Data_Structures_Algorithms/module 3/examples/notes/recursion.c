
// every program starts with main, so main is the first function on stack
int main(void)
{
    int value = recursion(3);

    return 0;
}

int recursion(int number)
{
    // check if number is greater than 1
    if (number > 1)
    {
        // recursive case
        // the recursive function call will pass in a number that
        // is one smaller than the original
        return recursion(number--);
    }

    else
    {
        // base case
        return 1;
    }
}