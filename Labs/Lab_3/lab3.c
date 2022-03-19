/******************************* SAMPLE TEST FILE ****************************/
/******************** NO IMPLEMENTATION HERE, ONLY TESTS *********************/
// two includes here to test for include guards in the header file 
#include "lab3staticstack.h"
#include "lab3staticstack.h"

int main(void)
{
    char filename[] = "lab3.txt";
    char buffer[STR_SIZE] = "";

    // read string from file and save it in buffer array
    readFile(filename, buffer);

    // push to stack
    int i = 0;
    printf("Push Status: ");
    while(buffer[i] != '\0')
    {
        printf("%d ", push(buffer[i]));
        i++;
    }
    printf("\n");

    // check stack items
    writeFile(filename);
    printf("Top: %c\n", viewTop());

    // pop from stack
    printf("Pop: ");
    while(status() != -1)
    {
        printf("%c ", pop());
    }
    printf("\n");
}

