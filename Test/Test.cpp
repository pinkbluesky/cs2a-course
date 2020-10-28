#include <iostream>
using namespace std;            

int main()
{
	char letter[5] = { 'o', 'k', 'c', 'e', 'g' };
	for (int i = 3; i >= 0; i--)
	{
		cout << letter[i];
	}
	cout << endl;
	return 0;
}

