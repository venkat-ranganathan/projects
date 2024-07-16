#ifndef RANGANATHANV_LAB4_H
#define RANGANATHANV_LAB4_H

// Include header files 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Macros
#define SCREEN_WIDTH 80
#define TABLE_WIDTH 20

#define STAR '*'
#define DASH '-'

#define SCHOOL "Binghamton University"
#define PROGRAMMER "Program written by: Venkat Ranganathan"
#define LAB "Lab 4"

#define TABLE_TITLE "Array Output"

#define ARRAY_SIZE 50
#define NUMBER_PER_LINE 5

// Function Prototypes
void OpenFiles(FILE ** pFin1, FILE ** pFIN2, FILE ** pFout);
void CloseFiles(FILE ** pFin1, FILE **pFin2, FILE ** pFout);

void PrintHeader(FILE* pOutput);
void CenterString(FILE* pOutput, const char string[], int lengthToCenterAcross);
void PrintDivider(FILE* pOutput, char symbol, int numberOf);

void ReadDataFromFile(FILE * pFin, int * array);
void ReadDataFromFile(FILE * pFin, double * array);
class objectType
{
	
	public:
	
	// Constructor prototype
	objectType(void)
	{
		// Initialize constructor to 0
		arrayCounter = 0;

		GenerateRandomNumbers();
	};
	// overloaded method for integer array
	objectType(int *array)
	{
		// Initialize constructor to 0
		arrayCounter = 0;

		// copy integer array into integer array in class
		for (int i = 0; i < ARRAY_SIZE; i++)
		{
			intArray[i] = array[i];
		}
	};
	// overloaded method for double array
	objectType(double *array)
	{
		// Initialize constructor to 0
		arrayCounter = 0;

		// copy integer array into integer array in class
		for (int i = 0; i < ARRAY_SIZE; i++)
		{
			doubleArray[i] = array[i];
		}
	};
	
	// Destructor prototype
	~objectType(void);
	
	// Public method prototypes
	//void PrintHeader(FILE* pOutput);
	void PrintArray(FILE * pOutput);
	void GenerateRandomNumbers()
	{
		// default constructor populates third array with genereated random numbers
		for (int index = 0; index < ARRAY_SIZE; index++)
		{		
			// Set each element of the array to a number between 0 and 200
			thirdArray[index] = rand() % 200 + 1;
		}
	}
	
	private:
	
	// Private method prototypes
	//void PrintDivider(FILE* pOutput, char symbol, int numberOf);
	//void CenterString(FILE* pOutput, const char string[], int lengthToCenterAcross);
	
	void PrintArrayHeader(FILE * pOutput);
	void PrintData(FILE * pOutput);
	
	// Private data
	int intArray[ARRAY_SIZE];
    double doubleArray[ARRAY_SIZE];
	int thirdArray[ARRAY_SIZE];
	int arrayCounter;
	
};

#endif