/*
|--------------------------------------------------------------------------------------------------
| Programmers Name: Prof. Foos
| Course:           CS-212: Data Structures for Engineers
| Program  Name:    Sample code for a queue
| Date:             12/24/2022
|
|--------------------------------------------------------------------------------------------------
| Program Description:
|   This is not a functioning program. It will not do anything if you run it.
|
|
|--------------------------------------------------------------------------------------------------
| Inputs:
|   There is no actual input, but the structures are set up to create a queue.
|
|--------------------------------------------------------------------------------------------------
| Processing:
|   Code is provided for the following functions:
|     InitializeQueue
|     QueueIsEmpty
|     Enqueue
|     Dequeue
|
|--------------------------------------------------------------------------------------------------
| Outputs:
|   N/A
|
|--------------------------------------------------------------------------------------------------
*/

#include <stdio.h>

typedef struct
{
	//
	// All the data that will be stored in one record
	// will be declared here. 
	//

	int sampleData;

} recordType;

typedef struct Node
{
	// Declare a record
	recordType data;

	struct Node* pNext;

} nodeType;

typedef struct
{
	nodeType* pFront;
	nodeType* pRear;

} queueType;

int main(void)
{
	// Declare the queue
	queueType queue;

	// DON'T FORGET TO INITIALIZE YOUR POINTERS TO NULL;
	InitializeQueue(&queue);

	/*
		---------------------------------------
		The rest of this program is not written
		---------------------------------------
	*/

	return 0;
}


//-----------------------------------------------------------------------------
// Function Name: InitializeQueue
// Description:
//    Assign both pointers of the queue to NULL
//
//-----------------------------------------------------------------------------

void InitializeQueue(queueType* queue)
{
	// Assign both pointers to NULL
	queue->pFront = NULL;
	queue->pRear = NULL;
}


//-----------------------------------------------------------------------------
// Function Name: QueueIsEmpty
// Description:
//   Check to see if the front pointer is NULL
//
//-----------------------------------------------------------------------------

int QueueIsEmpty(queueType queue)
{
	// Check to see if pointer is NULL
	return queue.pFront == NULL;
}


//-----------------------------------------------------------------------------
// Function Name: Enqueue
// Description:
//   This function will insert one node into a queue.
//
//   It is assumed that the node to insert has already been created and 
//  initialized. However, defensive coding is present to make sure the
//  the pointer is not NULL. 
//
//-----------------------------------------------------------------------------
void Enqueue(queueType* queue, nodeType* pTemp)
{
	if (pTemp == NULL)
	{
		// Print error message
		printf("ERROR, temp is NULL\n");
	}
	else
	{
		// Check to see if the queue is empty
		if (queue->pFront == NULL)
		{
			// Assign both pointers to our temp node
			queue->pFront = pTemp;
			queue->pRear = pTemp;
		}
		else
		{
			// Add new node to the queue
			queue->pRear->pNext = pTemp;
			queue->pRear = pTemp;
		}
	}
}


//-----------------------------------------------------------------------------
// Function Name: Dequeue
// Description:
//   This is sample code to remove one node from a queue. 
//
//   Depending the needs of your program you may wish to return the data.
//
//-----------------------------------------------------------------------------
void Dequeue(queueType* queue)
{
	nodeType* pTemp;

	if (queue->pFront == NULL)
	{
		// Print error message to the screen
		printf("ERROR, queue is empty\n");
	}
	else
	{
		// Assign temp to the front of the queue
		pTemp = queue->pFront;

		// Move the front pointer forward one
		queue->pFront = queue->pFront->pNext;

		// Check to see if the list is now empty
		if (queue->pFront == NULL)
		{
			// Set the rear pointer to NULL
			queue->pRear = NULL;
		}

		// Delete the temp pointer
		free(pTemp);
	}
}