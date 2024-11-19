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
	std::cout << "[19920104_091532] ";
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "created" << std::endl;
	_nbAccounts++;
}

Account::~Account( void )
{
	//[19920104_091532] index:0;amount:47;closed
	std::cout << "[19920104_091532] ";
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "closed" << std::endl;
}
//944567654 <- if you got here good luck
//[19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0
void	Account::displayAccountsInfos( void )
{
	std::cout << "[19920104_091532] ";
	std::cout << "accounts:" << Account::getNbAccounts() << ";";
	std::cout << "total:" << Account::getTotalAmount() << ";";
	std::cout << "deposits:" << Account::getNbDeposits() << ";";
	std::cout << "withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	int p_amount = 0;
	p_amount = _amount; // is not person_amount is PREVIOUS_amount omg
	_amount = _amount + deposit;
	_nbDeposits += 1;
	_totalNbDeposits += 1;
	_totalAmount += deposit;
	std::cout << "[19920104_091532] ";
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << p_amount << ";";
	std::cout << "deposit:" << deposit << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	bool	flag = false;
	int		p_amount = _amount;
	if (withdrawal > _amount)
		flag = false;
	else
	{
		p_amount = _amount;
		_amount = _amount - withdrawal;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals += 1;
		_nbWithdrawals += 1;
		flag = true;
	}
	//[19920104_091532] index:0;p_amount:47;withdrawal:refused
	//[19920104_091532] index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1
	std::cout << "[19920104_091532] ";
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << p_amount << ";";
	if (flag)
	{
		std::cout << "withdrawal:" << withdrawal << ";";
		std::cout << "amount:" << _amount << ";";
		std::cout << "nb_withdrawals:" << _nbWithdrawals<< std::endl;
	}
	else
		std::cout << "withdrawal:refused" << std::endl;
	return (flag);
}

int		Account::checkAmount( void ) const
{
	return (_amount);
}

//[19920104_091532] index:0;amount:42;deposits:0;withdrawals:0
void	Account::displayStatus( void ) const
{
	std::cout << "[19920104_091532] ";
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawals:" << _nbWithdrawals << std::endl;
}
