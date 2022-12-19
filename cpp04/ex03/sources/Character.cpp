/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 15:19:20 by mcombeau          #+#    #+#             */
/*   Updated: 2022/12/19 14:24:02 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Colors.h"
#include <iostream>
#include <string>

Character::Character(void) : _name("Unnamed")
{
	std::cout << CYAN "Character default constructor called." RESET << std::endl;
	this->_initializeEmptyInventory();
	return ;
}

Character::Character(Character const & src)
{
	std::cout << CYAN "Character copy constructor called." RESET << std::endl;
	this->_initializeEmptyInventory();
	*this = src;
	return ;
}

Character::Character(std::string const & name) : _name(name)
{
	std::cout << CYAN "Character name constructor called with name \""
		<< this->_name << "\"." RESET << std::endl;
	this->_initializeEmptyInventory();
	return ;
}

Character::~Character(void)
{
	std::cout << CYAN "Character destructor called for \""
		<< this->_name << "\"." RESET << std::endl;
	this->_deleteInventory();
	return ;
}

Character &	Character::operator=(Character const & src)
{
	std::cout << CYAN "Character assignment operator overload called."
		RESET << std::endl;
	this->_name = src._name;
	this->_deleteInventory();
	for (int i = 0; i < this->_inventorySize; i++)
	{
		if (src._inventory[i] != NULL)
			this->_inventory[i] = src._inventory[i]->clone();
	}
	return (*this);
}

std::string const &	Character::getName(void) const
{
	return (this->_name);
}

void	Character::setName(std::string const & newName)
{
	this->_name = newName;
	return ;
}

void	Character::equip(AMateria * materia)
{
	if (!materia)
	{
		std::cout << RED << this->_name
			<< ": Can't equip something that doesn't exist!"
			RESET << std::endl;
		return ;
	}
	for (int i = 0; i < this->_inventorySize; i++)
	{
		if (this->_inventory[i] == NULL)
		{
			this->_inventory[i] = materia;
			std::cout << GREEN << this->_name
				<< " equipped " << materia->getType()
				<< " materia to inventory index " << i << "." RESET << std::endl;
			return ;
		}
	}
	std::cout << RED << this->_name
		<< ": I can't carry any more materia!" RESET << std::endl;
	return ;
}

void	Character::unequip(int index)
{
	if (index < 0 || index >= this->_inventorySize)
	{
		std::cout << RED << this->_name
			<< ": I can't unequip anything from inventory index " << index
			<< ". It's not a valid index!" RESET << std::endl;
		return ;
	}
	if (this->_inventory[index] == NULL)
	{
		std::cout << RED << this->_name
			<< ": I don't have anything at index " << index << " to unequip!"
			RESET << std::endl;
		return ;
	}
	std::cout << GREEN << this->_name
		<< " unequipped " << this->_inventory[index]->getType()
		<< " materia from inventory index " << index << "." RESET << std::endl;
	this->_inventory[index] = NULL;	
	return ;
}

void	Character::use(int index, ICharacter & target)
{
	if (index < 0 || index >= this->_inventorySize)
	{
		std::cout << this->_name << ": " RED
			"Can't use item at inventory index " << index
			<< ". It's not a valid index!" RESET << std::endl; 
		return ;
	}
	if (this->_inventory[index] != NULL)
	{
		std::cout << this->_name << ": ";
		this->_inventory[index]->use(target);
	}
	else
		std::cout << this->_name
			<< ": "  RED "Oops, I don't have an item in my inventory at index "
			<< index << "!" RESET << std::endl;
	return ;
}

void	Character::displayInventory(void) const
{
	std::cout << this->_name << "'s inventory contains:" << std::endl;
	for (int i = 0; i < this->_inventorySize; i++)
	{
		std::cout << "\t[" << i << "] ";
		if (this->_inventory[i] == NULL)
			std::cout << "Empty slot.";
		else
			std::cout << this->_inventory[i]->getType() << " materia.";
		std::cout << std::endl;
	}
	return ;
}

void	Character::_initializeEmptyInventory(void)
{
	for (int i = 0; i < this->_inventorySize; i++)
		this->_inventory[i] = NULL;
	return ;
}

void	Character::_deleteInventory(void)
{
	for (int i = 0; i < this->_inventorySize; i++)
	{
		if (this->_inventory[i] != NULL)
		{
			delete this->_inventory[i];
			this->_inventory[i] = NULL;
		}
	}
	return ;
}