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

// client function prototypes
// adds a player
void addPlayer(int& numPlayers, Player players[]);
// prints all players
void printPlayers(int numPlayers, Player players[]);
// searches for a player
void searchPlayers(int numPlayers, Player players[]);
// removes a player
void removePlayer(int& numPlayers, Player players[]);

// client ----------------------------------------------------------------------
int main()
{
	// constants for the 5 possible user inputs
	static const char ADD_CHOICE = 'a';
	static const char PRINT_CHOICE = 'b';
	static const char SEARCH_CHOICE = 'c';
	static const char REMOVE_CHOICE = 'd';
	static const char QUIT_CHOICE = 'e';

	// variables
	int numPlayers = 0;
	// players length is the max length
	Player players[Player::MAX_PLAYERS];

	char choice;
	do
	{
		// print menu
		cout << "Enter an option:" << endl;
		cout << ADD_CHOICE << ". Add new player and score." << endl;
		cout << PRINT_CHOICE << ". Print all players and scores." << endl;
		cout << SEARCH_CHOICE << ". Search for a player's score." << endl;
		cout << REMOVE_CHOICE << ". Remove a player." << endl;
		cout << QUIT_CHOICE << ". Quit." << endl;

		cin >> choice;
		cout << endl;

		// add a new player
		if (choice == ADD_CHOICE)
		{
			addPlayer(numPlayers, players);
		}
		// print the players
		else if (choice == PRINT_CHOICE)
		{
			printPlayers(numPlayers, players);
		}
		// search for a player
		else if (choice == SEARCH_CHOICE)
		{
			searchPlayers(numPlayers, players);
		}
		// remove a player
		else if (choice == REMOVE_CHOICE)
		{
			removePlayer(numPlayers, players);
		}

		cout << endl;
	} while (choice != QUIT_CHOICE);
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

			// overwrite values starting at p[i]
			for (int k = i; k < numPlayers - 1; k++)
			{
				// overwrite
				players[k] = players[k + 1];
			}

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
	return firstName + " " + lastName + " " + to_string(score);
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

/*------------------------RUN 1----------------------------------------------
Enter an option:
a. Add new player and score.
b. Print all players and scores.
c. Search for a player's score.
d. Remove a player.
e. Quit.
a

Enter the new player's first name: Alex

Enter the new player's last name: Abraham

Enter the new player's score: 10

Alex Abraham 10 has been added.

Enter an option:
a. Add new player and score.
b. Print all players and scores.
c. Search for a player's score.
d. Remove a player.
e. Quit.
a

Enter the new player's first name: Betty

Enter the new player's last name: Burg

Enter the new player's score: 5

Betty Burg 5 has been added.

Enter an option:
a. Add new player and score.
b. Print all players and scores.
c. Search for a player's score.
d. Remove a player.
e. Quit.
b

List of players and their scores:
Alex Abraham 10
Betty Burg 5

Enter an option:
a. Add new player and score.
b. Print all players and scores.
c. Search for a player's score.
d. Remove a player.
e. Quit.
a

Enter the new player's first name: Cary

Enter the new player's last name: Chen

Enter the new player's score: 20

Cary Chen 20 has been added.

Enter an option:
a. Add new player and score.
b. Print all players and scores.
c. Search for a player's score.
d. Remove a player.
e. Quit.
c

Which player do you want to search for by last name?
Burg
Player found: Betty Burg 5

Enter an option:
a. Add new player and score.
b. Print all players and scores.
c. Search for a player's score.
d. Remove a player.
e. Quit.
c

Which player do you want to search for by last name?
zzzzz
No player found with last name zzzzz.

Enter an option:
a. Add new player and score.
b. Print all players and scores.
c. Search for a player's score.
d. Remove a player.
e. Quit.
d

Which player do you want to remove by last name?
Chen
Player Cary Chen 20 has been removed.

Enter an option:
a. Add new player and score.
b. Print all players and scores.
c. Search for a player's score.
d. Remove a player.
e. Quit.
b

List of players and their scores:
Alex Abraham 10
Betty Burg 5

Enter an option:
a. Add new player and score.
b. Print all players and scores.
c. Search for a player's score.
d. Remove a player.
e. Quit.
a

Enter the new player's first name: Danny

Enter the new player's last name: Diaz

Enter the new player's score: 40

Danny Diaz 40 has been added.

Enter an option:
a. Add new player and score.
b. Print all players and scores.
c. Search for a player's score.
d. Remove a player.
e. Quit.
b

List of players and their scores:
Alex Abraham 10
Betty Burg 5
Danny Diaz 40

Enter an option:
a. Add new player and score.
b. Print all players and scores.
c. Search for a player's score.
d. Remove a player.
e. Quit.
e



--------------------------------END OF RUN 1-------------------------------*/

/*----------------------------------RUN 2----------------------------------
Enter the new player's first name: Axel

Enter the new player's last name: Adams

Enter the new player's score: 10

Axel Adams 10 has been added.

Enter an option:
a. Add new player and score.
b. Print all players and scores.
c. Search for a player's score.
d. Remove a player.
e. Quit.
a

Enter the new player's first name: Betty

Enter the new player's last name: Burgs

Enter the new player's score: 20

Betty Burgs 20 has been added.

Enter an option:
a. Add new player and score.
b. Print all players and scores.
c. Search for a player's score.
d. Remove a player.
e. Quit.
a

Enter the new player's first name: Cary

Enter the new player's last name: Chen

Enter the new player's score: 44

Cary Chen 44 has been added.

Enter an option:
a. Add new player and score.
b. Print all players and scores.
c. Search for a player's score.
d. Remove a player.
e. Quit.
a

Enter the new player's first name: Deanna

Enter the new player's last name: Drake

Enter the new player's score: 40

Deanna Drake 40 has been added.

Enter an option:
a. Add new player and score.
b. Print all players and scores.
c. Search for a player's score.
d. Remove a player.
e. Quit.
a

Enter the new player's first name: Eddie

Enter the new player's last name: Edholm

Enter the new player's score: 10

Eddie Edholm 10 has been added.

Enter an option:
a. Add new player and score.
b. Print all players and scores.
c. Search for a player's score.
d. Remove a player.
e. Quit.
a

Enter the new player's first name: Fanny

Enter the new player's last name: Far

Enter the new player's score: 50

Fanny Far 50 has been added.

Enter an option:
a. Add new player and score.
b. Print all players and scores.
c. Search for a player's score.
d. Remove a player.
e. Quit.
a

Enter the new player's first name: Gerrie

Enter the new player's last name: Gertie

Enter the new player's score: 11

Gerrie Gertie 11 has been added.

Enter an option:
a. Add new player and score.
b. Print all players and scores.
c. Search for a player's score.
d. Remove a player.
e. Quit.
a

Enter the new player's first name: Henrietta

Enter the new player's last name: Holmes

Enter the new player's score: 55

Henrietta Holmes 55 has been added.

Enter an option:
a. Add new player and score.
b. Print all players and scores.
c. Search for a player's score.
d. Remove a player.
e. Quit.
a

Enter the new player's first name: Ian

Enter the new player's last name: Illan

Enter the new player's score: 100

Ian Illan 100 has been added.

Enter an option:
a. Add new player and score.
b. Print all players and scores.
c. Search for a player's score.
d. Remove a player.
e. Quit.
a

Enter the new player's first name: Jack

Enter the new player's last name: Jones

Enter the new player's score: 78

Jack Jones 78 has been added.

Enter an option:
a. Add new player and score.
b. Print all players and scores.
c. Search for a player's score.
d. Remove a player.
e. Quit.
a

Error: cannot add new player because the number of players would exceed 10

Enter an option:
a. Add new player and score.
b. Print all players and scores.
c. Search for a player's score.
d. Remove a player.
e. Quit.
b

List of players and their scores:
Axel Adams 10
Betty Burgs 20
Cary Chen 44
Deanna Drake 40
Eddie Edholm 10
Fanny Far 50
Gerrie Gertie 11
Henrietta Holmes 55
Ian Illan 100
Jack Jones 78

Enter an option:
a. Add new player and score.
b. Print all players and scores.
c. Search for a player's score.
d. Remove a player.
e. Quit.
d

Which player do you want to remove by last name?
Burgs
Player Betty Burgs 20 has been removed.

Enter an option:
a. Add new player and score.
b. Print all players and scores.
c. Search for a player's score.
d. Remove a player.
e. Quit.
b

List of players and their scores:
Axel Adams 10
Cary Chen 44
Deanna Drake 40
Eddie Edholm 10
Fanny Far 50
Gerrie Gertie 11
Henrietta Holmes 55
Ian Illan 100
Jack Jones 78

Enter an option:
a. Add new player and score.
b. Print all players and scores.
c. Search for a player's score.
d. Remove a player.
e. Quit.
d

Which player do you want to remove by last name?
Illan
Player Ian Illan 100 has been removed.

Enter an option:
a. Add new player and score.
b. Print all players and scores.
c. Search for a player's score.
d. Remove a player.
e. Quit.
b

List of players and their scores:
Axel Adams 10
Cary Chen 44
Deanna Drake 40
Eddie Edholm 10
Fanny Far 50
Gerrie Gertie 11
Henrietta Holmes 55
Jack Jones 78

Enter an option:
a. Add new player and score.
b. Print all players and scores.
c. Search for a player's score.
d. Remove a player.
e. Quit.
c

Which player do you want to search for by last name?
Chen
Player found: Cary Chen 44

Enter an option:
a. Add new player and score.
b. Print all players and scores.
c. Search for a player's score.
d. Remove a player.
e. Quit.
a

Enter the new player's first name: Zennie

Enter the new player's last name: Zhao

Enter the new player's score: 11

Zennie Zhao 11 has been added.

Enter an option:
a. Add new player and score.
b. Print all players and scores.
c. Search for a player's score.
d. Remove a player.
e. Quit.
b

List of players and their scores:
Axel Adams 10
Cary Chen 44
Deanna Drake 40
Eddie Edholm 10
Fanny Far 50
Gerrie Gertie 11
Henrietta Holmes 55
Jack Jones 78
Zennie Zhao 11

Enter an option:
a. Add new player and score.
b. Print all players and scores.
c. Search for a player's score.
d. Remove a player.
e. Quit.
e



---------------------------------END OF RUN 2------------------------------*/