#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(void){
	return (_nbAccounts);
}

int Account::getTotalAmount(void){
	return (_totalAmount);    
}

int Account::getNbDeposits(void){
	return (_totalNbDeposits);
}

int Account::getNbWithdrawals(void){
	return (_totalNbWithdrawals);
}

void Account::displayAccountsInfos(void){
	Account::_displayTimestamp();
	std::cout <<
	" accounts:" << _nbAccounts <<
	";total:" << _totalAmount <<
	";deposits:" << _totalNbDeposits <<
	";withdrawals:" << _totalNbWithdrawals
	<< std::endl;
}

Account::Account(int initial_deposit){
	static int index = 0;
	
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_totalAmount += initial_deposit;
	this->_accountIndex = index++;
	_nbAccounts++;
	Account::_displayTimestamp();
	std::cout <<
	" index:" << this->_accountIndex <<
	";amount:" << this->_amount <<
	";created" <<
	std::endl;
	return ;
}

Account::~Account(void){

	Account::_displayTimestamp();
	std::cout << 
	" index:" << this->_accountIndex <<
	";amount:" << this->_amount <<
	";closed" <<
	std::endl;
	return ;
}

void Account::makeDeposit(int deposit){
	Account::_displayTimestamp();
	std::cout <<
	" index:" << this->_accountIndex <<
	";p_amount:" << Account::checkAmount() <<
	";deposit:" << deposit; 
	if (deposit > 0)
	{
		_totalNbDeposits++;
		this->_nbDeposits++;
		this->_amount += deposit;
		_totalAmount += deposit;
	}
	std::cout <<
	";amount:" << Account::checkAmount() <<
	";nb_deposits:" << this->_nbDeposits <<
	std::endl;
}

bool Account::makeWithdrawal(int withdrawal){
	Account::_displayTimestamp();
	std::cout <<
	" index:" << this->_accountIndex <<
	";p_amount:" << Account::checkAmount();
	if (withdrawal <= Account::checkAmount())
	{
		_totalNbWithdrawals++;
		this->_nbWithdrawals++;
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		std::cout <<
		";withdrawal:" << withdrawal <<
		";amount:" << Account::checkAmount() <<
		";nb_withdrawals:" << this->_nbWithdrawals <<
		std::endl;
	}
	else
	{
		std::cout << ";withdrawal:refused" << std::endl;
		return (false);
	}
	return (true);
}

int Account::checkAmount(void) const{
	return (this->_amount);
}

void    Account::displayStatus(void) const{
	Account::_displayTimestamp();
	std::cout <<
	" index:" << _accountIndex <<
	";amount:" << Account::checkAmount() <<
	";deposits:" << this->_nbDeposits <<
	";withdrawals:" << this->_nbWithdrawals <<
	std::endl;
}

void    Account::_displayTimestamp(void){
	time_t rawtime;
	struct tm* timeinfo;
	
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	std::cout << "[" 
	<< (timeinfo->tm_year + 1900)
	<< (timeinfo->tm_mon + 1 < 10 ? "0" : "") << (timeinfo->tm_mon + 1)
	<< (timeinfo->tm_mday < 10 ? "0" : "") << timeinfo->tm_mday
	<< "_"
	<< (timeinfo->tm_hour < 10 ? "0" : "") << timeinfo->tm_hour
	<< (timeinfo->tm_min < 10 ? "0" : "") << timeinfo->tm_min
	<< (timeinfo->tm_sec < 10 ? "0" : "") << timeinfo->tm_sec
	<< "]";
}
