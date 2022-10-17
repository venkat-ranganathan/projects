#include <stdio.h>
#include <stdlib.h>

typedef struct Node // define structure and name it "Node"
{
    int data; 
    //struct Node n; // need this line because compiler needs to know size of structure // maybe it's not needed prof removed
    struct Node *next;
} Node; // need closing semicolon outside bracket of structure // added Node before semicolon to identify it?

Node * create(int n) // note space after *, is it important?
{
    Node *nptr; 

    nptr = malloc(sizeof(Node)); // allocating memory the size of Node to nptr
    if(nptr == NULL)
        return NULL;

    nptr->data = n; // initialize nptr to data
    nptr->next = NULL; // data next to nptr is NULL

    return nptr;
} // no need for semicolon outside bracket for Node

int insert(Node *list, int n) // function to insert data point
{
    Node *ptr;
    ptr = create(n); // creates node
    if(ptr == NULL)
        return 0;
    while(list != NULL) // continue loop unless the next data is NULL
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

void delete(Node *list) // function to delete data point, not working properly from lecture, wait for posted code
{
    Node *ptr;

    ptr = list;

    if(list == NULL)
        return;

    while(list->next != NULL) // continue loop unless the next data is NULL
    {
        ptr = list; // set pointer to list
        list = list->next; // set list as next
        /* else
        {
            //list->next = ptr;
            ptr = list;
        } */
    }

    free(ptr->next);
    ptr->next = NULL; // next data after ptr is NULL
    //return 0;
}

void print(Node *ptr) // calling Node *ptr into function
{
    while(ptr != NULL) // continue loop unless the next data is NULL
    {
        printf("%d\n", ptr->data); // what is %d? at a minimum adds a new line, then sets ptr as next data instead of NULL
        ptr = ptr->next;
    }
}

int main()
{
    Node *anchor;

    anchor = create(1); // create 1 on first node

    print(anchor);

   /*  printf("Insert 2: %d\n", insert(anchor, 2)); // should output both 1 and 2 before printing "Insert" portion, check posted code // SOLVED check below
    print(anchor); // need this line to print second number

    printf("Delete 2: \n");
    delete(anchor); // calls delete function to remove anchor */

    for(int i = 0; i < 10; i++)
    {
        printf("Insert %d status: %d\n", i, insert(anchor, i));
    }
    print(anchor);

    Node *tmp = search(anchor, 5);
    print(anchor);
}