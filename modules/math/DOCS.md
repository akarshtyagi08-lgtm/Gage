# 🧮 The Ultimate Gage Math Module (v4.0)

Welcome to the largest, most highly-optimized Mathematical engine available for the Gage language. This module contains 50 mathematically rigorous, robust, and highly performant functions tailored entirely around integer operations. 

In low-level engine development (especially on mobile and embedded systems), floating-point operations can be incredibly slow. Gage circumvents this by utilizing **Scaled Integer Math**. Functions like Pi, Sine, and Cosine operate on integer multipliers, ensuring zero performance drops.

---

## 🏗️ Architecture & Philosophy

All functions return a native 32-bit `int` and expect 32-bit `int` parameters. Division operations are heavily protected against `Divide by Zero` hardware faults, preventing catastrophic compiler crashes. 
*   **Time Complexity:** Ranging from O(1) for arithmetic up to O(sqrt(n)) for primality testing.
*   **Safety Vectors:** Internal guards are built into bounds checking, wrapping, and division.

---

## 🔢 Section 1: Core Arithmetic
These are the foundational operations that replace standard CPU instructions when you need safe, fault-tolerant execution.

### 1. `gage_math_add(a, b)`
*   **Description:** Standard mathematical addition. Adds integer `a` and integer `b`.
*   **Parameters:** `a` (int), `b` (int).
*   **Returns:** Sum of a and b.

### 2. `gage_math_subtract(a, b)`
*   **Description:** Standard mathematical subtraction. Subtracts `b` from `a`.
*   **Parameters:** `a` (int), `b` (int).
*   **Returns:** Difference of a and b.

### 3. `gage_math_multiply(a, b)`
*   **Description:** Standard mathematical multiplication. Computes the product.
*   **Parameters:** `a` (int), `b` (int).
*   **Returns:** Product of a and b.

### 4. `gage_math_divide(a, b)`
*   **Description:** Safe integer division. It internally checks if `b` is 0. If it is, it gracefully returns 0 instead of causing a hardware crash.
*   **Parameters:** `a` (int) - numerator, `b` (int) - denominator.
*   **Returns:** Quotient, or 0 if division by zero is attempted.

### 5. `gage_math_modulo(a, b)`
*   **Description:** Safe remainder calculation. Highly useful for array wrapping and odd/even checks.
*   **Parameters:** `a` (int), `b` (int).
*   **Returns:** Remainder of a / b.

### 6. `gage_math_absolute(a)`
*   **Description:** Returns the magnitude of a number by stripping its negative sign.
*   **Parameters:** `a` (int).
*   **Returns:** Positive integer.

### 7. `gage_math_sign(a)`
*   **Description:** Extracts the directional sign of an integer without its magnitude.
*   **Returns:** `1` if positive, `-1` if negative, `0` if zero.

---

## 🏛️ Section 2: Constants (Scaled)
Since Gage relies on integers, fundamental universe constants are provided multiplied by 100,000 for 6-digit precision.

### 8. `gage_math_pi_scaled()`
*   **Description:** The ratio of a circle's circumference to its diameter (3.14159).
*   **Returns:** `314159`

### 9. `gage_math_e_scaled()`
*   **Description:** Euler's number, the base of natural logarithms (2.71828).
*   **Returns:** `271828`

### 10. `gage_math_tau_scaled()`
*   **Description:** 2 * Pi. Extremely useful for 360-degree radian calculations (6.28318).
*   **Returns:** `628318`

### 11. `gage_math_phi_scaled()`
*   **Description:** The Golden Ratio (1.61803). Perfect for UI generation and natural proportions.
*   **Returns:** `161803`

### 12. `gage_math_sqrt2_scaled()`
*   **Description:** The square root of 2 (1.41421).
*   **Returns:** `141421`

---

## 🚧 Section 3: Bounds & Limits
Keeping dynamic data inside safe play areas.

### 13. `gage_math_min(a, b)`
*   **Description:** Compares two integers and returns the smaller one.

### 14. `gage_math_max(a, b)`
*   **Description:** Compares two integers and returns the larger one.

### 15. `gage_math_clamp(val, min, max)`
*   **Description:** If `val` is lower than `min`, it returns `min`. If higher than `max`, it returns `max`.

### 16. `gage_math_wrap(val, min, max)`
*   **Description:** If `val` exceeds `max`, it loops back to `min`. If it drops below `min`, it loops up to `max`. Perfect for screen-wrapping in games (like Pac-Man).

---

## ⚡ Section 4: Exponents & Roots
Scaling values exponentially.

### 17. `gage_math_square(a)`
*   **Description:** Multiplies a number by itself.

