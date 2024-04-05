/*
|--------------------------------------------------------------------------------------------------
| Programmers Name: Prof. Foos
| Course:           CS-212: Data Structures for Engineers
| Program  Name:    Simulation with queues
| Date:             12/22/2022
|
|--------------------------------------------------------------------------------------------------
| Program Description:
|   This program will simulate two lines at a store, each line will be a queue.
|   (The type of store is not important)
|
|   If both lines (the queues) are full the customer will leave angry.
|
|   If one of the lines (the queues) are not full the new customer will be placed in the line.
|
|   When a customer is at the front of line (the queue), the customer will start the process
|   of being checked out. When the process has completed, the customer be removed from the line.
|
|   Debugging Information: 
|   -----------------------
|    Look at the top of Simulation.c and you will find a macro called DEBUG. 
|   If this macro is uncommented, debug information will be printed to DebuggingData.txt. 
|   If this macro is left commented out, no information will be printed to the file. 
|
|--------------------------------------------------------------------------------------------------
| Inputs:
|   The following inputs to control the simulation are macros defined in Inputs.h:
|
|      ***************************************************************
|      *   SIMULATION CONTROL MACROS                                 *
|      ***************************************************************
|
|   SECONDS_FOR_PROGRAM_TO_RUN
|    The numbers seconds that your simulation will run for
|
|   MAX_QUEUE_SIZE
|    The max size of a line for the customers to stand in.
|
|      ***************************************************************
|      *   THE AMOUNT OF TIME BETWEEN POSSIBLE CUSTOMER CREATESION   *
|      ***************************************************************
|
|	SECONDS_BEFORE_A_NEW_TIME_IS_CALCULATED
|    Every so many seconds, a new customer may be created. This time is a random number 
|  that is re-generated every so many seconds. This macro is the number of seconds between
|  re-generations of the time needed before a new customer may be created. 
|   	
|   DEFAULT_TIME_TO_CREATE_CUSTOMER
|    The default time between possible customer creations. 
|
|    Formula to create new time: 
|    ((Random Number % TIME_SPAN_TO_CREATE_CUSTOMER) / 10) + MIN_TIME_TO_CREATE_CUSTOMER
|
|   MIN_TIME_TO_CREATE_CUSTOMER
|     This is the minimum number of seconds that will pass between calculations.    
|
|   TIME_SPAN_TO_CREATE_CUSTOMER
|     This is the span (max - min) between possible calculation. 
|
|      ***************************************************************
|      *   THE AMOUNT OF TIME NEEDED TO CEHCK A CUSTOMER OUT         *
|      ***************************************************************
|
|    Formula to create the amount of time needed to check a customer out:
|    (Random Number % TIME_SPAN_TO_PROCESS_CUSTOMER) + MIN_TIME_TO_PROCESS_CUSTOMER 
|    
|   MIN_TIME_TO_PROCESS_CUSTOMER
|      This is the minimum number of seconds that will are needed to check a customer out.
|
|   TIME_SPAN_TO_PROCESS_CUSTOMER
|      This is the span (max - min) between possible times
|
|      ***************************************************************
|      *   THE PROBABILITY THAT NEW CUSTOMER IS CREATED              *
|      ***************************************************************
|
|   SECONDS_BEFORE_A_NEW_PERCENTAGE
|     The amount of time before a new percentage is generated
|
|   DEFAULT_PERCENTAGE_TO_CREATE_CUSTOMER
|     The percentage chance that a new customer will be created before the 
|    the first new percentage calculation is made
|
|    Formula to create a new percentage:
|    (Random Number % PERCENTAGE_SPAN_TO_CREATE_CUSTOMER) + MIN_PERCENTAGE_TO_CREATE_CUSTOMER
|
|    MIN_PERCENTAGE_TO_CREATE_CUSTOMER
|      This is the minimum probability that a new customer will be created.
|
|    PERCENTAGE_SPAN_TO_CREATE_CUSTOMER
|      This is the span (max - min) between possible percentages.
|   
|--------------------------------------------------------------------------------------------------
| Processing:
|   The main function will do 4 tasks:
|
|     1)  Possibly create a new customer (if it's time)
|     2)  If the customer is created, the customer will either be placed into a queue or the
|         the customer will leave angry (because the queue is full).
|     3)  If a customer is at the front of the line, that customer will begin the checkout process
|     4)  Stats will be printed to the screen
|
|   The following information will be recorded:
|
|     1) Number of customers served
|     2) Number of customers that leave early
|     3) total time spent in line
|     4) total time serving a customer
|
|   The following information will be calculated:
|     1) The average time spent in line
|     2) The average time spent checking out
|
|--------------------------------------------------------------------------------------------------
| Outputs:
|   The following stats will printed to the screen at the end of every frame:
|     1) Number of people in line A
|     2) Number of people in line B
|     3) Total number of angry customers
|     4) Total number of customers served
|     5) Total number of customers
|     6) Average time to check out a customer
|     7) Average time spent in line
|
|   The following information will printed to an out file. 
|     - An integer code that contains the following information:
|       1) The identification number of the customer
|       2) Customer status (either angry or checked out)
|       3) The time the person was created
|       4A) The rating for the store (if they were checked out)
|       4B) Their opinion of the store if they left angry.
|
|--------------------------------------------------------------------------------------------------
*/

