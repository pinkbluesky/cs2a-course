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
#include <ctime>
#include <cstdlib>
using namespace std;

// set the highest possible number of guesses a user can make
const int MAX_GUESSES = 1000000;

// bounds for the random value selected (inclusive)
const int MIN_VAL = 1;
const int MAX_VAL = 100;

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
		cout << "Do you want to play again? ";
		cin >> response;
		cout << endl;

	} while (response[0] == 'y' || response[0] == 'Y'); // when the response starts with y, continue

	// call stats to print out stats
	stats(games, guesses, best);

	return 0;
}

// game method: runs one guessing game, returns the number of guesses used
int game()
{
	unsigned seed = time(0);
	srand(seed);
	int number;
	number = rand() % MAX_VAL + 1;

	int numGuesses = 0;
	cout << "I'm thinking of a number between " << MIN_VAL << " and " << MAX_VAL << "..." << endl;
	int curGuess = 0;
	do
	{
		// get a guess value from the user
		cout << "Your guess? ";
		cin >> guess;
		cout << endl;

		numGuesses++;

		// if the guess is too high
		if (number < guess)
		{
			cout << "It's lower." << endl;
		}
		// if the guess is too low
		else if (number > guess)
		{
			cout << "It's higher." << endl;-
		}
	} while (number != guess); // continue while the numbers do not match

	// print out the number of guesses made
	cout << "You got it right in " << numGuesses << " guesses!" << endl;
	return numGuesses;
}

// stats method: receives the number of games played, the total number
// of guesses overall, and the best score
// prints results
void stats(int games, int guesses, int best)
{

}