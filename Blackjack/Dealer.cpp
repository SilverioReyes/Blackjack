/******************************************************
* Author:					Silverio Reyes
* Filename:					Dealer.cpp
* Date Created:				07/26/2016
* Last Modification Date:	08/03/2016
* Lab Number:				CST 136 Lab 7
******************************************************/
#include "Dealer.h"

/******************************************************
* Function: Dealer::Dealer(const string& name) : Player(name)
*
*  Purpose:       This constructor takes 1 arg and assigns
*				  its value.
*
*  Precondition:  Must pass a const string by referance
*
*  Postcondition: The value(s) passed will be assigned
*				  to its base member
******************************************************/
Dealer::Dealer(const string& name) : Player(name)
{
}

/******************************************************
* Function: Card::~Card()
*
*  Purpose:       This constructor is called when memory
*				  needs to be deallocated
*
*  Precondition:  None.
*
*  Postcondition: Memory that was previously allocated
*				  will be freed.
******************************************************/
Dealer::~Dealer()
{
	Hand::~Hand();						// This is virutal based so it is invoked
}

/******************************************************
* Function: bool Dealer::Hit() const
*
*  Purpose:       This is to see if the dealer wants
*				  to hit.
*
*  Precondition:  None.
*
*  Postcondition: A boolean expression will be returned
*				  based if the dealer wants to hit or
*				  not.
******************************************************/
bool Dealer::Hit() const
{
	bool hit = false;					// Assume no hit is wanted
	if (GetcardsTotal() <= 16)			// Check if the card value is less than 16, if so hit
	{
		hit = true;						// Set hit to true
	}
	return hit;							// Return bool value
}

/******************************************************
* Function: void Dealer::FirstCardFlipped()
*
*  Purpose:       This is to flip the dealers card
*
*  Precondition:  None.
*
*  Postcondition: The card will be flipped
******************************************************/
void Dealer::FirstCardFlipped()
{
	// If the cards are empty
	if (!m_cards.empty())
	{
		// Flip the first card for dealer
		m_cards[0]->Flip();
	}
}
