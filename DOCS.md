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

    ```text
    print "Hello, World!"
    print 100
    ```

---

## 3. Variables & Memory
Store data in RAM using the `let` keyword. Variable names must start with a letter.

    ```text
    let my_number = 50
    let score = 100
    print my_number
    ```

---

## 4. Mathematical Operations
Gage supports standard math parsing. You can mix numbers and variables!
* **Addition:** `+`
* **Subtraction:** `-`
* **Multiplication:** `*`
* **Division:** `/`

    ```text
    let x = 10
    let y = 5
    let result = x + y * 2
    print result
    ```

---

## 5. If-Else Conditions (Logic)
Make your code smart using `if` and `else` blocks. 
* **Supported checks:** `==` (Equal), `>` (Greater than), `<` (Less than).
* **Note:** Always use `{` and `}` for your code blocks!

    ```text
    let age = 18

    if (age > 17) {
        print "Access Granted!"
    } else {
        print "Access Denied!"
    }
    ```

---

## 6. While Loops (Automation)
Repeat actions automatically until a condition becomes false.

    ```text
    let count = 1

    while (count < 5) {
        print count
        let count = count + 1
    }

    print "Loop finished!"
    ```

---

### Syntax Rules to Remember
1.  **No semicolons needed:** Do not put `;` at the end of lines!
2.  **Case-sensitive:** `let X` and `let x` are treated as two different variables.
3.  **Variable limits:** Gage currently supports up to 100 active variables per script to keep the language ultra-lightweight.
