# 🎲 The Ultimate Gage Random Module (v4.0)

Welcome to the absolute largest, most detailed, and highly optimized Random Generation module ever built for the Gage language ecosystem. This module has been meticulously engineered from the ground up to provide 50 distinct, mathematically sound, and high-performance algorithms. 

By eliminating static limits and replacing them with dynamic arguments (e.g., passing custom ranges, arrays, and weights directly into the functions), this architecture provides unprecedented control over statistical distributions, gaming logic, network mocking, and procedural generation.

---

## 🏗️ Architecture & Performance Philosophy

Every function inside this module is built using native C integer arithmetic. Floating-point math has been strictly avoided where possible to ensure that Gage scripts execute flawlessly on low-power devices, mobile processors, and embedded systems without losing precision. 
*   **Time Complexity:** O(1) for 98% of functions.
*   **Space Complexity:** O(1) across the board. No dynamic memory allocation (`malloc`/`free`) is used, eliminating memory leaks entirely.

---

## 📜 Section 1: Core Generators
These are the foundational functions used for basic numeric manipulation.

### 1. `gage_random_binary()`
*   **Description:** The absolute simplest form of entropy. It returns a pure boolean representation integer.
*   **Parameters:** None.
*   **Returns:** `0` or `1`.
*   **Performance:** Ultra-fast modulo operation against the hardware cycle.

### 2. `gage_random_bound(max)`
*   **Description:** Replaces hardcoded ceilings. It generates a value starting from absolute zero up to (and including) your dynamically provided maximum bound.
*   **Parameters:** `max` (integer) - The highest possible number you want to generate.
*   **Returns:** An integer between `0` and `max`.
*   **Edge Cases:** If a negative `max` is provided, the function safely falls back to returning `0` to prevent modulo crashing.

### 3. `gage_random_range(min, max)`
*   **Description:** The crown jewel of procedural generation. This allows you to set explicit lower and upper boundaries. It perfectly handles negative minimums (e.g., `-50` to `50`).
*   **Parameters:** `min` (integer) - The absolute floor. `max` (integer) - The absolute ceiling.
*   **Returns:** An integer perfectly distributed between `min` and `max`.
*   **Edge Cases:** If `min` is greater than or equal to `max`, it instantly returns `min` without crashing the CPU.

### 4. `gage_random_chance(numerator, denominator)`
*   **Description:** A fractional probability engine. Instead of standard percentages, you can say "Give me a 3 in 1000 chance". 
*   **Parameters:** `numerator` (int) - The hits required. `denominator` (int) - The total pool size.
*   **Returns:** `1` if the chance succeeds, `0` if it fails.

### 5. `gage_random_boolean(weight_true_percent)`
*   **Description:** A weighted boolean. If you want a boolean that is true 80% of the time, simply pass `80`.
*   **Parameters:** `weight_true_percent` (int) - The percentage chance of returning true.
*   **Returns:** `1` (True) or `0` (False).

### 6. `gage_random_sign()`
*   **Description:** Procedural math helper. Immediately returns a positive or negative multiplier.
*   **Parameters:** None.
*   **Returns:** `1` or `-1`.

---

## ⚔️ Section 2: Gaming & RPG Systems
Functions dedicated entirely to building video games, tabletop RPGs, and loot systems natively in Gage.

### 7. `gage_random_dice(count, sides)`
*   **Description:** Replaces 10 different hardcoded dice functions. Roll `3` dice with `6` sides, or `1` dice with `20` sides dynamically.
*   **Parameters:** `count` (int) - Number of dice to roll. `sides` (int) - Number of sides per die.
*   **Returns:** The aggregated sum of all dice rolled.

### 8. `gage_random_crit_hit(chance_pct, crit_mult, base)`
*   **Description:** A complete critical hit calculator in one function. Pass the base damage, the chance to crit, and the multiplier.
*   **Parameters:** `chance_pct` (int), `crit_mult` (int), `base` (int).
*   **Returns:** The final calculated damage.

### 9. `gage_random_damage_variance(base, variance_pct)`
*   **Description:** Prevents games from feeling flat. If a sword does 100 damage with a 10% variance, it will hit anywhere between 90 and 110.
*   **Parameters:** `base` (int), `variance_pct` (int).
*   **Returns:** The varied integer damage.

### 10. `gage_random_loot_tier(c, u, r, e, l)`
*   **Description:** A massive weighted distribution engine for loot drops. Pass the weights for Common, Uncommon, Rare, Epic, and Legendary.
*   **Parameters:** 5 integers representing the ticket pool for each rarity.
*   **Returns:** `1` (Common) to `5` (Legendary).

### 11. `gage_random_card_suit()`
*   **Description:** Instantly grabs a suite identifier for poker/card games.
*   **Returns:** `0` to `3`.

### 12. `gage_random_card_value()`
*   **Description:** Grabs a card rank.
*   **Returns:** `1` to `13`.

### 13. `gage_random_rock_paper_scissors()`
*   **Description:** Basic AI choice generator for RPS.
*   **Returns:** `0`, `1`, or `2`.

### 14. `gage_random_coin_toss()`
*   **Description:** Pure 50/50 split.
*   **Returns:** `0` (Tails), `1` (Heads).

### 15. `gage_random_direction_4way()`
*   **Description:** Returns cardinal directions for 2D grid movement (Up, Down, Left, Right).
*   **Returns:** `0` to `3`.

### 16. `gage_random_direction_8way()`
*   **Description:** Returns cardinal + diagonal directions for 2D movement.
*   **Returns:** `0` to `7`.

### 17. `gage_random_angle_360()`
*   **Description:** Picks a 360-degree vector for bullet hell or physics games.
*   **Returns:** `0` to `359`.

