# Cpp Module 09

This module of 42 school's C++ piscine explores STL containers, iterators, and algorithms. The use of STL is mandatory in this module. Each exercise requires the use of one or more container types, which cannot be reused for the following exercises in the module.

## Status
Validated 20/06/2023. Grade: 100%.

## Ex00 - Bitcoin Exchange
In the first exercise, we are provided with a CSV file containing a historical list of exchange rates for bitcoin. An input file contains a list of dates paried with a number of bitcoin, and for each, we must output the total value of the bitcoins at that date, based on the historical data. In this exercise, I chose to use an `std::map` to pair dates converted to Epoch `time_t` and values.

### Usage
Clone this repository and `cd` into `cpp09/ex00`. Then `make` to compile. Run the program with:

```
./btc <input.txt>
```

The output shows the resulting bitcoin values for each line in the input file.

## Ex01 - RPN
In the second exercise, we must implement a Reverse Polish Notation calculator. Because Reverse Polish Notation was designed for use with stacks, an `std::stack` was the obvious choice. An RPN calculation looks like this: `2 3 +`. Each operand (2 and 3 in the example) is pushed to a stack. When we encounter an operator (here, +), the last two operands are popped from the stack, the operation is performed, and the result is pushed back onto the stack.

### Usage
Clone this repository and `cd` into `cpp09/ex02`. Then `make` to compile. Run the program with:

```
./RPN <Reverse_Polish_Notation_expression>
```

Spaces do not matter in the RPN expression, each digit is treated as a separate number. The two following notations are equivalent:

```
./RPN "2 3 + 1 -"
./RPN 23+1-
```

The ouput shows the result of the operation.

## Ex02 - PmergeMe

The third exercise requires us to implement a Ford-Johnson merge-insertion sort algorithm using two distinct containers to compare the time it takes each to perform the same task. I chose the classic `std::vector` vs `std::list` for this.

### Usage

Clone this repository and `cd` into `cpp09/ex02`. Then `make` to compile. Run the program with:

```
./PmergeMe <numbers_to_sort>
./PmergeMe 9 3 1 15 6 30 8 7 11
```

To test with a randomly generated set of 3000 numbers:

```
./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`
```

The output displays the numbers sorted with a vector and a list, as well as the number of clock cycles each sort took to complete.

---
Made by mcombeau: mcombeau@student.42.fr | LinkedIn: [mcombeau](https://www.linkedin.com/in/mia-combeau-86653420b/) | Website: [codequoi.com](https://www.codequoi.com)
