# Cpp Module 03

This module of 42 school's C++ piscine explores issues of class inheritance.

## Status
Validated 27/12/2022. Grade: 100%.

## Ex00 - ClapTrap
In the first exercise, we must implement a simple class, ClapTrap, which has the ability to attack, take damage and be repaired. The class also has private attributes: a name, hit points, energy points and attack damage.

### Usage
Clone this repository and `cd` into `cpp03/ex00`. Then `make` to compile. Run the program with:

```
./trap
```
The output shows the results of a functionality test.

## Ex01 - ScavTrap
The second exercise builds on the first by implementing another class, ScavTrap, which inherits from the previously created ClapTrap class and implements some new functionality, guardGate. ScavTrap also has different default values in its hit points, energy points and attack damage attributes.

### Usage
Clone this repository and `cd` into `cpp03/ex01`. Then `make` to compile. Run the program with:

```
./trap
```

## Ex02 - FragTrap
The third exercise introduces yet another class, FragTrap, which also inherits from the ClapTrap class and also has its own functionality, highFivesGuys. FragTrap also has different default values in its hit points, energy points and attack damage attributes compared to both ClapTrap and ScavTrap.

### Usage
Clone this repository and `cd` into `cpp03/ex02`. Then `make` to compile. Run the program with:

```
./trap
```

## Ex03 - DiamondTrap
The fourth and last exercise in the series implements a new class, DiamonTrap. DiamondTrap inherits from both ScavTrap and FragTrap and has some attributes of one and some attributes from the other. It also only has one grand-parent class: upon instantiation, there is only one instance of ClapTrap. It also uniquely updates its grand-parent class' name upon construction.

### Usage
Clone this repository and `cd` into `cpp03/ex03`. Then `make` to compile. Run the program with:

```
./trap
```

---
Made by mcombeau: mcombeau@student.42.fr | LinkedIn: [mcombeau](https://www.linkedin.com/in/mia-combeau-86653420b/) | Website: [codequoi.com](https://www.codequoi.com)
