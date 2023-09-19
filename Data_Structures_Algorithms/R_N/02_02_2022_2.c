#include <stdio.h>

struct student {
	int id;
	float gpa;
};

void foo2(int arr[])
{
	// check size of array after passing to function
	// output is size of pointer (memory address) in bytes
	printf("size = %ld\n", sizeof(arr));
	
	// same statement with different notations
	arr[2]++;
	(*(arr + 2))++;
	printf("arr[2] = %d\n", arr[2]);
}

struct student foo3()
{
	// locally declared structure
	struct student s;
	s.id = 11111;
	s.gpa = 3.5;
	return s;
}

int main()
{
	// example: pointers vs arrays
	int array[] = {1,2,3,4,5};
	int *ptr;
	
	ptr = array;

	// same statement with different notations
	// array notation
	array[3] = array[3] + 1;
	// pointer notation
	*(array + 3) = *(array + 3) + 1;

	// use "ptr"
	*(ptr + 3) = *(ptr + 3) + 1;
	printf("array[3] = %d\n", array[3]);

	// check size of array
	// output is total size of array in bytes
	printf("size = %ld\n", sizeof(array));

	// pass array to foo()
	foo2(array);

	// example: structures
	// declare a variable of type structure student
	struct student st;
	// access structure fields
	st.id = 12345;
	st.gpa = 3.0;

	// declare a pointer of type structure student
	struct student *st_ptr;
	// access structure fields
	st_ptr->id = 6789;
	st_ptr->gpa = 3.2;

	// declare a structure variable in a function and return it
	st = foo3();
	printf("id %d, gpa %f\n", st.id, st.gpa);
}

