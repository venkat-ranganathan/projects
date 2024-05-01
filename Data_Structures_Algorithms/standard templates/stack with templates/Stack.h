

#ifndef STACK_H
#define STACK_H

// #define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>


template<class dataType>
class stackType
{

public:

	// Constructor
	stackType(void) { pTop = pNewNode = NULL; size = 0;}

	// Public methods
	void Push(dataType newData);

	bool Pop(dataType* pData);

	bool IsEmpty(void) { return pTop == NULL; }
	
	int Size(void) { return size; }

	
private:

	// Declare a node
	typedef struct nodePointerType
	{
		dataType data;

		struct nodePointerType* pNext;

	} nodeType;
	
	nodeType* pTop;
	nodeType* pNewNode;
	
	int size;

};

template<class dataType>
void stackType<dataType>::Push(dataType newData)
{
	pNewNode = (nodeType*)malloc(sizeof(nodeType));

	// Defensive coding
	if (pNewNode != NULL)
	{
		// Assign data of new node
		pNewNode->data = newData;

		// Add new node to the stack
		pNewNode->pNext = pTop;
		pTop = pNewNode;
		
		// Increase size by 1
		size++;
	}
}


template<class dataType>
bool stackType<dataType>::Pop(dataType* pData)
{
	bool dataPopped = false;

	nodeType* pTemp;

	if (!IsEmpty())
	{
		// Set the return value
		*pData = pTop->data;

		// Set temp to the top of the stack
		pTemp = pTop;

		// Move the top of the stack to the next node
		pTop = pTop->pNext;

		// Set return value to true
		dataPopped = true;

		// Free the temp node
		free(pTemp);
		
		// Decrease size by 1
		size--;

	}

	return dataPopped;
}

#endif