#include "Inputs.h"
#include "Simulation.h"

int main(void)
{
	// Create two queues
	queueType LineA;
	queueType LineB;

	// Initialize pointers for a new customer
	nodeType* pOnePerson = NULL;

	// Program data
	dataType data;

	time_t timeVar;
	
	// Record the simulation start time
	clock_t startTime = clock();

	FILE * pOutput;
	FILE * pDebug = NULL;

	int goodRatio;

	PrintHeader();

	OpenDataFile(&pOutput, &pDebug);

	InitializeQueue(&LineA);
	InitializeQueue(&LineB);

	PrintColumnHeading();

	InitializeData(&data);

	// Initializes random number generator to the clock
	srand((unsigned int)time(&timeVar));

	while (((clock() - startTime) / CLOCKS_PER_SEC) < SECONDS_FOR_PROGRAM_TO_RUN)
	{

		if (CreateNewCustomer(pDebug, &pOnePerson, &data))
		{
			ProcessNewCustomer(pDebug, pOutput, &LineA, &LineB, &pOnePerson, &data);
		}

		ProcessCustomerAtFront(pDebug, pOutput, &LineA, &LineB, &data);

		PrintStats(data, (SECONDS_FOR_PROGRAM_TO_RUN - (double)(clock() - startTime) / CLOCKS_PER_SEC) );

	} // Close while-loop

	// Move the cursor down two lines
	printf("\n\n");
	
	//
	// Process out the remaining customers who are in line
	//
	
	while(!QueueIsEmpty(LineA) || !QueueIsEmpty(LineB))
	{
		ProcessCustomerAtFront(pDebug, pOutput, &LineA, &LineB, &data);
		
		PrintRemainingCustomers(data);
	}
	
	// Move the cursor down two lines
	printf("\n\n");
	
	//
	// Determine if data file is good and print the results to the screen
	//
	
	PrintDivider(STAR, SCREEN_WIDTH);

	// Move the cursor down to the next line
	printf("\n");

	// Calculate good ratio variable
	goodRatio = data.numberOfCustomersServed > ((data.numberOfCustomersServed + data.numberOfAngryCustomers) / 2);
	
	// Print data to the screen
	CenterString(" * * Angry Customers must be less than 1/2 of all the customers * *", 100);
	CenterString(" * * Must have at least 100 happy customers * *", 100);
	CenterString(" * * Must have at least 20 angry customers * *", 100);

	printf("\n");

	printf("Total Customers: %d\n", data.numberOfCustomersServed + data.numberOfAngryCustomers);
	printf("Happy Customers: %d\n", data.numberOfCustomersServed);
	printf("Angry Customers: %d\n\n", data.numberOfAngryCustomers);
	
	printf("Status of Data File Requirements:\n");

	printf("Ratio of angry customers to total customers: ");
	(goodRatio) ? printf("GOOD\n") : printf("NO GOOD\n");

	printf("Minimum of 100 Happy Customer require is: ");
	(data.numberOfCustomersServed >= 100) ? printf("GOOD\n") : printf("NO GOOD\n");

	printf("Minimum of 20 Angry Customers is: ");
	(data.numberOfAngryCustomers >= 20) ? printf("GOOD\n\n") : printf("NO GOOD\n\n");

	
	if (data.numberOfCustomersServed >= 100 &&  data.numberOfAngryCustomers >= 20 && goodRatio)
	{
		// Print message is good message
		printf("Your data file is GOOD for lab 7!\n\n");
	}
	else
	{
		// Print message is bad message
		printf("Your data file does not meet the requirements for lab 7.\n");
		printf("Keep playing with the inputs in the Inputs.h file\n\n");

		ClearFile(pOutput);
	}

	PrintDivider(STAR, SCREEN_WIDTH);
	
	// Move the cursor down to the next line
	printf("\n");

#ifdef DEBUG
	fprintf(pDebug, "END OF FRAME DATA:\n");
	fprintf(pDebug, "Number in line 1:           %d\n", data.numberInQueueA);
	fprintf(pDebug, "Number in line 2:           %d\n", data.numberInQueueB);
	fprintf(pDebug, "Number of angry customers:  %d\n", data.numberOfAngryCustomers);
	fprintf(pDebug, "Number of customers served: %d\n\n", data.numberOfCustomersServed);
#endif

	// Check to see if line A is empty
	if (QueueIsEmpty(LineA))
	{
		// Print message to the screen
		printf("Line A is free\n");
	}

	// Check to see if line B is empty
	if (QueueIsEmpty(LineB))
	{
		// Print message to the screen
		printf("Line B is free\n");
	}

    CloseFile(&pOutput);
	
#ifdef DEBUG
	CloseFile(&pDebug);
#endif

	return 0;
}

