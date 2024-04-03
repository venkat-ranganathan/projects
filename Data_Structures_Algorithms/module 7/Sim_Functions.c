#include "Inputs.h"
#include "Simulation.h"

//-----------------------------------------------------------------------------
// Function Name: CreateNewCustomer
// Description:
//   Two random numbers will be multiplied 
//
//-----------------------------------------------------------------------------
int CreateNewCustomer(FILE * pDebug, nodeType ** pOnePerson, dataType * pData)
{
	
	int weHaveACustomer = FALSE;

	// Check to see if a new percentage to create a new customer needs to be generated
	if ((double)((clock() - pData->countDownToNewPercentage) / CLOCKS_PER_SEC) >= 
		SECONDS_BEFORE_A_NEW_PERCENTAGE)
	{
		// Calculate new percentage
		pData->percentageToCreateNewCustomer = 
			(rand() % PERCENTAGE_SPAN_TO_CREATE_CUSTOMER) + MIN_PERCENTAGE_TO_CREATE_CUSTOMER;

		// Establish new countdown
		pData->countDownToNewPercentage = clock();

#ifdef DEBUG
		fprintf(pDebug, "New percentage created: %d\n\n", pData->percentageToCreateNewCustomer);
#endif

	}


	// Check to see if a new time needed to create a new customer needs to be generated
	if ((double)((clock() - pData->countDownToNewPossibleCustomer) / CLOCKS_PER_SEC) >= 
		SECONDS_BEFORE_A_NEW_TIME_IS_CALCULATED)
	{
		// Calculate new time
		pData->timeToNextCustomer = (double)((rand() % TIME_SPAN_TO_CREATE_CUSTOMER) / 10) + 
			MIN_TIME_TO_CREATE_CUSTOMER;

		pData->countDownToNewPossibleCustomer = clock();

#ifdef DEBUG
		fprintf(pDebug, "New count down to new possible customer: %lf\n\n", 
			pData->timeToNextCustomer);
#endif

	}


	// Check to see if it's time to possibly create a new customer
	if (((double)(clock() - pData->countDownToNewCustomer) / CLOCKS_PER_SEC) >= 
		pData->timeToNextCustomer)
	{
		// This will be true a % of the time
		if ((rand() % 100) < pData->percentageToCreateNewCustomer)
		{
			// Create a new node
			*pOnePerson = (nodeType*)malloc(sizeof(nodeType));

			CreateNode(pDebug, pOnePerson, pData->personIdentificationNumber);

#ifdef DEBUG
			fprintf(pDebug, "Customer ID %d has been created\n", 
				pData->personIdentificationNumber);
#endif

			// Increase ID by 1
			pData->personIdentificationNumber++;

			weHaveACustomer = TRUE;

		}

		// Reset count down
		pData->countDownToNewCustomer = clock();
	}

	return weHaveACustomer;
}


//-----------------------------------------------------------------------------
// Function Name: ProcessNewCustomer
// Description:
//
//
//-----------------------------------------------------------------------------
void ProcessNewCustomer(FILE* pDebug, FILE* pOutput, queueType * pLineA, queueType * pLineB, 
	nodeType** pOnePerson, dataType* pData)
{
	// Check to see if lines are full
	if (pData->numberInQueueA == MAX_QUEUE_SIZE && pData->numberInQueueB == MAX_QUEUE_SIZE)
	{
		//
		// Process an angry customer
		// 

		// Increase count of 
		pData->numberOfAngryCustomers++;

		// Generate code
		(*pOnePerson)->person.code = (*pOnePerson)->person.code | ANGRY;
		(*pOnePerson)->person.code = (*pOnePerson)->person.code | ID((*pOnePerson), 8);
		(*pOnePerson)->person.code = (*pOnePerson)->person.code | TIME((*pOnePerson), 16);
		(*pOnePerson)->person.code = (*pOnePerson)->person.code | (REASON(1));
		
		// Record code to the output file
		fprintf(pOutput, "%u\n", (*pOnePerson)->person.code);

#ifdef DEBUG
		fprintf(pDebug, "Customer ID %d has left angry\n", 
			(*pOnePerson)->person.personID);
#endif

		// Remove angry customer from memory
		free(*pOnePerson);

	}
	else if (pData->numberInQueueA <= pData->numberInQueueB)
	{
		// Place new customer in line A
		Enqueue(pDebug, pLineA, *pOnePerson);
		pData->numberInQueueA++;

#ifdef DEBUG
		fprintf(pDebug, "Customer ID %d has entered line 1\n\n", 
			(*pOnePerson)->person.personID);
#endif

	}
	else
	{
		// Place new customer in line B
		Enqueue(pDebug, pLineB, *pOnePerson);
		pData->numberInQueueB++;

#ifdef DEBUG
		fprintf(pDebug, "Customer ID %d has entered line 2\n\n", 
			(*pOnePerson)->person.personID);
#endif
	}
}


