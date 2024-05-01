
#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 500
#define NAME_SIZE 50


typedef struct namePointerType
{
	char name[NAME_SIZE];

	namePointerType* pNext;

}nameType;


class HashTable
{
public:
	HashTable(void);

	void InsertNewNode(char name[]);
	void PrintList(FILE* pOutput);
	
	int NamesInList(void) { return counter;  }


private:

	nameType* pHashTable[TABLE_SIZE];
	nameType* pNewNode;

	int counter;

	int CreateHashValue(char name[]);
	void CreateNode(char name[]);
	void PrintOneName(FILE* pOutput, nameType* pOneRecord);

};

#endif
