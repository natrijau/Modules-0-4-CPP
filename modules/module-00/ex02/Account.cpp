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
	_displayTimestamp();
	std::cout << " accounts:\33[0;34m" << _nbAccounts
			 << "\033[0m;total:\33[0;34m" << _totalAmount
			 << "\033[0m;deposits:\33[0;34m" << _totalNbDeposits
			 << "\033[0m;withdrawals:\33[0;34m" << _totalNbWithdrawals << "\033[0m" << std::endl;
}

Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_nbAccounts++;
	_totalAmount += initial_deposit;

	_displayTimestamp();
	std::cout << " index:\33[0;34m" <<  _accountIndex
				<< "\033[0m;amount:\33[0;34m" <<  _amount
				<< "\033[0m;created" <<  std::endl;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << " index:\33[0;34m" <<  _accountIndex
				<< "\033[0m;amount:\33[0;34m" <<  _amount
				<< "\033[0m;closed" <<  std::endl;	
}

void	Account::makeDeposit(int deposit)
{
	_totalAmount += deposit;
	_totalNbDeposits++;
	_amount += deposit;
	_nbDeposits++;
	_displayTimestamp();
	std::cout << " index:\33[0;34m" <<  _accountIndex
			<< "\033[0m;p_amount:\33[0;34m" <<  _amount - deposit
			<< "\033[0m;deposits:\33[0;34m" <<  deposit
			<< "\033[0m;amount:\33[0;34m" <<  _amount 
			<< "\033[0m;nb_deposits:\33[0;34m" <<  _nbDeposits
			<< "\033[0m" <<  std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	if (withdrawal > _amount)
	{
		std::cout << " index:\33[0;34m" <<  _accountIndex
				<< "\033[0m;p_amount:\33[0;34m" <<  _amount
				<< "\033[0m;withdrawal:refused" <<  std::endl;	
		return (false);
	}
	_totalAmount -= withdrawal;
	_amount -= withdrawal;
	_nbWithdrawals++;
	std::cout << " index:\33[0;34m" <<  _accountIndex
			<< "\033[0m;p_amount:\33[0;34m" <<  _amount + withdrawal
			<< "\033[0m;withdrawal:\33[0;34m" <<  withdrawal
			<< "\033[0m;amount:\33[0;34m" <<  _amount
			<< "\033[0m;nb_withdrawals:\33[0;34m" <<  _nbWithdrawals
			<< "\033[0m" <<  std::endl;	
	return (true);
}
int		Account::checkAmount() const
{
	return (_amount);
}

void	Account::displayStatus() const
{
	_displayTimestamp();
	std::cout << " index:\33[0;34m" << _accountIndex
			 << "\033[0m;amount:\33[0;34m" << _amount
			 << "\033[0m;deposits:\33[0;34m" << _nbDeposits
			 << "\033[0m;withdrawals:\33[0;34m" << _nbWithdrawals 
			 << "\033[0m" << std::endl;
}

void    Account::_displayTimestamp(void)
{
	time_t rawtime;
	struct tm * timeinfo;
	char    ptr[18];

	time(&rawtime);
	timeinfo = localtime (&rawtime);
	strftime(ptr, 18, "[%Y%m%C_%H%M%S]", timeinfo);
	std::cout << ptr;
}

