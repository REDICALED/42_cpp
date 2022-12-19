#include "Account.hpp"
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;


Account::Account(int initial_deposit) {
	_displayTimestamp();
	Account::_accountIndex = Account::_nbAccounts;
	Account::_amount = initial_deposit;
	Account::_nbDeposits = 0;
	Account::_nbWithdrawals = 0;
	std::cout<<"index:"<<Account::_accountIndex<<";amount:";
	std::cout<<Account::_amount<<";created"<<std::endl;
	Account::_nbAccounts ++;
	Account::_totalAmount += Account::_amount;
}

int Account::getNbAccounts(void) {
	return Account::_nbAccounts;
}

int Account::getTotalAmount(void) {
	return Account::_totalAmount;
}

int Account::getNbDeposits(void) {
	return Account::_totalNbDeposits;
}

int	Account::getNbWithdrawals(void) {
	return Account::_totalNbWithdrawals;
}

void Account::displayAccountsInfos(void) {
	_displayTimestamp();
	std::cout<<"accounts:"<<Account::getNbAccounts()<<";";
	std::cout<<"total:"<<Account::getTotalAmount()<<";";
	std::cout<<"deposits:"<<Account::getNbDeposits()<<";";
	std::cout<<"withdrawals:"<<Account::getNbWithdrawals()<<std::endl;
}

void Account::makeDeposit(int deposit) {
	_displayTimestamp();
	std::cout<<"index:"<<Account::_accountIndex<<";";
	std::cout<<"p_amount:"<<Account::_amount<<";";
	std::cout<<"deposit:"<<deposit<<";";
	Account::_amount += deposit;
	Account::_totalAmount += deposit;
	Account::_nbDeposits ++;
	Account::_totalNbDeposits ++;
	std::cout<<"amount:"<<Account::_amount<<";";
	std::cout<<"nb_deposits:"<<Account::_nbDeposits<<std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
	_displayTimestamp();
	std::cout<<"index:"<<Account::_accountIndex<<";";
	std::cout<<"p_amount:"<<Account::_amount<<";";
	std::cout<<"withdrawal:";
	if (Account::_amount < withdrawal)
		Account::checkAmount();
	else
	{
		std::cout<<withdrawal<<";";
		Account::_amount -= withdrawal;
		Account::_totalAmount -= withdrawal;
		Account::_nbWithdrawals ++;
		Account::_totalNbWithdrawals ++;
		std::cout<<"amount:"<<Account::_amount<<";";
		std::cout<<"nb_withdrawals:"<<Account::_nbDeposits<<std::endl;
	}
	return (0);
}

int Account::checkAmount(void) const {
	std::cout<<"refused"<<std::endl;
	return (0);
}

void Account::displayStatus(void) const {
	_displayTimestamp();
	std::cout<<"index:"<<Account::_accountIndex<<";";
	std::cout<<"amount:"<<Account::_amount<<";";
	std::cout<<"deposits:"<<Account::_nbDeposits<<";";
	std::cout<<"withdrawals:"<<Account::_nbWithdrawals<<std::endl;
}

Account::~Account() {
	_displayTimestamp();
	std::cout<<"index:"<<Account::_accountIndex<<";amount:";
	std::cout<<Account::_amount<<";closed"<<std::endl;
}

void Account::_displayTimestamp( void )
{
	char s[100];
	time_t temp;
	
	temp = time(NULL);
	strftime(s,sizeof(s),"[%Y%m%d_%H%M%S] ", localtime(&temp));
	std::cout<<s;
}