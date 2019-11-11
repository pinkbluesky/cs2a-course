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
	double getLoanAmount();
	double getAnnualRate();
	int getLoanYears();
	// mutators
	bool setLoanAmount(double loanAmountVal);
	bool setAnnualRate(double annualRateVal);
	bool setLoanYears(double loanYearsVal);

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

	// SET THE MONTHLY RATE

	// if value is not valid
	if (!setLoanYears(loanYearsVal))
	{
		// set to default value
		loanYears = DEFAULT_VALUE;
	}

	// SET NUMBER OF PAYMENTS
}

// mutators: set value if validValue returns true

// sets the loan amount if it's a valid value
bool Mortgage::setLoanAmount(double loanAmountVal)
{
	if (validValue(loanAmountVal))
	{
		loanAmount = loanAmountVal;
		return true;
	}
	return false;
}

// sets the annual rate if it's a valid value
bool Mortgage::setAnnualRate(double annualRateVal)
{
	if (validValue(annualRateVal))
	{
		annualRate = annualRateVal;
		return true;
	}
	return false;
}

// sets the loan years if it's a valid value
bool Mortgage::setLoanYears(double loanYearsVal)
{
	if (validValue(loanYearsVal))
	{
		loanYears = loanYearsVal;
		return true;
	}
	return false;
}

// accessors: returns the requested value

// returns loan amount
double Mortgage::getLoanAmount()
{
	return loanAmount;
}

// returns annual rate
double Mortgage::getAnnualRate()
{
	return annualRate;
}

// returns the number of loan years
int Mortgage::getLoanYears()
{
	return loanYears;
}

// toString method
// returns a string containing all the Mortgage information
string Mortgage::toString()
{
	string out = "Amount of the loan: " + to_string(loanAmount) + "\n";
	out += "Annual interest rate: " + to_string(annualRate) + "\n";
	out += "Length of the loan in years: " + to_string(loanYears) + "\n";
}

// private helper method validValue()
// returns true if number is greater than default value
// returns false if not
bool Mortgage::validValue(double number)
{
	// if number is valid: greater than default value
	if (number > Mortgage::DEFAULT_VALUE)
	{
		return true;
	}

	// otherwise return false
	return false;
}