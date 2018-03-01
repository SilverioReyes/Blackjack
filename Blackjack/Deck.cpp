/******************************************************
* Author:					Silverio Reyes
* Filename:					Deck.cpp
* Date Created:				07/26/2016
* Last Modification Date:	08/03/2016
* Lab Number:				CST 136 Lab 7
******************************************************/
#include "Deck.h"

/******************************************************
* Function: Deck::Deck()
*
*  Purpose:       This is the default constructor
*
*  Precondition:  None.
*
*  Postcondition: The deck is initilized with a predetermined
*				  number and if that capacity runs out
*				  a new deck is created.
******************************************************/
Deck::Deck()
{
	m_cards.reserve(52);	// This request a change in capacity ( A deck of 52 cards)
	CreateDeck();			// Call the method that creates the deck of cards
}

/******************************************************
* Function: Deck::~Deck()
*
*  Purpose:       This constructor is called when memory
*				  needs to be deallocated
*
*  Precondition:  None.
*
*  Postcondition: Memory that was previously allocated
*				  will be freed.
******************************************************/
Deck::~Deck()
{
}

/******************************************************
* Function: void Deck::CreateDeck()
*
*  Purpose:       This is used to create a fresh deck
*				  of cards.
*
*  Precondition:  None.
*
*  Postcondition: A new deck of cards will be created
******************************************************/
void Deck::CreateDeck()
{
	// Start with a fresh deck of cards
	Clear();

	// Interate through the cards suits (outer loop)
	for (unsigned int suit = Card::DIAMONDS; suit <= Card::SPADES; ++suit)
	{
		// Inner loop will the rank values
		for (unsigned int rank = Card::ACE; rank <= Card::KING; ++rank)
		{
			// Call the hand member function that adds a card
			Addcard(new Card(true, static_cast <Card::rank>(rank), static_cast <Card::suit>(suit)));
		}
	}
}

/******************************************************
* Function: void Deck::ShuffleDeck()
*
*  Purpose:       This is used to shuffle the deck of 
*				  cards.
*
*  Precondition:  None.
*
*  Postcondition: The deck of cards will be shuffled
******************************************************/
void Deck::ShuffleDeck()
{
	// Random Generator function
	int randomNum = (rand() % 9) + 1;								// Value between 1 and 10
	srand(unsigned(std::time(0)));									// Seed time
	std::random_shuffle(m_cards.begin(), m_cards.end());			// Random shuffle invoked

	//for  (unsigned int i = 0; i < m_cards.size() - 1; i++)
	//{
	//	int random = i + rand() % (m_cards.size() - i);
	//	swap(m_cards[i], m_cards[random]);
	//}
}

/******************************************************
* Function: void Deck::Deal(Hand & oneHand)
*
*  Purpose:       This is used to deal the cards
*
*  Precondition:  Must pass an object of type hand by 
*				  reference
*
*  Postcondition: As long as the deck is not empty
*				  cards will be dealt. As we 
*				  add a card to a persons hand,
*				  we pop it off. If the deck is
*				  empty, a new deck is created.
******************************************************/
void Deck::Deal(Hand & oneHand)
{
	if (!m_cards.empty())
	{
		oneHand.Addcard(m_cards.back());
		m_cards.pop_back();
	}
	else
	{
		cout << "New Deck created" << endl;
		CreateDeck();
	}
}

/******************************************************
* Function: void Deck::DealDealersCards(IBasePlayer & oneBasePlayer)
*
*  Purpose:       This is used to deal the dealers card
*
*  Precondition:  Must pass an object of type IBasePlayer by
*				  reference
*
*  Postcondition: As long as the deck is not empty
*				  cards will be dealt. As we
*				  add a card to a persons hand,
*				  we pop it off. If the deck is
*				  empty, a new deck is created.
******************************************************/
void Deck::DealDealersCards(IBasePlayer & oneBasePlayer)
{
	if (!m_cards.empty())
	{
		oneBasePlayer.Addcard(m_cards.back());
		m_cards.pop_back();
	}
	else
	{
		cout << "New Deck created" << endl;
		CreateDeck();
	}
}

/******************************************************
* Function: void Deck::AdditionalCards(IBasePlayer & oneBasePlayer)
*
*  Purpose:       This is used to add addtional cards to a hand
*
*  Precondition:  Must pass an object of type IBasePlayer by
*				  reference
*
*  Postcondition: While the player has not busted and
*				  they choose to hit, a card will
*				  be added to their pile and their
*				  hand will be displayed. 
******************************************************/
void Deck::AdditionalCards(IBasePlayer & oneBasePlayer)
{
	while (!oneBasePlayer.isBusted() && oneBasePlayer.isPlayer_hitting())
	{
		Deal(oneBasePlayer);
		cout << oneBasePlayer << endl;	
	}

	if (oneBasePlayer.isBusted())
	{
		oneBasePlayer.Bust();
	}
}

