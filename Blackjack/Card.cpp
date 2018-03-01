/******************************************************
* Author:					Silverio Reyes
* Filename:					Card.cpp
* Date Created:				07/26/2016
* Last Modification Date:	08/03/2016
* Lab Number:				CST 136 Lab 7
******************************************************/
#include "Card.h"

/******************************************************
* Function: Card::Card() : m_isCardFaceUP(false), m_Rank(Card::ACE), m_Suit(Card::DIAMONDS)
*
*  Purpose:       This is the default constructor.
*
*  Precondition:  None
*
*  Postcondition: Preset values are set for the 
*				  card face value, rank and suit.
******************************************************/
Card::Card() : m_isCardFaceUP(false), m_Rank(Card::ACE), m_Suit(Card::DIAMONDS)
{
	//cout << "Inside card ctor" << endl;
}

/******************************************************
* Function: Card::Card() : m_isCardFaceUP(false), m_Rank(Card::ACE), m_Suit(Card::DIAMONDS)
*
*  Purpose:       This a constructor with 3 arguments.
*
*  Precondition:  Must pass 3 arguments of type 
*				  bool, rank, and suit.
*
*  Postcondition: Values for if the card is faced up,
*				  rank and suit are initialized
******************************************************/
Card::Card(bool isUp, rank r, suit s) : m_isCardFaceUP(isUp), m_Rank(r), m_Suit(s)
{
	//cout << "Inside card 3 arg ctor" << endl;
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
Card::~Card()
{
	//cout << "Inside card dtor" << endl;
}

/******************************************************
* Function: void Card::Flip()
*
*  Purpose:       This is used to flip the dealers card
*
*  Precondition:  None
*
*  Postcondition: Card is flipped
******************************************************/
void Card::Flip()
{ 
	m_isCardFaceUP = !m_isCardFaceUP;	// Flip the card 
}

/******************************************************
* Function: int Card::GetcardValue() const
*
*  Purpose:       This is used to get the card value
*
*  Precondition:  None
*
*  Postcondition: The card value is returned
******************************************************/
int Card::GetcardValue() const
{
	int cardValue = 0;					// If the card is face down its value is 0

	if (m_isCardFaceUP)					// Check if the card is face up
	{
		cardValue = m_Rank;				// Assign the card value
	}
	return cardValue;					// Return the card value
}
