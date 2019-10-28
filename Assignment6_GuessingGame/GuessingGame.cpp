/*
* Class: CS2A
* Description: The computer randomly chooses a number for the 
* user to guess. Until the user wants to stop, the game 
* repeats multiple times. Eventually, when the 
* game stops, statistics are printed.
* Due date: November 4th, Monday, 2019
* Name: Alina Li
* File name: GuessingGame.cpp
*/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
using namespace std;

// set the highest number of guesses a user can make
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

	string response = "";
	do
	{
		// run 1 game with game()
		int guessesNeeded = game();

		// update stats
		guesses += guessesNeeded;
		games++;
		best = std::fmin(guessesNeeded, best);

		// ask user if they want to play again
		cout << "Do you want to play again? ";
		cin >> response;
		cout << endl;

	} while (response[0] == 'y' || response[0] == 'Y');

	// call stats to print out stats
	stats(games, guesses, best);

	return 0;
}

// game method: runs one guessing game
// returns the number of guesses used
int game()
{
	unsigned seed = time(0);
	srand(seed);
	int number;
	number = rand() % MAX_VAL + 1;

	int numGuesses = 0;
	cout << "I'm thinking of a number between " << MIN_VAL 
		<< " and " << MAX_VAL << "..." << endl;
	int curGuess = 0;
	do
	{
		// get a guess value from the user
		cout << "Your guess? ";
		cin >> curGuess;

		numGuesses++;

		// if the guess is too high
		if (number < curGuess)
		{
			cout << "It's lower." << endl;
		}
		// if the guess is too low
		else if (number > curGuess)
		{
			cout << "It's higher." << endl;
		}

	} while (number != curGuess); 

	// print out the number of guesses made
	cout << "You got it right in " << numGuesses 
		<< " guesses!" << endl;
	return numGuesses;
}

// stats method: receives the number of games played, 
// the total number of guesses overall, and the best score
// prints results
void stats(int games, int guesses, int best)
{
	cout << "Overall results:" << endl;
	cout << "Total games = " << games << endl;
	cout << "Total guesses = " << guesses << endl;
	cout << "Guesses / Game = " << fixed << setprecision(1) 
		<< ((double)guesses / games) << endl;
	cout << "Best game = " << best << endl;
}

/*------------------RUN 1--------------------------
I'm thinking of a number between 1 and 100...
Your guess? 50
It's lower.
Your guess? 20
It's higher.
Your guess? 40
It's lower.
Your guess? 30
It's higher.
Your guess? 35
It's lower.
Your guess? 32
It's lower.
Your guess? 31
You got it right in 7 guesses!
Do you want to play again? yes

I'm thinking of a number between 1 and 100...
Your guess? 1
It's higher.
Your guess? 10
It's higher.
Your guess? 20
It's higher.
Your guess? 30
It's higher.
Your guess? 40
It's lower.
Your guess? 35
You got it right in 6 guesses!
Do you want to play again? yellow

I'm thinking of a number between 1 and 100...
Your guess? 100
It's lower.
Your guess? 90
It's lower.
Your guess? 80
It's lower.
Your guess? 70
It's lower.
Your guess? 50
It's lower.
Your guess? 30
It's lower.
Your guess? 20
It's lower.
Your guess? 10
It's lower.
Your guess? 2
It's higher.
Your guess? 4
You got it right in 10 guesses!
Do you want to play again? okay!

Overall results:
Total games = 3
Total guesses = 23
Guesses / Game = 7.7
Best game = 6

--------------------END OF RUN 1--------------------*/

/*---------------------RUN 2------------------------
I'm thinking of a number between 1 and 100...
Your guess? 50
It's higher.
Your guess? 80
It's lower.
Your guess? 60
It's higher.
Your guess? 70
It's lower.
Your guess? 64
It's higher.
Your guess? 67
It's lower.
Your guess? 66
It's lower.
Your guess? 65
You got it right in 8 guesses!
Do you want to play again? y

I'm thinking of a number between 1 and 100...
Your guess? 50
It's lower.
Your guess? 25
It's higher.
Your guess? 34
It's lower.
Your guess? 30
It's higher.
Your guess? 32
It's higher.
Your guess? 33
You got it right in 6 guesses!
Do you want to play again? nothanks

Overall results:
Total games = 2
Total guesses = 14
Guesses / Game = 7.0
Best game = 6

--------------------END OF RUN 2--------------------*/