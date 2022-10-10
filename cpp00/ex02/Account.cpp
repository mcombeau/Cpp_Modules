/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:46:58 by mcombeau          #+#    #+#             */
/*   Updated: 2022/10/10 18:47:53 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(void) : _accountIndex(_nbAccounts),
						_amount(0),
						_nbDeposits(0),
						_nbWithdrawals(0) {
	_nbAccounts++;
	return ;
}

Account::Account(int initial_deposit) : _accountIndex(_nbAccounts),
										_amount(initial_deposit),
										_nbDeposits(0),
										_nbWithdrawals(0) {
	_nbAccounts++;
	return ;
}

Account::~Account(void)	{
	_nbAccounts--;
	return ;
}

int	Account::getNbAccounts( void ) {
	return(_nbAccounts);
}

int	Account::getTotalAmount( void ) {
	return (_totalAmount);
}

int	Account::getNbDeposits( void ) {
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void ) {
	return (_totalNbWithdrawals);
}

void	Account::makeDeposit( int deposit ) {
	(void)deposit;
	return;
}

bool	Account::makeWithdrawal( int withdrawal ) {
	(void)withdrawal;
	return (true);
}

int		Account::checkAmount( void ) const {
	return (0);
}
void	Account::displayStatus( void ) const {
	return ;
}

void	Account::_displayTimestamp( void ) {
	return ;
}

void	Account::displayAccountsInfos( void ) {
		std::cout << "Account info" << std::endl;
		return ;
}
