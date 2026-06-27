# Gage Programming Language v3.1.1 Documentation
Welcome to the official documentation for Gage, a high-performance, transpiled programming language designed for efficiency and ease of use.
## Table of Contents
 1. Introduction
 2. Getting Started
 3. Variables & Constants
 4. Arithmetic & Power Operators
 5. Control Flow
 6. Functions
 7. Changelog (v3.1.1)
## 1. Introduction
Gage is a lightweight, transpiled language that converts your code into C, allowing you to leverage the speed of the clang compiler while enjoying a simplified, intuitive syntax. Whether you are building small scripts or complex tools, Gage provides the foundation to get your ideas running fast.
## 2. Getting Started
Gage requires a C compiler (like clang) to transform your .gg files into executable binaries.
 * **File Extension**: All Gage files must end in .gg.
 * **Running a Script**: Use the gage command followed by your filename: gage script.gg.
## 3. Variables & Constants
Gage supports both mutable variables and immutable constants.
 * **let**: Used to declare mutable variables.
   * *Example*: let count = 10
 * **const**: Used to declare immutable constants that cannot be changed after assignment.
   * *Example*: const PI = 3.14
## 4. Arithmetic & Power Operators
Gage provides standard math operators, including enhanced support for exponentiation and modulo assignment.
 * **Addition (+), Subtraction (-), Multiplication (*), Division (/)**: Standard arithmetic.
 * **Power (**)**: Used for calculating exponents.
   * *Example*: print 2 ** 3 (Result: 8)
 * **Modulo Assignment (%=)**: Calculates the remainder of a division and assigns it back to the variable.
   * *Example*: let x = 10; x %= 3 (x becomes 1)
## 5. Control Flow
Gage supports robust conditional logic to handle complex application flow.
 * **If/Else/Elif**: Standard conditional branching.
 * **While Loops**: Repeated execution based on conditions.
 * **For Loops**: Counter-based iterations.
 * **Switch/Case**: Multi-way branching for cleaner logic trees.
## 6. Functions
Gage supports procedural functions, allowing you to modularize your code.
 * **Declaration**: Use fn followed by the function name and parameters.
 * **Return**: Use return to pass values back from functions.
## 7. Changelog (v3.1.1)
The v3.1.1 update focuses on mathematical power and data integrity:
 * **New const keyword**: Added support for immutable constant variables.
 * **New ** operator**: Added native exponentiation support using pow() from math.h.
 * **New %= operator**: Added modulo assignment support.