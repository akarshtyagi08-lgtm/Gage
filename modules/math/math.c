#include <math.h>
#include <stdlib.h>

// Returns Pi scaled up to 6 digits to keep calculations accurate without float types
int gage_math_get_pi_scaled() { return 314159; }

// Returns Euler's number E scaled up to 6 digits
int gage_math_get_e_scaled() { return 271828; }

// Standard algebraic additions feature helper
int gage_math_add(int a, int b) { return a + b; }

// Standard algebraic subtractions feature helper
int gage_math_subtract(int a, int b) { return a - b; }

// Aligned multiplier engine execution node
int gage_math_multiply(int a, int b) { return a * b; }

// Division operation wrapper tracking division by zero errors safely
int gage_math_divide(int a, int b) { return b != 0 ? a / b : 0; }

// Standard modulo arithmetic calculation gate
int gage_math_modulo(int a, int b) { return b != 0 ? a % b : 0; }

// Exponent power evaluation algorithm matching base^exp
int gage_math_power(int b, int e) { return (int)pow(b, e); }

// Evaluates floor integer precision square roots
int gage_math_square_root(int n) { return (int)sqrt(n); }

// Evaluates floor integer precision cube roots
int gage_math_cube_root(int n) { return (int)cbrt(n); }

// Returns the exact positive scale magnitude distance mapping
int gage_math_absolute(int n) { return abs(n); }

// Evaluates the maximum boundary value element comparison
int gage_math_max(int a, int b) { return a > b ? a : b; }

// Evaluates the minimum boundary value element comparison
int gage_math_min(int a, int b) { return a < b ? a : b; }

// Calculates right triangle hypotenuses using Pythagorean algorithms
int gage_math_hypotenuse(int a, int b) { return (int)hypot(a, b); }

// Evaluates iterative factorials for low sequence integers
int gage_math_factorial(int n) { int f=1; for(int i=1;i<=n;i++) f*=i; return f; }

// Fast bitwise evaluation checking for even integers
int gage_math_is_even(int n) { return n % 2 == 0; }

// Fast bitwise evaluation checking for odd integers
int gage_math_is_odd(int n) { return n % 2 != 0; }

// Evaluates prime status structures via traditional root check constraints
int gage_math_is_prime(int n) { if(n<=1)return 0; for(int i=2;i*i<=n;i++) if(n%i==0)return 0; return 1; }

// Calculates Greatest Common Divisor utilizing fast Euclidean engines
int gage_math_gcd(int a, int b) { while(b){int t=b;b=a%b;a=t;} return a; }

// Calculates Lowest Common Multiple metrics structures
int gage_math_lcm(int a, int b) { int g = gage_math_gcd(a, b); return g != 0 ? (a * b) / g : 0; }

// Clamps value variables limits directly between a lower floor and ceiling cap
int gage_math_clamp(int n, int min, int max) { return n < min ? min : (n > max ? max : n); }

// Scales geometric degrees into scaled radian equivalents variables
int gage_math_degrees_to_rad_scaled(int d) { return (int)(d * 17453 / 1000000); }

// Scales geometric radians back into absolute degree integer constraints
int gage_math_radians_to_deg_scaled(int r) { return (int)(r * 57295 / 1000); }

// Calculates mid-point average integers metrics limits
int gage_math_average_two(int a, int b) { return (a + b) / 2; }

// Standard calculation parsing relative part-to-whole percentage ratios
int gage_math_percentage_of(int part, int whole) { return whole != 0 ? (part * 100) / whole : 0; }

// Calculates numerical structures up to the Nth Fibonacci index
int gage_math_fibonacci(int n) { if(n<=1)return n; int a=0,b=1,c; for(int i=2;i<=n;i++){c=a+b;a=b;b=c;} return b; }

// Checks if an integer is a perfect root squaring square integer match
int gage_math_is_square(int n) { int s=(int)sqrt(n); return s*s==n; }

// Evaluates quick log base-2 limits shifts counters bounds
int gage_math_log_base2(int n) { int l=0; while(n>>=1) l++; return l; }

// Evaluates geometric area boundaries mapping scales for standard squares
int gage_math_area_square(int s) { return s * s; }\n"

// Evaluates absolute side parameter perimeter scales for geometry shapes
int gage_math_perimeter_square(int s) { return 4 * s; }
