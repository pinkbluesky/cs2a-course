/*
* Class: CS2A
* Description: Compute and print out five expressions based on the number of letters in your first name, and your student ID.
* Due date: October 7th, 2019
* Name: Alina Li
* File name: FiveExpressions.cpp
*/

#include <iostream>
using namespace std;

int main()
{
	int myId = 20399733;
	int numLet = 5;

	cout << "My last name is Li." << endl;
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
	cout << "Expression 3: " << doubleResult << endl;
	// expression 4
	intResult = 1 + 2 + 3 + 4 + 5;
	cout << "Expression 4: " << intResult << endl;
	// expression 5
	doubleResult = (15000.0) / (80.0 + ((myId - 123456.0) / ((numLet + 20.0) * (numLet + 20.0))));
	cout << "Expression 5: " << doubleResult << endl;

	return 0;
}