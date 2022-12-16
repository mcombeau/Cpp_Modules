# Cpp Module 01

In this series of c++ exercises, we learn about memory allocation in c++, pointers to members, references, input and output streams, and switch statements.

## Status
Validated 12/12/2022. Grade: 90% (error on ex04).

## Ex00 - Brainzz
The first exercise is a lesson on memory allocation with `new` and `delete`. We must create a Zombie class and instantiate it on the heap or on the stack.

### Usage
Clone the repository and `cd` into `cpp01/ex00`, then `make` to compile. To run the program:

```
./brainzz
```

## Ex01 - Moarbrainzz
Using the class from the previous exercise, we must allocate several Zombie objects in a single allocation.

### Usage
Clone the repository and `cd` into `cpp01/ex01`, then `make` to compile. To run the program:

```
./moarbrainzz
```
Then, follow the prompts and input the number of zombies to instantiate, and the name of the zombie horde.

## Ex02 - Pointers and References
The third exercise is a simple test to show how pointers and references work by printing the address of a variable, a pointer to it and a reference to it, as well as the variable, pointer and reference values.

### Usage
Clone the repository and `cd` into `cpp01/ex02`, then `make` to compile. To run the program:

```
./brain
```

## Ex03 - Unecessary Violence
In the fourth exercise, we must apply our knowledge of pointers and references with a Weapon class and two Human classes. The HumanA class takes a reference to a Weapon whereas the HumanB class takes a pointer to a Weapon.

### Usage
Clone the repository and `cd` into `cpp01/ex03`, then `make` to compile. To run the program:

```
./unecessary_violence
```

## Ex04 - Sed is for losers
The fifth exercise is about input and output streams in c++. In a provided file, we must read the provided file and replace every instance of the provided string with another provided string. 

### Usage
Clone the repository and `cd` into `cpp01/ex04`, then `make` to compile. To run the program:

```
./loser_sed "filename" "string_to_replace" "replacement_string" 
```

The result of the program can be viewed in a new file with the same name and the extension .replace. (For example if the provided filename was "test", the result file is "test.replace").

To use the included tester:

```
bash test.sh
```

## Ex05 - Harl
This exercise is an introduction to pointers to member functions. Harl is a class and Harl can complain on several levels. The harl class has 4 functions for its complaints (DEBUG, INFO, WARNING, ERROR). We must pick the appropriate member function with a pointer rather than a forest of if-else statements.

### Usage
Clone the repository and `cd` into `cpp01/ex05`, then `make` to compile. To run the program:

```
./harl
```

## Ex06 - HarlFilter
The last exercise builds on the last one. Now we must use a switch statement to display Harl's complaints. We must display all complaints of the requested level and above (for example, requesting INFO should display the INFO, WARNING and ERROR messages).

### Usage
Clone the repository and `cd` into `cpp01/ex06`, then `make` to compile. To run the program:

```
./harlFilter "LEVEL"
```

---
Made by mcombeau: mcombeau@student.42.fr | LinkedIn: [mcombeau](https://www.linkedin.com/in/mia-combeau-86653420b/) | Website: [codequoi.com](https://www.codequoi.com)
