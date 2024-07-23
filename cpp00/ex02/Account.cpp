#include "Account.hpp"
#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>


Account::Account(int initial_depost) {
	this->_accountIndex = 0;
	this->_amount = initial_depost;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
}

Account::~Account(void) {

}

int	Account::getNbAccounts(void) {
		return _nbAccounts;
}

int	Account::getTotalAmount(void) {
	return _totalAmount;
}

int	Account::getNbDeposits(void) {
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals(void) {
	return _totalNbWithdrawals;
}

void	Account::displayAccountsInfos(void) {
	std::cout << _displayTimestamp << "index:" << 
		_accountIndex << std::endl;
}

void	Account::makeDeposit(int deposit) {
	
}

bool	Account::makeWithdrawal(int withdrawal) {

}

int		Account::checkAmount(void) const {

}

void	Account::displayStatus(void) const {

}

void	Account::_displayTimestamp(void) {
	std::time_t now = std::time(0);
    std::tm *ltm = std::localtime(&now);

	std::cout << "["
              << 1900 + ltm->tm_year
              << std::setw(2) << std::setfill('0') << 1 + ltm->tm_mon
              << std::setw(2) << std::setfill('0') << ltm->tm_mday << "_"
              << std::setw(2) << std::setfill('0') << ltm->tm_hour
              << std::setw(2) << std::setfill('0') << ltm->tm_min
              << std::setw(2) << std::setfill('0') << ltm->tm_sec
              << "] ";
}