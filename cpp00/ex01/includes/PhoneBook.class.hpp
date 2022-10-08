/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 13:30:03 by mcombeau          #+#    #+#             */
/*   Updated: 2022/10/08 18:02:10 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

# include <string>
# include "Contact.class.hpp"

class	PhoneBook {
	private:
		int		_index;
		Contact	_contactList[8];
		std::string	_getInput(std::string const prompt);
		void	_incrementIndex(void);
	public:
		PhoneBook(void);
		~PhoneBook(void);

		void	addContact(void);
//		bool	searchContact(void);
};

#endif