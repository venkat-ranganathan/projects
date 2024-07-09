#ifndef RANGANATHANV_LAB4_H
#define RANGANATHANV_LAB4_H

// Include header files 
#include <stdio.h>
#include <string.h>

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

// Prototypes
void OpenFiles(FILE ** pFin, FILE ** pFout);
void CloseFiles(FILE ** pFin, FILE ** pFout);

//void PrintHeader(FILE* pOutput);
//void PrintDivider(FILE* pOutput, char symbol, int numberOf);
//void CenterString(FILE* pOutput, const char string[], int lengthToCenterAcross);

//void ReadDataFromFile(FILE * pFin);
//void ReadDataFromFile(FILE * pFin, int array);
//void ReadDataFromFile(FILE * pFin, double array);
class objectType
{
	
	public:
	
	// Constructor prototype
	objectType(void);
	objectType(int *array);
	objectType(double *array);
	
	// Destructor prototype
	~objectType(void);
	
	// Public method prototypes
	void PrintHeader(FILE* pOutput);
	void ReadDataFromFile(FILE * pFin);
	void PrintArray(FILE * pOutput);
	
	private:
	
	// Private method prototypes
	void PrintDivider(FILE* pOutput, char symbol, int numberOf);
	void CenterString(FILE* pOutput, const char string[], int lengthToCenterAcross);
	
	void PrintArrayHeader(FILE * pOutput);
	void PrintData(FILE * pOutput);
	
	// Private data
	int intArray[ARRAY_SIZE];
    double doubleArray[ARRAY_SIZE];
	int arrayCounter;
	
};

#endif