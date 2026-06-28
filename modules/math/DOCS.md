# 🧮 Advanced Math Module Documentation

The `math` module supplies 30 high-performance arithmetic, geometric, algebraic, and algorithmic formula processors directly inside the Gage engine pipeline.

## Complete Feature Matrix

| Feature Function | Parameters | Return Value | Functional Purpose & Math Context |
| :--- | :--- | :--- | :--- |
| `gage_math_get_pi_scaled()` | None | `314159` | Returns Pi scaled up to 6 decimal precision scales avoiding floating constraints. |
| `gage_math_get_e_scaled()` | None | `271828` | Returns Euler's scale parameter constant representation tracking data. |
| `gage_math_add(a, b)` | `a`, `b` (Int) | `a + b` | Fast low-level arithmetic summation node. |
| `gage_math_subtract(a, b)` | `a`, `b` (Int) | `a - b` | Standard algebraic difference operator structure. |
| `gage_math_multiply(a, b)` | `a`, `b` (Int) | `a * b` | Traditional algebraic cross product parsing step. |
| `gage_math_divide(a, b)` | `a`, `b` (Int) | Divided ratio| Computes integer division with built-in zero error protections. |
| `gage_math_modulo(a, b)` | `a`, `b` (Int) | Remainder | Computes division remainders for cyclical logic systems. |
| `gage_math_power(b, e)` | `base`, `exp` | `base^exp` | Computes fast value variable power calculations via engine limits. |
| `gage_math_square_root(n)`| `n` (Int) | Square root | Returns base integer component floor square root transformations. |
| `gage_math_cube_root(n)` | `n` (Int) | Cube root | Evaluates integer cube root properties cleanly. |
| `gage_math_absolute(n)` | `n` (Int) | Magnitude | Strips out numerical sign bits to evaluate structural distance scales. |
| `gage_math_max(a, b)` | `a`, `b` (Int) | Max item | Compares items to extract upper bounded limits definitions. |
| `gage_math_min(a, b)` | `a`, `b` (Int) | Min item | Compares items to extract lower bounded limits definitions. |
| `gage_math_hypotenuse(a,b)`| `a`, `b` (Int) | Hypotenuse | Evaluates structural distance layouts for graphics plotting mechanics. |
| `gage_math_factorial(n)` | `n` (Int) | Factorial scale| Evaluates strict sequential compounding multiplication limits. |
| `gage_math_is_even(n)` | `n` (Int) | `0` or `1` | Fast checking flag verifying division capabilities by factor 2. |
| `gage_math_is_odd(n)` | `n` (Int) | `0` or `1` | Fast checking flag verifying alternate numerical coordinate balance. |
| `gage_math_is_prime(n)` | `n` (Int) | `0` or `1` | Implements primality factor testing for data distribution arrays. |
| `gage_math_gcd(a, b)` | `a`, `b` (Int) | Great Divisor | Implements Euclidean reduction to extract common denominators. |
| `gage_math_lcm(a, b)` | `a`, `b` (Int) | Multiple scale| Computes matching common multiplication timeline intersections. |
| `gage_math_clamp(n,min,max)`| Value, bounds | Clamped value | Wraps out-of-bounds metrics fields straight into safe target caps. |
| `gage_math_degrees_to_rad_scaled()`| Degrees | Radians scale| Converts rotational geometry systems angles safely down. |
| `gage_math_radians_to_deg_scaled()`| Radians | Degrees scale| Restores radians calculations directly back into angles tracking format. |
| `gage_math_average_two(a,b)`| `a`, `b` (Int) | Midpoint scale| Computes structural mid-points between distinct metric arrays. |
| `gage_math_percentage_of()`| Ratio points | Percentage Int| Evaluates proportions maps values scaled directly to a factor of 100. |
| `gage_math_fibonacci(n)` | `n` (Int) | Sequence Int | Iterates structural natural growth sequences safely up to limits. |
| `gage_math_is_square(n)` | `n` (Int) | `0` or `1` | Validates perfect integer dimension root squaring consistency. |
| `gage_math_log_base2(n)` | `n` (Int) | Shift factor | Evaluates raw power structural logarithmic scaling indicators. |
| `gage_math_area_square(s)` | `side` (Int) | Total Area | Calculates space metrics capacities bounds for grid tracking squares. |
| `gage_math_perimeter_square(s)`| `side` (Int) | Boundary scale| Evaluates perimeter tracking outlines distances maps elements. |
