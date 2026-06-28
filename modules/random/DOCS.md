# 🎲 Random Module Documentation

The `random` module provides 30 production-grade functions for simulating real-world randomness, games, and math generation inside the Gage Engine ecosystem.

## Complete Feature Matrix

| Feature Function | Parameters | Return Scope | Description & Use Case |
| :--- | :--- | :--- | :--- |
| `gage_random_binary()` | None | `0` or `1` | Returns exactly 0 or 1. Perfect for strict yes/no flags. |
| `gage_random_to_custom(max)` | `max` (Int) | `0` to `max` | Generates a bounded value starting from zero up to your custom limit. |
| `gage_random_range(min, max)`| `min`, `max` | `min` to `max` | Standard custom-to-custom lower and upper bounded item generator. |
| `gage_random_coin_flip()` | None | `0` or `1` | Coin flipping simulation. Returns 0 for Tails, 1 for Heads. |
| `gage_random_dice_six()` | None | `1` to `6` | Simulates a standard 6-sided dice roll for games. |
| `gage_random_dice_twenty()` | None | `1` to `20` | Generates a 1-20 D20 score for classic tabletop RPG mechanics. |
| `gage_random_percentage()` | None | `0` to `100` | Useful for dropped rates, damage probabilities, or success rates. |
| `gage_random_negative_range()`| `min`, `max` | Negative limits | Explicit range calculator that cleanly respects negative floor bounds. |
| `gage_random_odd(max)` | `max` (Int) | Odd Int | Guarantees an odd value. Excellent for parsing odd procedural loops. |
| `gage_random_even(max)` | `max` (Int) | Even Int | Guarantees an even value output for aligned spacing systems. |
| `gage_random_sign()` | None | `-1` or `1` | Returns 1 or -1. Speeds up direction calculations in 2D physics engines. |
| `gage_random_byte()` | None | `0` to `255` | Generates an unsigned 8-bit byte integer for raw socket packets. |
| `gage_random_rgb_channel()` | None | `0` to `255` | Returns an integer fit to act as a raw color channel (Red, Green, Blue). |
| `gage_random_ascii_upper()` | None | `65` to `90` | Returns an uppercase alphabetical ASCII character marker token. |
| `gage_random_ascii_lower()` | None | `97` to `122` | Returns a lowercase alphabetical ASCII character marker token. |
| `gage_random_digit()` | None | `0` to `9` | Returns an integer digit between 0 and 9 for string masking algorithms. |
| `gage_random_rock_paper_scissors()`| None | `0` to `2` | Simulates choices: 0 equals Rock, 1 equals Paper, 2 equals Scissors. |
| `gage_random_day_of_week()` | None | `1` to `7` | Chooses an integer representative day sequence mapping marker (1-7). |
| `gage_random_month()` | None | `1` to `12` | Picks a calendar month representation metric bound (1 to 12). |
| `gage_random_hour()` | None | `0` to `23` | Emulates full military format hour timelines dynamically. |
| `gage_random_minute()` | None | `0` to `59` | Generates minutes constraints tracking indices safely. |
| `gage_random_year_near()` | None | `2020`-`2035` | Picks a nearby timeline calendar year value for data testing. |
| `gage_random_angle()` | None | `0` to `359` | Picks an absolute vector rotation angle inside a 360-degree loop. |
| `gage_random_millisecond()`| None | `0` to `999` | Generates micro split delta bounds values for clock variations. |
| `gage_random_bool()` | None | `0` or `1` | A clean wrapper for standard conditional true/false triggers. |
| `gage_random_chance_one_in(n)`| `n` (Int) | `0` or `1` | Returns true precisely once inside every N checking passes. |
| `gage_random_card_suit()` | None | `0` to `3` | Returns standard card suit offsets: Spades, Hearts, Diamonds, Clubs. |
| `gage_random_card_value()` | None | `1` to `13` | Returns typical card scales: Ace (1), numbers 2-10, Jack/Queen/King (11-13). |
| `gage_random_grid_index(w, h)`| `w`, `h` | Flattened index| Converts width and height limits to flat single index array grids. |
| `gage_random_prime_low()` | None | Prime pool | Draws a low mathematical prime factor below 30 directly. |
