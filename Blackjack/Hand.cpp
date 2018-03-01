/******************************************************
* Author:					Silverio Reyes
* Filename:					Hand.cpp
* Date Created:				07/26/2016
* Last Modification Date:	08/03/2016
* Lab Number:				CST 136 Lab 7
******************************************************/
#include "Hand.h"

/******************************************************
* Function: Hand::Hand()
*
*  Purpose:       This is the default constructor
*
*  Precondition:  None.
*
*  Postcondition: A predetermind number of cards are 
*				  reserved for each hand
******************************************************/
Hand::Hand()
{
	// Allocate a predetermined number of cards
	m_cards.reserve(8);
}

/******************************************************
* Function: Hand::~Hand()
*
*  Purpose:       This constructor is called when memory
*				  needs to be deallocated
*
*  Precondition:  None.
*
*  Postcondition: Memory that was previously allocated
*				  will be freed.
******************************************************/
Hand::~Hand()
{
	// Start with a fresh set of hands
	Clear();
}

/******************************************************
* Function: void Hand::Addcard(Card * card)
*
*  Purpose:       This is used to add a card to hand
*
*  Precondition:  Must pass and object of type Card by
*				  pointer.
*
*  Postcondition: A card of type card is added to players
*				  hand
******************************************************/
void Hand::Addcard(Card * card)
{
	m_cards.push_back(card);			// Add a card of type card to the players hand. 
}

/******************************************************
* Function: int Hand::GetcardsTotal() const
*
*  Purpose:       This is used to get the total value
*				  of the cards in each hand.
*
*  Precondition:  None.
*
*  Postcondition: The value of the cards in each hand
*				  is returned.
******************************************************/
int Hand::GetcardsTotal() const
{
	int totalValue = 0;					// This will be used to get the total value of cards

	if (m_cards.empty())				// Check if hand has cards
	{
		return totalValue;
	}

	if (m_cards[0]->GetcardValue() == 0)// Check if hand has first card face down
	{
		return totalValue;
	}

	// Add up card values, by default ACE is treated as value of 1
	vector<Card*>::const_iterator it;	// This is used to protect the items in card
	for (it = m_cards.begin(); it != m_cards.end(); ++it)
	{
		totalValue += (*it)->GetcardValue();
	}

	// Give player best score based on the fact that they have an ACE on hand
	if (isAce_inHand() && totalValue <= Card::KING + 1)
	{
		totalValue += Card::KING;
	}

	return totalValue;					// Return the value of the cards in hand
}

/******************************************************
* Function: bool Hand::isAce_inHand() const
*
*  Purpose:       This is used to check if an Ace
*				  is contained within a hand.
*
*  Precondition:  None.
*
*  Postcondition: A boolean expression will be returned
*				  based if the hand contains an ace
*				  or not.
******************************************************/
bool Hand::isAce_inHand() const
{
	bool aceInhand = false;				// Set default to false
	// Interate through the cards to see if there is an ACE
	for (unsigned int i = 0; i <= m_cards.size() - 1; i++)
	{
		if (m_cards[i]->GetcardValue() == Card::ACE)
		{
			aceInhand = true;			// If hand has an ace set to true
		}
	}
	return aceInhand;					// Return the boolean expression
}

/******************************************************
* Function: void Hand::Clear()
*
*  Purpose:       This is used to free memory up from
*				  heap.
*
*  Precondition:  None.
*
*  Postcondition: Memory will be freed
******************************************************/
void Hand::Clear()
{
	//iterate through vector, freeing all memory on the heap
	vector <Card*>::iterator iter = m_cards.begin();
	for (iter = m_cards.begin(); iter != m_cards.end(); ++iter)
	{
		delete *iter;
		*iter = 0; //get rid of dangling pointer - null pointer
	}

	//clear vector of pointers
	m_cards.clear();
}
