#include "lab3staticstack.h"
#include "lab3staticstack.h"

// Lab states to include the two lines below
static char stack[STACK_SIZE] = "";
static int top = -1;

// Read characters from file and store into buffer
void readFile(char filename[], char buffer[]) 
{
    // Declaring stream is a file pointer
    FILE *stream; 

    // Declaring i and ch
    int i, ch;

    // Opening filename, which is a reference to whatever "name" is set to in the main file
    stream = fopen( filename, "r");
  
    // Exits if there's no file
    if( stream == NULL )
        exit( 0 );

    // Reads the first character in the filename 
    ch = fgetc( stream );

    for( i = 0; (i < STR_SIZE - 1) && ( feof( stream ) == 0 ); i++)
    {
        // Stores the character[i] from the filename into the corresponding buffer[i]
        buffer[i] = ( char )ch;

        // Reads the next character in the filename
        ch = fgetc( stream );
    }

    // Add null to end string
    buffer[i] = '\0';

    //printf( "Testing to see if this works %s\n", buffer ); // can modify the beginning and end of full STRING buffer output

    // Closing file
    fclose( stream );
}

int push(const char c)
{
    
}

/* char pop()
{

} */

/* int status()
{

} */

/* char viewTop()
{
    
} */

// Write to new file (from buffer) but reverse the order of characters
/* void writeFile(char outputfile[])//, const char buffer[]) 
{
     // Created a different named stream
    FILE *stream; 

    // Opened outpufile, which is a reference to whatever "name" is set to in the main file
    stream = fopen(outputfile, "a"); 

    // Adding new line before writing the string
    fprintf(stream, "\n"); 

    // Declaring size and setting value to 0
    int size = 0;

    // While loop adds '1' to size for every character in buffer until '\0' is reached
    while (buffer[size] != '\0')
    {
        size++;
    }

    // Declaring i and setting value to 0
    int i = 0; 

    // Continues loop until terminating character, '\0' is reached
    while (buffer[i] != '\0') 
    {
        // Reverses the order items are proessed
        for(i = size - 1; i >= 0; i--)
        {
            // This loop adds '|' after each character until '\0' is reached
            fprintf(stream, "|%c", buffer[i]); 
        }
    }
    
    // Closing file
    fclose(stream); 
} */
