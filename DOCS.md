# Gage Programming Language v3.4.0 Documentation

## 1. Modules & Imports (Set 4)
You can now import standard library modules to unlock powerful features using `import module_name`.

*   **`import math`**:
    *   `sin(x)`, `cos(x)`, `tan(x)`: Trigonometry.
    *   `log(x)`: Logarithm.
    *   `ceil(x)`, `floor(x)`, `round(x)`: Advanced rounding.
*   **`import random`**:
    *   `randint(min, max)`: Get a random integer.
    *   `rand_float()`: Get a random decimal between 0 and 1.
    *   `seed_random()`: Resets the random seed based on time. (Auto-runs when imported).
*   **`import time`**:
    *   `timestamp()`: Returns current Unix time.
    *   `clock_ticks()`: Returns raw CPU ticks.
*   **`import os`**:
    *   `exit(code)`: Instantly kills the script.
    *   `get_env("VAR")`: Reads OS system variables.
*   **`import fs`**:
    *   `remove_file("name")`: Deletes a file.
    *   `rename_file("old", "new")`: Renames a file.
*   **`import string`**:
    *   `str_len("txt")`: Returns string length.
    *   `to_upper(c)` / `to_lower(c)`: Character case conversion.
*   **`import sys`**:
    *   `cpu_yield()`: Temporarily hands CPU priority to other apps.
*   **`import io`**:
    *   `flush_out()`: Forces terminal to draw instantly.
    *   `bell()`: Triggers the system notification sound.
*   **`import term`**:
    *   `reset_term()`: Clears all color/bold styling.
    *   `bold()`, `underline()`: Text formatting.
*   **`import net`**:
    *   `ping("url")`: Pings a website.

## Changelog (v3.4.0)
*   **The Module Engine**: Added the `import` keyword and 10 standard libraries encompassing 30 new macro-injected C-functions.
