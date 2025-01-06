#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts()
{
	return (_nbAccounts);
}

int	Account::getTotalAmount()
{
	return (_totalAmount);
}

int	Account::getNbDeposits()
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals()
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos()
{
	std::cout << std::endl << "	Accounts information" << std::endl;
	std::cout << "	Number total of accounts | " << _nbAccounts << std::endl;
	std::cout << "	Total Amount | " << _totalAmount << std::endl;
	std::cout << "	Number of Deposits | " << _totalNbDeposits << std::endl;
	std::cout << "	Number with drawals | " << _totalNbWithdrawals << std::endl;
}

Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_nbAccounts++;
	_totalAmount += initial_deposit;

	std::cout << "	Creation of account" << std::endl;
	_displayTimestamp();
	std::cout << "	Index | " <<  _accountIndex << std::endl;
	std::cout << "	Account balance | " <<  _amount << std::endl << std::endl;
}

Account::~Account(void)
{
	std::cout << std::endl << "	Closing account" << std::endl;
	_displayTimestamp();
	std::cout << "	Index | " <<  _accountIndex << std::endl;
	std::cout << "	Account balance | " <<  _amount << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	std::cout << std::endl << "	Account number " << _accountIndex
				<< " make a deposit of " << deposit << std::endl;
	_displayTimestamp();
	_totalAmount += deposit;
	_totalNbDeposits++;
	_amount += deposit;
	_nbDeposits++;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	std::cout << std::endl << "	Account number " << _accountIndex
				<< " withdraws an amount of " << withdrawal << std::endl;
	_displayTimestamp();
	if (withdrawal > _amount)
	{
		std::cout << "		Insufficient balance" << std::endl;
		std::cout << "		Maximum withdrawal allowed : " << _amount << std::endl;
		return (false);
	}
	_totalAmount -= withdrawal;
	_amount -= withdrawal;
	_nbWithdrawals++;
	return (true);
}
int		Account::checkAmount() const
{
	return (_amount);
}

void	Account::displayStatus() const
{
	std::cout << std::endl << "	Account status " << std::endl;
	std::cout << "	Index | " << _accountIndex << std::endl;
	std::cout << "	Amount | " << _amount << std::endl;
	std::cout << "	Number of deposits made | " << _nbDeposits << std::endl;
	std::cout << "	Number of withdrawals made | " << _nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp()
{
	time_t timestamp;
	time(&timestamp);
	std::cout << "	Date | " << ctime(&timestamp);
}

