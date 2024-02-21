
#include <iostream>

#include <fstream>

using namespace std;

#define MAX_ROWS 4
#define MAX_COLUMNS 5

void SearchTwoDArray(int matrix[MAX_ROWS][MAX_COLUMNS],
	int rowStart, int columnStart, int& foundRow, int& foundColumn,
	int searchValue, bool& match);

int main(void)
{
	int row, column;
	bool match;

	int table[MAX_ROWS][MAX_COLUMNS];
    
	ifstream fin("data.txt");

	for (int counterRow = 0; counterRow < MAX_ROWS; counterRow++)
	{
		// Read in one row of the table
		for (int counterCol = 0; counterCol < MAX_COLUMNS; counterCol++)
		{
			// Read in one element of the table
			fin >> table[counterRow][counterCol];
		}
	}


	SearchTwoDArray(table, 0, 0, row, column, 67, match);


	return 0;
}

void SearchTwoDArray(int matrix[MAX_ROWS][MAX_COLUMNS],
	int rowStart, int columnStart, int& foundRow, int& foundColumn,
	int searchValue, bool& match)
{
	//searches through each column of the row
	if (columnStart < MAX_COLUMNS)
	{
		SearchTwoDArray(matrix, rowStart, columnStart + 1, foundRow, foundColumn, searchValue, match);
	}

	//once all columns are checked moves to next row and repeats process
	if (rowStart < MAX_ROWS)
	{
		SearchTwoDArray(matrix, rowStart + 1, columnStart, foundRow, foundColumn, searchValue, match);
	}
	//set found row and column and match if a match is found
	if (matrix[rowStart][columnStart] == searchValue)
	{
		foundRow = rowStart;
		foundColumn = columnStart;
		match = true;
	}
}

