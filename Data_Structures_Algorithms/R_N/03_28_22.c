// basic implementation of linked list; non-working code used to show idea

struct list
{
    int data;
    struct list *next;
}

struct list
{
    int data;
    struct list *next;
    struct list *prev; // another pointer referencing to previous node so you can implement two-way linked list
}

struct list
{
    int data;
    struct list *parent;
    struct list *right;
    struct list *left;
}

