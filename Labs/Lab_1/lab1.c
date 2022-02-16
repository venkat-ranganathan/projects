/******************************* SAMPLE TEST FILE ****************************/
/******************** NO IMPLEMENTATION HERE, ONLY TESTS *********************/
// two includes here to test for include guards in the header file 
#include "lab1dev.h"
#include "lab1dev.h"

int main(void)
{
    char name[] = "CS212";

    welcome(name);

    printf("########## Test-1: leftmostOnePos(4) ##########\n");
    assert(leftmostOnePos(4) == 3);
    printf("> Passed Test-1!\n");

    printf("########## Test-2: leftmostOnePos(250) ##########\n");
    assert(leftmostOnePos(250) == 8);
    printf("> Passed Test-2!\n");

    printf("########## Test-3: leftmostOnePos(SHRT_MAX) ##########\n");
    assert(leftmostOnePos(SHRT_MAX) == 15);
    printf("> Passed Test-3!\n");

    printf("> Passed leftmostOnePos() tests!\n\n");

    printf("> All Tests Passed Successfully!\n");
}

