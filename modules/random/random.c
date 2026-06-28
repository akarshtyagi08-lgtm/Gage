#include <stdlib.h>
#include <time.h>

int gage_random_binary() { return rand() % 2; }
int gage_random_to_custom(int max) { return max > 0 ? rand() % (max + 1) : 0; }
int gage_random_range(int min, int max) { return min >= max ? min : min + (rand() % (max - min + 1)); }
int gage_random_coin_flip() { return rand() % 2; }
int gage_random_dice_six() { return 1 + (rand() % 6); }
int gage_random_dice_twenty() { return 1 + (rand() % 20); }
int gage_random_percentage() { return rand() % 101; }
int gage_random_negative_range(int min, int max) { return min >= max ? min : min + (rand() % (max - min + 1)); }
int gage_random_odd(int max) { int r = rand() % (max > 0 ? max : 1); return r % 2 == 0 ? (r + 1 >= max ? r - 1 : r + 1) : r; }
int gage_random_even(int max) { int r = rand() % (max > 0 ? max : 1); return r % 2 != 0 ? r - 1 : r; }
int gage_random_sign() { return (rand() % 2) ? 1 : -1; }
int gage_random_byte() { return rand() % 256; }
int gage_random_rgb_channel() { return rand() % 256; }
int gage_random_ascii_upper() { return 65 + (rand() % 26); }
int gage_random_ascii_lower() { return 97 + (rand() % 26); }
int gage_random_digit() { return rand() % 10; }
int gage_random_rock_paper_scissors() { return rand() % 3; }
int gage_random_day_of_week() { return 1 + (rand() % 7); }
int gage_random_month() { return 1 + (rand() % 12); }
int gage_random_hour() { return rand() % 24; }
int gage_random_minute() { return rand() % 60; }
int gage_random_year_near() { return 2026 + (rand() % 10); }
int gage_random_angle() { return rand() % 360; }
int gage_random_millisecond() { return rand() % 1000; }
int gage_random_bool() { return rand() % 2; }
int gage_random_chance_one_in(int n) { return n <= 1 ? 1 : (rand() % n) == 0; }
int gage_random_card_suit() { return rand() % 4; }
int gage_random_card_value() { return 1 + (rand() % 13); }
int gage_random_grid_index(int w, int h) { return (w * h) > 0 ? rand() % (w * h) : 0; }
int gage_random_prime_low() { int p[]={2,3,5,7,11,13,17,19,23,29}; return p[rand() % 10]; }
