
// Include for output to the screen
#include <stdio.h>

// Include for the string class
#include <string>

using namespace std;

int main(void)
{
	// string is class that contains an array of characters.

	// The equal sign is overloaded so you can assign string like this:

	// Assign the string a name
	string name = "MR. Football";

	// Print info about the string
	printf("Name = %s\n\n", name.c_str());
	printf("How many characters long is name? %d\n\n", (int)name.length());

	// Replace the second character
	name.at(1) = 'r';

	// Print info about the string
	printf("Name = %s\n\n", name.c_str());
	printf("How many characters long is name? %d\n\n", (int)name.length());

	// Add another string to the string
	name.append(" and Mr. Basketball");

	// Print info about the string
	printf("Name = %s\n\n", name.c_str());
	printf("How many characters long is name? %d\n\n", (int)name.length());


	///////////////////////////////////////////////////////////////////////////////////////
	// Other String Functions
	//
	//   capacity()
	//
	//   resize()
	//
	//   shrink_to_fit()
	// 
	//   begin() - iterators
	//   end() 
	// 
	//   rbegin() - reverse iterator
	//   rend()
	// 
	//   There are many more
	// 
	//   See https://www.geeksforgeeks.org/stdstring-class-in-c/ for more information
	// 
	//   See http://www.yolinux.com/TUTORIALS/LinuxTutorialC++StringClass.html for more information
	//
	
	return 0;
}