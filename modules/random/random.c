#include <stdlib.h>
#include <time.h>
#include <math.h>

// --- CORE GENERATORS ---
int gage_random_binary() { return rand() % 2; }
int gage_random_bound(int max) { return max > 0 ? rand() % (max + 1) : 0; }
int gage_random_range(int min, int max) { return min >= max ? min : min + (rand() % (max - min + 1)); }
int gage_random_chance(int numerator, int denominator) { return denominator > 0 ? (rand() % denominator) < numerator : 0; }
int gage_random_boolean(int weight_true_percent) { return (rand() % 100) < weight_true_percent; }
int gage_random_sign() { return (rand() % 2) ? 1 : -1; }

// --- GAMING & RPG ---
int gage_random_dice(int count, int sides) { int total = 0; for(int i=0; i<count; i++) total += 1 + (rand() % sides); return total; }
int gage_random_crit_hit(int chance_pct, int crit_mult, int base) { return (rand() % 100) < chance_pct ? base * crit_mult : base; }
int gage_random_damage_variance(int base, int variance_pct) { int var = (base * variance_pct) / 100; return gage_random_range(base - var, base + var); }
int gage_random_loot_tier(int c_weight, int u_weight, int r_weight, int e_weight, int l_weight) { 
    int roll = rand() % (c_weight + u_weight + r_weight + e_weight + l_weight);
    if (roll < c_weight) return 1; roll -= c_weight;
    if (roll < u_weight) return 2; roll -= u_weight;
    if (roll < r_weight) return 3; roll -= r_weight;
    if (roll < e_weight) return 4; return 5;
}
int gage_random_card_suit() { return rand() % 4; }
int gage_random_card_value() { return 1 + (rand() % 13); }
int gage_random_rock_paper_scissors() { return rand() % 3; }
int gage_random_coin_toss() { return rand() % 2; }
int gage_random_direction_4way() { return rand() % 4; }
int gage_random_direction_8way() { return rand() % 8; }
int gage_random_angle_360() { return rand() % 360; }

// --- MATH & DISTRIBUTIONS (Optimized Integer Mocks) ---
int gage_random_even_range(int min, int max) { int r = gage_random_range(min, max); return r % 2 == 0 ? r : (r + 1 <= max ? r + 1 : r - 1); }
int gage_random_odd_range(int min, int max) { int r = gage_random_range(min, max); return r % 2 != 0 ? r : (r + 1 <= max ? r + 1 : r - 1); }
int gage_random_multiple_of(int base, int max) { return base * gage_random_range(1, max / (base > 0 ? base : 1)); }
int gage_random_power_of_two(int max_exp) { return 1 << gage_random_range(0, max_exp); }
int gage_random_gaussian_mock(int mean, int std_dev) { return mean + (((rand()%100) + (rand()%100) + (rand()%100) - 150) * std_dev) / 100; }
int gage_random_triangle_mock(int min, int max, int mode) { int r = gage_random_range(min, max); return (r + mode) / 2; }
int gage_random_prime_under_100() { int p[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97}; return p[rand()%25]; }

// --- DATA, NETWORK & CRYPTO ---
int gage_random_color_rgb24() { return rand() % 16777216; }
int gage_random_color_hex() { return rand() % 0xFFFFFF; }
int gage_random_uuid_v4_part() { return rand() % 65536; }
int gage_random_ipv4_octet() { return rand() % 256; }
int gage_random_network_port() { return gage_random_range(1024, 65535); }
int gage_random_mac_byte() { return rand() % 256; }
int gage_random_memory_address_mock() { return rand() * rand(); }
int gage_random_http_status_mock() { int s[]={200, 201, 301, 302, 400, 401, 403, 404, 500, 502}; return s[rand()%10]; }
int gage_random_file_size_kb(int min, int max) { return gage_random_range(min, max); }
int gage_random_encryption_key_mock() { return rand() ^ 0xDEADBEEF; }

// --- CHARACTERS & STRINGS ---
int gage_random_ascii_printable() { return gage_random_range(32, 126); }
int gage_random_alpha_upper() { return gage_random_range(65, 90); }
int gage_random_alpha_lower() { return gage_random_range(97, 122); }
int gage_random_alphanumeric() { int r = rand() % 62; return r < 26 ? 65 + r : (r < 52 ? 97 + (r - 26) : 48 + (r - 52)); }
int gage_random_vowel_lower() { char v[] = {'a','e','i','o','u'}; return v[rand()%5]; }
int gage_random_consonant_lower() { char c[] = {'b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','y','z'}; return c[rand()%21]; }
int gage_random_hex_digit() { int r = rand() % 16; return r < 10 ? 48 + r : 65 + (r - 10); }
int gage_random_base64_char() { int r = rand() % 64; if(r<26)return 65+r; if(r<52)return 97+(r-26); if(r<62)return 48+(r-52); return r==62?'+':'/'; }
int gage_random_password_char() { return gage_random_range(33, 125); }

// --- DATES, TIME & WORLD ---
int gage_random_timestamp(int start_ts, int end_ts) { return gage_random_range(start_ts, end_ts); }
int gage_random_day_of_month(int max_days) { return gage_random_range(1, max_days); }
int gage_random_hour_of_day() { return rand() % 24; }
int gage_random_minute_of_hour() { return rand() % 60; }
int gage_random_timezone_offset() { return gage_random_range(-12, 12); }
int gage_random_latitude_mock() { return gage_random_range(-90, 90); }
int gage_random_longitude_mock() { return gage_random_range(-180, 180); }
