#include <stdio.h>
#include "math.c"

int main() {
    printf("=== GAGE MATH MODULE DEMO ===\n\n");
    
    printf("[Core] Safe Division (100 / 0): %d (Avoids crash!)\n", gage_math_divide(100, 0));
    printf("[Constants] Scaled Pi: %d\n", gage_math_pi_scaled());
    printf("[Constants] Golden Ratio (Phi): %d\n", gage_math_phi_scaled());
    
    printf("\n[Limits] Clamp 150 between 0-100: %d\n", gage_math_clamp(150, 0, 100));
    printf("[Limits] Wrap 370 degrees (0-359): %d\n", gage_math_wrap(370, 0, 359));
    
    printf("\n[Geometry] Hypotenuse of 3 and 4: %d\n", gage_math_hypotenuse(3, 4));
    printf("[Geometry] 2D Distance (0,0 to 10,10): %d\n", gage_math_distance_2d(0, 0, 10, 10));
    
    printf("\n[Trig] Sin(90 deg) scaled by 1000: %d\n", gage_math_sin_scaled(90));
    
    printf("\n[Algorithms] Is 17 Prime? %s\n", gage_math_is_prime(17) ? "Yes" : "No");
    printf("[Algorithms] 10th Fibonacci Number: %d\n", gage_math_fibonacci(10));
    printf("[Algorithms] GCD of 48 and 18: %d\n", gage_math_gcd(48, 18));
    
    printf("\n[Mapping] Lerp 50%% between 0 and 200: %d\n", gage_math_lerp(0, 200, 50));
    printf("[Mapping] Map 5 (scale 0-10) to (0-100): %d\n", gage_math_map_range(5, 0, 10, 0, 100));
    
    printf("\n=== DEMO COMPLETE ===\n");
    return 0;
}
