#include "lab2arrays.h"
#include "lab2arrays.h"

// Read characters from file and store into buffer
void readFile(char inputfile[], char buffer[]) 
{
    
    // Declaring stream is a file pointer
    FILE *stream; 

    // Declaring i and ch
    int i, ch;

    // Opening inputfile, which is a reference to whatever "name" is set to in the main file
    stream = fopen( inputfile, "r");
  
    // Exits if there's no file
    if( stream == NULL )
        exit( 0 );

    // Reads the first character in the inputfile 
    ch = fgetc( stream );

    for( i = 0; (i < STR_SIZE - 1) && ( feof( stream ) == 0 ); i++)
    {
        // Stores the character[i] from the inputfile into the corresponding buffer[i]
        buffer[i] = ( char )ch;

        // Reads the next character in the inputfile
        ch = fgetc( stream );
    }

    // Add null to end string
    buffer[i] = '\0';

    //printf( "Testing to see if this works %s\n", buffer ); // can modify the beginning and end of full STRING buffer output

    // Closing file
    fclose( stream );
}

// Take characters from buffer and write to new file
void writeFile(char outputfile[], const char buffer[]) 
{
    // Created a different named stream
    FILE *stream; 

    // Opened outpufile, which is a reference to whatever "name" is set to in the main file
    stream = fopen(outputfile, "a"); 

    // Adding new line before writing the string
    fprintf(stream, "\n"); 

    // Declaring i and setting value to 0
    int i = 0; 

    // This separates each character in the array so you can add new characters between each character
    while (buffer[i] != '\0') 
    {
        // This loop adds '|' after each character until '\0' is reached
        fprintf(stream, "|%c", buffer[i++]); 
        //printf("|%c", buffer[i++]);
    }
    
    // Closing file
    fclose(stream); 
}

// Write to new file (from buffer) using switch case
void writeFileSwitchCase(char outputfile[], const char buffer[]) 
{
    // Declare  duffer as new array with character limit set to STR_SIZE
    char duffer[STR_SIZE] = "";

    // Created a different named stream
    FILE *stream; 

    // Opened outpufile, which is a reference to whatever "name" is set to in the main file
    stream = fopen(outputfile, "a"); 

    // Adding new line before writing the string
    fprintf(stream, "\n"); 

    // Declaring int i is equal to zero
    int i = 0;

    // loop until '\0' is reached
    while (buffer[i] != '\0')
    {
        // Detects, then converts lower case to upper case by subtracting 32 from the lower case letter from buffer[i]
        if(buffer[i] >= 'a' && buffer[i] <= 'z')
        {
            // Defines duffer[i] as equal to buffer[i] minus 32
            duffer[i] = buffer[i] - 32;

            // Prints case-changed array after adding '|' before the character
            fprintf(stream,  "|%c", duffer[i]);

            // continues loop
            i++;
        }

        // Detects, then converts upper case to lower case by adding 32 to letter from buffer[i]
        else if (buffer[i] >= 'A' && buffer[i] <= 'Z')
        {
            // Defines duffer[i] as equal to buffer[i] plus 32
            duffer[i] = buffer[i] + 32;

            // Prints case-changed array after adding '|' before the character
            fprintf(stream,  "|%c", duffer[i]);

            // continues loop
            i++;
        }

        // Carries out regular behavior of writeFile() function
        else
        {
            // Adds '|' before every character in buffer array
            fprintf(stream, "|%c", buffer[i++]);
        }
        
    }

    // Closing file
    fclose(stream); 
}

// Write to new file (from buffer) but reverse the order of characters
void writeFileReverse(char outputfile[], const char buffer[]) 
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
}

// Write to new file (from buffer) but only write odd characters
void writeFileOddIndex(char outputfile[], const char buffer[]) 
{
     // Created a different named stream
    FILE *stream; 

    // Opened outpufile, which is a reference to whatever "name" is set to in the main file
    stream = fopen(outputfile, "a"); 

    // Adding new line before writing the string
    fprintf(stream, "\n"); 

    // Declaring i and setting value to 0
    int i = 0; 

    // While loop continues until termination character, '\0' is reached
    while (buffer[i] != '\0') 
    {
        // Continues increments 'i' if i is an even number
        if (i % 2 == 0)
        {
            i++;
        }

        // Prints buffer value with '|' added before it as long as i is not an even number
        else
        {
            // This loop adds '|' after each character until '\0' is reached
            fprintf(stream, "|%c", buffer[i++]); 
        }
    }
    
    // Closing file
    fclose(stream); 
}
