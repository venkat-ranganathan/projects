/******************************* SAMPLE TEST FILE ****************************/
/******************** NO IMPLEMENTATION HERE, ONLY TESTS *********************/
// two includes here to test for include guards in the header file 
#include "lab4staticqueue.h"
#include "lab4staticqueue.h"

int main(void)
{
    char filename[] = "lab4.txt";
    char buffer[STR_SIZE] = "";

    // read string from file and save it in buffer array
    readFile(filename, buffer);

    // insert to queue
    int i = 0;
    printf("Enqueue Status: ");
    while(buffer[i] != '\0')
    {
        printf("%d ", enqueue(buffer[i]));
        i++;
    }
    printf("\n");

    // check stack items
    writeFile(filename);
    printf("Front: %c\n", viewFront());
    printf("Rear: %c\n", viewRear());

    // remove from the queue
    printf("Dequeue: ");
    while(status() != -1)
    {
        printf("%c ", dequeue());
    }
    printf("\n");
}

