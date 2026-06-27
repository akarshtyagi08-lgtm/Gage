# Gage Programming Language v3.3.2 Documentation
Welcome to the official documentation for Gage.

## Table of Contents
 1. Getting Started
 2. CLI Commands
 3. Variables & Constants
 4. Arithmetic & Math (Set 1)
 5. System Automation (Set 2)
 6. Control Flow
 7. Changelog (v3.3.2)

## 5. System Automation (Set 2)
Gage supports direct interaction with the OS shell:
 * **exec("command")**: Executes a terminal command. (e.g., `exec("ls -l")`)
 * **sleep(seconds)**: Pauses script execution. (e.g., `sleep(2)`)
 * **clear()**: Clears the terminal screen.

## 7. Changelog (v3.3.2)
 * **Version Alignment**: Version bumped to 3.3.2 across the compiler binary, help menu, and documentation.
 * **System Suite (Set 2)**: Fully operational `exec`, `sleep`, and `clear`.
 * **Bracket Hotfix**: Solved parameter nesting bugs for cleaner expression boundaries.
