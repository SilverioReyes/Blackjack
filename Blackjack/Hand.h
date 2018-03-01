/******************************************************
* Author:					Silverio Reyes
* Filename:					Hand.h
* Date Created:				07/26/2016
* Last Modification Date:	08/03/2016
* Lab Number:				CST 136 Lab 7
******************************************************/
#ifndef HAND_H
#define HAND_H	
#endif // !HAND_H

#include "Card.h"

/******************************************************
* Class: Hand
*
* Purpose: This class is used to model the attributes and
*		   behaviors of a Hand. It has a data member
*		   that is used as a container for the cards
*		   and member functions that can add a card,
*		   get the cards total value, determine if 
*		   an Ace is obtained, and also used to 
*		   deallocated memory from heap.
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
class Hand 
{
public:
	Hand();						// Default constructor
	virtual ~Hand();			// Destructor may be used somewhere else later
	
	void Addcard(Card* card);	// This member function is used to add a card to the players hand
	int GetcardsTotal() const;	// This member function is used to get the total value of the cards
	bool isAce_inHand() const;	// This member function is used to check if players hand has an ACE
	void Clear();				// This member function is used to deallocated memory from heap

protected:
	vector <Card*> m_cards;		// A container of cards
};

