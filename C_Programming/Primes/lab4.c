/******************** DO NOT MAKE ANY CHANGES TO THIS FILE *******************/
#include "lab4prime.h"
#include "lab4prime.h"

int main(void)
{
    printf("########## Test-1: isPrime(1) ##########\n");
    assert(isPrime(1) == 0);
    printf("> Passed Test-1!\n");

    printf("########## Test-2: isPrime(11) ##########\n");
    assert(isPrime(11) == 1);
    printf("> Passed Test-2!\n");

    printf("########## Test-3: isPrime(INT_MAX) ##########\n");
    assert(isPrime(INT_MAX) == 1);
    printf("> Passed Test-3!\n");

    printf("########## Test-4: isPrime(UINT_MAX) ##########\n");
    assert(isPrime(UINT_MAX) == 0);
    printf("> Passed Test-4!\n");

    printf("########## Test-5: maxPrimeFactor(1) ##########\n");
    assert(maxPrimeFactor(1) == 0);
    printf("> Passed Test-5!\n");

    printf("########## Test-6: maxPrimeFactor(127) ##########\n");
    assert(maxPrimeFactor(127) == 127);
    printf("> Passed Test-6!\n");

    printf("########## Test-7: maxPrimeFactor(SHRT_MAX) ##########\n");
    assert(maxPrimeFactor(SHRT_MAX) == 151);
    printf("> Passed Test-7!\n");

    printf("########## Test-8: maxPrimeFactor(UINT_MAX) ##########\n");
    assert(maxPrimeFactor(UINT_MAX) == 65537);
    printf("> Passed Test-8!\n");

    printf("> All Tests Passed Successfully!\n");
}
