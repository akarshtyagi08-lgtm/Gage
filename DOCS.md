# Gage Programming Language - Official Technical Manual (v3.4.1)

**Developer:** Akarsh Tyagi
**Contact:** akarshtyagi08@gmail.com
**Repository:** https://github.com/akarshtyagi08-lgtm/Gage

---

## 1. Introduction
Gage is a high-performance, C-inspired programming language built for efficiency and direct hardware control. It operates as a source-to-source compiler: it reads your `.gg` (Gage) script, generates intermediate C code (`.gm.c` and `.gt.c`), and uses `clang` to produce a binary executable (`.ge`). This ensures your scripts run with native C-like speed.

## 2. Environment Setup
- **Requirements**: Clang compiler installed in Termux.
- **Directory Structure**: Always work within `/sdcard/GAGE/` to ensure full sync capabilities between your terminal and file manager.
- **File Extensions**: Use `.gg` for your source scripts.
- **Modules**: Keep all external C files in the `modules/` folder.

## 3. Detailed Language Reference

### 3.1 Variable Declaration: `let`
- **Purpose**: Initializes an integer variable. Gage enforces strict integer typing.
- **Syntax**: `let [variable_name] = [integer_value]`
- **Example**: `let score = 100`
- **Detailed Rules**: 
    - Variable names must be alphanumeric and cannot start with numbers.
    - Reserved keywords (print, while, let, if, else, etc.) cannot be used as names.
    - If you try to declare a variable that already exists, the linter may throw an error.

### 3.2 Output: `print`
- **Purpose**: Displays an integer in the terminal.
- **Syntax**: `print [variable_or_integer]`
- **Behavior**: Every `print` command automatically adds a newline character (`\n`) to the output.
- **Note**: You do not need to manually manage string formatting or newlines for basic output.

### 3.3 Control Flow: `while`
- **Purpose**: Execute a block of code repeatedly while the condition is true.
- **Syntax**: 

  while ([condition]) {
      [statement_1]
      [statement_2]
  }

 * **Tip**: Ensure your loop condition eventually becomes false to avoid infinite loops.
### 3.4 Logical Branching: if, elif, else
 * **Purpose**: Control program flow based on conditions.
 * **Supported Operators**: == (Equal), != (Not Equal), > (Greater), < (Less).
 * **Syntax**:
   if (x == 10) { print 1 }
   elif (x == 5) { print 0 }
   else { print 9 }
### 3.5 System Interface: exec
 * **Purpose**: Execute native shell commands from within your Gage script.
 * **Syntax**: exec "[shell_command]"
 * **Example**: exec "clear" or exec "ls -la".
 * **Warning**: Be careful executing commands that might block execution indefinitely.
### 3.6 UI Controls & Terminal Rendering
 * **color [code]**: Sets the terminal text color using ANSI integer codes (e.g., color 31 for red, color 32 for green).
 * **clear**: Wipes the current terminal screen buffer, giving you a fresh canvas.
 * **hide_cursor**: Hides the blinking terminal cursor for a cleaner UI.
 * **show_cursor**: Restores the terminal blinking cursor.
 * **delay [ms]**: Pauses script execution for the specified milliseconds using usleep. Use this for animation frames.
 * **sleep [s]**: Pauses script execution for the specified number of seconds.
## 4. The Modular System (import)
Modular programming keeps your main script clean and readable.
 * **Setup**: Create a folder named modules/ in your root (/sdcard/GAGE/modules/).
 * **Creating a Module**:
   1. Create a file in modules/, e.g., modules/random.c.
   2. Write your C logic (e.g., srand(time(NULL));).
 * **Importing**:
   * Usage: import [name]
   * Example: import random
 * **Mechanism**: The compiler scans your import statement, locates /sdcard/GAGE/modules/[name].c, reads it, and injects that content directly into the translated C code before the final compilation step.
## 5. Error Handling & The Gage Linter
Gage's internal linter performs static analysis on your code.
 * **Syntax Error**: Triggered if you miss braces {} or parentheses () in your loops or conditions.
 * **Linter Error**: Triggered if you attempt to use an undeclared variable. The compiler will stop and report: [Gage Linter Error] Variable not found: [var_name].
 * **Module Error**: Triggered if you import [name] but the file modules/[name].c does not exist in the designated directory.
 * **Clang/Compiler Error**: If the intermediate C translation is logically invalid (e.g., C syntax errors), the Clang compiler will stop and provide a C-level error report. Check .gt.c for specific C-level issues.
## 6. Frequently Asked Questions (FAQ)
**Q: Do I need \n for a new line?**
A: No. Every print command includes a newline by default.
**Q: Where should my module files go?**
A: Always in the /sdcard/GAGE/modules/ directory.
**Q: Why is my script failing?**
A: Double-check that you are in the /sdcard/GAGE directory, check your file extension (must be .gg), and verify that all variables used are defined with let at the top of the file.
**Q: How do I verify my Gage version?**
A: Type gage -v or gage --version in your terminal.
## 7. Best Practices
 1. **Initialize first**: Always declare variables using let before using them in loops.
 2. **Module hygiene**: Delete unused .c files in modules/ to prevent accidentally injecting old code.
 3. **Cleanliness**: Use the clear command at the very start of scripts that render UI components.
 4. **Debugging**: If your Gage logic behaves unexpectedly, check the generated .gm.c file to see how it was translated.
 5. **Naming**: Use descriptive variable names (e.g., let frameCounter = 1) to help with debugging.
 6. **Collaboration**: If you find a bug, email the logs to akarshtyagi08@gmail.com.
EOF
