#include <stdio.h>
#include <stdlib.h>

#define SIZE 128 // don't add an equal sign when using #define

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node * create(int n)
{
    Node *nptr;

    // allocate node
    nptr = malloc(sizeof(Node));
    if(nptr == NULL)
        return NULL;

    // initialize node
    nptr->data = n;
    nptr->next = NULL;

    return nptr;
}

int insert(Node *list, int n)
{
    Node *ptr;

    // create new node
    ptr = create(n);
    if(ptr == NULL)
        return 0;
    
    // attach to list
    while(list != NULL)
    {
        if(list->next != NULL)
            list = list->next;
        else
        {
            list->next = ptr;
            return 1;
        }
    }

    return 0;
}

void delete(Node *list)
{
    Node *ptr;

    // if list is empty
    if(list == NULL)
        return;
    
    // if list has one node
    if(list->next == NULL)
    {
        free(list);
        return;
    }

    // if list has more than one node; complexity is also O(n) here
    while(list->next != NULL)
    {
	ptr = list;
        list = list->next;
    }

    // delete
    free(ptr->next);
    ptr->next = NULL;
}

void print(Node *ptr)
{
    while(ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

// searching an array ADDED 03/23/22; this is O(n) complexity (which isn't great/good because you have to search
// sequentially)
int search(int arr[], int n)
{
    for(int i = 0; i < SIZE; i++) // SIZE needs to be defined
        if(arr[i] == n)
            return i;
}

Node * search(Node *list, int n)
{
    // if list is empty
    if(list == NULL)
    {
       return NULL;
    }
    
    // if list has one node only
    if(list->next == NULL)
    {
        if(list->data == n)
            return list;
        else
            return NULL;
    }
    
    // if list has more than one node
    while(list->next != NULL)
    {
        if(list->data == n)
            return list;
        list = list->next;
    }

    if(list->data == n)
        return list;
        
    return NULL;
}

int main()
{
    Node *anchor = NULL;
    
    // create head node
    anchor = create(0);
    
    // insert ten nodes to end
    printf("insert ten nodes to end:\n");
    for(int i = 1; i <= 10; i++)
    {
        printf("insert %d status: %d\n", i, insert(anchor, i));
    }
    print(anchor);

    // search for node with data 5
    printf("search for node with data 5:\n");
    Node *tmp = search(anchor, 5);
    if(tmp != NULL)
        printf("node found, data: %d\n", tmp->data);
    else
        printf("node not found!\n");

    // delete ten nodes from the end
    printf("delete ten nodes from end:\n");
    for(int i = 1; i <= 10; i++)
    {
        delete(anchor);
    }
    print(anchor);

    // delete head node
    free(anchor);
}

