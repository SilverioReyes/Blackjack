/******************************************************
* Author:					Silverio Reyes
* Filename:					Blackjack.cpp
* Date Created:				07/26/2016
* Last Modification Date:	08/03/2016
* Lab Number:				CST 136 Lab 7
******************************************************/

/******************************************************
* Author:					Silverio Reyes
* Date Created:				07/26/2016
* Last Modification Date:	08/03/2016
* Lab Number:				CST 136 Lab 7
* Filename:					main.cpp
*
*      Overview: This program is used to simulate the 
*				 BlackJack game commonly know as "21"
*
* 	  	  Input: Lab 7 program consist of user input for player name,
*				 Money to deposit in for their bank roll, placing bets
*				 and selecting y or n for options such as hitting, doubling
*				 and splitting.
*
* 	 	 Output: The output will display messages to get the amount of 
*				 players, players names, players bank roll, and players bets.
*				 The output will then display the players hand along with the 
*				 dealers hand. Each player will have the option to hit and
*				 when the first hand is dealt depending on the rules of the house,
*				 players will have an option to double and split.
*
* Console output sample:
--------------------------------------------------------------------------------
--------------------------------------------------------------------------------
--------------------------------------------------------------------------------

Welcome to the game of BlackJack.
Players, note that the lower case letters h,d,c, and s signify the following:

h = hearts
d = diamonds
c = clubs
s = spades

Press enter to continue and good luck...

--------------------------------------------------------------------------------

How many players will be playing (max 4)? 2
Please enter the following players names:
Player 1: Silver
Player 2: Heather

Please enter the following players bank roll:
Player 1: 500
Player 2: 250

Silver, Please place your bet ($5.00 Mininum): 250
Heather, Please place your bet ($5.00 Mininum): 175
Silver: 5h      7d      (12)
Heather: 6s     3h      (9)
Dealer: XX      3d
Heather, Do you want to double down? (Y/N) y
Sorry, you dont have enough to double down. Your bet is still worth: 175
Silver, Do you want to hit? (Y/N): y
Silver: 5h      7d      4h      (16)

Silver, Do you want to hit? (Y/N): n

Heather, Do you want to hit? (Y/N): y
Heather: 6s     3h      3c      (12)

Heather, Do you want to hit? (Y/N): y
Heather: 6s     3h      3c      5s      (17)

Heather, Do you want to hit? (Y/N): n

Dealer: 7s      3d      (10)

Dealer, Do you want to hit? (Y/N): y
Dealer: 7s      3d      2d      (12)

Dealer, Do you want to hit? (Y/N): y
Dealer: 7s      3d      2d      5d      (17)

Dealer, Do you want to hit? (Y/N): n

Dealer: 7s      3d      2d      5d      (17)
Silver Loses
Bank roll is now: 250
Heather Pushes
Bank roll is now: 250
Do you want to play again? (Y/N): n
Press any key to continue . . .

*****************************************************/
#include <iostream>
#include "Blackjack.h"

// Prototypes
void displayMessage();
ostream& operator<<(ostream& os, const Card& aCard);					// This will be used to set the card attributes
ostream& operator<<(ostream& os, const IBasePlayer& BasePlayer);		// This will be used to display the players hand totals along with card attributes
void avoidInputStreamFailedState();										// This will be used to handle stream input error

