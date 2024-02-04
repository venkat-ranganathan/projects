
#include "Source.h"

int main(void)
{
	int numbers[SIZE];
	int tag;

	FILE* inputFile;
	FILE* outputFile;

	OpenFile(&inputFile, "data.txt", "r");
	OpenFile(&outputFile, "OutputFile.txt", "w");

	ReadDataFromFile(inputFile, numbers, &tag);

	PrintArray(outputFile, numbers, tag);

	PrintArray(stdout, numbers, tag);

	CloseFile(&inputFile);
	CloseFile(&outputFile);

	return 0;

}

