#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void )
{
	return Account::_nbAccounts;
}
int	Account::getTotalAmount( void )
{
	return Account::_totalAmount;
}
int	Account::getNbDeposits( void )
{
	return Account::_totalNbDeposits;
}
int	Account::getNbWithdrawals( void )
{
	return Account::_totalNbWithdrawals;
}

void	Account::displayAccountsInfos()
{
	
	_displayTimestamp();
	std::cout << "accounts:" 
	<< Account::_nbAccounts 
	<< ";total:" 
	<< Account::_totalAmount 
	<< ";deposits:" 
	<<  Account::_totalNbDeposits 
	<<";withdrawals:" 
	<< Account::_totalNbWithdrawals 
	<< std::endl;
}

Account::Account( int initial_deposit )
{
	_accountIndex =  _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	Account::_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << initial_deposit << ";created" << std::endl;
	Account::_nbAccounts+= 1;
}
Account::~Account( void)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;

}
void	Account::_displayTimestamp( void )
{
	std::time_t result = std::time(NULL);
	std::tm * ptm = std::localtime(&result);
	char buffer[32];
	std::strftime(buffer, 32, "[%Y%m%d_%H%M%S] ", ptm);
	std::cout << buffer;
	// std::cout  << "[19920104_091532] ";
}

void Account::makeDeposit( int deposit)
{
	// index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
	_displayTimestamp();
	std::cout << "index:"
	<< _accountIndex
	<< ";p_amount:"
	<< _amount
	<< ";deposit:"
	<< deposit
	<< ";amount:"
	<< _amount + deposit
	<< ";nb_deposits:"
	<< _nbDeposits + 1
	<< std::endl;
	_amount += deposit;
	Account::_totalNbDeposits+= 1;
	Account::_totalAmount+= deposit;
	_nbDeposits++;
}
bool Account::makeWithdrawal( int withdrawal )
{
	// [19920104_091532] index:3;p_amount:434;withdrawal:4;amount:430;nb_withdrawals:1
	_displayTimestamp();
	std::cout << "index:"
	<< _accountIndex
	<< ";p_amount:"
	<< _amount
	<< ";withdrawal:";
	if (_amount < withdrawal)
		return std::cout << "refused" << std::endl, false;
	std::cout 
	<< withdrawal
	<< ";amount:"
	<< _amount - withdrawal
	<< ";nb_withdrawals:"
	<< _nbWithdrawals + 1
	<< std::endl;
	_amount -= withdrawal;
	_nbWithdrawals++;
	Account::_totalNbWithdrawals +=1;
	Account::_totalAmount -= withdrawal;
	return true;
}

int Account::checkAmount( void ) const
{
	return _amount;
}
void Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" 
	<< _accountIndex 
	<< ";amount:" 
	<< _amount
	<< ";deposits:"
	<< _nbDeposits 
	<< ";withdrawals:"
	<<	_nbWithdrawals
	<< std::endl; 
}