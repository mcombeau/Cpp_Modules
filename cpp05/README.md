# Cpp Module 05

This module of 42 school's C++ piscine is an introduction to exception classes and messages and try/catch blocks.

## Status
Validated 30/12/2022. Grade: 100%.

## Ex00 - Bureaucrats
In the first exercise, we must implement a simple class, Bureaucrat. The Bureaucrat's highest possible grade is 1 and its lowest is 150. Attempting to construct a Bureaucrat with a grade that is either too high or too low should throw the appropriate exception. The same is true when a Bureaucrat's grade increases or decreases.

### Usage
Clone this repository and `cd` into `cpp05/ex00`. Then `make` to compile. Run the program with:

```
./bureaucrat
```
The output shows the results of a functionality test.

## Ex01 - Forms
The second exercise builds on the first by implementing another class, Form. Forms start off unsigned and require a certain grade to be signed and to be executed. If a form grade is out of bounds, the appropriate exception must be thrown.

### Usage
Clone this repository and `cd` into `cpp05/ex01`. Then `make` to compile. Run the program with:

```
./bureaucrat
```

## Ex02 - More Forms!
The third exercise asks us to extend the variety of our forms. The Form class becomes abstract, and three specific forms will inherit from it: the Shrubbery Creation Form, the Robotomy Request Form, and the Presidential Pardon Form. Each have different grades required to sign and execute them, as well as their own effects. 

### Usage
Clone this repository and `cd` into `cpp05/ex02`. Then `make` to compile. Run the program with:

```
./bureaucrat
```

## Ex03 - Interns
The fourth and last exercise in the series builds on the previous ones. A new class, Intern, although it has no grade and no unique characteristics, has the ability to create each of the previously-defined forms. Of course, exceptions will be thrown if the requested form cannot be created.

### Usage
Clone this repository and `cd` into `cpp05/ex03`. Then `make` to compile. Run the program with:

```
./bureaucrat
```

---
Made by mcombeau: mcombeau@student.42.fr | LinkedIn: [mcombeau](https://www.linkedin.com/in/mia-combeau-86653420b/) | Website: [codequoi.com](https://www.codequoi.com)
