# Cpp Module 00

The first module of 42 school's C++ piscine is an introduction to C++ and Object-Oriented Programming. In these exercises, we learn the basics: namespaces, classes, construcors, initialization lists, destructors, public and private member and non-member variables and functions, static variables, the const keyword, strings, iomanip, std streams, etc.

## Status

Awaiting evaluation.

## Ex00 - Megaphone

For the first exercise, we must create a small program named "magaphone" that takes strings as parameters and outputs them in uppercase. This is an introduction to stdio
streams and the string class.

### Usage

Clone the repository and cd into `cpp00/ex00`. Compile with `make`. To run the program:

```
./megaphone "String" "to capitalize"
```

## Ex01 - PhoneBook

For the second exercise in the module, we must create a small phonebook program with the ability to add up to 8 contacts, search through them by index and display contact information (First name, last name, nickname, phone number, etc). The contacts are only saved for the duration of the program's execution, which makes this a pretty forgetful phonebook...
This is an introduction to class creation and management, string and iomanip.

### Usage

Clone the repository and `cd` into `cpp00/ex01`. Compile with `make`. To run the program:

```
./FMN-PhoneBook
```

Then, you can type `ADD` to add a contact, `SEARCH` to display saved contact list and select one to show the information for, `EXIT` to quit the program.

## Ex02 - Account.cpp

The third exercise provides us with a header and a test file, as well as an expected log file. The class file of this program is missing and we must recreate it to produce the same output as in the log file.
This is an introduction to `static` member variables and the const keyword.

### Usage

Clone the repository and `cd` into `cpp00/ex02`. Compile with `make`. To run the program:

```
./test-GBU
```

The output of the program must match the provided `.log` file, except the timestamps which will obviously be different. To easily compare the file and the output, we can remove the timestamps and save the output to new files:

```
./test-GBU > new.log
< new.log cut -d " " -f2 > new_no_timestamps.log
< 19920104_091532.log cut -d " " -f2 > old_no_timestamps.log
diff -s old_no_timestamps.log new_no_timestamps.log
```

---
Made by mcombeau: mcombeau@student.42.fr | LinkedIn: [mcombeau](https://www.linkedin.com/in/mia-combeau-86653420b/) | Website: [codequoi.com](https://www.codequoi.com)
