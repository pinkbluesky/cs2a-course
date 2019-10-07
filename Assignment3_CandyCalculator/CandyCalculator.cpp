/*
* Class: CS2A
* Description: CandyCalculator calculates the number of candy bars needed for a person to maintain his/her weight. 
* This is done by calculating BMR, which is based on gender, weight, height, age, and activity.  
* Due date: Oct 14, 2019
* Name: Alina Li
* File name: CandyCalculator.cpp
*/

#include <iostream>
using namespace std;

int main()
{
	cout << "This program will calculate the number of 230 calorie candy bars to eat to maintain your weight.";
	
	cout << "What is your age in years?";
	int age;
	cin >> age;
	if ((age < 1) || (age > 100))
	{
		cout << "You must enter an age between 1 and 100.";
		return 0;
	}

	cout << "What is your total height in inches?";
	int height;
	cin >> height;
	if ((height < 10) || (height > 100))
	{
		cout << "You must enter a height between 10 and 100.";
		return 0;
	}

	cout << "What is your weight in pounds?";
	int weight;
	cin >> weight;
	if ((weight < 10) || (weight > 500))
	{
		cout << "You must enter a weight between 10 and 500.";
		return 0;
	}

	return 0;
}