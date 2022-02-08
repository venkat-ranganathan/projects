#include <stdio.h>

void foo(int *counter)
{
    *counter = *counter + 1; // can also use (*counter)++;
    printf("counter = %d\n", *counter);
}

void foo2(int arr[])
{
    printf("size = %ld\n", sizeof(arr));
    arr[2]++;
    (*(arr+2))++;
    printf("arr[2] = %d\n", arr[2]);
}

int main()
{
    int counter = 0;
    int y = 2;
    int array[] = {1,2,3,4,5};
    int *ptr;

    counter++; // or counter = counter + 1;

    {
        counter++;
    }

    if(y==2)
    {
        counter++;
    }

    for(int i = 0; i < 5; i++)
    {
        foo(&counter);
        array[3] = array[3] + 1;
        *(array + 3) = *(array + 3) + 1;
        printf("size = %ld\n", sizeof(array));
        foo2(array);
    }
}

// struct student st;
// st.id
// return st;