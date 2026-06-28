#include <stdlib.h>
#include <time.h>

// Returns exactly 0 or 1
int gage_random_binary() { return rand() % 2; }

// Returns a random number from 0 up to a custom max value
int gage_random_to_custom(int max) { return max > 0 ? rand() % (max + 1) : 0; }

// Returns a random number bounded between a lower min and upper max limit
int gage_random_range(int min, int max) { return min + (rand() % (max - min + 1)); }

// Returns 0 for Tails, 1 for Heads
int gage_random_coin_flip() { return rand() % 2; }

// Standard 6-sided dice simulator (1 to 6)
int gage_random_dice_six() { return 1 + (rand() % 6); }

// RPG 20-sided dice simulator (1 to 20)
int gage_random_dice_twenty() { return 1 + (rand() % 20); }

// Generates a percentage score from 0 to 100
int gage_random_percentage() { return rand() % 101; }

// Handles ranges including negative bounds properly
int gage_random_negative_range(int min, int max) { return min + (rand() % (max - min + 1)); }

// Guarantees an odd number up to a max value
int gage_random_odd(int max) { int r = rand() % max; return r % 2 == 0 ? (r + 1 == max ? r - 1 : r + 1) : r; }

// Guarantees an even number up to a max value
int gage_random_even(int max) { int r = rand() % max; return r % 2 != 0 ? r - 1 : r; }

// Randomly returns 1 (positive) or -1 (negative) for game directions
int gage_random_sign() { return (rand() % 2) ? 1 : -1; }

// Generates a random 8-bit byte value (0 to 255)
int gage_random_byte() { return rand() % 256; }

// Generates a single channel color value for RGB channels
int gage_random_rgb_channel() { return rand() % 256; }

// Generates an uppercase letter ASCII value (A-Z)
int gage_random_ascii_upper() { return 65 + (rand() % 26); }

// Generates a lowercase letter ASCII value (a-z)
int gage_random_ascii_lower() { return 97 + (rand() % 26); }

// Generates a numeric char digit offset (0-9)
int gage_random_digit() { return rand() % 10; }

// Simple Rock-Paper-Scissors index chooser (0=Rock, 1=Paper, 2=Scissors)
int gage_random_rock_paper_scissors() { return rand() % 3; }

// Chooses a numeric day tracking index (1 to 7)
int gage_random_day_of_week() { return 1 + (rand() % 7); }

// Chooses a random month calendar index (1 to 12)
int gage_random_month() { return 1 + (rand() % 12); }

// Generates a random 24-hour military hour index (0 to 23)
int gage_random_hour() { return rand() % 24; }

// Generates a clock minute constraint value (0 to 59)
int gage_random_minute() { return rand() % 60; }

// Generates a close modern timeline anchor year (2020 to 2035)
int gage_random_year_near() { return 2020 + (rand() % 15); }

// Generates a full circle geometry degree vector angle (0 to 359)
int gage_random_angle() { return rand() % 360; }

// Generates precise millisecond clock splits (0 to 999)
int gage_random_millisecond() { return rand() % 1000; }

// Standard binary true or false bool switch
int gage_random_bool() { return rand() % 2; }

// Returns true exactly once every N random checks
int gage_random_chance_one_in(int n) { return (rand() % n) == 0; }

// Chooses a standard playing card suit array index (0 to 3)
int gage_random_card_suit() { return rand() % 4; }

// Returns a playing card deck card weight value (1 to 13)
int gage_random_card_value() { return 1 + (rand() % 13); }

// Converts 2D grid dimensions into a flat array coordinates tracking index
int gage_random_grid_index(int w, int h) { return rand() % (w * h); }

// Pulls a random low prime number pool constant safely below 30
int gage_random_prime_low() { int p[]={2,3,5,7,11,13,17,19,23,29}; return p[rand() % 10]; }
