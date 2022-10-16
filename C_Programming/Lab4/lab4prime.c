// preprocessor directive
#include "lab4prime.h"

// checks whether a given integer "number" is a prime number or not
// returns '0' if "number" is not prime & returns '1' if "number" is prime
unsigned int isPrime(unsigned int number)
{
    // checks if the integer "number" is equal to 2 or 3, returns prime if true
    if (number == 2 || number == 3)
    {
        return 1;
    }

    // checks if integer "number" is <= 1 or integer "number" is divisible by 2 or 3
    // & returns not prime if true
    if (number <= 1 || number % 2 == 0 || number % 3 == 0)
    {
        return 0;
    }

    // checks if integer "number" values greater than or equal to 5 are prime or not
    // starts at i = 5, keeps running until i^2 is less than or equal to "number",
    // then sets i = i + 6 and continues loop

    for (int i = 5; i * i <= number; i += 6)
    {
        // checks if integer "number" is divisible by i or i + 2 and returns not prime if true
        if (number % i == 0 || number % (i + 2) == 0)
        {
            return 0;
        }
    }

    // otherwise number is prime
    return 1;
}

// finds the largest prime factor of a given integer "number"
// 1) returns '0' if "number" is less than 2
// 2) returns the value of "number" if "number" is a prime number
// 3) returns the largest prime factor of "number" if none of the above is true
unsigned int maxPrimeFactor(unsigned int number)
{
    // 1) checks if "number" is less than 2, and returns 0 if true
    if (number < 2)
    {
        return 0;
    }

    // lmao this kept failing test 7 and 8 until I switched the order of loops 2 & 3

    // 3) returns largest prime factor of "number" if neither of the above are true
    // starts by dividing the integer "number" by 2, and working backwards until "number" >= 2
    for (int i = number / 2; i >= 2; i--)
    {
        // checks if integer "number" is divisible i
        if (number % i == 0)
        {
            // checks if i is a prime number using the isPrime function I created earlier
            if (isPrime(i))
            {
                // we can just return i as the largest prime factor since we're working backwards
                // anything after this won't be the largest prime factor, since i is decreasing
                return i;
            }
        }
    }

    // 2) checks if number is a prime number itself, and returns the value of the number if true
    for (int i = 2; i <= number; i++)
    {
        if (number % i == 0)
        {
            return number;
        }
    }
}