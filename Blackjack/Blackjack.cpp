/******************************************************
* Author:					Silverio Reyes
* Filename:					Blackjack.cpp
* Date Created:				07/26/2016
* Last Modification Date:	08/03/2016
* Lab Number:				CST 136 Lab 7
******************************************************/
#include "Blackjack.h"

/******************************************************
* Function: Blackjack::Blackjack(const vector<string>& names, const vector<int>& bankRolls)
*
*  Purpose:       This is the constructor with 2 args.
*				  It collects the name and bank roll 
*				  of each player in the game. It 
*				  then is used create and shuffle the deck
*				  of cards.
*
*  Precondition:  It must pass two args that are containers
*				  that cannot change location. These
*			      containers should hold the name and money
*				  of each player.
*
*  Postcondition: The players money and name will be stored in memory
******************************************************/
Blackjack::Blackjack(const vector<string>& names, const vector<int>& bankRolls)
{
	// Create a container iterator that is a constant for looping through the players to get names
	vector<string>::const_iterator iterName;		
	for (iterName = names.begin(); iterName != names.end(); ++iterName)	
	{
		m_Players.push_back(Player(*iterName));
	}

	// Create a container iterator that is a constant for looping through the players to get their bank rolls
	vector<int>::const_iterator iterBank;
	for (iterBank = bankRolls.begin(); iterBank != bankRolls.end(); ++iterBank)
	{
		m_BankRolls.push_back(Player(*iterBank));	
	}

	srand ((unsigned)time(0));						// Seed the system time for random generator purposes
	m_deck.CreateDeck();							// Call the method that creates the deck of cards
	m_deck.ShuffleDeck();							// Call the method that shuffles the deck of cards
}

/******************************************************
* Function: Blackjack::~Blackjack()
*
*  Purpose:       This constructor is called when memory
*				  needs to be deallocated
*
*  Precondition:  None.
*
*  Postcondition: Memory that was previously allocated
*				  will be freed.
******************************************************/
Blackjack::~Blackjack()
{
}

/******************************************************
* Function: void Blackjack::PlayGame()
*
*  Purpose:       This is used to play the game. It deals
*				  with dealing cards and displaying cards and
*				  having options for betting, doubling, splitting, and
*				  hitting.
*
*  Precondition:  None.
*
*  Postcondition: Cards will be dealt and displayed and
*				  based on the users option and outcome
*				  of the game, winners, losers, and pushers
*				  will be annonced along with their updated
*				  bank rolls.
******************************************************/
void Blackjack::PlayGame()
{
	vector<Player>::iterator iterPlayer;			// Declare a container of players
	vector<Player>::iterator iterBank;				// Delcare a container of players
	vector <Card*>::const_iterator iterCard;		// Delcare a container of card pointers
	
	for  (unsigned int i = 0; i < 2; i++)			// Only deal 2 cards to each hand at start of game for players!
	{
													// Loop through the container of players
		for (iterPlayer = m_Players.begin(); iterPlayer != m_Players.end(); ++iterPlayer)
		{
			m_deck.Deal(*iterPlayer);				// Deal card to the player
		}
	}

	for (unsigned int i = 0; i < 2; i++)			// Deal 2 cards to the dealer now
	{
		m_deck.DealDealersCards(m_dealer);			// Deal card to the dealer
	}

	m_dealer.FirstCardFlipped();					// Make sure to flip the dealers card down

	// Interate throught the players bankroll and display the players name and bet
	for (unsigned int i = 0; i < m_BankRolls.size(); i++)
	{
		if (!(m_BankRolls[i].isBankDepleted()))
		{
			m_Players[i].GetName();
			m_BankRolls[i].PlaceBet();
		}
	}

	// iterate though the container of players
	for (iterPlayer = m_Players.begin(); iterPlayer != m_Players.end(); ++iterPlayer)
	{
		cout << *iterPlayer << endl;				// Display the players hand
	}
	cout << m_dealer << endl;						// Display the dealers hand
	
	// check to see if the players opening hands are worth 11, 10, or 9 so they have the option to double down
	for (unsigned int i = 0; i <= m_Players.size() - 1; i++)
	{
		if (m_Players[i].GetcardsTotal() == 9 || m_Players[i].GetcardsTotal() == 10 || m_Players[i].GetcardsTotal() == 11)
		{
			if (m_Players[i].isPlayer_doubling())
			{
				m_Players[i].GetBankRoll();
				m_BankRolls[i].DoubleDown();
			}
		}
	}

	// Check to see if the players opening hands are the same so they have the option to split

	// iterate though the container of players so they have the option to hit!
	for (iterPlayer = m_Players.begin(); iterPlayer != m_Players.end(); ++iterPlayer)
	{
		m_deck.AdditionalCards(*iterPlayer);		// Display the players hand
	}
	
	// Interate through all the players to see if they have busted, if they have displays losings
	for (unsigned int i = 0; i <= m_Players.size() - 1; i++)
	{
		if (m_Players[i].isBusted())				// As long as the players have busted 
		{
			m_BankRolls[i].GetLosings();			// Get the players losings
		}
	}

	cout << endl;						
	m_dealer.FirstCardFlipped();					// Reveal the dealers card
	cout << m_dealer << endl;						// Display the dealers hand
	m_deck.AdditionalCards(m_dealer);				// Give another card to dealer

	if (!(m_dealer.isBusted()))						// As long as the dealer has not busted
	{
		cout << "\n" << m_dealer;					// Display the dealers card
	}

	if (m_dealer.isBusted())						// If the dealer has busted then all players win!
	{
													// Iterate through all the players
		for (unsigned int i = 0; i <= m_Players.size() - 1; i++)
		{
			if (!(m_Players[i].isBusted()))				// As long as the players havent busted yet!
			{
				m_Players[i].Winner();					// Display the players that win
				m_BankRolls[i].GetWinnings();			// Display the players winnings
			}
		}
	}
	else
	{
		for (unsigned int i = 0; i <= m_Players.size() - 1; i++)					// Interate through the players
		{
			if (!(m_Players[i].isBusted()))											// Check to see if players have not busted
			{
				if (m_Players[i].GetcardsTotal() > m_dealer.GetcardsTotal())		// If the players cards total are greater than the dealers hand
				{
					m_Players[i].Winner();											// Display the players that win
					m_BankRolls[i].GetWinnings();									// Display the players winnings
				}
				else if (m_Players[i].GetcardsTotal() < m_dealer.GetcardsTotal())	// If the players cards total are less than the dealers hand
				{
					m_Players[i].Lose();											// Display the players that loss
					m_BankRolls[i].GetLosings();									// Display the players losings 
				}
				else
				{
					m_Players[i].Push();											// Display the players that tied (push)
					m_BankRolls[i].GetPushings();									// Display the players bankroll
				}
			}
		}
	}

	// Deallocated the players and the bankrolls (free memory)
	for (unsigned int i = 0; i <= m_Players.size() - 1; i++)
	{
		m_Players[i].Clear();
		m_BankRolls[i].Clear();
	}

	m_dealer.Clear();
}
