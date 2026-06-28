#include <stdio.h>

// --- CORE LOGIC GATES (30 ORIGINAL INTEGRATIONS) ---
int gage_bitwise_and(int a, int b) { return a & b; } //[span_1](start_span)[span_1](end_span)
int gage_bitwise_or(int a, int b) { return a | b; }  //[span_2](start_span)[span_2](end_span)
int gage_bitwise_xor(int a, int b) { return a ^ b; } //[span_3](start_span)[span_3](end_span)
int gage_bitwise_not(int a) { return ~a; }           //[span_4](start_span)[span_4](end_span)
int gage_bitwise_left_shift(int a, int s) { return a << s; }   //[span_5](start_span)[span_5](end_span)
int gage_bitwise_right_shift(int a, int s) { return a >> s; }  //[span_6](start_span)[span_6](end_span)
int gage_bitwise_set_bit(int a, int n) { return a | (1 << n); } //[span_7](start_span)[span_7](end_span)
int gage_bitwise_clear_bit(int a, int n) { return a & ~(1 << n); } //[span_8](start_span)[span_8](end_span)
int gage_bitwise_toggle_bit(int a, int n) { return a ^ (1 << n); } //[span_9](start_span)[span_9](end_span)
int gage_bitwise_check_bit(int a, int n) { return (a >> n) & 1; } //[span_10](start_span)[span_10](end_span)
int gage_bitwise_count_set_bits(int n) { int c=0; while(n){c+=n&1;n>>=1;} return c; } //[span_11](start_span)[span_11](end_span)
int gage_bitwise_check_parity(int n) { int p=0; while(n){p^=n&1;n>>=1;} return p; } //[span_12](start_span)[span_12](end_span)
int gage_bitwise_isolate_lowest_bit(int n) { return n & -n; } //[span_13](start_span)[span_13](end_span)
int gage_bitwise_clear_lowest_bit(int n) { return n & (n - 1); } //[span_14](start_span)[span_14](end_span)
int gage_bitwise_is_power_of_two(int n) { return n > 0 && (n & (n - 1)) == 0; } //[span_15](start_span)[span_15](end_span)
int gage_bitwise_generate_mask(int n) { return (1 << n) - 1; } //[span_16](start_span)[span_16](end_span)
int gage_bitwise_rotate_left(int n, int s) { return (n << s) | (n >> (32 - s)); } //[span_17](start_span)[span_17](end_span)
int gage_bitwise_rotate_right(int n, int s) { return (n >> s) | (n << (32 - s)); } //[span_18](start_span)[span_18](end_span)
int gage_bitwise_binary_to_gray(int n) { return n ^ (n >> 1); } //[span_19](start_span)[span_19](end_span)
int gage_bitwise_gray_to_binary(int n) { int m=n; while(m>>=1) n^=m; return n; } //[span_20](start_span)[span_20](end_span)
int gage_bitwise_swap_nibbles(int b) { return ((b & 0x0F) << 4) | ((b & 0xF0) >> 4); } //[span_21](start_span)[span_21](end_span)
int gage_bitwise_reverse_bytes(int n) { return ((n>>24)&0xff)|((n<<8)&0xff0000)|((n>>8)&0xff00)|((n<<24)&0xff000000); } //[span_22](start_span)[span_22](end_span)
int gage_bitwise_get_bit_length(int n) { int l=0; while(n){n>>=1;l++;} return l; } //[span_23](start_span)[span_23](end_span)
int gage_bitwise_sign_extend(int v, int b) { int m = 1 << (b - 1); return (v ^ m) - m; } //[span_24](start_span)[span_24](end_span)
int gage_bitwise_zero_extend(int v, int b) { return v & ((1 << b) - 1); } //[span_25](start_span)[span_25](end_span)
int gage_bitwise_multiply_by_p2(int v, int p) { return v << p; } //[span_26](start_span)[span_26](end_span)
int gage_bitwise_divide_by_p2(int v, int p) { return v >> p; }   //[span_27](start_span)[span_27](end_span)
int gage_bitwise_invert_even_bits(int n) { return n ^ 0xAAAAAAAA; } //[span_28](start_span)[span_28](end_span)
int gage_bitwise_invert_odd_bits(int n) { return n ^ 0x55555555; }   //[span_29](start_span)[span_29](end_span)
int gage_bitwise_mock_checksum(int a, int b) { return (a ^ b) << 2; } //[span_30](start_span)[span_30](end_span)

