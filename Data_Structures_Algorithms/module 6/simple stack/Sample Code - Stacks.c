
#include <stdio.h>

typedef struct
{
	//
	// All the data that will be stored in one record
	// will be declared here.
	//

	int sampleData;

} recordType;

typedef struct node
{
	// Declare a record
	recordType data;

	struct node* pNext;

} nodeType;

typedef struct
{
	nodeType* pTop;

} stackType;



int main(void)
{
	// Declare our stackType
	stackType stack;

	InitializeStack(&stack);



	return 0;
}


//-----------------------------------------------------------------------------
// Function Name: InitializeStack
// Description:
//   Set the top pointer to equal NULL
//
//-----------------------------------------------------------------------------
void InitializeStack(stackType* pStack)
{
	// Set pointer to NULL
	pStack->pTop = NULL;
}


//-----------------------------------------------------------------------------
// Function Name: StackIsEmpty
// Description:
//   Returns true or false based on if the pointer to top is NULL
//
//-----------------------------------------------------------------------------
int StackIsEmpty(stackType stack)
{
	// check to see if the stack is empty
	return stack.pTop == NULL;
}


//-----------------------------------------------------------------------------
// Function Name: Push
// Description:
//   Add one node to the stack.
//   Thus function assumes that the new node has already been 
//  declared and initialized. 
//
//-----------------------------------------------------------------------------
void Push(stackType* pStack, nodeType* pNewNode)
{
	//Defensive coding
	if (pNewNode == NULL)
	{
		printf("ERROR - There is no new data\n");
	}
	else
	{
		// Set the next pointer of the new node to equal top
		pNewNode->pNext = pStack->pTop;

		// Move the top pointer
		pStack->pTop = pNewNode;
	}
}


//-----------------------------------------------------------------------------
// Function Name: Pop
// Description:
//   Remove one node from the stack
//
//   Depending on the needs of your program, you may want to pass in a 
//  nodeType pointer so you can return the data from the node. 
//
//-----------------------------------------------------------------------------

void Pop(stackType* pStack)
{
	nodeType* pTemp;

	// See if the stack is empty
	if (!StackIsEmpty(*pStack))
	{
		// Assign pTemp to the top of the stack
		pTemp = pStack->pTop;

		// Move the top pointer down one node
		pStack->pTop = pStack->pTop->pNext;

		// Free the memory pointed to by temp
		free(pTemp);

	}

}









