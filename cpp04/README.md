# Cpp Module 04

This module of 42 school's C++ piscine explores issues of class inheritance, subtype polymorphism, abstract classes, and interfaces.

## Status
Validated 29/12/2022. Grade: 100%.

## Ex00 - Animals
In the first exercise, we must implement a simple class, Animal, and its two derived classes, Dog and Cat. All classes have their own makeSound function which displays a different message depending on the animal. We must manipulate cats and dogs through pointers of their parent class, Animal, and ensure that the sounds they make are appropriate to their type. 

### Usage
Clone this repository and `cd` into `cpp04/ex00`. Then `make` to compile. Run the program with:

```
./animal
```
The output shows the results of a functionality test.

## Ex01 - Animals with brains
The second exercise builds on the first by implementing another class, Brain. Cat and Dog instances will have a Brain which can contain up to 100 ideas. Copies of Dogs and Cats musn't be shallow, and there should be no memory leaks. 

### Usage
Clone this repository and `cd` into `cpp04/ex01`. Then `make` to compile. Run the program with:

```
./animal
```

## Ex02 - Abstract animals
The third exercise introduces us to the concept of abstract classes. The Animal base class should no longer be instantiable.

### Usage
Clone this repository and `cd` into `cpp04/ex02`. Then `make` to compile. Run the program with:

```
./animal
```
To check that the Animal class is no longer instantiable, uncomment the commented test in `cpp04/ex02/sources/main.c`. The program should no longer compile.

## Ex03 - Materias
The fourth and last exercise in the series requires the implementation of pure abstract classes: interfaces. The Character class is implemented according to the ICharacter interface. A character has an inventory of up to 4 materia which can be equipped, unequipped or used. A materia can be one of two types: ice or cure. Materias are created with a MateriaSource class which implements the IMateriaSource interface.

### Usage
Clone this repository and `cd` into `cpp04/ex03`. Then `make` to compile. Run the program with:

```
./materia
```

---
Made by mcombeau: mcombeau@student.42.fr | LinkedIn: [mcombeau](https://www.linkedin.com/in/mia-combeau-86653420b/) | Website: [codequoi.com](https://www.codequoi.com)
