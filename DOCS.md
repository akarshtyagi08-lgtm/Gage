# The Official Gage Language Guide

Welcome to Gage! This guide covers all the syntax, rules, and commands you need to write powerful scripts.

---

## 1. Terminal Commands
How to use Gage from your command line:

* **Run a script:** `gage filename.gg`
* **Check version:** `gage --version` or `gage -v`

---

## 2. Printing to the Console
Use the `print` keyword to output text or numbers. 
* **Strings** must be wrapped in double quotes `" "`.
* **Variables/Numbers** are printed directly without quotes.
* **Escape sequences:** Use `\n` for a new line and `\\` for a backslash.

    ```text
    print "Hello\nWorld"
    ```

---

## 3. Comments
Need to hide text? Use `||` at the start and end of your comments.

    ```text
    || This is a comment that the computer ignores ||
    print 100
    ```

---

## 4. Variables & Memory
Store data in RAM using the `let` keyword. 

    ```text
    let my_number = 50
    ```

---

## 5. Arrays (Initialization)
You can initialize arrays with square brackets.

    ```text
    let my_list = [1, 2, 3]
    ```

---

## 6. Mathematical Operations
Gage supports standard math parsing.
* **Addition:** `+`, **Subtraction:** `-`, **Multiplication:** `*`, **Division:** `/`

    ```text
    let result = 10 + 5
    ```

---

## 7. If-Else Conditions (Logic)
Make your code smart using `if` and `else` blocks. 

    ```text
    let age = 18
    if (age > 17) {
        print "Access Granted!"
    }
    ```

---

## 8. While Loops (Automation)
Repeat actions automatically until a condition becomes false.

    ```text
    while (count < 5) {
        print count
    }
    ```

---

## 9. User Input
Use the `input` keyword to get values from the user.
    
    ```text
    let x = input
    ```

---

### Syntax Rules to Remember
1.  **No semicolons:** Do not put `;` at the end of lines!
2.  **Case-sensitive:** `let X` and `let x` are different.
3.  **Variable limits:** Gage now supports UNLIMITED variables!
4.  **Mandatory extension:** All files must end with `.gg`.
o different variables.
3.  **Variable limits:** Gage currently supports up to 100 active variables per script to keep the language ultra-lightweight.
4.  **Mandatory extension:** All source files must end with the `.gg` extension.
