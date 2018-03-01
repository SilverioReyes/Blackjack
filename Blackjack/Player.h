/******************************************************
* Author:					Silverio Reyes
* Filename:					Player.h
* Date Created:				07/26/2016
* Last Modification Date:	08/03/2016
* Lab Number:				CST 136 Lab 7
******************************************************/
#ifndef PLAYER_H
#define PLAYER_H

#include "IBasePlayer.h"

/******************************************************
* Class: Player : public IBasePlayer
*
* Purpose: This class is used to model the attributes and
*		   behaviors of a Player. It has a data member
*		   that is used to hold the players bet and 
*		   inherits the attributes and behaviors from
*		   the abstract base class IBasePlayer. It
*		   Implements the pure virtual functions 
*		   for players hitting or doubling.
*		   There will be methods that will determine
*		   if the player(s) have won, lost, pushed, placed
*		   bet, doubled down, and how much money
*		   is in their bank.
*
* Manager functions:
*	Hand()
*	virtual ~Hand()
*
* Methods:
*	void Addcard(Card* card)
*	int GetcardsTotal() const
*	bool isAce_inHand() const
*	void Clear()
********************************************************/
class Player : public IBasePlayer
{
public:
	Player();								// Default constructor -Currently no defininiton
	Player(const string& name = "");		// Constructor with 1 arg which will inherit base class
	Player(const int& bank);				// Constructor with 1 arg that passes the arg by reference
	Player(const vector<string>& names) {};	// Constructor with 1 arg of type string container to hold the players name
	Player(const vector<int>& bankRolls) {};// Constructor with 1 arg of type int container to hold the players money
	virtual ~Player();						// Destructor
	
	virtual bool isPlayer_hitting() const;	// This signature matches the virtual method inherited from IBasePlayer used for if player wants to hit
	virtual bool isPlayer_doubling() const;	// This signature matches the virtual method inherited from IBasePlayer used for if player wants to hit
	void Winner();							// This will be used to display winner
	void Lose() const;						// This will be used to display loser
	void Push() const;						// This will be used to display pusher
	void PlaceBet();						// This will be used to for the player to place bet
	void DoubleDown();						// This will be used if player wants to double down on opening hand
	void GetName() const;					// This will be used to get the players name
	void GetWinnings();						// This will be used to get the players new bank roll
	void GetLosings() const;				// This will be used to get the players new bank roll
	void GetPushings();						// This will be used to get the players new bank roll
	int GetBankRoll();						// This will be used to get the players bank roll
	void avoidInputStreamFailedState() const;	// This will be used to handle input stream

private:
	int bet;								// This will be used to hold the players bet (must be kept tracked of for double down purposes)
};
#endif // !PLAYER_H
