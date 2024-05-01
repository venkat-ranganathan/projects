
#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>


typedef struct
{
	int number;

} recordType;

class queueType
{

public:

	// Constructor
	queueType(void) { pFront = pRear = NULL; }

	// Public methods
	void Enqueue(int number);
	bool Dequeue(int * pNumber);

	bool IsEmpty(void) { return pFront == NULL; }

	
private:

	// Declare a node
	typedef struct dataType
	{
		recordType record;

		struct dataType* pNext;

	} nodeType;
	
	nodeType* pFront;
	nodeType* pRear;
	
	nodeType* pNewNode;

};


#endif
