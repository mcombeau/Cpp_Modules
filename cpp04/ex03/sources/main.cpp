/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 12:16:46 by mcombeau          #+#    #+#             */
/*   Updated: 2022/12/19 15:00:42 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Colors.h"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include <iostream>

void	testMateriaSource(void)
{
	std::cout << std::endl <<  "-------------------------------" << std::endl
		<< "\tMATERIA SOURCE TEST" << std::endl
		<<  "-------------------------------" << std::endl;
	std::cout << std::endl << "-- MATERIA SOURCE CREATION" << std::endl;
	MateriaSource * source = new MateriaSource();
	source->displayKnownRecipes();

	std::cout << std::endl << "-- MATERIA SOURCE LEARNING RECIPES" << std::endl;
	source->learnMateria(NULL);
	source->learnMateria(new Cure());
	source->learnMateria(new Ice());
	source->displayKnownRecipes();

	std::cout << std::endl << "-- MATERIA SOURCE DEEP COPY" << std::endl;
	MateriaSource * copySource = new MateriaSource(*source);
	std::cout << "Original ";
	source->displayKnownRecipes();
	std::cout << "Copy ";
	copySource->displayKnownRecipes();
	std::cout << "Original Materia Source learns another recipe:" << std::endl;
	source->learnMateria(new Cure());
	std::cout << "Original ";
	source->displayKnownRecipes();
	std::cout << "Copy ";
	copySource->displayKnownRecipes();
	std::cout << "Deleting Copy Materia Source:" << std::endl;
	delete copySource;

	std::cout << std::endl << "-- MATERIA SOURCE LEARNING TOO MANY RECIPES" << std::endl;
	source->displayKnownRecipes();
	source->learnMateria(new Ice());
	source->learnMateria(new Cure());
	source->displayKnownRecipes();

	std::cout << std::endl << "-- MATERIA SOURCE CREATING MATERIA FROM RECIPES" << std::endl;
	AMateria *	m1 = NULL;
	AMateria *	m2 = NULL;
	AMateria *	m3 = NULL;
	
	m1 = source->createMateria("ice");
	if (m1 == NULL)
		std::cout << "Materia was not created." << std::endl;
	else
		std::cout << "Created materia is " << m1->getType() << std::endl;
	m2 = source->createMateria("cure");
	if (m2 == NULL)
		std::cout << "Materia was not created." << std::endl;
	else
		std::cout << "Created materia is " << m2->getType() << std::endl;
	m3 = source->createMateria("rock");
	if (m3 == NULL)
		std::cout << "Materia was not created." << std::endl;
	else
		std::cout << "Created materia is " << m2->getType() << std::endl;
	if (m1 != NULL)
		delete m1;
	if (m2 != NULL)
		delete m2;
	if (m2 != NULL)
		delete m3;

	std::cout << std::endl << "-- MATERIA SOURCE DELETION" << std::endl;
	delete source;
}

void	testCharacters(void)
{
	std::cout << std::endl <<  "-------------------------------" << std::endl
		<< "\tCHARACTER TEST" << std::endl
		<<  "-------------------------------" << std::endl;
	std::cout << std::endl << "-- MATERIA CREATION" << std::endl;
	AMateria *	m1 = new Cure();
	AMateria *	m2 = new Cure();
	AMateria *	m3 = new Cure();
	AMateria *	m4 = new Ice();
	AMateria *	m5 = new Ice();
	AMateria *	m6 = new Ice();

	std::cout << std::endl << "-- CHARACTER CREATION" << std::endl;
	Character *	emily = new Character("Emily");
	emily->displayInventory();

	std::cout << std::endl << "-- CHARACTER EQUIPPING ITEMS" << std::endl;
	emily->equip(NULL);
	emily->equip(m1);
	emily->equip(m2);
	emily->displayInventory();

	std::cout << std::endl << "-- CHARACTER DEEP COPY" << std::endl;
	Character *	emilyCopy = new Character(*emily);
	std::cout << "Changing copy's name from \"" << emilyCopy->getName()
		<< "\" to \"Copy\"." << std::endl;
	emilyCopy->setName("Copy");
	emily->displayInventory();
	emilyCopy->displayInventory();
	emily->equip(m3);
	emily->displayInventory();
	emilyCopy->displayInventory();
	std::cout << "Deleting copy character:" << std::endl;
	delete emilyCopy;

	std::cout << std::endl << "-- CHARACTER EQUIPPING TOO MANY ITEMS" << std::endl;
	emily->displayInventory();
	emily->equip(m4);
	emily->equip(m5);
	emily->equip(m6);
	emily->displayInventory();

	std::cout << std::endl << "-- CHARACTER UNEQUIPPING ITEMS" << std::endl;
	emily->unequip(-1);
	emily->unequip(10000);
	emily->unequip(4);
	emily->unequip(2);
	emily->displayInventory();
	emily->equip(m5);
	emily->displayInventory();
	emily->unequip(1);
	emily->unequip(2);
	emily->displayInventory();
	emily->unequip(2);

	std::cout << std::endl << "-- CHARACTER UNEQUIPPING ITEM DOES NOT DELETE IT" << std::endl;
	std::cout << "- Creating a tmp materia of type cure:" << std::endl;
	AMateria * tmp = new Cure();
	std::cout << "- Equipping the tmp materia:" << std::endl;
	emily->equip(tmp);
	std::cout << "- Unequipping the tmp materia:" << std::endl;
	emily->unequip(1);
	std::cout << "- Deleting the tmp materia:" << std::endl;
	delete tmp;

	std::cout << std::endl << "-- CHARACTER DELETION" << std::endl;
	delete emily;

	std::cout << std::endl << "-- CLEANING UP UNEQUIPPED MATERIA" << std::endl;
	delete m2;
	delete m3;
	delete m5;
	delete m6;
}

void	testMateriaDuelBetweenTwoCharacters(void)
{
	std::cout << std::endl <<  "-------------------------------" << std::endl
		<< "    WELCOME TO THE EPIC DUEL" << std::endl
		<<  "-------------------------------" << std::endl;
	std::cout << std::endl << "-- CREATING MATERIA SOURCE" << std::endl;
	MateriaSource * source = new MateriaSource();
	source->learnMateria(new Cure);
	source->learnMateria(new Ice());

	std::cout << std::endl << "-- MATERIA SOURCE CREATES ITEMS ON THE FLOOR" << std::endl;
	int const	nb_items = 6;
	AMateria * materias[nb_items + 1];
	materias[nb_items] = NULL;

	std::cout << "-- Creating an array of " << nb_items << " materias." << std::endl;
	for (int i = 0; i < nb_items; i++)
	{
		if (i % 2)
			materias[i] = source->createMateria("ice");
		else
			materias[i] = source->createMateria("cure");
	}
	std::cout << std::endl;

	std::cout << std::endl << "-- CREATING CHARACTERS" << std::endl;
	Character * igor = new Character("Igor");
	Character *	jessica = new Character("Jessica");

	std::cout << std::endl << "-- EQUIPPING CHARACTERS" << std::endl;
	for (int i = 0; i < nb_items / 2; i++)
		igor->equip(materias[i]);
	for (int i = nb_items / 2; i < nb_items; i++)
		jessica->equip(materias[i]);

	std::cout << std::endl << "-- 3, 2, 1, 0! FIGHT!" << std::endl;
	igor->use(-1, *igor);
	igor->use(4, *igor);
	jessica->use(3, *igor);
	igor->use(2, *igor);
	igor->use(1, *jessica);
	igor->use(1, *jessica);
	jessica->use(1, *jessica);
	jessica->use(2, *igor);
	jessica->use(1, *igor);
	igor->use(0, *jessica);

	std::cout << std::endl << "-- CHARACTER DELETION" << std::endl;
	delete igor;
	delete jessica;

	std::cout << std::endl << "-- MATERIA SOURCE DELETION" << std::endl;
	delete source;
}

int	main(void)
{
	testMateriaSource();
	testCharacters();
	testMateriaDuelBetweenTwoCharacters();
	return (0);
}