---

## 📈 Section 3: Math & Distributions
Mocking statistical analysis and mathematical bounds safely.

### 18. `gage_random_even_range(min, max)`
*   **Description:** Forces the output to be an even number within your bounds.
*   **Returns:** An even integer.

### 19. `gage_random_odd_range(min, max)`
*   **Description:** Forces the output to be an odd number within your bounds.
*   **Returns:** An odd integer.

### 20. `gage_random_multiple_of(base, max)`
*   **Description:** Returns a random multiple of your base up to the max (e.g., multiples of 5 up to 100).
*   **Returns:** A scaled integer.

### 21. `gage_random_power_of_two(max_exp)`
*   **Description:** Returns random byte limits (2, 4, 8, 16, 32, etc.) using fast bit shifting.
*   **Returns:** An integer power of 2.

### 22. `gage_random_gaussian_mock(mean, std_dev)`
*   **Description:** An integer-based emulation of the Central Limit Theorem to create a Bell Curve distribution.
*   **Returns:** Center-weighted integer.

### 23. `gage_random_triangle_mock(min, max, mode)`
*   **Description:** Emulates a triangular distribution focusing around a specific mode.
*   **Returns:** Biased integer.

### 24. `gage_random_prime_under_100()`
*   **Description:** Pulls from a hardcoded array of primes. Extremely fast.
*   **Returns:** A prime integer.

---

## 🌐 Section 4: Data, Network & Crypto
Tools to fake server data, IP addresses, and UUIDs for testing.

### 25. `gage_random_color_rgb24()`
*   **Description:** The ultimate color generator. Returns a massive 24-bit integer combining RGB into one value.
*   **Returns:** `0` to `16777215`.

### 26. `gage_random_color_hex()`
*   **Description:** Generates standard Hex color combinations natively.
*   **Returns:** Hex-ready integer.

### 27. `gage_random_uuid_v4_part()`
*   **Description:** Generates a 16-bit block used to manually stitch together UUID strings.
*   **Returns:** `0` to `65535`.

### 28. `gage_random_ipv4_octet()`
*   **Description:** Safe network byte limit.
*   **Returns:** `0` to `255`.

### 29. `gage_random_network_port()`
*   **Description:** Bypasses reserved ports, returning only safe ephemeral ports.
*   **Returns:** `1024` to `65535`.

### 30. `gage_random_mac_byte()`
*   **Description:** Used to build random hardware addresses.
*   **Returns:** `0` to `255`.

### 31. `gage_random_memory_address_mock()`
*   **Description:** Generates a massive integer to simulate RAM pointers.
*   **Returns:** Huge integer.

### 32. `gage_random_http_status_mock()`
*   **Description:** Returns standard Web codes (200, 404, 500, etc.) from an array.
*   **Returns:** Integer status code.

### 33. `gage_random_file_size_kb(min, max)`
*   **Description:** File weight mock generator.
*   **Returns:** KB integer representation.

### 34. `gage_random_encryption_key_mock()`
*   **Description:** Bitwise XOR randomizer creating a mock 32-bit key.
*   **Returns:** Obfuscated integer.

---

## 🔡 Section 5: Characters & Strings
ASCII mapping utilities.

### 35. `gage_random_ascii_printable()`
*   **Description:** Any visible character on a keyboard.
*   **Returns:** ASCII code (32-126).

### 36. `gage_random_alpha_upper()`
*   **Description:** Standard A-Z.
*   **Returns:** ASCII code (65-90).

### 37. `gage_random_alpha_lower()`
*   **Description:** Standard a-z.
*   **Returns:** ASCII code (97-122).

### 38. `gage_random_alphanumeric()`
*   **Description:** Safely bounds and skips symbols, returning ONLY letters and numbers.
*   **Returns:** Filtered ASCII code.

### 39. `gage_random_vowel_lower()`
*   **Description:** Returns a random vowel char code.
*   **Returns:** ASCII for a, e, i, o, or u.

### 40. `gage_random_consonant_lower()`
*   **Description:** Returns a random consonant char code.
*   **Returns:** ASCII code.

### 41. `gage_random_hex_digit()`
*   **Description:** Returns a char code for 0-9 or A-F.
*   **Returns:** ASCII code.

### 42. `gage_random_base64_char()`
*   **Description:** Complex mapping ensuring strict Base64 compliance.
*   **Returns:** ASCII code.

### 43. `gage_random_password_char()`
*   **Description:** Removes spaces, keeps letters, numbers, and hard symbols for password gen.
*   **Returns:** ASCII code.

---

## 🌍 Section 6: Dates, Time & World
Simulates the physical world and chronometers.

### 44. `gage_random_timestamp(start_ts, end_ts)`
*   **Description:** Pass two epoch timestamps and get a random second between them.
*   **Returns:** UNIX timestamp.

### 45. `gage_random_day_of_month(max_days)`
*   **Description:** Day picker bounded by the specific month you pass.
*   **Returns:** `1` to `max_days`.

### 46. `gage_random_hour_of_day()`
*   **Description:** 24-hour timeline generator.
*   **Returns:** `0` to `23`.

### 47. `gage_random_minute_of_hour()`
*   **Description:** 60-minute tracker.
*   **Returns:** `0` to `59`.

### 48. `gage_random_timezone_offset()`
*   **Description:** Generates GMT offsets.
*   **Returns:** `-12` to `12`.

### 49. `gage_random_latitude_mock()`
*   **Description:** Equator-based mapping.
*   **Returns:** `-90` to `90`.

### 50. `gage_random_longitude_mock()`
*   **Description:** Prime meridian-based mapping.
*   **Returns:** `-180` to `180`.

---
*End of Random Module Documentation.*
