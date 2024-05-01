#ifndef RANGANATHANV_LAB7_H
#define RANGANATHANV_LAB7_H

// Define if you are compiling in Visual Studio 
#define _CRT_SECURE_NO_WARNINGS

// Include for input and output 
#include <stdio.h>

// Include for the srand and rand function
#include <stdlib.h>

// Include for strlen
#include <string.h>

// Include for the time function
#include <time.h>

// Comment line out if you don't want to capture file in the debug output file
#define DEBUG

// Macros used for dividers
#define SCREEN_WIDTH 100
#define STAR '*'
#define DASH '-'

// Macros used for header
#define SCHOOL "Binghamton University"
#define PROGRAMMER "Program written by: Venkat Ranganathan"
#define LAB "Lab 7 - Queues"

#define TRUE 1
#define FALSE 0

#define HAPPY 1 << 6
#define ANGRY 1 << 7
#define ID(source, id) (source->person.personID << id)
#define TIME(source, time) (source->person.timeCreated << time)

// Lab 7 - CreateNodeNode function
#define MASK_7 128 // bit position 7 decimal value
#define MASK_ID 65280 // bit 1111 1111 0000 0000

#define REASON(reason) (rand() % (1 << 2)) << reason

// Define the data for the program
typedef struct
{
	// Number of nodes in each queue
	int numberInQueueA;
	int numberInQueueB;

	// Time needed before a decision is made about creating a new customer
	clock_t countDownToNewPossibleCustomer;
	double timeToNextCustomer;

	// Variables that control the percentage that a new customer will be created
	clock_t countDownToNewPercentage;
	int percentageToCreateNewCustomer;

	// Customers who are created, but their is no room
	// in the queues so they "leave" angry
	int numberOfAngryCustomers;

	// Counter for number of customers served
	int numberOfCustomersServed;

	// This variable will start at 1 and will increment with each customer
	int personIdentificationNumber;

	// A customer is only being processed when they are at the front of the queue
	// This is the total time spent at the front of the queue
	double totalTimeToServeCustomer;

	// This is the total time the customer spent waiting in line
	double totalTimeInLine;

	clock_t countDownToNewCustomer;

} dataType;

// Define the data for our node
typedef struct
{
	// Identification number
	int personID;

	// creation time
	int timeCreated;

	// This will be a random number, so ever person is different 
	double timeNeededToProcess;

	// Time is recorded when a person is created
	clock_t timeEnteredLine;

	// Time is recorded when a person reaches the front of the queue
	clock_t startTimeToBeProcessed;

	unsigned int code;

} personType;

// Define the node for our queue
typedef struct node
{
	personType person;

	// Pointer to another node
	struct node* pNext;

} nodeType;

typedef struct 
{
	nodeType * pFront;
	nodeType * pRear;
	
} queueType;

// Prototypes
void PrintHeader(void);
void PrintDivider(char symbol, int numberOf);
void CenterString(char string[], int lengthToCenterAcross);

void OpenDataFile(FILE** pOutputLog, FILE** pDebugLog);
void CloseFile(FILE** pFile);
void ClearFile(FILE* pOutput);

void PrintColumnHeading(void);
void PrintStats(dataType data, double secondsRemaining);
void PrintRemainingCustomers(dataType data);

int CreateNewCustomer(FILE* pDebug, nodeType** pOnePerson, dataType* pData);

void ProcessCustomerAtFront(FILE* pDebug, FILE* pLog, queueType * pLineA, queueType * pLineB, 
	dataType* pData);

void ProcessNewCustomer(FILE* pDebug, FILE* pLog, queueType * pLineA, queueType * pLineB, nodeType** pOnePerson, dataType* pData);

void InitializeData(dataType* pData);
void CreateNode(FILE* pDebug, nodeType** pTemp, int id);

void InitializeQueue(queueType* queue);
void Enqueue(FILE* pDebug, queueType * Line, nodeType* newPerson);
void Dequeue(FILE* pDebug, FILE* pLog, int* pNumberInline, queueType * pLine, dataType* pData);
int QueueIsEmpty(queueType line);

void FreeList(queueType* pLine);
	
#endif