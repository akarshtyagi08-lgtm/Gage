# Gage Programming Language v3.3.3 Documentation
Welcome to the official documentation for Gage.

## Table of Contents
 1. Getting Started
 2. CLI Commands
 3. Variables & Constants
 4. Arithmetic & Math (Set 1)
 5. System Automation (Set 2)
 6. Game Dev & Graphics (Set 3)
 7. Control Flow
 8. Changelog (v3.3.3)

## 6. Game Dev & Graphics (Set 3)
Gage supports direct ANSI terminal manipulation for rendering games and animations:
 * **render "string"**: Draws output without a trailing newline.
 * **cursor(x, y)**: Moves the drawing cursor to a specific screen coordinate.
 * **color(code)**: Changes text color (e.g., 31=Red, 32=Green, 34=Blue, 0=Reset).
 * **delay(ms)**: Pauses execution for precise milliseconds (better than sleep).
 * **hide_cursor() / show_cursor()**: Toggles terminal cursor visibility.

## 8. Changelog (v3.3.3)
 * **Game Dev Suite (Set 3)**: Added terminal graphics Engine (`render`, `cursor`, `color`, `delay`, `hide_cursor`, `show_cursor`).
 * **Version Bump**: Updated all help menus and docs to v3.3.3.
