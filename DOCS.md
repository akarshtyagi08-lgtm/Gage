# Gage Programming Language - Master Documentation (v3.4.1)

## 1. Introduction
Gage is a high-performance, C-inspired programming language built for efficiency and direct hardware control. Designed as a lightweight compiler, Gage translates your script into an intermediate C source code, which is then compiled using Clang.

## 2. Table of Contents
1. Installation & Environment Setup
2. Writing Your First Script
3. Variable Declaration (let)
4. Standard Output (print)
5. Mathematical Operations
6. Control Flow: While Loops
7. Control Flow: If/Else/Elif Statements
8. Control Flow: For Loops
9. System Interfacing (exec)
10. UI Control: Color and Clear
11. Cursor Management
12. Time Management (sleep/delay)
13. Modular Programming (import)
14. Advanced Compiler Features
15. Troubleshooting & FAQ

---

## 3. Installation & Environment Setup
Ensure your environment has Clang installed. Gage generates `.gm.c` and `.gt.c` files during compilation. Ensure these files have read/write permissions in your `/sdcard/GAGE/` directory.

## 4. Writing Your First Script
Create a file with the `.gg` extension (e.g., `test.gg`). 
- Syntax: `print 1`
- Execution: `gage test.gg`

## 5. Variable Declaration (let)
Gage uses `let` for defining integers.
- Syntax: `let variable_name = value`
- Example: `let score = 100`
- Rules: Names must be alphanumeric and can contain underscores.

## 6. Standard Output (print)
Outputs values to the terminal.
- Behavior: Every `print` call appends a newline (`\n`) automatically.
- Example: `print 50`

## 7. Mathematical Operations
Gage supports basic arithmetic operators:
- `+` : Addition
- `-` : Subtraction
- `*` : Multiplication
- `/` : Division
- `%` : Modulo

## 8. Control Flow: While Loops
Used for repeating blocks of code based on a condition.
- Syntax: 
  while (condition) {
      statement
  }

## 9. Control Flow: If/Else/Elif
Logic branches allow for conditional execution.
- Syntax:
  if (condition) {
      // code
  } elif (condition) {
      // code
  } else {
      // code
  }

## 10. Control Flow: For Loops
Ideal for iteration over ranges or animation frames. 

## 11. System Interfacing (exec)
Executes system commands.
- Syntax: `exec "command"`
- Example: `exec "clear"`

## 12. UI Control: Color and Clear
- `color [code]`: Changes terminal text color.
- `clear`: Wipes the console buffer.

## 13. Cursor Management
- `hide_cursor`: Makes the terminal cursor invisible.
- `show_cursor`: Resets the terminal cursor.
- `cursor`: Places the cursor at specific coordinates.

## 14. Time Management
- `delay [ms]`: Pause in milliseconds. Uses `usleep`.
- `sleep [s]`: Pause in seconds.

## 15. Modular Programming (import)
The modular system allows extending the core language.
- Structure: Place module files in `/sdcard/GAGE/modules/`.
- Usage: `import random`
- Implementation: The compiler reads `modules/[name].c` and injects code.

---

## 16. Advanced Features
- Tokenization: The compiler uses a custom tokenizer to handle `|` operators, string literals, and whitespace.
- Intermediate Files: The compiler generates `.gm.c` and `.gt.c` during the build process.

## 17. Troubleshooting & FAQ
- Q: My code isn't running? 
  A: Check for syntax errors in your `.gg` file. Ensure you are in the `/sdcard/GAGE` directory.
- Q: Why are modules not importing? 
  A: Ensure the file exists at `/sdcard/GAGE/modules/[name].c`.
- Q: How to check version? 
  A: Type `gage -v` or `gage --version`.

---
GitHub Repository: https://github.com/akarshtyagi08-lgtm/Gage
Note: Gage is an evolving language. Suggestions for new tokens or modules can be submitted via Pull Requests.
