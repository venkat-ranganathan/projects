
#include "HashTable.h"

using namespace std;

int main(void)
{
	FILE* pFin = fopen("Names.txt", "r");
	FILE* pFout = fopen("Output.txt", "w");

	HashTable namesDatabase;

	char name[NAME_SIZE];

	while (fscanf(pFin, "%s", name) == 1)
	{
		namesDatabase.InsertNewNode(name);
	}

	// Print the number of names read in from the input file
	fprintf(pFout, "Number of names read in: %d\n\n", namesDatabase.NamesInList());

	namesDatabase.PrintList(pFout);
	
	return 0;
}