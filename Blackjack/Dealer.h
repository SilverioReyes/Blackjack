/******************************************************
* Author:					Silverio Reyes
* Filename:					Dealer.h
* Date Created:				07/26/2016
* Last Modification Date:	08/03/2016
* Lab Number:				CST 136 Lab 7
******************************************************/
#ifndef DEALER_H
#define DEALER_H
#endif // !DEALER_H

#include "Player.h"

/******************************************************
* Class: Dealer : public Player
*
* Purpose: This class is to model the attributes and
*		   behaviors of a Dealer. It derives from
*		   the class player and adds additional features
*		   that makes it differnt than a regular player.
*		   (Dealer has more capabilities) 
*
* Manager functions:
*	Dealer(const string& name = "Dealer")
*	virtual ~Dealer()
*
* Methods:
*	virtual bool Hit() const
*	void FirstCardFlipped()
********************************************************/
class Dealer : public Player
{
public:
	Dealer(const string& name = "Dealer");		// This constructor sets the name of house dealer
	virtual ~Dealer();							// Destructor

	virtual bool Hit() const;					// This method is used so the dealer has the option to hit
	void FirstCardFlipped();					// This method is used so the dealer first card is flipped down
};

