# Cpp Module 06

This module of 42 school's C++ piscine is an introduction to the different C++ casts.

## Status
Validated 02/01/2023. Grade: 100%.

## Ex00 - Scalar Type Conversion
In the first exercise, we must create a program able to static cast a given literal from one scalar type (char, int, float or double) to each of the 3 others.

### Usage
Clone this repository and `cd` into `cpp06/ex00`. Then `make` to compile. Run the program with:

```
./convert_scalar <char>
./convert_scalar <int>
./convert_scalar <float>f
./convert_scalar <double>
./convert_scalar <inf, inff, -inf, -inff, or nan>
```
The output shows the results of the conversion to each of the types. (Note that floats and double must both contain a floating point, and floats must be indicated with a trailling 'f').

## Ex01 - Serialization
In the second exercise, we must create a simple program able to serialize and deserialize a pointer to a class instance thanks to a reinsterpret cast.

### Usage
Clone this repository and `cd` into `cpp06/ex01`. Then `make` to compile. Run the program with:

```
./serializer
```

## Ex02 - Identify
The third exercise asks us to create a program which randomly instantiates one of three derived classes as their parent base class pointer. Then, the program must be able to identify which of the three derived classes the pointer points to, using dynamic casting. It must also be able to identify the class by reference instead of by pointer.

### Usage
Clone this repository and `cd` into `cpp06/ex02`. Then `make` to compile. Run the program with:

```
./identifier
```

---
Made by mcombeau: mcombeau@student.42.fr | LinkedIn: [mcombeau](https://www.linkedin.com/in/mia-combeau-86653420b/) | Website: [codequoi.com](https://www.codequoi.com)
