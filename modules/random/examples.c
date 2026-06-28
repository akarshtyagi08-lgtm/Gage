#include <stdio.h>
#include "random.c"

int main() {
    // Seed the randomizer once for the example block
    srand(time(NULL));
    
    printf("=== GAGE RANDOM MODULE DEMO ===\n\n");
    
    printf("[Core] Random Range (10 to 50): %d\n", gage_random_range(10, 50));
    printf("[Core] Negative Range (-100 to -10): %d\n", gage_random_range(-100, -10));
    printf("[Core] 75%% Boolean Chance: %s\n", gage_random_boolean(75) ? "True" : "False");
    
    printf("\n[Gaming] Roll 3d6 (3 Dice, 6 Sides): %d\n", gage_random_dice(3, 6));
    printf("[Gaming] Damage (Base 1000, 20%% variance): %d\n", gage_random_damage_variance(1000, 20));
    printf("[Gaming] Loot Tier (High Common weight): Tier %d\n", gage_random_loot_tier(100, 50, 10, 5, 1));
    
    printf("\n[Math] Even Number (0-100): %d\n", gage_random_even_range(0, 100));
    printf("[Math] Multiple of 5 (Up to 100): %d\n", gage_random_multiple_of(5, 100));
    printf("[Math] Gaussian Bell Curve Center: %d\n", gage_random_gaussian_mock(50, 10));
    
    printf("\n[Network] Random IPv4 Octet: %d\n", gage_random_ipv4_octet());
    printf("[Network] Safe Ephemeral Port: %d\n", gage_random_network_port());
    
    printf("\n[Strings] Random Upper Alpha: %c\n", (char)gage_random_alpha_upper());
    printf("[Strings] Random Base64 Char: %c\n", (char)gage_random_base64_char());
    
    printf("\n=== DEMO COMPLETE ===\n");
    return 0;
}
