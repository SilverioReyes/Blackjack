/******************************************************
* Author:					Silverio Reyes
* Filename:					IBasePlayer.cpp
* Date Created:				07/26/2016
* Last Modification Date:	08/03/2016
* Lab Number:				CST 136 Lab 7
******************************************************/
#include "IBasePlayer.h"

/******************************************************
* Function: IBasePlayer::IBasePlayer(const string & name) : m_name(name)
*
*  Purpose:       This constructor takes 1 arg and assigns
*				  its value.
*
*  Precondition:  Must pass a const string by referance
*
*  Postcondition: The value(s) passed will be assigned
*				  to its base member
******************************************************/
IBasePlayer::IBasePlayer(const string & name) : m_name(name)
{
}

/******************************************************
* Function: IBasePlayer::IBasePlayer(const vector<string>& name)
*
*  Purpose:       This constructor takes 1 arg and assigns
*				  its value.
*
*  Precondition:  Must pass a const string vector by referance
*
*  Postcondition: The value(s) passed will be assigned
*				  to its corresponding data member
******************************************************/
IBasePlayer::IBasePlayer(const vector<string>& name)
{
	this->name = name;
}

/******************************************************
* Function: IBasePlayer::IBasePlayer(const int & bank) : m_bank(bank)
*
*  Purpose:       This constructor takes 1 arg and assigns
*				  its value.
*
*  Precondition:  Must pass a const int by referance
*
*  Postcondition: The value(s) passed will be assigned
*				  to its corresponding data member
******************************************************/
IBasePlayer::IBasePlayer(const int & bank) : m_bank(bank)
{
}

/******************************************************
* Function: IBasePlayer::IBasePlayer(const vector<int>& bankRolls)
*
*  Purpose:       This constructor takes 1 arg and assigns
*				  its value.
*
*  Precondition:  Must pass a const int vector by referance
*
*  Postcondition: The value(s) passed will be assigned
*				  to its corresponding data member
******************************************************/
IBasePlayer::IBasePlayer(const vector<int>& bankRolls)
{
	this->bankRolls = bankRolls;
}

/******************************************************
* Function: IBasePlayer::~IBasePlayer()
*
*  Purpose:       This constructor is called when memory
*				  needs to be deallocated
*
*  Precondition:  None.
*
*  Postcondition: Memory that was previously allocated
*				  will be freed.
******************************************************/
IBasePlayer::~IBasePlayer()
{
}

/******************************************************
* Function: bool IBasePlayer::isBusted() const
*
*  Purpose:       This is used to check if the player 
*				  has busted
*
*  Precondition:  None.
*
*  Postcondition: Based if the member busted or not, 
*				  a boolean expression will be returned
******************************************************/
bool IBasePlayer::isBusted() const
{
	bool playerBust = false;
	if (GetcardsTotal() > 21)
	{
		playerBust = true;
	}
	return playerBust;
}

/******************************************************
* Function: void IBasePlayer::Bust() const
*
*  Purpose:       This is used to display the player
*				  that busted
*
*  Precondition:  None.
*
*  Postcondition: Player that busted will be displayed
******************************************************/
void IBasePlayer::Bust() const
{
	cout << m_name << " Has busted!" << endl;
}

/******************************************************
* Function: bool IBasePlayer::isBankDepleted() const
*
*  Purpose:       This is used to check if the 
*				  Player ran out of money or does
*				  not have the minimum to cover bet.
*
*  Precondition:  None.
*
*  Postcondition: Based on the players bank roll, a
*				  boolean expression will be returned
******************************************************/
bool IBasePlayer::isBankDepleted() const
{
	bool bankDepleted = false;
	if (m_bank == 0 || m_bank < 5)
	{
		bankDepleted = true;
	}
	return bankDepleted;
}

