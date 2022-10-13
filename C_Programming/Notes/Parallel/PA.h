
#ifndef PA_H
#define PA_H

// Include for input and output to the screen
#include <stdio.h>

// Include for string functions
#include <string.h>

// Macros
#define DOUBLE_RETURN "\n\n"
#define USER_NOT_FOUND_MESSAGE "\n\n* * * USER NOT FOUND * * *\n\n"
#define ARRAY_IS_EMPTY "\n\n* * * ARRAY IS EMPTY * * *\n\n"

// Constants
const char TAB = '\t';
const char BLANK = ' ';
const char DASH = '-';
const int DONE = 0;
const int MAX = 100;
const int STRING_SIZE = 20;

// Utility function prototypes
void PrintDivider(char symbol, int length);
int FindName(char nameToFind[], const char names[][STRING_SIZE], int tagField);

// Fie function prototypes
void OpenFile(FILE *fin);
void ReadInData(FILE *fin, char name[][STRING_SIZE], int rating[], int highScore[], int *tagField);

// Main menu function prototypes
void DisplayMenu(void);
int GetSelection(void);
void ExecuteSelection(int selection, char names[][STRING_SIZE], int rating[], int hiScore[], int *tagField);

// Print data function prototypes
void PrintDataHeader(void);
void PrintOneRecord(char name[], int rating, int hiScore);
void PrintAllRecords(const char names[][STRING_SIZE], const int rating[], const int hiScore[], int tagField);

// Add and delete record prototypes
void AddOneRecord(char names[][STRING_SIZE], int rating[], int hiScore[], int *tagField);
void DeleteOneRecord(char names[][STRING_SIZE], int rating[], int hiScore[], int *tagField, int location);

// Other prototypes
int CalculateTotal(const int array[], int tagField);
int FindHighest(const int array[], int tagField);
int FindLowest(const int array[], int tagField);
void PrintResult(double average, char message[]);

#endif