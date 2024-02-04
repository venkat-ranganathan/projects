
#ifndef SOURCE_H
#define SOURCE_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define SIZE 20

void ReadDataFromFile(FILE* inputFile, int array[], int* pTag);
void PrintArray(FILE* outputFile, const int array[], int tag);

void OpenFile(FILE** pFile, char fileName[], char type[]);
void CloseFile(FILE** pFile);

#endif