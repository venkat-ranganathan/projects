
#include "Queue.h"

void queueType::Enqueue(int number)
{
	pNewNode = (nodeType*)malloc(sizeof(nodeType));

	// Defensive coding
	if (pNewNode != NULL)
	{
		// Assign data of new node
		pNewNode->record.number = number;
		pNewNode->pNext = NULL;

		// Check to see if the queue is empty
		if (pFront == NULL)
		{
			// Assign both pointers to our temp node
			pFront = pNewNode;
			pRear = pNewNode;
		}
		else
		{
			// Add new node to the queue
			pRear->pNext = pNewNode;
			pRear = pNewNode;
		}
	
	}
}

bool queueType::Dequeue(int * pNumber)
{
	bool dequeueSuccessful = false;

	nodeType* pTemp;

	if (!IsEmpty())
	{
		// Set the return value
		*pNumber = pFront->record.number;

		// Assign temp to the front of the queue
		pTemp = pFront;

		// Move the front pointer forward one
		pFront = pFront->pNext;

		// Check to see if the list is now empty
		if (pFront == NULL)
		{
			// Set the rear pointer to NULL
			pRear = NULL;
		}

		// Delete the temp pointer
		free(pTemp);
		
		// Set return value
		dequeueSuccessful = true;

	}

	return dequeueSuccessful;
}