//-----------------------------------------------------------------------------
// Function Name: QueueIsEmpty
// Description:
//   Returns true if the queue is empty, otherwise it returns false
//
//-----------------------------------------------------------------------------
int QueueIsEmpty(queueType line)
{
	// Check to see if the rear pointer is NULL
	return line.pFront == NULL;
}

//-----------------------------------------------------------------------------
// Function Name: ProcessCustomerAtFront
// Description:
//    Both queues will be checked against NULL. 
//
//    If they are not equal to NULL, then Dequeue will be called. 
//
//-----------------------------------------------------------------------------
void ProcessCustomerAtFront(FILE* pDebug, FILE* pOutput, queueType * pLineA, queueType * pLineB, 
	dataType* pData)
{

	// Check to see if at least one person is in line A
	if (!QueueIsEmpty(*pLineA))
	{
		Dequeue(pDebug, pOutput, &pData->numberInQueueA, pLineA, pData);
	}

	// Check to see if at least one person is in line B
	if (!QueueIsEmpty(*pLineA))
	{
		Dequeue(pDebug, pOutput, &pData->numberInQueueB, pLineB, pData);
	}

}


//-----------------------------------------------------------------------------
// Function Name: InitializeData
// Description:
//    All the default data will be initialized
//
//-----------------------------------------------------------------------------
void InitializeData(dataType* pData)
{
	// Set counters data
	pData->numberInQueueA = 0;
	pData->numberInQueueB = 0;
	pData->numberOfAngryCustomers = 0;
	pData->numberOfCustomersServed = 0;
	pData->totalTimeToServeCustomer = 0;
	pData->totalTimeInLine = 0;

	// Initialize the starting ID number
	pData->personIdentificationNumber = 1;

	// Initialize default times
	pData->percentageToCreateNewCustomer = DEFAULT_PERCENTAGE_TO_CREATE_CUSTOMER;
	pData->timeToNextCustomer = DEFAULT_TIME_TO_CREATE_CUSTOMER;

	// Record clock time for count downs
	pData->countDownToNewPercentage = clock();
	pData->countDownToNewCustomer = clock();
	pData->countDownToNewPossibleCustomer = clock();
}


//-----------------------------------------------------------------------------
// Function Name: CreateNode
// Description:
//   This function will create a new customer 
//
//-----------------------------------------------------------------------------
void CreateNode(FILE * pDebug, nodeType** pTemp, int id)
{
	// Time the customer will need to be checked out
	double time = (double)(((rand() % TIME_SPAN_TO_PROCESS_CUSTOMER)) + 
		MIN_TIME_TO_PROCESS_CUSTOMER); 

	// Assigning default data
	(*pTemp)->person.personID = id;
	(*pTemp)->pNext = NULL;
	
	// Assign default values
	(*pTemp)->person.timeEnteredLine = 0;
	(*pTemp)->person.timeNeededToProcess = 0;

	// Assign time created
	(*pTemp)->person.timeCreated = clock();

	// Assign time needed to check this customer out
	(*pTemp)->person.timeNeededToProcess = time;

	// Assign code starting value
	(*pTemp)->person.code = 0;

#ifdef DEBUG
	fprintf(pDebug, "NEW NODE DATA\n");
	fprintf(pDebug, "Person ID: %d\n", (*pTemp)->person.personID);
	fprintf(pDebug, "Time to process %lf\n\n", (*pTemp)->person.timeNeededToProcess);
#endif
}


//-----------------------------------------------------------------------------
// Function Name: Enqueue
// Description:
//    This function will accept one queue and one new customer as parameters.
//  The new customer will be inserted into the queue. 
//
//-----------------------------------------------------------------------------
void Enqueue(FILE* pDebug, queueType * pLine, nodeType* pNewPerson)
{
	// Check to see if the list is empty 
	if (QueueIsEmpty(*pLine))
	{
		//
		// If the list is empty, the person goes straight to the counter
		//

		// Person can start checking out
		pNewPerson->person.startTimeToBeProcessed = clock();

		// Assign the new person to the queue
		pLine->pRear = pNewPerson;
		pLine->pFront = pNewPerson;
		
#ifdef DEBUG
		fprintf(pDebug, "Customer %d just went straight to checkout.\n\n", 
			pNewPerson->person.personID);
#endif

	}
	else
	{
		//
		// If there is at least one person in line, then the customer
		// must wait there their turn
		//

		// There is at least one person in line, so the new person shall wait 
		pNewPerson->person.timeEnteredLine = clock();

		// Assign the new person to the queue
		pLine->pRear->pNext = pNewPerson;
		pLine->pRear = pNewPerson;
		
#ifdef DEBUG
		fprintf(pDebug, "Customer %d just went to the back of the line.\n\n", 
			pNewPerson->person.personID);
#endif

	}

	pNewPerson = NULL;

}


