#include <iostream>
using namespace std;

class CounterType
{
private:
	int count;
public:
	bool setCount(int);
	void addOne();
	bool subtractOne();
	int getCount();
	void printCount();
};

int main()
{
	CounterType myCounterType;

	bool valid = false;
	while (!valid)
	{
		int input;
		cout << "Enter a number to start with: ";
		cin >> input;
		valid = myCounterType.setCount(input);
		cout << endl;

		if (!valid)
		{
			cout << "Please enter a nonnegative whole number."
				<< endl;
		}
	}

	// if subtract one results in a negative number
	if (!myCounterType.subtractOne())
	{
		// print out error message
		cout << "Error: cannot subtract 1 because then count would be negative" 
			<< endl;
	}
	else
	{
		cout << "The value after subtracting 1: "
			<< myCounterType.getCount() << endl; 
	}
	
	myCounterType.addOne();
	cout << "The value after adding 1: " 
		<< myCounterType.getCount() << endl;

	cout << "Final value: ";
	myCounterType.printCount();
	return 0;
}

// set a new value for count if it is nonnegative
bool CounterType::setCount(int newCount)
{
	// if newCount is nonnegative
	if (newCount >= 0)
	{
		// set the new value
		count = newCount;
		return true;
	}
	// if value is invalid
	return false;
}


// increment count
void CounterType::addOne()
{
	count++;
}

// decrement count if new value is not negative
bool CounterType::subtractOne()
{
	// if new value would be negative
	if (count - 1 < 0)
	{
		// cannot subtract
		return false;
	}

	// otherwise:
	// decrement count and return true
	count--;
	return true;
}

// return the value of count
int CounterType::getCount()
{
	return count;
}

// prints count
void CounterType::printCount()
{
	cout << count;
}

/*---------------------------RUN 1--------------------------------
Enter a number to start with: -10

Please enter a nonnegative whole number.
Enter a number to start with: -1

Please enter a nonnegative whole number.
Enter a number to start with: 6

The value after subtracting 1: 5
The value after adding 1: 6
Final value: 6
--------------------------END OF RUN 1--------------------------*/

/*------------------------RUN 2---------------------------------
Enter a number to start with: 0

Error: cannot subtract 1 because then count would be negative
The value after adding 1: 1
Final value: 1
-------------------------END OF RUN 2--------------------------*/