# Cpp Module 02
The third module of the 42 c++ piscine explores the concepts of ad-hoc polymorphism, operator overloading and the Orthodox Canonical class form.

## Status
Validated 15/12/2022. Grade: 90% (error on ex03)

## Ex00 - Fixed Class
Because floating point types lack accuracy and can be slow, we must implement a new class for Fixed point numbers. This exercise is an introduction to the Orthodox Canonical form, in which a class should have a default constructor, a copy constructor, a destructor and an assignment operator overload.

### Usage
Clone this repository and `cd` into `cpp02/ex00`. Then `make` to compile. Run the program with:

```
./fixed
```

The output shows the sequence of calls to constructors, destructors, assignment operators and getters.

## Ex01 - A More Useful Fixed Class
This exercise builds on the previous one. Now we must add an output stream overload to the class, as well as new constructors from int and float and member functions able to translate a Fixed number into an integer or a float.

### Usage
Clone this repository and `cd` into `cpp02/ex01`. Then `make` to compile. Run the program with:

```
./fixed
```

## Ex02 - Overload Madness
The third exercise, again, builds on the previous one. Now we must implement overloads for all operators (comparison < > <= >= == !=, binary + - * /, unary prefix++ ++postfix prefix-- postfix--) as well as regular and const versions of functions that return the largest or smallest of two fixed numbers.

### Usage
Clone this repository and `cd` into `cpp02/ex02`. Then `make` to compile. Run the program with:

```
./fixed
```

## Ex03 - BSP
At the module's summit, we must implement a new class, Point, which makes use of the Fixed class from the previous exercise. We must also implement a function, bsp, which can determine whether a Point is inside a triangle or not.

### Usage
Clone this repository and `cd` into `cpp02/ex03`. Then `make` to compile. Run the program with:

```
./bsp
```

Check the results on [GeoGebra](https://www.geogebra.org/calculator) (the triangles tested are provided in the `cpp02/ex03/geogebra` folder).

---
Made by mcombeau: mcombeau@student.42.fr | LinkedIn: [mcombeau](https://www.linkedin.com/in/mia-combeau-86653420b/) | Website: [codequoi.com](https://www.codequoi.com)
