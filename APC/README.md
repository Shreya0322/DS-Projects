# Arbitrary Precision Calculator (APC)
## Description

The Arbitrary Precision Calculator (APC) is a C programming project that performs basic arithmetic operations on integers of arbitrary length, allowing calculations on numbers that exceed the storage capacity of built-in data types such as int and long int.
The project represents large integers using a Doubly Linked List (DLL), where each node stores a portion of the number. By using dynamic memory allocation and pointer manipulation, the calculator efficiently performs arithmetic operations on very large numbers.

## Features
- Supports integers of arbitrary length.
- Performs addition (+), subtraction (-), multiplication (*), and division (/).
- Uses a Doubly Linked List for efficient storage and processing of large numbers.
- Dynamically allocates memory based on the size of the input numbers.
- Handles numbers larger than the range of built-in C data types.

## Technologies Used
- C Programming
- Doubly Linked List
- Dynamic Memory Allocation
- Pointers
- Command-Line Arguments

## Compilation
Compile all source files using: gcc *.c
Execution

## Run the program using:
./a.out <operand1> '<operator>' <operand2>

## Example
./a.out 123456789123456789123456789 '+' 987654321987654321987654321

## Project Workflow
- Accept two operands and an arithmetic operator as command-line arguments.
- Store each operand as a Doubly Linked List.
- Perform the requested arithmetic operation.
- Display the computed result.
