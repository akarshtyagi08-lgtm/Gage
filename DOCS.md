# Gage Programming Language v3.3.4 - Complete Master Documentation

Welcome to the ultimate documentation for Gage. This document covers every single detail, syntax rule, and feature currently supported by the compiler.

---

## 1. Getting Started
Gage requires a C compiler (like `clang`) to run because it transpiles your scripts directly into native C code for maximum speed.
* **File Extension:** Your files MUST end in `.gg` (e.g., `game.gg`).
* **Execution:** Run your scripts in the terminal by typing `gage game.gg`.

## 2. CLI Commands
The terminal interface for Gage includes built-in tools:
* `gage --version` : Prints the current compiler version.
* `gage help` : Prints a highly detailed cheat sheet of every command directly in your terminal.

---

## 3. Core Variables & Data
Gage handles numbers seamlessly, automatically detecting if you mean integers or floats.
* **`let` (Mutable Variables):** Variables that can be updated later.
  * *Example:* `let hp = 100` -> `hp -= 20`
* **`const` (Immutable Constants):** Variables that are locked forever. Great for strict logic.
  * *Example:* `const GRAVITY = 9.8`

---

## 4. Arithmetic & Math (Set 1)
Gage supports advanced math natively, transpiling directly to C's `<math.h>` for lightning speed.
* **Basic Operators:** `+` (Add), `-` (Subtract), `*` (Multiply), `/` (Divide)
* **Modulo (`%`):** Finds the remainder. (e.g., `10 % 3` returns `1`)
* **Power (`**`):** Exponents. (e.g., `2 ** 3` returns `8`)
* **Assignment Shortcuts:** `+=`, `-=`, `*=`, `/=`, `%=`
* **Math Functions:**
  * `sqrt(number)`: Returns the square root. (e.g., `print(sqrt(144))` -> 12)
  * `abs(number)`: Converts negative to positive. (e.g., `print(abs(-50))` -> 50)
  * `max(a, b)`: Returns the larger of two numbers.
  * `min(a, b)`: Returns the smaller of two numbers.

---

## 5. System Automation (Set 2)
You can control your entire operating system (Linux/Termux) using Gage.
* **`exec("command")`**: Runs a shell command. 
  * *Example:* `exec("mkdir secret_folder")` or `exec("ls -l")`
* **`sleep(seconds)`**: Freezes the script completely for X seconds.
  * *Example:* `sleep(2)`
* **`clear()`**: Instantly clears the terminal screen.

---

## 6. Game Dev & Graphics Engine (Set 3)
Gage turns your terminal into a canvas using ANSI escape codes. Perfect for rendering 2D games and animations.
* **`render`**: Works exactly like `print`, but it **does not** create a new line. Essential for drawing side-by-side text.
  * *Example:* `render "###"`
* **`cursor(x, y)`**: Moves your drawing pen to a specific column (x) and row (y) on the terminal screen.
  * *Example:* `cursor(10, 5)` (Moves to column 10, row 5)
* **`color(code)`**: Changes the color of anything rendered after it.
  * *Example:* `color(31)` (Red), `color(32)` (Green), `color(34)` (Blue), `color(0)` (Reset to default white)
* **`delay(milliseconds)`**: A high-precision timer. Use this instead of `sleep()` for 60FPS game loops. 1000ms = 1 second.
  * *Example:* `delay(16)` (Delays for 16 milliseconds)
* **`hide_cursor()`**: Makes the blinking terminal cursor invisible.
* **`show_cursor()`**: Brings the blinking cursor back. ALWAYS run this before your script exits!

---

## 7. Control Flow
Control how your program makes decisions.
* **`while` Loops:** Repeats code as long as a condition is true. Parentheses and braces are required!
  * *Example:*
    ```
    let i = 0
    while (i < 10) {
        print i
        i += 1
    }
    ```

---

## 8. Changelog (v3.3.4)
* **Massive Documentation Overhaul:** Restored all missing sections and added extensive, detailed examples for every single syntax rule.
* **Help Menu Expansion:** `gage help` now provides a massive, formatted cheat sheet inside the terminal.
* **SD Card Synchronization Support:** Files are now safely mirrored to `/sdcard/GAGE` for external viewing.
