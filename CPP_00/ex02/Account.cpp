#include "Account.hpp"
#include <iostream>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void )
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (Account::_totalNbWithdrawals);
}

static void	displayAccountsInfos( void )
{

}

Account::Account( void )
{
	Account::_accountIndex = 0;
	Account::_amount = 0;
	Account::_nbDeposits = 0;
	Account::_nbWithdrawals = 0;
	Account::_nbAccounts = 0;
	Account::_totalAmount = 0;
	Account::_totalNbDeposits = 0;
	Account::_totalNbWithdrawals = 0;
}

Account::Account( int initial_deposit )
{
	_totalAmount += initial_deposit;
	Account::_accountIndex = _nbAccounts;
	Account::_amount = initial_deposit;
	Account::_nbDeposits = 0;
	Account::_nbWithdrawals = 0;

	//[19920104_091532] index:0;amount:42;created
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "created" << std::endl;
	_nbAccounts++;
}

Account::~Account( void )
{

}
//944567654 <- if you got here good luck
//[19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0
void	Account::displayAccountsInfos( void )
{
	std::cout << "accouts:" << Account::getNbAccounts() << ";";
	std::cout << "total:" << Account::getTotalAmount() << ";";
	std::cout << "deposits:" << Account::getNbDeposits() << ";";
	std::cout << "withdrawals:" << Account::getNbWithdrawals() << ";" << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	_amount = _amount + deposit;
	_nbDeposits += 1;
	_totalNbDeposits += 1;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	if (withdrawal > _amount)
		return (false);
	_amount = _amount - withdrawal;
	_nbWithdrawals += 1;
	_totalNbWithdrawals += 1;
	return (true);
}

int		Account::checkAmount( void ) const
{
	return (_amount);
}

//[19920104_091532] index:0;amount:42;deposits:0;withdrawals:0
void	Account::displayStatus( void ) const
{
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawals:" << _nbWithdrawals << ";" << std::endl;
}
