/******************************************************
* Author:					Silverio Reyes
* Filename:					Card.h
* Date Created:				07/26/2016
* Last Modification Date:	08/03/2016
* Lab Number:				CST 136 Lab 7
******************************************************/
#ifndef CARD_H
#define CARD_H	
#endif // !CARD_H

// Preprocessor directives
#include <iostream>
#include <time.h>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using std::cin;							// Individual statement for input
using std::cout;						// Individual statement for output
using std::endl;						// Individual statement for newline and flush
using std::rand;						// Individual statement for random generator
using std::srand;						// Individual statement to seed system time
using std::swap;						// Indivdiual statement to swap object contents
using std::ostream;						// Individual statement for output stream
using std::string;						// Individual statement for string of characters
using std::vector;						// Individual statement for STL container

/******************************************************
* Class: Card
*
* Purpose: This class is to model the attributes and 
*		   behaviors of a playing card. Its purposes
*		   is to define the characteristic of a card.
*
* Manager functions:
*	Card()
*	Card(bool isUp, rank r, suit s)
*	~Card()
*
* Methods:
*	void Flip()
*	int GetcardValue() const
********************************************************/
class Card
{
public:
	enum rank { ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK = 10, QUEEN = 10, KING = 10 };	// This is to determine ranking
	enum suit { DIAMONDS, HEARTS, CLUBS, SPADES };																	// This is to determine suit
	
	Card();								// Default Constructor
	Card(bool isUp, rank r, suit s);	// Constructor with 3 args
	~Card();							// Destructor

	void Flip();						// This member function will be used to flip the card
	int GetcardValue() const;			// This member function will be used to get the value of the card
	friend ostream& operator<<(ostream& os, const Card& aCard);	// This will be used to overload the stream insertion operator 

private:
	rank m_Rank;						// This will be used to hold the cards rank
	suit m_Suit;						// This will be used to hold the cards suit (Diamonds and hearts are both red and clubs and spades are both black)
	bool m_isCardFaceUP;				// This will be used to flip the cards
};

