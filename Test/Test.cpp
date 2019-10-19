#include <iostream>
using namespace std;

void maxValue(int value1, int value2, int max)
{
	if (value1 > value2)
		max = value1;
	else
		max = value2;
}

int main()
{
	int max = 0;
	maxValue(1, 2, max);
	cout << "max is " << max << endl;

	return 0;
}