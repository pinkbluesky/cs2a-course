/*
* Class: CS2A
* Description: Implement a class TripleString with private member variables, 
* constants, methods, and accessors and mutators. Test the class and its 
* components and print output.
* Due date: Monday, November 11th, 2019
* Name: Alina Li
* File name: Foothill.cpp
*/

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class TripleString
{
private:
	// private member variables
	string string1, string2, string3;
 
public:
	// static constants
	static const int MIN_LEN;
	static const int MAX_LEN = 50;
	static const string DEFAULT_STRING;

	// constructors
	TripleString();
	TripleString(string str1, string str2, string str3);

	// mutators and accessors
	bool setString1(string str1);
	bool setString2(string str2);
	bool setString3(string str3);
	string getString1();
	string getString2();
	string getString3();
	// info method
	string toString();

private:
	// private static helper methods
	static bool validString(string str);

};

// TripleString static constants initialization
const int MIN_LEN = 1;
const int MAX_LEN = 50;
const string DEFAULT_STRING = " (undefined) ";

// client -------------------------------------------------------------------------
// main method that tests and runs the class
int main()
{
	// initialize 4 TripleString objects
	TripleString pets;
	TripleString fruits;
	TripleString sports("ice skating", "baseball", "basketball");
	TripleString languages("French", "Spanish", "English");

	// immediately display objects
	cout << "----- TripleStrings after instantiation -------" << endl;
	cout << pets.toString() << endl;
	cout << fruits.toString() << endl;
	cout << sports.toString() << endl;
	cout << languages.toString() << endl << endl;

	// mutate one or more members of every object
	pets.setString1("dogs");
	pets.setString2("cats");
	pets.setString3("fish");
	// mutate fruits object
	fruits.setString1("oranges");
	fruits.setString2("apples");
	fruits.setString3("watermelon");
	// mutate sports object
	sports.setString2("golf");
	// mutate languages object
	languages.setString1("Mandarin");
	languages.setString3("Japanese");

	// display objects again
	cout << "----- TripleStrings after changes ------" << endl;
	cout << pets.toString() << endl;
	cout << fruits.toString() << endl;
	cout << sports.toString() << endl;
	cout << languages.toString() << endl << endl;

	// two explicit mutator tests
	cout << "----- Mutator tests -----" << endl;

	// Mutator 1: empty string
	cout << "Attempted to change string2 of pets(TripleString1) into an empty string:" << endl;
	if (pets.setString2(""))
	{
		cout << "TripleString mutator accepted the empty string." << endl;
	}
	else
	{
		cout << "TripleString mutator correctly rejected the empty string." << endl;
	}
	cout << endl;

	// Mutator 2: string with 60 characters
	cout << "Attempted to change string 1 of languages(TripleString4) into a 60-char string:" << endl;
	const string LONG_STR = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	if (languages.setString1(LONG_STR))
	{
		cout << "TripleString mutator accepted the 60-char string." << endl;
	}
	else
	{
		cout << "TripleString mutator correctly rejected the 60-char string." << endl;
	}
	cout << endl;

	// two accessor tests
	cout << "----- Accessor tests -----" << endl;
	cout << "sports (TripleString3) string 2 value is: " << sports.getString2() << endl;
	cout << "pets (TripleString1) string 3 value is: " << pets.getString3();

	return 0;
}
// end client ---------------------------------------------------------------------

// TripleString class methods

// constructors:
TripleString::TripleString()
{
	string1 = DEFAULT_STRING;
	string2 = DEFAULT_STRING;
	string3 = DEFAULT_STRING;
}

TripleString::TripleString(string str1, string str2, string str3)
{
	// if str1 invalid
	if (!setString1(str1))
	{
		// set to default value
		string1 = DEFAULT_STRING;
	}
	// if str2 invalid
	if (!setString2(str2))
	{
		// set to default value
		string2 = DEFAULT_STRING;
	}
	// if str1 invalid
	if (!setString3(str3))
	{
		// set to default value
		string3 = DEFAULT_STRING;
	}
}

// methods:

// private helper method
// returns true if str is within MIN and MAX_LEN, false if not
bool TripleString::validString(string str)
{
	if (str.length() >= MIN_LEN && str.length() <= MAX_LEN)
	{
		return true;
	}
	return false;
}

// method that returns a string containing all the info
string TripleString::toString()
{
	// returns a string with all three strings
	return string1 + ", " + string2 + ", " + string3 + "\n";
}

// mutators:
bool TripleString::setString1(string str1)
{
	// if input is valid
	if (validString(str1))
	{
		// set the new string
		string1 = str1;
		return true;
	}
	else
	{
		// no action taken
		return false;
	}
}

bool TripleString::setString2(string str2)
{
	// if input is valid
	if (validString(str2))
	{
		// set the new string
		string2 = str2;
		return true;
	}
	else
	{
		// no action taken
		return false;
	}
}

bool TripleString::setString3(string str3)
{
	// if input is valid
	if (validString(str3))
	{
		// set the new string
		string3 = str3;
		return true;
	}
	else
	{
		// no action taken
		return false;
	}
}

// accessors:
string TripleString::getString1()
{
	return string1;
}

string TripleString::getString2()
{
	return string2;
}

string TripleString::getString3()
{
	return string3;
}