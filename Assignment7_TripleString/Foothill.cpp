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

// main method that tests and runs the class
int main()
{
	return 0;
}

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

bool TripleString::setString1(string str3)
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