/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 12:16:46 by mcombeau          #+#    #+#             */
/*   Updated: 2022/12/16 17:39:44 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <string>
#include <iostream>

#define NUMBER_ANIMALS 4

void	testAnimalArray(void)
{
	std::cout <<  "-------------------------------" << std::endl
		<< "\tANIMAL ARRAY TEST" << std::endl
		<<  "-------------------------------" << std::endl << std::endl;
	Animal	* animalArray[NUMBER_ANIMALS + 1];
	animalArray[NUMBER_ANIMALS] = NULL;

	std::cout << "-- Creating a kennel of " << NUMBER_ANIMALS << " animals: " 
		<< NUMBER_ANIMALS / 2 << " cats and "
		<< NUMBER_ANIMALS - (NUMBER_ANIMALS / 2) << " dogs." << std::endl;

	for (int i = 0; i < NUMBER_ANIMALS / 2; i++)
		animalArray[i] = new Cat();
	std::cout << std::endl;
	for (int i = NUMBER_ANIMALS / 2; i < NUMBER_ANIMALS; i++)
		animalArray[i] = new Dog();
	
	std::cout << std::endl << "-- The cats and dogs are loud..." << std::endl;
	for (int i = 0; animalArray[i]; i++)
		animalArray[i]->makeSound();
	
	std::cout << std::endl << "-- Destroy the loud animals!"<< std::endl;
	for (int i = 0; animalArray[i]; i++)
		delete animalArray[i];
	std::cout << std::endl;
}

void testCopyCat(void)
{
	std::cout <<  "-------------------------------" << std::endl
		<< "\tCOPY CAT TEST" << std::endl
		<<  "-------------------------------" << std::endl << std::endl
		<< "-- Creating \"Norminet\" cat." << std::endl;
	Cat * norminet = new Cat();

	std::cout << std::endl << "-- Putting ideas in Norminet's brain..." << std::endl;
	norminet->getBrain()->setIdea(0, "I think I have a hairball...");
	norminet->getBrain()->setIdea(1, "I need to cough the hairball up...");
	norminet->getBrain()->setIdea(2, "Human, clean that up, will you?");

	std::cout << "Norminet idea 0: \"" << norminet->getBrain()->getIdea(0) << "\"" << std::endl;
	std::cout << "Norminet idea 1: \"" << norminet->getBrain()->getIdea(1) << "\"" << std::endl;
	std::cout << "Norminet idea 2: \"" << norminet->getBrain()->getIdea(2) << "\"" << std::endl;

	std::cout << std::endl << "-- Creating a copy of \"Norminet\" cat" << std::endl;
	Cat * copyCat = new Cat(*norminet);

	std::cout << std::endl << "-- CopyCat should have the same ideas as Norminet." << std::endl;
	std::cout << "CopyCat idea0: \"" << copyCat->getBrain()->getIdea(0) << "\"" << std::endl;
	std::cout << "CopyCat idea1: \"" << copyCat->getBrain()->getIdea(1) << "\"" << std::endl;
	std::cout << "CopyCat idea2: \"" << copyCat->getBrain()->getIdea(2) << "\"" << std::endl;

	std::cout << std::endl << "-- Putting new ideas in Norminet's brain..." << std::endl;
	norminet->getBrain()->setIdea(0, "Where is that mouse??");
	norminet->getBrain()->setIdea(1, "I'm hungry.");
	norminet->getBrain()->setIdea(2, "I shall outsmart that mouse!");

	std::cout << "Norminet idea 0: \"" << norminet->getBrain()->getIdea(0) << "\"" << std::endl;
	std::cout << "Norminet idea 1: \"" << norminet->getBrain()->getIdea(1) << "\"" << std::endl;
	std::cout << "Norminet idea 2: \"" << norminet->getBrain()->getIdea(2) << "\"" << std::endl;
	
	std::cout << std::endl << "-- CopyCat's ideas should not have changed." << std::endl;
	std::cout << "CopyCat idea0: \"" << copyCat->getBrain()->getIdea(0) << "\"" << std::endl;
	std::cout << "CopyCat idea1: \"" << copyCat->getBrain()->getIdea(1) << "\"" << std::endl;
	std::cout << "CopyCat idea2: \"" << copyCat->getBrain()->getIdea(2) << "\"" << std::endl;

	std::cout << std::endl << "-- Setting CopyCat = Norminet." << std::endl;
	*copyCat = *norminet;

	std::cout << std::endl << "-- CopyCat's ideas should have changed to Norminet's." << std::endl;
	std::cout << "CopyCat idea0: \"" << copyCat->getBrain()->getIdea(0) << "\"" << std::endl;
	std::cout << "CopyCat idea1: \"" << copyCat->getBrain()->getIdea(1) << "\"" << std::endl;
	std::cout << "CopyCat idea2: \"" << copyCat->getBrain()->getIdea(2) << "\"" << std::endl;


	std::cout << std::endl << "-- Deleting Norminet and CopyCat." << std::endl;
	delete norminet;
	delete copyCat;
	std::cout << std::endl;
}

void testCopyDog(void)
{
	std::cout <<  "-------------------------------" << std::endl
		<< "\tCOPY DOG TEST" << std::endl
		<<  "-------------------------------" << std::endl << std::endl
		<< "-- Creating \"Moulinet\" dog" << std::endl;
	Dog * moulinet = new Dog();
	std::cout << std::endl << "-- Putting ideas in Moulinet's brain..." << std::endl;
	moulinet->getBrain()->setIdea(0, "Food! Food! Food!");
	moulinet->getBrain()->setIdea(1, "Human! Human! Human!");

	std::cout << "Moulinet idea 0: \"" << moulinet->getBrain()->getIdea(0) << "\"" << std::endl;
	std::cout << "Moulinet idea 1: \"" << moulinet->getBrain()->getIdea(1) << "\"" << std::endl;

	std::cout << std::endl << "-- Creating a copy of \"Moulinet\" dog." << std::endl;
	Dog * copyDog = new Dog(*moulinet);
	
	std::cout << std::endl << "-- CopyDog should have the same ideas as Moulinet." << std::endl;
	std::cout << "CopyDog idea0: \"" << copyDog->getBrain()->getIdea(0) << "\"" << std::endl;
	std::cout << "CopyDog idea1: \"" << copyDog->getBrain()->getIdea(1) << "\"" << std::endl;
	
	std::cout << std::endl << "-- Putting new ideas in Moulinet's brain..." << std::endl;
	moulinet->getBrain()->setIdea(0, "Fetch! Fetch! Fetch!");
	moulinet->getBrain()->setIdea(1, "Bark! Bark! Bark!");

	std::cout << "Moulinet idea 0: \"" << moulinet->getBrain()->getIdea(0) << "\"" << std::endl;
	std::cout << "Moulinet idea 1: \"" << moulinet->getBrain()->getIdea(1) << "\"" << std::endl;
	
	std::cout << std::endl << "-- CopyDog's ideas should not have changed." << std::endl;
	std::cout << "CopyDog idea0: \"" << copyDog->getBrain()->getIdea(0) << "\"" << std::endl;
	std::cout << "CopyDog idea1: \"" << copyDog->getBrain()->getIdea(1) << "\"" << std::endl;

	std::cout << std::endl << "-- Setting CopyDog = Moulinet." << std::endl;
	*copyDog = *moulinet;

	std::cout << std::endl << "-- CopyDog's ideas should have changed to Moulinet's." << std::endl;
	std::cout << "CopyCat idea0: \"" << copyDog->getBrain()->getIdea(0) << "\"" << std::endl;
	std::cout << "CopyCat idea1: \"" << copyDog->getBrain()->getIdea(1) << "\"" << std::endl;

	std::cout << std::endl << "-- Deleting Moulinet and CopyDog." << std::endl;
	delete moulinet;
	delete copyDog;
	std::cout << std::endl;
}

int	main(void)
{
	testAnimalArray();
	testCopyCat();
	testCopyDog();
	return (0);
}
