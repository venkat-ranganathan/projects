
#include "Stack.h"

void stackType::Push(int number)
{
	pNewNode = (nodeType*)malloc(sizeof(nodeType));

	// Defensive coding
	if (pNewNode != NULL)
	{
		// Assign data of new node
		pNewNode->record.number = number;

		// Add new node to the stack
		pNewNode->pNext = pTop;
		pTop = pNewNode;
	}
}

int stackType::Pop(void)
{
	int returnValue = -1;

	nodeType* pTemp;

	if (!IsEmpty())
	{
		// Set the return value
		returnValue = pTop->record.number;

		// Set temp to the top of the stack
		pTemp = pTop;

		// Move the top of the stack to the next node
		pTop = pTop->pNext;


		// Free the temp node
		free(pTemp);

	}

	return returnValue;
}


