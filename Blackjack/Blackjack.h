/******************************************************
* Author:					Silverio Reyes
* Filename:					Blackjack.h
* Date Created:				07/26/2016
* Last Modification Date:	08/03/2016
* Lab Number:				CST 136 Lab 7
******************************************************/

#ifndef BLACKJACK_H
#define BLACKJACK_H
#endif // !BLACKJACK_H
#include "Deck.h"
#include "Dealer.h"

/******************************************************
* Class: Blackjack : public Deck, public Dealer
*
* Purpose: This class inherits the attributes and behaviors
*		   of the classes Deck and Dealer. This class creates
*		   data members that represent the dealer and deck, and
*		   containers that hold the players and players bank roll.
*		   There will be manager functions that will be used
*		   for the incomming players for the Blackjack game and
*		   a member function to play the game.
*
* Manager functions:
*	Blackjack(const vector<string>& names ,const vector<int>& bankRolls);
*	~Blackjack();
*
* Methods:
*	void PlayGame();
********************************************************/
class Blackjack : public Deck, public Dealer
{
public:																		// Access control
	Blackjack(const vector<string>& names ,const vector<int>& bankRolls);	// This constructors has 2 args taht are STL containers for player names and their bankroll
	~Blackjack();															// Destructor
	void PlayGame();														// Member function used to play the game

private:																	// Access control
	Deck m_deck;															// This will be used to model the attributes and behaviors for the deck										
	Dealer m_dealer;														// This will be used to model the attributes and behaviors for the dealer
	vector<Player> m_Players;												// This will be used to hold a number of players
	vector<Player> m_BankRolls;												// This will be used to hold the players bank roll
};

