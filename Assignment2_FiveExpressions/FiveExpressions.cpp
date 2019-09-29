/*
* Class: CS2A
* Description: Compute and print out five expressions based on the number of letters in your first name, and your student ID.
* Due date: October 7th, 2019
* Name: Alina Li
* File name: FiveExpressions.cpp
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int myId = 20399733;
	int numLet = 5;

	cout << "My last name is Li" << endl;
	cout << "My Student ID is " << myId << endl;
	cout << "The number of characters in my first name is " << numLet << endl << endl;

	int intResult;
	double doubleResult;

	// expression 1 calculation and print-out
	intResult = myId % 17;
	cout << "Expression 1: " << intResult << endl;
	// expression 2 
	intResult = (numLet + 17) % 11;
	cout << "Expression 2: " << intResult << endl;
	// expression 3
	doubleResult = (myId) / (numLet + 800.0);
	cout << "Expression 3: " << setprecision(20) << fixed << doubleResult << endl;
	// expression 4
	intResult = 1 + 2 + 3 + 4 + 5;
	cout << "Expression 4: " << intResult << endl;
	// expression 5
	doubleResult = (15000.0) / (80.0 + ((myId - 123456.0) / ((numLet + 20.0) * (numLet + 20.0))));
	cout << "Expression 5: " << setprecision(20) << fixed << doubleResult << endl;

	return 0;
}

/*
-----------RUN--------------
My last name is Li
My Student ID is 20399733
The number of characters in my first name is 5

Expression 1: 5
Expression 2: 0
Expression 3: 25341.28322981366363819689
Expression 4: 15
Expression 5: 0.46122563418770690102

--------END of RUN-----------*/