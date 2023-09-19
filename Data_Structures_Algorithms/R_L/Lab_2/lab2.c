/******************************* SAMPLE TEST FILE ****************************/
/******************** NO IMPLEMENTATION HERE, ONLY TESTS *********************/
// two includes here to test for include guards in the header file 
#include "lab2arrays.h"
#include "lab2arrays.h"

int main(void)
{
    char name[] = "lab2.txt";
    char buffer[STR_SIZE] = "";

    readFile(name, buffer);
    writeFile(name, buffer);
    writeFileSwitchCase(name, buffer);
    writeFileReverse(name, buffer);
    writeFileOddIndex(name, buffer);
}

