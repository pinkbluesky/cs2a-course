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

char getKeyCharacter();
string getString();

string maskCharacter(string theString, char keyCharacter);
string removeCharacter(string theString, char keyCharacter);
int countKey(string theString, char keyCharacter);

const int MIN_STR_LENGTH = 4;

int main()
{
	char keyCharacter = getKeyCharacter();
	string theString = getString();

	cout << "String with key character, '" << keyCharacter << "' masked:" << endl;
	cout << maskCharacter(theString, keyCharacter) << endl;

	cout << "String with '" << keyCharacter << "' removed:" << endl;
	cout << removeCharacter(theString, keyCharacter) << endl;

	cout << "Number of occurrences of key character '" << keyCharacter << "':" << endl;
	cout << countKey(theString, keyCharacter) << endl;

	return 0;
}

// gets the key character from the user input
// only stops when the user input is valid
char getKeyCharacter()
{

}

// gets the string from the user input
// only stops when the input is at least 4 characters
string getString()
{

}

// replaces occurrences of key character in the string with *
// returns the new string
string maskCharacter(string theString, char keyCharacter)
{

}

// deletes occurrences of key character in the string
// returns the new string
string removeCharacter(string theString, char keyCharacter)
{

}

// counts the number of occurrences of key character in the string
// returns the number
int countKey(string theString, char keyCharacter)
{

}