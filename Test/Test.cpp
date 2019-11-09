#include <iostream>
using namespace std;

int fac(int num);

int main()
{
	int num = 3;
	cout << fac((-1) * num);
	

	return 0;
}

int fac(int num)
{
	int ans = 1;
	if (num < 0) return -1;
	while (num > 0)
	{
		ans = ans * num;
		num--;
	}
	return ans;
}