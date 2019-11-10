/*
* Class: CS2A
* Description: Design a class that calculates the monthly payment 
* on a home mortgage. Test the class and its components and print
* output that demonstrates the class' capabilities.
* Due date: Monday, Nov 18th, 2019
* Name: Alina Li
* File name: Foothill.cpp
*/

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Mortgage
{
private:
	// private class variables
	double loanAmount;
	double annualRate;
	double monthlyRate;
	int loanYears;
	int numberPayments;

public:
	// static constants
	static const int NUM_OF_MONTHS;
	static const int DEFAULT_VALUE;

	// constructors
	Mortgage();
	Mortgage(double loanAmount, double annualRate, double monthlyRate,
		int loanYears, int numberPayments);

	// accessors
	// mutators
	bool setLoanAmount(double loanAmountVal);
	bool setAnnualRate(double annualRateVal);
	bool setMonthlyRate(double monthlyRateVal);
	bool setLoanYears(double loanYearsVal);
	bool setNumberPayments(double numberPaymentsVal);

	// toString
	string toString();

private:
	// static helper method
	static bool validValue(double number);
};

// define static constants
const int Mortgage::NUM_OF_MONTHS = 12;
const int Mortgage::DEFAULT_VALUE = 0;

// client ----------------------------------------------------------------------
int main()
{
	Mortgage mortgage1, mortgage2;

	return 0;
}

// Mortgage class methods
// constructors:

// initializes all member variables to DEFAULT_VALUE
Mortgage::Mortgage() : loanAmount(DEFAULT_VALUE), annualRate(DEFAULT_VALUE),
monthlyRate(DEFAULT_VALUE), loanYears(DEFAULT_VALUE), 
numberPayments(DEFAULT_VALUE)
{ /*Body intentionally empty*/ }

// initializes member variables if value is valid
// if not valid, initializes to DEFAULT_VALUE
Mortgage::Mortgage(double loanAmountVal, double annualRateVal, 
	double monthlyRateVal, int loanYearsVal, int numberPaymentsVal) 
{
	// if value is not valid
	if (!setLoanAmount(loanAmountVal))
	{
		// set to default value
		loanAmount = DEFAULT_VALUE;
	}

	// if value is not valid
	if (!setAnnualRate(annualRateVal))
	{
		// set to default value
		annualRate = DEFAULT_VALUE;
	}

	// if value is not valid
	if (!setMonthlyRate(monthlyRateVal))
	{
		// set to default value
		monthlyRate = DEFAULT_VALUE;
	}

	// if value is not valid
	if (!setLoanYears(loanYearsVal))
	{
		// set to default value
		loanYears = DEFAULT_VALUE;
	}

	// if value is not valids
	if (!setNumberPayments(numberPaymentsVal))
	{
		// set to default value
		numberPayments = DEFAULT_VALUE;
	}
}

// mutators: set value if validValue returns true
bool Mortgage::setLoanAmount(double loanAmountVal)
{
	if (validValue(loanAmountVal))
	{
		loanAmount = loanAmountVal;
		return true;
	}
	return false;
}

bool Mortgage::setAnnualRate(double annualRateVal)
{
	if (validValue(annualRateVal))
	{
		annualRate = annualRateVal;
		return true;
	}
	return false;
}

bool Mortgage::setMonthlyRate(double monthlyRateVal)
{
	if (validValue(monthlyRateVal))
	{
		monthlyRate = monthlyRateVal;
		return true;
	}
	return false;
}

bool Mortgage::setLoanYears(double loanYearsVal)
{
	if (validValue(loanYearsVal))
	{
		loanYears = loanYearsVal;
		return true;
	}
	return false;
}

bool Mortgage::setNumberPayments(double numberPaymentsVal)
{
	if (validValue(numberPaymentsVal))
	{
		numberPayments = numberPaymentsVal;
		return true;
	}
	return false;
}

// accessors:

// toString method
// returns a string containing all the Mortgage information
string toString()
{

}

// private helper method validValue()
// returns true if number is greater than default value
// returns false if not
bool validValue(double number)
{
	// if number is valid: greater than default value
	if (number > Mortgage::DEFAULT_VALUE)
	{
		return true;
	}

	// otherwise return false
	return false;
}