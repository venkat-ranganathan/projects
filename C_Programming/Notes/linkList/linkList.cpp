// preprocessor directives
#include "linkList.h"

// struct prototype declaration
typedef struct dataType
{
    int number;

    struct dataType *pNext;
} linkList;

// function prototypes
void CreateNode(linkList *pTemp, int input);
void FindLocation(linkList *pList, linkList *pFirst, linkList *pSecond);
void InsertNewNode(linkList *pList, linkList *pFirst, linkList *pSecond);
// void PrintList(linkList *pList);

// main function
int main()
{
    int input;
    linkList *pTemp;
    linkList *pFirst = NULL;
    linkList *pSecond = NULL;

    linkList *pList = NULL;

    return 0;
}

void CreateNode(linkList *pTemp, int input)
{
    // create new node
    pTemp = (linkList *)malloc(sizeof(linkList));

    // assign values of new node
    pTemp->number = input;
    pTemp->pNext = NULL;
}

void InsertNewNode(linkList *pList, linkList *pFirst, linkList *pSecond)
{
    if (linkList == NULL)
    {
        pList = pTemp;
    }

    else if (pSecond == NULL)
    {
        // arrow is pointer to a structure
        if (pTemp->number > pFirst->pNext)
        {
            pFirst->pNext = pTemp;
        }

        else
        {
            pTemp->pNext = pList;
            pFirst->pTemp;
        }
    }

    else
    {
        if (pTemp->number > pFirst->pNext)
        {
            pFirst->pNext = pTemp;
        }

        else
        {
            pTemp->pNext = pList;
            pSecond->pTemp;
        }
    }
}

void FindLocation(linkList *pList, linkList *pFirst, linkList *pSecond)
{
    int done = 0;

    pFirst = pList;

    if (pList != NULL)
    {
        while (pFirst->pNext != NULL && !done)
        {
            if (pFirst->number < n)
            {
                pSecond = pFirst;
                pFirst = pFirst->pNext;
            }

            else
            {
                done = 1;
            }
        }
    }
}