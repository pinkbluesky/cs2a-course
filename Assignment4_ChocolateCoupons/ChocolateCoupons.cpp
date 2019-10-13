/*
* Class: CS2A
* Description: This program is a repeating transactions with a customer
* that keeps track of the number of chocolate bar coupons. It also
* allows the customer to buy chocolate bars.
* Due date: 10/21/19, Monday
* Name: Alina Li
* File name: ChocolateCoupons.cpp
*/

#include <iostream>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

#define QUALIFICATION_NUM 7

int main()
{

	int credits = 0;

	char inputCh;

	// continue reading input while input is not s
	do
	{
		cout << "Menu:" << endl;
		cout << "	P (process purchase)" << endl
			<< "	S (shut down)" << endl;
		cout << "Your choice: ";

		string inputStr;
		getline(cin, inputStr);
		inputCh = inputStr[0];
		cout << endl;

		// if input is process purchase
		if (inputCh == 'P' || inputCh == 'p')
		{
			// check if customer qualifies for a free chocolate bar
			if (credits >= QUALIFICATION_NUM)
			{
				cout << "You qualify for a free chocolate bar. Would you like to use your credits? (y or n)" << endl;
				string ynInput;
				getline(cin, ynInput);

				// if user's answer is y (they want a free chocolate bar)
				if (ynInput[0] == 'y' || ynInput[0] == 'Y')
				{
					credits -= QUALIFICATION_NUM;
					cout << "You have just used " << QUALIFICATION_NUM << " credits and have " << credits << " credits left." << endl;
					cout << "Enjoy your free chocolate bar!" << endl;
					continue;
				}
				// if user's answer is invalid (print error msg, return to start of loop)
				else if (ynInput[0] != 'y' && ynInput[0] != 'Y'
					&& ynInput[0] != 'n' && ynInput[0] != 'N')
				{
					cout << "*** Invalid input: Please enter Y or N ***" << endl;
				}
			}

			cout << "How many chocolate bars would you like to buy?"
				<< endl;
			string numOfBarsInput;
			getline(cin, numOfBarsInput);
			stringstream converter(numOfBarsInput);

			int numOfBars;
			converter >> numOfBars;
			credits += numOfBars;

			cout << endl;
			cout << "You just earned " << numOfBars
				<< " coupons and have a total of " << credits << " to use."
				<< endl;
		}
		// if input is invalid
		else if (inputCh != 'P' && inputCh != 'p'
			&& inputCh != 'S' && inputCh != 's')
		{
			cout << "*** Please enter P or S ***" << endl;
		}

	} while (inputCh != 'S' && inputCh != 's');

	cout << "System shutting down now. Good bye!" << endl;

	return 0;
}