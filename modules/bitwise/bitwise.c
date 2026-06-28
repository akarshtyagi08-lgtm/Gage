int gage_bitwise_and(int a, int b) { return a & b; }
int gage_bitwise_or(int a, int b) { return a | b; }
int gage_bitwise_xor(int a, int b) { return a ^ b; }
int gage_bitwise_not(int a) { return ~a; }
int gage_bitwise_left_shift(int a, int s) { return a << s; }
int gage_bitwise_right_shift(int a, int s) { return a >> s; }
int gage_bitwise_set_bit(int a, int n) { return a | (1 << n); }
int gage_bitwise_clear_bit(int a, int n) { return a & ~(1 << n); }
int gage_bitwise_toggle_bit(int a, int n) { return a ^ (1 << n); }
int gage_bitwise_check_bit(int a, int n) { return (a >> n) & 1; }
int gage_bitwise_count_set_bits(int n) { int c=0; while(n){c+=n&1;n>>=1;} return c; }
int gage_bitwise_check_parity(int n) { int p=0; while(n){p^=n&1;n>>=1;} return p; }
int gage_bitwise_isolate_lowest_bit(int n) { return n & -n; }
int gage_bitwise_clear_lowest_bit(int n) { return n & (n - 1); }
int gage_bitwise_is_power_of_two(int n) { return n > 0 && (n & (n - 1)) == 0; }
int gage_bitwise_generate_mask(int n) { return (1 << n) - 1; }
int gage_bitwise_rotate_left(int n, int s) { return (n << s) | (n >> (32 - s)); }
int gage_bitwise_rotate_right(int n, int s) { return (n >> s) | (n << (32 - s)); }
int gage_bitwise_binary_to_gray(int n) { return n ^ (n >> 1); }
int gage_bitwise_gray_to_binary(int n) { int m=n; while(m>>=1) n^=m; return n; }
int gage_bitwise_swap_nibbles(int b) { return ((b & 0x0F) << 4) | ((b & 0xF0) >> 4); }
int gage_bitwise_reverse_bytes(int n) { return ((n>>24)&0xff)|((n<<8)&0xff0000)|((n>>8)&0xff00)|((n<<24)&0xff000000); }
int gage_bitwise_get_bit_length(int n) { int l=0; while(n){n>>=1;l++;} return l; }
int gage_bitwise_sign_extend(int v, int b) { int m = 1 << (b - 1); return (v ^ m) - m; }
int gage_bitwise_zero_extend(int v, int b) { return v & ((1 << b) - 1); }
int gage_bitwise_multiply_by_p2(int v, int p) { return v << p; }
int gage_bitwise_divide_by_p2(int v, int p) { return v >> p; }
int gage_bitwise_invert_even_bits(int n) { return n ^ 0xAAAAAAAA; }
int gage_bitwise_invert_odd_bits(int n) { return n ^ 0x55555555; }
int gage_bitwise_mock_checksum(int a, int b) { return (a ^ b) << 2; }
