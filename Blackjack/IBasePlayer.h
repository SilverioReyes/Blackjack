/******************************************************
* Author:					Silverio Reyes
* Filename:					IBasePlayer.h
* Date Created:				07/26/2016
* Last Modification Date:	08/03/2016
* Lab Number:				CST 136 Lab 7
******************************************************/
#ifndef IBASEPLAYER_H
#define IBASEPLAYER_H	

#include "Hand.h"

/******************************************************
* Class: IBasePlayer : public Hand
*
* Purpose: This class is an abstract base class containing
*		   two pure virtual functions that will need 
*		   to be implemented within the classes that derive 
*		   it. This class extends the capabilites of the 
*		   class hand and is used so that other 
*		   classes can use it as a base class. 

* Manager functions:
*	IBasePlayer(const string& name = " ")
*	IBasePlayer(const int& bank)
*	IBasePlayer(const vector<string>& name)
*	IBasePlayer(const vector<int>& bankRolls)
*	~IBasePlayer()
*
* Methods:
*	virtual bool isPlayer_hitting() const = 0
*	virtual bool isPlayer_doubling() const = 0
*	bool isBusted() const
*	void Bust() const
*	bool isBankDepleted() const
*	friend ostream& operator<<(ostream& os, const IBasePlayer& BasePlayer)
********************************************************/
class IBasePlayer : public Hand
{
public:												
	IBasePlayer(const string& name = " ");			// Constructor with 1 arg of type string to hold names of players
	IBasePlayer(const int& bank);					// Constructor with 1 arg of type int to hold the players money
	IBasePlayer(const vector<string>& name);		// Constructor with 1 arg of type string container to hold all of the players name
	IBasePlayer(const vector<int>& bankRolls);		// Constructor wiht 1 arg of type int container to hold all of the players money
	~IBasePlayer();									// Destructor

	virtual bool isPlayer_hitting() const = 0;		// This is a pure virtual function. It will need to be implemented within derive classes
	virtual bool isPlayer_doubling() const = 0;		// This is a pure virtual function. It will need to be implemented within derive classes
	bool isBusted() const;							// This method will be used to check if the player has a hand that is over 21
	void Bust() const;								// This method will be used to annonce the player that has busted
	bool isBankDepleted() const;					// This method will be used to check if the player has ran out of money
	friend ostream& operator<<(ostream& os, const IBasePlayer& BasePlayer);	// Overloading the insertion operator 

protected:
	string m_name;									// This will be used to store the players name
	int m_bank;										// This will be used to store the players money
	bool m_IsplayerBust;							// This will be used to check if the player has busted
	vector <string> name;							// This will be used to store all of the players name in a container
	vector <int> bankRolls;							// This will be used to store all of the players money in a container
};

#endif	// !BASEPLAYER_H