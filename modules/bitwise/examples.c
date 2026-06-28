#include <stdio.h>
#include "bitwise.c"

int main() {
    printf("=== GAGE LOW-LEVEL BITWISE LOGIC SUB-ENGINE DEMO ===\n\n");

    int x = 45;  // Binary: 00101101
    int y = 25;  // Binary: 00011001

    // 1. Core Logic Gates Audits
    printf("[Gates Validation] Input X (%d) AND Input Y (%d) Result: %d\n", x, y, gage_bitwise_and(x, y));
    printf("[Gates Validation] Input X (%d) XOR Input Y (%d) Result: %d\n", x, y, gage_bitwise_xor(x, y));

    // 2. Individual Bit Cell Position Tracking Checks
    printf("\n[Bit Adjusters] Setting bit index position 4 on value %d: %d\n", x, gage_bitwise_set_bit(x, 4));
    printf("[Bit Adjusters] Toggling bit index position 0 on value %d: %d\n", x, gage_bitwise_toggle_bit(x, 0));
    printf("[Bit Adjusters] Verification check - is bit index 3 active in %d? %s\n", x, gage_bitwise_check_bit(x, 3) ? "YES" : "NO");

    // 3. Population and Parity Metric Verifications
    printf("\n[Metrics] Total set bit cells count inside integer %d: %d active bits\n", x, gage_bitwise_count_set_bits(x));
    printf("[Metrics] Parity evaluation signature flag: %s parity\n", gage_bitwise_check_parity(x) ? "ODD" : "EVEN");
    printf("[Metrics] Is integer number 64 a perfect power of two alignment? %s\n", gage_bitwise_is_power_of_two(64) ? "TRUE" : "FALSE");

    // 4. Branchless Math Operations Sweeps
    int neg_val = -150;
    printf("\n[Branchless Physics] Input Signed Value: %d\n", neg_val);
    printf("[Branchless Physics] Calculated Absolute Value (No Conditional Jumps): %d\n", gage_bitwise_abs(neg_val));
    printf("[Branchless Physics] Extracting branchless minimum between 89 and 42: %d\n", gage_bitwise_min(89, 42));

    // 5. Silicon Logic Emulator Additions / Subtractions Testing
    int val_a = 15;
    int val_b = 27;
    printf("\n[Silicon Emulation] Re-routing arithmetic additions straight over logic gates loops...\n");
    int sum = gage_bitwise_add_no_arithmetic(val_a, val_b);
    printf("[Silicon Emulation] Unified Gates Sum (%d + %d): %d\n", val_a, val_b, sum);
    printf("[Silicon Emulation] Unified Gates Difference (%d - %d): %d\n", val_b, val_a, gage_bitwise_sub_no_arithmetic(val_b, val_a));

    // 6. Data Packing Span Updates Checks
    int base_word = 0xFFFFFFFF;
    printf("\n[Data Packing] Original filled storage block: 0x%X\n", base_word);
    printf("[Data Packing] Clearing out horizontal bit band range (indices 4 to 12): 0x%X\n", gage_bitwise_clear_bit_range(base_word, 4, 12));

    // 7. Byte Architecture Endian Shifts
    int endian_word = 0x11223344;
    printf("\n[Architecture Swap] Pre-swap Word: 0x%X\n", endian_word);
    printf("[Architecture Swap] Reversing byte alignments sequence tracks: 0x%X\n", gage_bitwise_reverse_bytes(endian_word));

    printf("\n=== LOW-LEVEL PERFORMANCE ENGINE INTEGRATION SUCCESSFUL ===\n");
    return 0;
}