int main()
{
	int players = 0;													// Declare variable to hold the amount of players
	vector <string> names;												// Declare a container of type string that holds the names of players
	vector <int> bankrolls;												// Declare a container of type int that holds the bankrolls of each player
	string name;														// Declare variable to hold the name of the player
	int bank;															// Declare varaible to hold the money of each player

	displayMessage();
	cout << "How many players will be playing (max 4)? ";				// Display message to user on how many players are going to play
	cin >> players;														// Get the amount 
	avoidInputStreamFailedState();										// Check stream
		
	// You can do exception handling here (try catch)
	while (players <= 0 || players > 4)
	{
		cout << "Please enter a number between 0 and 5: ";
		cin >> players;
		avoidInputStreamFailedState();
	}

	// Get names of players
	cout << "Please enter the following players names: " << endl;
	for (int i = 0; i < players; ++i)
	{
		cout << "Player " << i + 1 << ": ";	
		cin >> name;
		names.push_back(name);
	}
	cout << endl;

	// Get bankroll from players
	cout << "Please enter the following players bank roll: " << endl;
	for (int i = 0; i < players; ++i)
	{
		cout << "Player " << i + 1 << ": ";
		cin >> bank;
		avoidInputStreamFailedState();

		// You can do exception handling here (try catch)
		while (bank < 5)
		{
			cout << "Please enter a bank roll of 5 or more: ";
			cin >> bank;
			avoidInputStreamFailedState();
		}

		// store the money in the players bankroll
		bankrolls.push_back(bank);
	}
	cout << endl;

	// Start the BlackJack Game
	Blackjack blackJack(names,bankrolls);

	// check if the user wants to play the game again
	char again = 'y';
	while (again != 'n' && again != 'N')
	{
		blackJack.PlayGame();
		cout << "\nDo you want to play again? (Y/N): ";
		cin >> again;
		avoidInputStreamFailedState();
	}
	return 0;
}

void displayMessage()
{
	// Display message to user that data on file has been read
	cout << "--------------------------------------------------------------------------------\n";
	cout << "\t\t\tWelcome to the game of BlackJack.\n";
	cout << "Players, note that the lower case letters h,d,c, and s signify the following:\n";
	cout << "\n\t\t\t\th = hearts\n";
	cout << "\t\t\t\td = diamonds\n";
	cout << "\t\t\t\tc = clubs\n";
	cout << "\t\t\t\ts = spades\n";
	cout << "\n\t\t    Press enter to continue and good luck...\n";
	cout << "\n--------------------------------------------------------------------------------\n";
}

/******************************************************
* Function: ostream& operator<<(ostream& os, const Card& aCard)
*
*  Purpose:       This is used so that the cards attributes
*				  are displayed when they are dealt
*
*  Precondition:  Must pass an ostream by reference and
*				  a const object of type Card by reference 
*
*  Postcondition: The value(s) passed will be used 
*				  to for the cards attributes
******************************************************/
ostream& operator<<(ostream& os, const Card& aCard)
{
	const string RANKS[] = { "0", "A", "2", "3", "4", "5", "6", "7", "8", "9",
		"10", "J", "Q", "K" };

	const string SUITS[] = { "d", "h", "c", "s" };

	if (aCard.m_isCardFaceUP)
		os << RANKS[aCard.m_Rank] << SUITS[aCard.m_Suit];
	else
		os << "XX";

	return os;
}

/******************************************************
* Function: ostream& operator <<(ostream& os, const IBasePlayer& BasePlayer)
*
*  Purpose:       This is used so that a generic player
*				  can be displayed using the stream
*				  insertion operator.
*
*  Precondition:  Must pass an ostream by reference and
*				  a const object of type IBasePlayer by reference
*
*  Postcondition: The Players card information will be displayed
******************************************************/
ostream& operator <<(ostream& os, const IBasePlayer& BasePlayer)
{
	os << BasePlayer.m_name << ": ";

	vector <Card*>::const_iterator iterCard;
	if (!BasePlayer.m_cards.empty())
	{
		for (iterCard= BasePlayer.m_cards.begin(); iterCard != BasePlayer.m_cards.end(); ++iterCard)
			os << *(*iterCard) << "\t";

		if (BasePlayer.GetcardsTotal() != 0)
			cout << "(" << BasePlayer.GetcardsTotal() << ")";

	}
	else
		os << "<empty>";

	return os;
}
void avoidInputStreamFailedState()
{
	cin.clear();
	cin.ignore(100, '\n');
}