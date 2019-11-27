/*
* Name: Alina Li
* Date: 11/25/19, Due: 12/2/19
* Assignment: Lab Exercise 5, Question 32
* Description: 
* Write a  program that declares an array alpha of 50 components of 
* type double. Initialize the array so that the first 25 components 
* are equal to the square of the index variable, and the last 25 
* components are equal to three times the index variable.
* Output the array so that 10 elements per line are printed.
*/

#include <iostream>
using namespace std;

int main()
{
	// initialize array
	double alpha[50];

	// initialize first 25 elements
	for (int i = 0; i < 25; i++)
	{
		alpha[i] = i * i;
	}

	// initialize last 25 elements
	for (int i = 25; i < 50; i++)
	{
		alpha[i] = 3 * i;
	}

	// print 10 elements per line (5 lines in total)
	// for each 5 lines:
	for (int i = 0; i < 5; i++)
	{
		// for each element in the line
		for (int j = 0; j < 10; j++)
		{
			cout << alpha[i * 10 + j] << " ";
		}
		cout << endl;
	}

	return 0;
}

/*----RUN---------
0 1 4 9 16 25 36 49 64 81
100 121 144 169 196 225 256 289 324 361
400 441 484 529 576 75 78 81 84 87
90 93 96 99 102 105 108 111 114 117
120 123 126 129 132 135 138 141 144 147

----END OF RUN ---*/