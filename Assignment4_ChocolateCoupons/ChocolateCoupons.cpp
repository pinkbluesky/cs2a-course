
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
#define MIN_BARS 1
#define MAX_BARS 100

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
		cout << "	Your choice: ";

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
				cout << "You qualify for a free chocolate bar. " << endl
					<< "Would you like to use your credits? (Y or N)" 
					<< endl;
				string ynInput;
				getline(cin, ynInput);

				// if user's answer is y (they want a free chocolate bar)
				if (ynInput[0] == 'y' || ynInput[0] == 'Y')
				{
					credits -= QUALIFICATION_NUM;
					cout << "You have just used " << QUALIFICATION_NUM 
						<< " credits and have " << credits 
						<< " credits left." << endl;
					cout << "Enjoy your free chocolate bar!" << endl;
					continue;
				}
				// if user's answer is invalid 
				// (print error msg, return to start of loop)
				else if (ynInput[0] != 'y' && ynInput[0] != 'Y'
					&& ynInput[0] != 'n' && ynInput[0] != 'N')
				{
					cout << "*** Invalid input: Please enter Y or N ***" 
						<< endl;
					continue;
				}
			}

			cout << "How many chocolate bars would you like to buy?"
				<< endl;
			string numOfBarsInput;
			getline(cin, numOfBarsInput);
			stringstream converter(numOfBarsInput);

			int numOfBars;
			converter >> numOfBars;
			// check for out of range value
			if (numOfBars < MIN_BARS || numOfBars > MAX_BARS)
			{
				cout << "*** Please enter a value between "
					<< MIN_BARS << " and " << MAX_BARS
					<< " ***" << endl;
				continue;
			}
			credits += numOfBars;

			cout << endl;
			cout << "You just earned " << numOfBars
				<< " coupons and have a total of " 
				<< credits << " to use."
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

/***************** RUN 1 ****************************
Menu:
		P (process purchase)
		S (shut down)
		Your choice: P

How many chocolate bars would you like to buy?
10

You just earned 10 coupons and have a total of 10 to use.
Menu:
		P (process purchase)
		S (shut down)
		Your choice: Process my purchase, please

You qualify for a free chocolate bar. 
Would you like to use your credits? (Y or N)
yes!
You have just used 7 credits and have 3 credits left.
Enjoy your free chocolate bar!
Menu:
		P (process purchase)
		S (shut down)
		Your choice: uh, maybe?

*** Please enter P or S ***
Menu:
		P (process purchase)
		S (shut down)
		Your choice: p

How many chocolate bars would you like to buy?
20000000
*** Please enter a value between 1 and 100 ***
Menu:
		P (process purchase)
		S (shut down)
		Your choice: p

How many chocolate bars would you like to buy?
100

You just earned 100 coupons and have a total of 103 to use.
Menu:
		P (process purchase)
		S (shut down)
		Your choice: p

You qualify for a free chocolate bar. 
Would you like to use your credits? (Y or N)
i don't know!
*** Invalid input: Please enter Y or N ***
Menu:
		P (process purchase)
		S (shut down)
		Your choice: p

You qualify for a free chocolate bar. 
Would you like to use your credits? (Y or N)
Nooooooo
How many chocolate bars would you like to buy?
9

You just earned 9 coupons and have a total of 112 to use.
Menu:
		P (process purchase)
		S (shut down)
		Your choice: ppp

You qualify for a free chocolate bar. 
Would you like to use your credits? (Y or N)
89
*** Invalid input: Please enter Y or N ***
Menu:
		P (process purchase)
		S (shut down)
		Your choice: p

You qualify for a free chocolate bar. 
Would you like to use your credits? (Y or N)
y
You have just used 7 credits and have 105 credits left.
Enjoy your free chocolate bar!
Menu:
		P (process purchase)
		S (shut down)
		Your choice: p

You qualify for a free chocolate bar. 
Would you like to use your credits? (Y or N)
n
How many chocolate bars would you like to buy?
10

You just earned 10 coupons and have a total of 115 to use.
Menu:
		P (process purchase)
		S (shut down)
		Your choice: p

You qualify for a free chocolate bar. 
Would you like to use your credits? (Y or N)
no
How many chocolate bars would you like to buy?
20

You just earned 20 coupons and have a total of 135 to use.
Menu:
		P (process purchase)
		S (shut down)
		Your choice: shut down

System shutting down now. Good bye!

**************** END of RUN 1 ****************************/

/******************* RUN 2 ************************************
Menu:
		P (process purchase)
		S (shut down)
		Your choice: p

How many chocolate bars would you like to buy?
0
*** Please enter a value between 1 and 100 ***
Menu:
		P (process purchase)
		S (shut down)
		Your choice: p

How many chocolate bars would you like to buy?
-10000
*** Please enter a value between 1 and 100 ***
Menu:
		P (process purchase)
		S (shut down)
		Your choice: p

How many chocolate bars would you like to buy?
10

You just earned 10 coupons and have a total of 10 to use.
Menu:
		P (process purchase)
		S (shut down)
		Your choice: pokey

You qualify for a free chocolate bar.
Would you like to use your credits? (Y or N)
YYY
You have just used 7 credits and have 3 credits left.
Enjoy your free chocolate bar!
Menu:
		P (process purchase)
		S (shut down)
		Your choice: P

How many chocolate bars would you like to buy?
200
*** Please enter a value between 1 and 100 ***
Menu:
		P (process purchase)
		S (shut down)
		Your choice: p

How many chocolate bars would you like to buy?
99

You just earned 99 coupons and have a total of 102 to use.
Menu:
		P (process purchase)
		S (shut down)
		Your choice: PPPrrroooccceeesss please

You qualify for a free chocolate bar.
Would you like to use your credits? (Y or N)
Y
You have just used 7 credits and have 95 credits left.
Enjoy your free chocolate bar!
Menu:
		P (process purchase)
		S (shut down)
		Your choice: p

You qualify for a free chocolate bar.
Would you like to use your credits? (Y or N)
n
How many chocolate bars would you like to buy?
1

You just earned 1 coupons and have a total of 96 to use.
Menu:
		P (process purchase)
		S (shut down)
		Your choice: s

System shutting down now. Good bye!

*************** END of RUN 2 *************************************/