/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 13:30:03 by mcombeau          #+#    #+#             */
/*   Updated: 2022/10/13 16:00:30 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

# include <string>
# include "Contact.class.hpp"

class	PhoneBook {
	private:
		int		_index;
		bool	_abort;
		Contact	_contactList[8];

		std::string	_getInput(std::string const prompt);
		void		_incrementIndex(void);
		bool		_displayContactByIndex(std::string const input) const;
		void		_displayContactTable(void) const;
		void		_printContactInfoToTable(int const index) const;
		void		_printTableString(std::string str) const;

	public:
		PhoneBook(void);
		~PhoneBook(void);

		std::string	trimBlank(std::string str);
		bool		addContact(void);
		void		displayContact(int index) const;
		bool		searchContact(void);
};

#endif