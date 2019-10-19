/*
* Class: CS2A
* Description: Process a string and key character. Perform three operations
* (replace key characters with *, delete key characters from the string, and 
* count the number of key characters). 
* Due date: Oct 28, 2019, Monday
* Name: Alina Li
* File name: TextProcessing.cpp
*/

#include <iostream>
#include <string>
using namespace std;

// method prototypes
char getKeyCharacter();
string getString();
string maskCharacter(string theString, char keyCharacter);
string removeCharacter(string theString, char keyCharacter);
int countKey(string theString, char keyCharacter);

const int MIN_STR_LENGTH = 4;
const int MAX_STR_LENGTH = 500;

int main()
{
	char keyCharacter = getKeyCharacter();
	string theString = getString();

	cout << "String with key character, '" << keyCharacter << "' masked:" << endl;
	cout << maskCharacter(theString, keyCharacter) << endl << endl;

	cout << "String with '" << keyCharacter << "' removed:" << endl;
	cout << removeCharacter(theString, keyCharacter) << endl << endl;

	cout << "Number of occurrences of key character '" << keyCharacter << "':" << endl;
	cout << countKey(theString, keyCharacter) << endl;

	return 0;
}

// gets the key character from the user input
// only stops when the user input is valid
char getKeyCharacter()
{
	string input;
	do
	{
		cout << "Enter a single character to act as a key: ";
		getline(cin, input);
		cout << endl;
	} while (input.length() != 1);

	return input[0];
}

// gets the string from the user input
// only stops when the input is at least 4 characters
string getString()
{
	string input;
	do
	{
		cout << "Enter a sentence at least " << MIN_STR_LENGTH << " characters long "
			<< endl << "and at most " << MAX_STR_LENGTH << " characters long: " << endl;
		getline(cin, input);
		cout << endl;
	} while (input.length() < MIN_STR_LENGTH || input.length() > MAX_STR_LENGTH);

	return input;
}

// replaces occurrences of key character in the string with *
// returns the new string
string maskCharacter(string theString, char keyCharacter)
{
	string newStr = "";
	for (int i = 0; i < theString.length(); i++)
	{
		// if the character is key, then add *
		if (theString[i] == keyCharacter)
		{
			newStr = newStr + "*";
		}
		else
		{
			newStr = newStr + theString[i];
		}
	}

	return newStr;
}

// deletes occurrences of key character in the string
// returns the new string
string removeCharacter(string theString, char keyCharacter)
{
	string newStr = "";
	for (int i = 0; i < theString.length(); i++)
	{
		// when the character is not key, then add it
		if (theString[i] != keyCharacter)
		{
			newStr = newStr + theString[i];
		}
	}

	return newStr;
}

// counts the number of occurrences of key character in the string
// returns the number
int countKey(string theString, char keyCharacter)
{
	int count = 0;
	for (int i = 0; i < theString.length(); i++)
	{
		// when it matches key, increment count
		if (theString[i] == keyCharacter)
		{
			count++;
		}
	}

	return count;
}

/*-------------RUN 1----------------------------------
Enter a single character to act as a key: e

Enter a sentence at least 4 characters long
and at most 500 characters long:
heelloo hEElloo!!!

String with key character, 'e' masked:
h**lloo hEElloo!!!

String with 'e' removed:
hlloo hEElloo!!!

Number of occurrences of key character 'e':
2

-----------END OF RUN 1----------------------------*/

/*-------------RUN 2--------------------------------
Enter a single character to act as a key: this is a key

Enter a single character to act as a key:

Enter a single character to act as a key: Ffff

Enter a single character to act as a key:

Enter a single character to act as a key: \

Enter a sentence at least 4 characters long
and at most 500 characters long:


Enter a sentence at least 4 characters long
and at most 500 characters long:
sss

Enter a sentence at least 4 characters long
and at most 500 characters long:
""

Enter a sentence at least 4 characters long
and at most 500 characters long:
hello /how /are /you \doing \today?

String with key character, '\' masked:
hello /how /are /you *doing *today?

String with '\' removed:
hello /how /are /you doing today?

Number of occurrences of key character '\':
2

-----------END OF RUN 2-----------------------------*/

/*------------RUN 3---------------------------------
Enter a single character to act as a key: áá

Enter a single character to act as a key: á

Enter a sentence at least 4 characters long
and at most 500 characters long:
hola, comó estás? HOLA, COMÓ ESTÁS?

String with key character, 'á' masked:
hola, comó est*s? HOLA, COMO ESTAS?

String with 'á' removed:
hola, comó ests? HOLA, COMO ESTAS?

Number of occurrences of key character 'á':
1

-----------END OF RUN 3-----------------------------*/