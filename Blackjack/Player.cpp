/******************************************************
* Author:					Silverio Reyes
* Filename:					IBasePlayer.cpp
* Date Created:				07/26/2016
* Last Modification Date:	08/03/2016
* Lab Number:				CST 136 Lab 7
******************************************************/
#include "Player.h"

/******************************************************
* Function: Player::Player()
*
*  Purpose:       This is the default constructor
*
*  Precondition:  None
*
*  Postcondition: Initilizes bet to 0
******************************************************/
Player::Player()
{
	bet = 0;
}

/******************************************************
* Function: Player::Player(const string & name) : IBasePlayer(name)
*
*  Purpose:       This constructor takes 1 arg and assigns
*				  its value.
*
*  Precondition:  Must pass a const string by referance
*
*  Postcondition: The value(s) passed will be assigned
*				  to its base member
******************************************************/
Player::Player(const string & name) : IBasePlayer(name)
{
}

/******************************************************
* Function: Player::Player(const int & bank) : IBasePlayer(bank)
*
*  Purpose:       This constructor takes 1 arg and assigns
*				  its value.
*
*  Precondition:  Must pass a const string by referance
*
*  Postcondition: The value(s) passed will be assigned
*				  to its base member
******************************************************/
Player::Player(const int & bank) : IBasePlayer(bank)
{
}

/******************************************************
* Function: Player::~Player()
*
*  Purpose:       This constructor is called when memory
*				  needs to be deallocated
*
*  Precondition:  None.
*
*  Postcondition: Memory that was previously allocated
*				  will be freed.
******************************************************/
Player::~Player()
{
	// Call the virtual destructor and assigne name to nothing
	Hand::~Hand();			
	m_name = "\0";
}

/******************************************************
* Function: bool Player::isPlayer_hitting() const
*
*  Purpose:       This is used to check if the player is 
*				  going to hit.
*
*  Precondition:  None.
*
*  Postcondition: Based on if the player is going to 
*				  hit or not, a boolean expression
*				  will be returned.
******************************************************/
bool Player::isPlayer_hitting() const
{
	bool giveHit = false;												// Assume no hit is needed
	char answer = '\0';													// Set answer to nothing
	cout << "\n" << m_name << ", Do you want to hit? (Y/N): ";			// Display message to user
	cin >> answer;														// Get answer
	avoidInputStreamFailedState();
	
	if (answer == 'Y' || answer == 'y')									// Check if yes or no
	{
		giveHit = true;													// Set varibale to true
	}

	return giveHit;														// Return boolean expression
}

/******************************************************
* Function: bool Player::isPlayer_doubling() const
*
*  Purpose:       This is used to check if the player is
*				  going to double.
*
*  Precondition:  None.
*
*  Postcondition: Based on if the player is going to
*				  double or not, a boolean expression
*				  will be returned.
******************************************************/
bool Player::isPlayer_doubling() const
{
	bool giveDouble = false;											// Assume no double is needed
	char answer = '\0';													// Set answer to nothing
	cout << m_name << ", Do you want to double down? (Y/N) ";			// Display message to user
	cin >> answer;														// Get answer
	avoidInputStreamFailedState();
	
	if (answer == 'Y' || answer == 'y')									// Check if yes or no
	{
		giveDouble = true;												// If yes, set variable to true
	}

	return giveDouble;													// Return boolean expression
}

/******************************************************
* Function: void Player::Winner() 
*
*  Purpose:       This is used to display winner.
*
*  Precondition:  None.
*
*  Postcondition: Winner is displayed.
******************************************************/
void Player::Winner() 
{
	cout << endl;
	cout << m_name << " Wins" << endl;
}

/******************************************************
* Function: void Player::Lose() const
*
*  Purpose:       This is used to display loser.
*
*  Precondition:  None.
*
*  Postcondition: Loser is displayed.
******************************************************/
void Player::Lose() const
{
	cout << endl;
	cout << m_name << " Loses" << endl;
}

/******************************************************
* Function: void Player::Push() const
*
*  Purpose:       This is used to display Tie (Push)
*
*  Precondition:  None.
*
*  Postcondition: Pusher is displayed.
******************************************************/
void Player::Push() const
{
	cout << endl;
	cout << m_name << " Pushes" << endl;
}

/******************************************************
* Function: void Player::PlaceBet() 
*
*  Purpose:       This is used for players to place bet
*
*  Precondition:  None.
*
*  Postcondition: Bet is set to its corresponding data 
*				  member
******************************************************/
void Player::PlaceBet() 
{
	int bet = 0;														// Set starting bet to 0
	GetName();															// Get the players name
	cout << ", " << "Please place your bet ($5 Mininum): ";			    // Display message to player
	cin >> bet;															// Get the bet
	avoidInputStreamFailedState();										// Check input stream

	while (bet < 5 || bet > m_bank)										// While bet is not less than minimum bet and bet is greater than players bank
	{
		cout << "\nPlease place a bet between 5 and " << m_bank << ": ";
		cin >> bet;
		avoidInputStreamFailedState();
	}
	this->bet = bet;													// Set bet to data member
	m_bank -= this->bet;												// Update the players bank (withdrawel occured)
}

/******************************************************
* Function: void Player::DoubleDown()
*
*  Purpose:       This is used to calculate the double
*				  down amount for bet.
*
*  Precondition:  None.
*
*  Postcondition: The players previous bet has now
*				  been doubled
******************************************************/
void Player::DoubleDown()
{
	m_bank = GetBankRoll();
	if (m_bank >= bet)
	{
		m_bank -= bet;
		bet = 2 * bet;
		cout << "Your bet is now worth: " << bet;
	}
	else
	{
		cout << "Sorry, you dont have enough to double down. Your bet is still worth: " << bet;
	}

}

/******************************************************
* Function: void Player::GetName() const
*
*  Purpose:       This is used to get the players name
*
*  Precondition:  None.
*
*  Postcondition: The players name will be returned
******************************************************/
void Player::GetName() const
{
	cout << m_name;
}

/******************************************************
* Function: void Player::GetWinnings()
*
*  Purpose:       This is used to get the players winnings
*
*  Precondition:  None.
*
*  Postcondition: The players winnings will be returned
******************************************************/
void Player::GetWinnings()
{	
	m_bank += 2 * bet;						
	cout << "Bank roll is now: " << m_bank;
}

/******************************************************
* Function: void Player::GetLosings() const
*
*  Purpose:       This is used to get the players losings
*
*  Precondition:  None.
*
*  Postcondition: The players losings will be returned
******************************************************/
void Player::GetLosings() const
{
	cout << "Bank roll is now: " << m_bank;
}

/******************************************************
* Function: void Player::GetPushings()
*
*  Purpose:       This is used to get the players Pushings
*
*  Precondition:  None.
*
*  Postcondition: The players pushings will be returned
******************************************************/
void Player::GetPushings()
{
	m_bank += bet;
	cout << "Bank roll is now: " << m_bank;
}

int Player::GetBankRoll()
{
	return m_bank;
}

void Player::avoidInputStreamFailedState() const
{
	cin.clear();
	cin.ignore(100, '\n');
}