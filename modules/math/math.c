#include <math.h>
#include <stdlib.h>

// --- CORE ARITHMETIC ---
int gage_math_add(int a, int b) { return a + b; }
int gage_math_subtract(int a, int b) { return a - b; }
int gage_math_multiply(int a, int b) { return a * b; }
int gage_math_divide(int a, int b) { return b != 0 ? a / b : 0; }
int gage_math_modulo(int a, int b) { return b != 0 ? a % b : 0; }
int gage_math_absolute(int a) { return a < 0 ? -a : a; }
int gage_math_sign(int a) { return (a > 0) - (a < 0); }

// --- CONSTANTS (Scaled to 6 decimal places) ---
int gage_math_pi_scaled() { return 314159; }
int gage_math_e_scaled() { return 271828; }
int gage_math_tau_scaled() { return 628318; }
int gage_math_phi_scaled() { return 161803; }
int gage_math_sqrt2_scaled() { return 141421; }

// --- BOUNDS & LIMITS ---
int gage_math_min(int a, int b) { return a < b ? a : b; }
int gage_math_max(int a, int b) { return a > b ? a : b; }
int gage_math_clamp(int val, int min, int max) { return val < min ? min : (val > max ? max : val); }
int gage_math_wrap(int val, int min, int max) { int range = max - min + 1; return val < min ? max - ((min - val - 1) % range) : min + ((val - min) % range); }

// --- EXPONENTS & ROOTS ---
int gage_math_square(int a) { return a * a; }
int gage_math_cube(int a) { return a * a * a; }
int gage_math_pow(int base, int exp) { int res = 1; for(int i=0; i<exp; i++) res *= base; return res; }
int gage_math_sqrt(int a) { return a > 0 ? (int)sqrt(a) : 0; }
int gage_math_cbrt(int a) { return (int)cbrt(a); }
int gage_math_log2(int a) { int l = 0; while(a >>= 1) l++; return l; }
int gage_math_log10(int a) { return a > 0 ? (int)log10(a) : 0; }

// --- GEOMETRY & SPATIAL ---
int gage_math_hypotenuse(int a, int b) { return (int)sqrt(a*a + b*b); }
int gage_math_area_square(int side) { return side * side; }
int gage_math_area_rect(int w, int h) { return w * h; }
int gage_math_area_circle_scaled(int radius) { return (314159 * radius * radius) / 100000; }
int gage_math_perimeter_rect(int w, int h) { return 2 * (w + h); }
int gage_math_circumference_scaled(int radius) { return (2 * 314159 * radius) / 100000; }
int gage_math_distance_1d(int a, int b) { return gage_math_absolute(a - b); }
int gage_math_distance_2d(int x1, int y1, int x2, int y2) { return (int)sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1)); }
int gage_math_manhattan_distance(int x1, int y1, int x2, int y2) { return gage_math_absolute(x2-x1) + gage_math_absolute(y2-y1); }

// --- TRIGONOMETRY (Scaled inputs/outputs for integer limits) ---
int gage_math_sin_scaled(int deg) { return (int)(sin(deg * 3.14159 / 180.0) * 1000); }
int gage_math_cos_scaled(int deg) { return (int)(cos(deg * 3.14159 / 180.0) * 1000); }
int gage_math_tan_scaled(int deg) { return (int)(tan(deg * 3.14159 / 180.0) * 1000); }
int gage_math_deg_to_rad_scaled(int deg) { return (deg * 314159) / 180000; }
int gage_math_rad_to_deg_scaled(int rad_scaled) { return (rad_scaled * 180000) / 314159; }

// --- NUMBER THEORY & ALGORITHMS ---
int gage_math_is_even(int a) { return a % 2 == 0; }
int gage_math_is_odd(int a) { return a % 2 != 0; }
int gage_math_is_prime(int n) { if(n<=1)return 0; for(int i=2; i*i<=n; i++) if(n%i==0)return 0; return 1; }
int gage_math_is_perfect_square(int n) { if(n<0)return 0; int s = (int)sqrt(n); return s*s == n; }
int gage_math_is_power_of_two(int n) { return n > 0 && (n & (n - 1)) == 0; }
int gage_math_gcd(int a, int b) { while(b) { int t = b; b = a % b; a = t; } return a; }
int gage_math_lcm(int a, int b) { int g = gage_math_gcd(a, b); return g ? (a * b) / g : 0; }
int gage_math_factorial(int n) { int f = 1; for(int i=1; i<=n; i++) f *= i; return f; }
int gage_math_fibonacci(int n) { if(n<=1)return n; int a=0, b=1, c; for(int i=2; i<=n; i++) { c=a+b; a=b; b=c; } return b; }
int gage_math_sum_to_n(int n) { return (n * (n + 1)) / 2; }

// --- INTERPOLATION & MAPPING ---
int gage_math_lerp(int a, int b, int t_pct) { return a + ((b - a) * t_pct) / 100; }
int gage_math_map_range(int val, int in_min, int in_max, int out_min, int out_max) { 
    return (val - in_min) * (out_max - out_min) / (in_max - in_min) + out_min; 
}
int gage_math_percentage(int part, int total) { return total != 0 ? (part * 100) / total : 0; }
