/*
* Name: Alina Li
* Assignment: Midterm Question 30
*/

#include <iostream>
using namespace std;

int getEmployees();
int getDaysOut(int numOfEmployees);
double calcAverage(int numOfEmployees, int totalDaysAbsent);

int main()
{
	// ask the user for the number of employees in the company
	int numOfEmployees = getEmployees();
	// get the total number of days absent
	int totalDaysAbsent = getDaysOut(numOfEmployees);
	// calculate the average and print
	cout << "The average number of days missed was " 
		<< calcAverage(numOfEmployees, totalDaysAbsent) << "." << endl;
	return 0;
}

// asks the user for the number of employees in the company and returns value
int getEmployees()
{
	// set original value to 0
	int numOfEmployees = 0;
	while (numOfEmployees < 1)
	{
		cout << "How many employees are there in the company? ";
		cin >> numOfEmployees;
		cout << endl;

		// if invalid input
		if (numOfEmployees < 1)
		{
			cout << "The number of employees must be at least 1." << endl;
		}
	}

	return numOfEmployees;
}

// get and sums the total days absent from all the employees
int getDaysOut(int numOfEmployees)
{
	int totalDaysAbsent = 0;
	for (int i = 0; i < numOfEmployees; i++)
	{
		// -1 is the starting value for input
		int input = -1;
		while (input < 0)
		{
			// get the number of days the ith employee missed
			cout << "How many days did employee " << (i + 1) << " miss? ";
			cin >> input;
			cout << endl;

			if (input < 0)
			{
				cout << "The days missed must be at least 0." << endl;
			}
			else
			{
				totalDaysAbsent += input;
			}
		}
	}

	return totalDaysAbsent;
}

// calculates the average days missed per employee based on the 
// number of employees and the total number of days absent
double calcAverage(int numOfEmployees, int totalDaysAbsent)
{
	return ((double)totalDaysAbsent) / numOfEmployees;
}
