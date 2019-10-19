// kiloConverter.cpp 
// This menu-driven program lets the user convert 
// pounds to kilograms and kilograms to pounds.
// Alina Li
#include <iostream>
using namespace std;

// Function prototypes
void displayMenu();
int getChoice(int min, int max);
double kilosToPounds(double kilos);
double poundsToKilos(double pounds);

/*****     main     *****/
int main()
{
	int choice;
	double weight;       // Amount of weight to be converted

	do
	{  // Call functions to display the menu and get the user's choice
		displayMenu();
		choice = getChoice(1, 3);

		// Get the weight to be converted
		if (choice != 3)
		{
			cout << "Weight to be converted: ";
			cin >> weight;
		}

		// Call the appropriate function to do the desired conversion
		if (choice == 1)
			cout << weight << " kilograms = "
			<< kilosToPounds(weight) << " pounds.\n";
		else if (choice == 2)
			cout << weight << " pounds = "
			<< poundsToKilos(weight) << " kilograms.\n";
		// else choice == 3 so do nothing
	} while (choice != 3);

	return 0;
}

/*****     displayMenu     *****/
void displayMenu()
{
	cout << "Menu:" << endl
		<< "1. Convert kilograms to pounds" << endl
		<< "2. Convert pounds to kilograms" << endl
		<< "3. Quit" << endl;
}

/*****     getChoice     *****/
/***** getChoice *****/
int getChoice(int min, int max)
{
	int input;

	// Get and validate the input
	cin >> input;
	while (input < min || input > max)
	{
		cout << "Invalid input. Enter an integer between "
			<< min << " and " << max << ": ";
		cin >> input;
	}
	return input;
}

/*****     kilosToPounds     *****/
double kilosToPounds(double kilos)
{
	return kilos * 2.2;
}

/*****    poundsToKilos     *****/
double poundsToKilos(double pounds)
{
	return pounds / 2.2;
}

/*----------------RUN 1------------------
Menu:
1. Convert kilograms to pounds
2. Convert pounds to kilograms
3. Quit
1
Weight to be converted: 45
45 kilograms = 99 pounds.
Menu:
1. Convert kilograms to pounds
2. Convert pounds to kilograms
3. Quit
2
Weight to be converted: 90
90 pounds = 40.9091 kilograms.
Menu:
1. Convert kilograms to pounds
2. Convert pounds to kilograms
3. Quit
3

--------------END OF RUN 1---------------*/