// --- BRANCHLESS PREMIUM ADVANCED MATHS (20 NEW FUNCTIONS) ---
void gage_bitwise_swap_integers(int* a, int* b) { if (a != b) { *a ^= *b; *b ^= *a; *a ^= *b; } }
int gage_bitwise_merge_bits(int a, int b, int mask) { return a ^ ((a ^ b) & mask); }
int gage_bitwise_abs(int n) { int mask = n >> 31; return (n + mask) ^ mask; }
int gage_bitwise_min(int x, int y) { return y ^ ((x ^ y) & -(x < y)); }
int gage_bitwise_max(int x, int y) { return x ^ ((x ^ y) & -(x < y)); }
int gage_bitwise_has_opposite_signs(int x, int y) { return (x ^ y) < 0; }
int gage_bitwise_is_power_of_four(int n) { return n > 0 && (n & (n - 1)) == 0 && (n & 0x55555555) != 0; }
int gage_bitwise_count_trailing_zeros(int n) { if (n == 0) return 32; int c = 0; if ((n & 0xFFFF) == 0) { c += 16; n >>= 16; } if ((n & 0xFF) == 0) { c += 8; n >>= 8; } if ((n & 0xF) == 0) { c += 4; n >>= 4; } if ((n & 0x3) == 0) { c += 2; n >>= 2; } if ((n & 0x1) == 0) c += 1; return c; }
int gage_bitwise_count_leading_zeros(int n) { if (n == 0) return 32; int c = 0; if ((n & 0xFFFF0000) == 0) { c += 16; n <<= 16; } if ((n & 0xFF000000) == 0) { c += 8; n <<= 8; } if ((n & 0xF0000000) == 0) { c += 4; n <<= 4; } if ((n & 0xC0000000) == 0) { c += 2; n <<= 2; } if ((n & 0x80000000) == 0) c += 1; return c; }
int gage_bitwise_reverse_bits(int n) { n = ((n >> 1) & 0x55555555) | ((n & 0x55555555) << 1); n = ((n >> 2) & 0x33333333) | ((n & 0x33333333) << 2); n = ((n >> 4) & 0x0F0F0F0F) | ((n & 0x0F0F0F0F) << 4); n = ((n >> 8) & 0x00FF00FF) | ((n & 0x00FF00FF) << 8); return (n >> 16) | (n << 16); }
int gage_bitwise_add_no_arithmetic(int a, int b) { while (b != 0) { int carry = a & b; a = a ^ b; b = carry << 1; } return a; }
int gage_bitwise_sub_no_arithmetic(int a, int b) { while (b != 0) { int borrow = (~a) & b; a = a ^ b; b = borrow << 1; } return a; }
int gage_bitwise_multiply_no_arithmetic(int a, int b) { int res = 0; while (b > 0) { if (b & 1) res = res ^ a; a <<= 1; b >>= 1; } return res; }
int gage_bitwise_isolate_highest_bit(int n) { n |= (n >> 1); n |= (n >> 2); n |= (n >> 4); n |= (n >> 8); n |= (n >> 16); return n - (n >> 1); }
int gage_bitwise_clear_bit_range(int n, int start, int end) { int mask = ~(((1 << (end - start + 1)) - 1) << start); return n & mask; }
int gage_bitwise_set_bit_range(int n, int start, int end) { int mask = (((1 << (end - start + 1)) - 1) << start); return n | mask; }
int gage_bitwise_toggle_bit_range(int n, int start, int end) { int mask = (((1 << (end - start + 1)) - 1) << start); return n ^ mask; }
int gage_bitwise_hamming_distance(int a, int b) { int xor_val = a ^ b; int dist = 0; while (xor_val) { dist++; xor_val &= (xor_val - 1); } return dist; }
int gage_bitwise_circular_shift(int n, int shift, int bit_width) { shift %= bit_width; return ((n << shift) | (n >> (bit_width - shift))) & ((1 << bit_width) - 1); }
int gage_bitwise_is_even_branchless(int n) { return (n & 1) ^ 1; }
