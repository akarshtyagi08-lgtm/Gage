#include <math.h>
#include <stdlib.h>

int gage_math_get_pi_scaled() { return 314159; }
int gage_math_get_e_scaled() { return 271828; }
int gage_math_add(int a, int b) { return a + b; }
int gage_math_subtract(int a, int b) { return a - b; }
int gage_math_multiply(int a, int b) { return a * b; }
int gage_math_divide(int a, int b) { return b != 0 ? a / b : 0; }
int gage_math_modulo(int a, int b) { return b != 0 ? a % b : 0; }
int gage_math_power(int b, int e) { return (int)pow(b, e); }
int gage_math_square_root(int n) { return (int)sqrt(n); }
int gage_math_cube_root(int n) { return (int)cbrt(n); }
int gage_math_absolute(int n) { return abs(n); }
int gage_math_max(int a, int b) { return a > b ? a : b; }
int gage_math_min(int a, int b) { return a < b ? a : b; }
int gage_math_hypotenuse(int a, int b) { return (int)hypot(a, b); }
int gage_math_factorial(int n) { int f=1; for(int i=1;i<=n;i++) f*=i; return f; }
int gage_math_is_even(int n) { return n % 2 == 0; }
int gage_math_is_odd(int n) { return n % 2 != 0; }
int gage_math_is_prime(int n) { if(n<=1)return 0; for(int i=2;i*i<=n;i++) if(n%i==0)return 0; return 1; }
int gage_math_gcd(int a, int b) { while(b){int t=b;b=a%b;a=t;} return a; }
int gage_math_lcm(int a, int b) { int g = gage_math_gcd(a, b); return g != 0 ? (a * b) / g : 0; }
int gage_math_clamp(int n, int min, int max) { return n < min ? min : (n > max ? max : n); }
int gage_math_degrees_to_rad_scaled(int d) { return (int)(d * 17453 / 1000000); }
int gage_math_radians_to_deg_scaled(int r) { return (int)(r * 57295 / 1000); }
int gage_math_average_two(int a, int b) { return (a + b) / 2; }
int gage_math_percentage_of(int part, int whole) { return whole != 0 ? (part * 100) / whole : 0; }
int gage_math_fibonacci(int n) { if(n<=1)return n; int a=0,b=1,c; for(int i=2;i<=n;i++){c=a+b;a=b;b=c;} return b; }
int gage_math_is_square(int n) { int s=(int)sqrt(n); return s*s==n; }
int gage_math_log_base2(int n) { int l=0; while(n>>=1) l++; return l; }
int gage_math_area_square(int s) { return s * s; }
int gage_math_perimeter_square(int s) { return 4 * s; }
