# Gage Programming Language v3.2.0 Documentation
Welcome to the official documentation for Gage, a high-performance, transpiled programming language designed for efficiency and ease of use.

## Table of Contents
 1. Introduction
 2. Getting Started
 3. Variables & Constants
 4. Arithmetic & Math Functions
 5. Control Flow
 6. Functions
 7. Changelog (v3.2.0)

## 1. Introduction
Gage is a lightweight, transpiled language that converts your code into C, allowing you to leverage the speed of the clang compiler while enjoying a simplified, intuitive syntax.

## 2. Getting Started
Gage requires a C compiler (like clang).
 * **File Extension**: All Gage files must end in `.gg`.
 * **Running a Script**: Use the command `gage script.gg`.
 * **Check Version**: Use the command `gage --version`.

## 3. Variables & Constants
 * **let**: Used to declare mutable variables. (`let count = 10`)
 * **const**: Used to declare immutable constants. (`const PI = 3.14`)

## 4. Arithmetic & Math Functions
Gage supports standard math operators and new built-in Set 1 Math functions.
 * **Basic Math**: `+`, `-`, `*`, `/`
 * **Power (`**`)**: Exponents (`print 2 ** 3`)
 * **Modulo Assignment (`%=`)**: Remainder assignment (`x %= 3`)
 * **Functions**: `sqrt(x)`, `abs(x)`, `max(a, b)`, `min(a, b)`

## 5. Control Flow
 * **If/Else/Elif**: Standard conditional branching.
 * **While Loops**: Repeated execution based on conditions.
 * **For Loops**: Counter-based iterations.

## 7. Changelog (v3.2.0)
 * **New Math Suite (Set 1)**: Added native support for `sqrt()`, `abs()`, `max()`, and `min()`.
 * **Version Fix**: The `gage --version` and `gage -v` commands are now fully operational.
 * **Performance**: Optimized expression parsing to prevent token collision during variable assignment.
