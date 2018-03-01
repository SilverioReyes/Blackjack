/******************************************************
* Author:					Silverio Reyes
* Filename:					Deck.h
* Date Created:				07/26/2016
* Last Modification Date:	08/03/2016
* Lab Number:				CST 136 Lab 7
******************************************************/
#ifndef DECK_H
#define DECK_H
#endif // !DECK_H

#include "Player.h"

/******************************************************
* Class: Deck : public Hand
*
* Purpose: This class is to model the attributes and
*		   behaviors of a Deck. It derives from
*		   the class hand and adds additional features
*		   that makes it differnt than a hand.
*		   Deck has more capabilities such as
*		   creating and shuffling deck, and dealing
*		   and adding cards.
*
* Manager functions:
*	Dealer(const string& name = "Dealer")
*	virtual ~Dealer()
*
* Methods:
*	virtual bool Hit() const
*	void FirstCardFlipped()
********************************************************/
class Deck : public Hand
{
public:
	Deck();							// Default constructor
	virtual ~Deck();				// Destructor 

	void CreateDeck();				// This method will be used to create a deck of 52 cards
	void ShuffleDeck();				// This method will be used to shuffle a deck of 52 cards
	void Deal(Hand& oneHand);		// This method will be used to deal the cards to player and house
	void AdditionalCards(IBasePlayer& oneBasePlayer);	// This method will be used to add a card to a players hand if they hit
	void DealDealersCards(IBasePlayer & oneBasePlayer);	// This method will be used for the dealer to keep track of cards dealt
};

