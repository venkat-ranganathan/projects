#include "HashTable.h"

HashTable::HashTable(void)
{
	for (int counter = 0; counter < TABLE_SIZE; counter++)
	{
		// Assign all pointer in table to NULL
		pHashTable[counter] = NULL;
	}

	// Set counter to 0
	counter = 0;
}


int HashTable::CreateHashValue(char name[])
{
	int hashValue = 0;

	for (unsigned int index = 0; index < strlen(name); index++)
	{
		// Add ASCII value to hashValue
		hashValue += (int)name[index];
	}

	// Return a number between 0 and (TABLE_SIZE - 1)
	return hashValue % TABLE_SIZE;

}


void HashTable::CreateNode(char name[])
{
	pNewNode = (nameType*)malloc(sizeof(nameType));

	if (pNewNode != NULL)
	{
		strcpy(pNewNode->name, name);

		pNewNode->pNext = NULL;
	}

}
void HashTable::InsertNewNode(char name[])
{
	int index;

	CreateNode(name);

	// Get the hash value
	index = CreateHashValue(pNewNode->name);

	// Set the new node next pointer to equal the front of the list
	pNewNode->pNext = pHashTable[index];

	// Set the front of the list to equal the new node
	pHashTable[index] = pNewNode;

	// Increase counter by 1
	counter++;


}


void HashTable::PrintOneName(FILE * pOutput, nameType* pOneRecord)
{
	// Print one name
	fprintf(pOutput, "%s\n", pOneRecord->name);
}

void HashTable::PrintList(FILE* pOutput)
{
	nameType* pLocation;

	for (int index = 0; index < TABLE_SIZE; index++)
	{
		// Set location to the current pointer in the array
		pLocation = pHashTable[index];

		fprintf(pOutput, "\nNames at array location %d\n", index);
		fprintf(pOutput, "------------------------\n");

		if (pHashTable[index] == NULL)
		{
			fprintf(pOutput, "\tNo records\n\n");
		}

		while (pLocation != NULL)
		{
			PrintOneName(pOutput, pLocation);

			// Move pointer to the next node
			pLocation = pLocation->pNext;
		}

	}
}