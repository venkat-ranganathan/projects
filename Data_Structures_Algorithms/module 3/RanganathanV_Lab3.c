#include "RanganathanV_Lab3.h"

int main(void)
{
    // declare file pointers
	FILE* pFout;
	
	OpenFile(&pFout, "OutputFile.txt", "w");

	PrintHeader(pFout);

	CloseFile(&pFout);

    return 0;
}