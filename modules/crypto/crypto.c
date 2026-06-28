#include <stdlib.h>

int gage_crypto_simple_hash(int key) { return (key * 2654435761) % 100000; }
int gage_crypto_xor_cipher(int val, int mask) { return val ^ mask; }
int gage_crypto_add_salt(int val) { return val + 0xDEAD; }
int gage_crypto_add_pepper(int val) { return val ^ 0xBEEF; }
int gage_crypto_caesar_encrypt(int ch, int shift) { return ch + shift; }
int gage_crypto_caesar_decrypt(int ch, int shift) { return ch - shift; }
int gage_crypto_rot13_mock(int ch) { return ch + 13; }
int gage_crypto_generate_key() { return rand() ^ 0x3F3F3F3F; }
int gage_crypto_generate_iv() { return rand() ^ 0x1A1A1A1A; }
int gage_crypto_mock_md5(int input) { return (input * input) % 7919; }
int gage_crypto_mock_sha256(int input) { return (input * input * 17) % 104729; }
int gage_crypto_mock_aes_encrypt(int v, int k) { return (v ^ k) + 5; }
int gage_crypto_mock_aes_decrypt(int v, int k) { return (v - 5) ^ k; }
int gage_crypto_mock_rsa_encrypt(int v, int e) { return (v * e) % 997; }
int gage_crypto_mock_rsa_decrypt(int v, int d) { return (v * d) % 997; }
int gage_crypto_obfuscate_byte(int b) { return ~b & 0xFF; }
int gage_crypto_deobfuscate_byte(int b) { return ~b & 0xFF; }
int gage_crypto_vigenere_mock_encrypt(int v, int k) { return v + (k % 10); }
int gage_crypto_vigenere_mock_decrypt(int v, int k) { return v - (k % 10); }
int gage_crypto_checksum8(int a, int b) { return (a + b) % 256; }
int gage_crypto_checksum16(int a, int b) { return (a + b) % 65536; }
int gage_crypto_scramble_bits(int n) { return ((n & 0x55) << 1) | ((n & 0xAA) >> 1); }
int gage_crypto_unscramble_bits(int n) { return ((n & 0xAA) >> 1) | ((n & 0x55) << 1); }
int gage_crypto_mock_crc32(int data) { return data ^ 0xEDB88320; }
int gage_crypto_constant_time_compare(int a, int b) { return !(a ^ b); }
int gage_crypto_mask_leak_bits(int n) { return n & 0xF0F0F0F0; }
int gage_crypto_diffie_hellman_mock(int base, int secret) { return (base * secret) % 101; }
int gage_crypto_hide_lower_nibble(int b) { return b & 0xF0; }
int gage_crypto_hide_upper_nibble(int b) { return b & 0x0F; }
int gage_crypto_verify_hmac_mock(int a, int b) { return a == b; }
