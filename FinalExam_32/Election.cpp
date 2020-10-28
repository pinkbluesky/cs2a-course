#include <iostream>
#include <iomanip> 
#include <string>

using namespace std;
// your code here 
// returns the sum of the total votes
int sumVotes(int list[], int size);
// returns the index of the winner
int winnerIndex(int list[], int size);

int main()
{
	string candidates[5];
	int votes[5] = { 0 };
	int totalVotes;
	int i;

	cout << fixed << showpoint;
	cout << setprecision(2);
	cout << "Enter candidate's name and the votes received by "
		<< "the candidate." << endl;

	for (i = 0; i < 5; i++)
		cin >> candidates[i] >> votes[i];

	totalVotes = sumVotes(votes, 5);

	cout << "Candidate    Votes Received   % of Total Votes" << endl;
	for (i = 0; i < 5; i++)
		cout << left << setw(10) << candidates[i]
		<< right << " " << setw(10) << votes[i] << "   " << setw(15)
		<< (((double) votes[i]) / ((double) totalVotes)) * 100
		<< endl;

	cout << "Total            " << totalVotes << endl;

	cout << "The Winner of the Election is "
		<< candidates[winnerIndex(votes, 5)] << "." << endl;

	return 0;
}
// your code here 
// returns the sum of the total votes
int sumVotes(int list[], int size)
{
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += list[i];
	}
	return sum;
}

// returns the index of the winner
int winnerIndex(int list[], int size)
{
	int winnerIndex = 0;
	for (int i = 1; i < size; i++)
	{
		// if the current person has more votes
		if (list[i] > list[winnerIndex])
		{
			winnerIndex = i;
		}
	}

	return winnerIndex;
}

/*
Enter candidate's name and the votes received by the candidate.
Johnson 5000
Miller 4000
Duffy 6000
Robinson 25000
Ashtony 18000
Candidate    Votes Received   % of Total Votes
Johnson          5000              8.62
Miller           4000              6.90
Duffy            6000             10.34
Robinson        25000             43.10
Ashtony         18000             31.03
Total            58000
The Winner of the Election is Robinson.

*/
