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
#include <iomanip>
#include <cmath>
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
	Mortgage(double loanAmount, double annualRate, int loanYears);

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

	// calculation methods
	double getMonthlyPayment();
	double getTotalPayback();
	// toString for calculations
	string calToString();

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
	// initialize 4 mortgages
	Mortgage mortgage1, mortgage2;
	Mortgage mortgage3 (3000, 0.035, 3);
	Mortgage mortgage4(45000, 0.025, 5);
	
	// immediately print 4 mortgages
	cout << "Mortgages before mutations: --------------------" << endl << endl;
	cout << "Mortgage 1: " << endl << mortgage1.toString() << endl << endl;
	cout << "Mortgage 2: " << endl << mortgage2.toString() << endl << endl;
	cout << "Mortgage 3: " << endl << mortgage3.toString() << endl;
	cout << mortgage3.calToString() << endl;
	cout << "Mortgage 4: " << endl << mortgage4.toString() << endl;
	cout << mortgage4.calToString() << endl;

	// mutate one or more members of every object
	mortgage1.setLoanAmount(4000);
	mortgage1.setAnnualRate(0.054);
	mortgage1.setLoanYears(2);

	mortgage2.setLoanAmount(1050);
	mortgage2.setAnnualRate(0.012);
	mortgage2.setLoanYears(10);

	mortgage3.setLoanAmount(1000);

	mortgage4.setAnnualRate(0.011);
	mortgage4.setLoanYears(8);

	// display 4 mortgages
	cout << "Mortgages after mutations: --------------------" << endl << endl;
	cout << "Mortgage 1: " << endl << mortgage1.toString() << endl;
	cout << mortgage1.calToString() << endl;
	cout << "Mortgage 2: " << endl << mortgage2.toString() << endl;
	cout << mortgage2.calToString() << endl;
	cout << "Mortgage 3: " << endl << mortgage3.toString() << endl;
	cout << mortgage3.calToString() << endl;
	cout << "Mortgage 4: " << endl << mortgage4.toString() << endl;
	cout << mortgage4.calToString() << endl;

	// 2 explicit mutator calls
	cout << "2 mutator calls: -----------------------------" << endl << endl;
	const double INVALID_ANNUAL = -0.111;
	cout << "Attempted to change Mortgage 1's annual rate to " 
		<< INVALID_ANNUAL << endl;
	if (mortgage1.setAnnualRate(INVALID_ANNUAL))
	{
		cout << "Change was incorrectly successful";
	}
	else
	{
		cout << "Change was correctly not successful";
	}
	cout << endl << mortgage1.toString() << endl;

	const double INVALID_LOAN_Y = -100;
	cout << "Attempted to change Mortgage 2's loan years to " 
		<< INVALID_LOAN_Y << endl;
	if (mortgage2.setLoanYears(INVALID_LOAN_Y))
	{
		cout << "Change was incorrectly successful";
	}
	else
	{
		cout << "Change was correctly not successful";
	}
	cout << endl << mortgage2.toString() << endl;

	// 2 accessor calls
	cout << "2 accessor calls: -------------------------" << endl << endl;
	cout << "Mortgage 3's loan years: " << mortgage3.getLoanYears() << endl;
	cout << "Mortgage 4's annual rate: " << mortgage4.getAnnualRate() << endl;
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
	int loanYearsVal) 
{
	// if value is not valid
	if (!setLoanAmount(loanAmountVal))
	{
		// set to default value
		loanAmount = DEFAULT_VALUE;
	}

	// if value is not valid
	// annual rate also sets monthly rate
	if (!setAnnualRate(annualRateVal))
	{
		// set to default value
		annualRate = DEFAULT_VALUE;
	}

	// if value is not valid
	// loan years also sets numberPayments
	if (!setLoanYears(loanYearsVal))
	{
		// set to default value
		loanYears = DEFAULT_VALUE;
	}
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
		monthlyRate = annualRate / 12;
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
		numberPayments = loanYears * NUM_OF_MONTHS;
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
	ostringstream streamLoanA, streamRate, streamLoanY;
	streamLoanA << fixed << setprecision(2) << loanAmount;
	string out = "Amount of the loan: " + streamLoanA.str() + "\n";

	streamRate << fixed << setprecision(3) << annualRate;
	out += "Annual interest rate: " + streamRate.str() + "\n";

	streamLoanY << loanYears;
	out += "Length of the loan in years: " + streamLoanY.str() + "\n";

	return out;
}

// get and calculate monthly payment
double Mortgage::getMonthlyPayment()
{
	double term = pow(1 + annualRate / 12, 12 * loanYears);
	return (loanAmount * annualRate * term / 12) / (term - 1);
}

// calculate total payback using monthyPayment * numPayments
double Mortgage::getTotalPayback()
{
	return getMonthlyPayment() * numberPayments;
}

// returns a string containing the values of the two calculations
string Mortgage::calToString()
{
	ostringstream streamMonthly, streamTotal;

	streamMonthly << fixed << setprecision(2) << getMonthlyPayment();
	string out = "Monthly payment: " + streamMonthly.str() + "\n";

	streamTotal << fixed << setprecision(2) << getTotalPayback();
	out += "Total payback: " + streamTotal.str() + "\n";

	return out;
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

/*-------------------RUN 1----------------------------------
Mortgages before mutations: --------------------

Mortgage 1:
Amount of the loan: 0.00
Annual interest rate: 0.000
Length of the loan in years: 0


Mortgage 2:
Amount of the loan: 0.00
Annual interest rate: 0.000
Length of the loan in years: 0


Mortgage 3:
Amount of the loan: 3000.00
Annual interest rate: 0.035
Length of the loan in years: 3

Monthly payment: 87.91
Total payback: 3164.62

Mortgage 4:
Amount of the loan: 45000.00
Annual interest rate: 0.025
Length of the loan in years: 5

Monthly payment: 798.63
Total payback: 47917.88

Mortgages after mutations: --------------------

Mortgage 1:
Amount of the loan: 4000.00
Annual interest rate: 0.054
Length of the loan in years: 2

Monthly payment: 176.20
Total payback: 4228.87

Mortgage 2:
Amount of the loan: 1050.00
Annual interest rate: 0.012
Length of the loan in years: 10

Monthly payment: 9.29
Total payback: 1114.78

Mortgage 3:
Amount of the loan: 1000.00
Annual interest rate: 0.035
Length of the loan in years: 3

Monthly payment: 29.30
Total payback: 1054.87

Mortgage 4:
Amount of the loan: 45000.00
Annual interest rate: 0.011
Length of the loan in years: 8

Monthly payment: 489.89
Total payback: 47029.64

2 mutator calls: -----------------------------

Attempted to change Mortgage 1's annual rate to -0.111
Change was correctly not successful
Amount of the loan: 4000.00
Annual interest rate: 0.054
Length of the loan in years: 2

Attempted to change Mortgage 2's loan years to -100
Change was correctly not successful
Amount of the loan: 1050.00
Annual interest rate: 0.012
Length of the loan in years: 10

2 accessor calls: -------------------------

Mortgage 3's loan years: 3
Mortgage 4's annual rate: 0.011

------------------END OF RUN 1----------------------------*/