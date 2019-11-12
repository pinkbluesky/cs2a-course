/*
* Class: CS2A
* Description: Create a Player class that has names and a score.
* Implement a main method that tests the Player class with an
* array of Players. The user has the option to add a new player,
* print all the players, search for a player, or remove a player.
* Due date: Monday, November 25th, 2019
* Name: (your name)
* File name: Foothill.cpp
*/

#include <iostream>
#include <string>
using namespace std;

class Player
{
private:
	// private members
	string firstName;
	string lastName;
	int score;

public:
	// static public members
	static const string DEFAULT_NAME;
	static const int DEFAULT_SCORE;
	static const int MAX_SCORE;
	static const int MAX_PLAYERS;
	static const int MAX_LEN;
	static const int MIN_LEN;
	
	// public methods
	// constructors
	Player();
	Player(string firstName, string lastName, int score);

	// accessors
	string getFirstName() { return firstName; }; // returns the first name
	string getLastName() { return lastName;  }; // returns the last name
	int getScore() { return score;  }; // returns the player's score
	// mutators
	bool setFirstName(string firstName);
	bool setLastName(string lastName);
	bool setScore(int score);

	// toString()
	string toString();

private:
	// private static helper methods
	static bool validString(string str);
	static bool validScore(int score);
};

// Player static constants 
const string Player::DEFAULT_NAME = "";
const int Player::DEFAULT_SCORE = 0;
const int Player::MAX_SCORE = 100;
const int Player::MAX_PLAYERS = 10;
const int Player::MAX_LEN = 30;
const int Player::MIN_LEN = 2;

// client ----------------------------------------------------------------------
int main()
{
	return 0;
}

// methods to run the client

// adds a new players and their score as long as the number of players in the 
// array is not greater than MAX_PLAYERS
// edits players[] array and numPlayers
// prints a confirmation message if successful, or error message if not
void addPlayer(int &numPlayers, Player players[])
{
	// if the length of the array would exceed the max_players
	if (numPlayers + 1 > Player::MAX_PLAYERS)
	{
		// print error message
		cout << "Error: cannot add new player because the number of "
			<< "players would exceed " << Player::MAX_PLAYERS << endl;
	}
	// if we can add the new player
	else
	{
		// ask user for the new player
		string firstName;
		string lastName;
		int score;
	
		cout << "Enter the new player's first name: ";
		cin >> firstName;
		cout << endl;

		cout << "Enter the new player's last name: ";
		cin >> lastName;
		cout << endl;

		cout << "Enter the new player's score: ";
		cin >> score;
		cout << endl;

		Player newPlayer(firstName, lastName, score);

		// update the empty position at players[numPlayers]
		players[numPlayers] = newPlayer;
		// update numPlayers
		numPlayers++;

		// print confirmation message
		cout << newPlayer.toString() << " has been added." << endl;
	}
}

// prints the players and their scores in the array
// does not edit any parameters
// prints a list of players or a message stating that there are no players 
void printPlayers(int numPlayers, Player players[])
{
	// print intro msg
	cout << "List of players and their scores: " << endl;
	for (int i = 0; i < numPlayers; i++)
	{
		// prints the player name and score
		cout << players[i].toString() << endl;
	}
}

// asks for a last name to search for
// prints the player's name and score or a message if the player wasn't found
void searchPlayers(int numPlayers, Player players[])
{
	// ask for user input
	string searchLastName;
	cout << "Which player do you want to search for by last name?" << endl;
	cin >> searchLastName;

	for (int i = 0; i < numPlayers; i++)
	{
		// if the name matches
		if (players[i].getLastName() == searchLastName)
		{
			// print player info
			cout << "Player found: " << players[i].toString() << endl;
			// exit
			return;
		}
	}

	// if no player matched
	cout << "No player found with last name " << searchLastName << "." << endl;
}

// asks for a last name of a Player to remove from the array
// edits players[] array and numPlayers
// prints a confirmation message if deletion was successful or message
void removePlayer(int& numPlayers, Player players[])
{
	// ask for user input
	string lastName;
	cout << "Which player do you want to remove by last name?" << endl;
	cin >> lastName;

	for (int i = 0; i < numPlayers; i++)
	{
		// if the name matches
		if (players[i].getLastName() == lastName)
		{
			// print a confirmation message
			cout << "Player " << players[i].toString() << " has been removed." 
				<< endl;
			// update numPlayers
			numPlayers--;
			// exit
			return;
		}
	}

	// if no player was found
	cout << "No player found with last name " << lastName << "." << endl;
}

// Player methods
// constructors

// constructs a Player object with members set to default values
Player::Player() : firstName(DEFAULT_NAME), lastName(DEFAULT_NAME),
score(DEFAULT_SCORE)
{/* Body intentionally empty */}

// constructs a Player object with the given values if the values are valid
// if not valid, they are set to the default value
Player::Player(string firstName, string lastName, int score)
{
	// if parameter is invalid and cannot be set
	if (!setFirstName(firstName))
	{
		// set this->firstName to the default
		this->firstName = DEFAULT_NAME;
	}

	// if parameter is invalid and cannot be set
	if (!setLastName(lastName))
	{
		// set this->lastName to the default
		this->lastName = DEFAULT_NAME;
	}

	// if parameter is invalid and cannot be set
	if (!setScore(score))
	{
		// set this->score to the default
		this->score = DEFAULT_SCORE;
	}
}

// mutators

// sets the first name if the parameter is a valid string (returns true)
// if invalid, returns false and does nothing
bool Player::setFirstName(string firstName)
{
	// if the name is valid
	if (validString(firstName))
	{
		// set the new name
		this->firstName = firstName;
		return true;
	}

	// if not, return false
	return false;
}

// sets the last name if the parameter is a valid string (returns true)
// if invalid, returns false and does nothing
bool Player::setLastName(string lastName)
{
	// if the name is valid
	if (validString(lastName))
	{
		// set the new name
		this->lastName = lastName;
		return true;
	}

	// if not, return false
	return false;
}

// sets the score of the Player object if the parameter is valid 
// if invalid, returns false and does nothing
bool Player::setScore(int score)
{
	// if the name is valid
	if (validScore(score))
	{
		// set the new name
		this->score = score;
		return true;
	}

	// if not, return false
	return false;
}

// returns a string containing all the Player info
string Player::toString()
{
	return firstName + " " + lastName + " " + to_string(score) + "\n";
}

// private static helper methods

// checks if the parameter is a valid string
// must be between MIN and MAX_LEN inclusive
bool Player::validString(string str)
{
	// if length is within the range
	if (str.length() >= MIN_LEN && str.length() <= MAX_LEN)
	{
		return true;
	}

	return false;
}

// checks if the parameter is a valid score 
// must be between DEFAULT_SCORE and MAX_SCORE inclusive
bool Player::validScore(int score)
{
	// if number is within the range
	if (score >= DEFAULT_SCORE && score <= MAX_SCORE)
	{
		return true;
	}

	return false;
}