//-----------------------------------------------------------------------------
// Function Name: Dequeue
// Description:
//
//
//-----------------------------------------------------------------------------
void Dequeue(FILE* pDebug, FILE* pOutput, int* pNumberInline, queueType * pLine, dataType* pData)
{
	nodeType* pTemp;

	// Check to see if line is empty
	// if (!QueueIsEmpty(*pLine))
	if (pLine->pFront != NULL)
	{

		// Check to see if done processing
		if (((double)(clock() - pLine->pFront->person.startTimeToBeProcessed) / CLOCKS_PER_SEC) >
			pLine->pFront->person.timeNeededToProcess)
		{
			// Add time needed to process this customer to the accumulator
			pData->totalTimeToServeCustomer += clock() - 
					pLine->pFront->person.startTimeToBeProcessed;

			// Create code
			pLine->pFront->person.code = pLine->pFront->person.code | HAPPY;
			pLine->pFront->person.code = pLine->pFront->person.code | ID(pLine->pFront, 8);
			pLine->pFront->person.code = pLine->pFront->person.code | TIME(pLine->pFront, 16);
			pLine->pFront->person.code = pLine->pFront->person.code | (REASON(1 << 2));

			// Log message that customer has checked out. 
			fprintf(pOutput, "%u\n", pLine->pFront->person.code);

			// Assign temp to the front pointer
			pTemp = pLine->pFront;
			
			// Move the front pointer down one spot
			pLine->pFront =  pLine->pFront->pNext;

			if (!QueueIsEmpty(*pLine))
			{
				//
				// We know there is at least one more person in line
				// 

				// Record the time spent in line
				pData->totalTimeInLine += clock() - pTemp->person.timeEnteredLine;

				// Record start processing time
				pLine->pFront->person.startTimeToBeProcessed = clock();
				
#ifdef DEBUG
				fprintf(pDebug, "Customer ID %d just checked out\n", 
					pTemp->person.personID);
				fprintf(pDebug, "Start time to be processed: %ld\n", 
					pTemp->person.startTimeToBeProcessed);
				fprintf(pDebug, "Time entered line:          %ld\n", 
					pTemp->person.timeEnteredLine);
				fprintf(pDebug, "Time needed to process      %lf\n\n", 
					pTemp->person.timeNeededToProcess);
#endif

			}
			else
			{
				// There was only one customer in the line
				// Now the line is empty
				pLine->pRear = NULL;
			}

			// One customer has been processed
			pData->numberOfCustomersServed++;
			(*pNumberInline)--;

			// Free the old last node
			if (pTemp != NULL) free(pTemp);
		}
	}
}


//-----------------------------------------------------------------------------
// Function Name: PrintColumnHeading
// Description:
//   This function will print the header for the output to the screen.
//
//-----------------------------------------------------------------------------
void PrintColumnHeading(void)
{
	// Print tab to the screen
	printf("\t");

	PrintDivider(DASH, 80);

	// Print header to the screen
	printf("\t|Number of | Number of | Number of | Number of | Total     | Average | Average |    -----------\n");
	printf("\t|people in | people in | angry     | customers | number of | time to | time in |    |  Count  |\n");
	printf("\t|line A    | line B    | customers | served    | customer  | process | line    |    |  Down   |\n\t");

	PrintDivider(DASH, 95);
	
}


//-----------------------------------------------------------------------------
// Function Name:PrintStats
// Description:
//   This function will first calculate the average time to checkout a 
//  customer and the average time spent in line.
// 
//   * Before printing the data to the screen, \r will be used to return the 
//  cursor to the beginning of the line.
// 
//  All data will be printed the screen
//
//-----------------------------------------------------------------------------
void PrintStats(dataType data, double secondsRemaining)
{
	double averageTimeToProcess = 0;
	double averageTimeInLine = 0;
	
	// Check for divide by 0
	if((data.personIdentificationNumber - 1) != 0)
	{
		// Calculate  averageTimeToProcess
		averageTimeToProcess = ((double)data.totalTimeToServeCustomer /
			(data.personIdentificationNumber - 1)) / CLOCKS_PER_SEC;

		// Calculate averageTimeInLine
		averageTimeInLine = ((double)data.totalTimeInLine /
			(data.personIdentificationNumber - 1)) / CLOCKS_PER_SEC;
	}

	// Print one line of data to the screen
	// Use \r to return the cursor to the beginning of the line
	printf("\r\t|%5d     |%7d    |%7d    |%7d    |%7d    |%6.2lfs  |%6.2lfs  |    | %0.2lfs  |",
		data.numberInQueueA,
		data.numberInQueueB,
		data.numberOfAngryCustomers,
		data.numberOfCustomersServed,
		data.personIdentificationNumber - 1,
		averageTimeToProcess,
		averageTimeInLine,
		secondsRemaining
	);
}


//-----------------------------------------------------------------------------
// Function Name FreeList
// Description:
//   This function will free any remaining customers
//
//-----------------------------------------------------------------------------
void FreeList(queueType* pLine)
{
	nodeType* pTemp;

	while (pLine->pFront != NULL)
	{
		// Assign pTemp to the front of the line
		pTemp = pLine->pFront;

		// Move the front of the line to the next node
		pLine->pFront = pLine->pFront->pNext;

		// Delete pTemp
		free(pTemp);

	}

}