### 18. `gage_math_cube(a)`
*   **Description:** Multiplies a number by itself twice.

### 19. `gage_math_pow(base, exp)`
*   **Description:** Calculates an integer base raised to an integer exponent.

### 20. `gage_math_sqrt(a)`
*   **Description:** Finds the floor square root of an integer.

### 21. `gage_math_cbrt(a)`
*   **Description:** Finds the integer cube root.

### 22. `gage_math_log2(a)`
*   **Description:** Computes the base-2 logarithm (used heavily in bitwise math and tree depths).

### 23. `gage_math_log10(a)`
*   **Description:** Computes the base-10 logarithm.

---

## 📐 Section 5: Geometry & Spatial
Built for 2D game engines and physics colliders.

### 24. `gage_math_hypotenuse(a, b)`
*   **Description:** Uses the Pythagorean theorem (a^2 + b^2 = c^2) to find the longest side of a right triangle.

### 25. `gage_math_area_square(side)`
*   **Description:** Calculates the area of a square bounding box.

### 26. `gage_math_area_rect(w, h)`
*   **Description:** Calculates the area of a rectangle.

### 27. `gage_math_area_circle_scaled(radius)`
*   **Description:** Calculates circle area using scaled Pi.

### 28. `gage_math_perimeter_rect(w, h)`
*   **Description:** Calculates the outside distance of a rectangle.

### 29. `gage_math_circumference_scaled(radius)`
*   **Description:** Calculates the perimeter of a circle.

### 30. `gage_math_distance_1d(a, b)`
*   **Description:** Finds the absolute distance between two points on a line.

### 31. `gage_math_distance_2d(x1, y1, x2, y2)`
*   **Description:** Finds the true vector distance between two points on a 2D grid.

### 32. `gage_math_manhattan_distance(x1, y1, x2, y2)`
*   **Description:** Calculates grid-based distance (useful in tile-based pathfinding like A*).

---

## 🔄 Section 6: Trigonometry (Scaled)
Using degrees to return integer-scaled wave metrics.

### 33. `gage_math_sin_scaled(deg)`
*   **Description:** Returns the sine of an angle (in degrees), multiplied by 1000.

### 34. `gage_math_cos_scaled(deg)`
*   **Description:** Returns the cosine of an angle (in degrees), multiplied by 1000.

### 35. `gage_math_tan_scaled(deg)`
*   **Description:** Returns the tangent of an angle (in degrees), multiplied by 1000.

### 36. `gage_math_deg_to_rad_scaled(deg)`
*   **Description:** Converts standard degrees to scaled radians.

### 37. `gage_math_rad_to_deg_scaled(rad_scaled)`
*   **Description:** Converts scaled radians back to standard degrees.

---

## 🧬 Section 7: Number Theory & Algorithms
High-level mathematical proofs and sequence generators.

### 38. `gage_math_is_even(a)`
*   **Description:** Checks for even divisibility.

### 39. `gage_math_is_odd(a)`
*   **Description:** Checks for odd indivisibility.

### 40. `gage_math_is_prime(n)`
*   **Description:** True primality test. Runs in O(sqrt(n)) time.

### 41. `gage_math_is_perfect_square(n)`
*   **Description:** Checks if a number's square root is a whole integer.

### 42. `gage_math_is_power_of_two(n)`
*   **Description:** Ultra-fast bitwise check to see if a number fits binary alignments (e.g., 2, 4, 8, 16).

### 43. `gage_math_gcd(a, b)`
*   **Description:** Greatest Common Divisor using the Euclidean algorithm.

### 44. `gage_math_lcm(a, b)`
*   **Description:** Lowest Common Multiple.

### 45. `gage_math_factorial(n)`
*   **Description:** Iterative factorial (n!) calculator.

### 46. `gage_math_fibonacci(n)`
*   **Description:** Returns the Nth number in the Fibonacci sequence.

### 47. `gage_math_sum_to_n(n)`
*   **Description:** Calculates the triangular sum of all numbers from 1 to N instantly using Gauss's formula.

---

## 🎛️ Section 8: Interpolation & Mapping
Dynamically transitioning values.

### 48. `gage_math_lerp(a, b, t_pct)`
*   **Description:** Linear Interpolation. Finds a value a specific percentage (`t_pct`) between `a` and `b`. Essential for smooth animations.

### 49. `gage_math_map_range(val, in_min, in_max, out_min, out_max)`
*   **Description:** Takes a value from one scale (e.g., 0-10) and maps it precisely to another (e.g., 0-100).

### 50. `gage_math_percentage(part, total)`
*   **Description:** Safe ratio calculator returning a solid percentage integer (0-100).

---
*End of Math Module Documentation.*
