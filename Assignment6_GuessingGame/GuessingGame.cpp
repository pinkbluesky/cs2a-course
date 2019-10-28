/*
* Class: CS2A
* Description: The computer randomly chooses a number for the user to guess.
* Until the user wants to stop, the game repeats multiple times. Eventually,
* when the game stops, statistics are printed.
* Due date: November 4th, Monday, 2019
* Name: Alina Li
* File name: GuessingGame.cpp
*/

#include <iostream>
using namespace std;

// set the highest possible number of guesses a user can make
const int MAX_GUESSES = 1000000;

// method prototypes
int game();
void stats(int games, int guesses, int best);

// main method
int main()
{
	// keeps track of the number of games played
	int games = 0;
	// keeps track of the total number of guesses made
	int guesses = 0;
	// keeps track of the smallest number of guesses
	int best = MAX_GUESSES;

	do
	{
		// run 1 game with game()
		int guessesNeeded = game();
		cout << "You got it right in " << guessesNeeded << " guesses!" << endl;

		// update stats
		guesses += guessesNeeded;
		games++;
		best = std::fmin(guessesNeeded, best);

		// ask user if they want to play again
		cout << "Do you want to play again?";
		string response;
		getline(cin, response); 

	} while (response[0] == 'y' || response[0] == 'Y'); // when the response starts with y, continue

	// call stats to print out stats
	stats(games, guesses, best);

	return 0;
}

// game method: runs one guessing game, returns the number of guesses used
int game()
{

}

// stats method: receives the number of games played, the total number
// of guesses overall, and the best score
// prints results
void stats(int games, int guesses, int best)
{

}