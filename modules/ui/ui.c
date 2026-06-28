#include <stdio.h>
#include <string.h>

// --- COLOR PACKS (DYNAMIC RGB & HEX) ---
void gage_ui_set_text_color_rgb(int r, int g, int b) { printf("\033[38;2;%d;%d;%dm", r & 0xFF, g & 0xFF, b & 0xFF); fflush(stdout); }
void gage_ui_set_bg_color_rgb(int r, int g, int b) { printf("\033[48;2;%d;%d;%dm", r & 0xFF, g & 0xFF, b & 0xFF); fflush(stdout); }
void gage_ui_color_hex_text(int hex) { int r = (hex >> 16) & 0xFF; int g = (hex >> 8) & 0xFF; int b = hex & 0xFF; printf("\033[38;2;%d;%d;%dm", r, g, b); fflush(stdout); }
void gage_ui_color_hex_bg(int hex) { int r = (hex >> 16) & 0xFF; int g = (hex >> 8) & 0xFF; int b = hex & 0xFF; printf("\033[48;2;%d;%d;%dm", r, g, b); fflush(stdout); }
void gage_ui_set_text_color_256(int code) { printf("\033[38;5;%dm", code & 0xFF); fflush(stdout); }
void gage_ui_set_bg_color_256(int code) { printf("\033[48;5;%dm", code & 0xFF); fflush(stdout); }

// --- SYSTEM HARDCODED CODES (LEGACY BACKWARDS COMPATIBILITY) ---
void gage_ui_color_red() { printf("\033[31m"); fflush(stdout); }
void gage_ui_color_green() { printf("\033[32m"); fflush(stdout); }
void gage_ui_color_blue() { printf("\033[34m"); fflush(stdout); }
void gage_ui_color_yellow() { printf("\033[33m"); fflush(stdout); }
void gage_ui_color_cyan() { printf("\033[36m"); fflush(stdout); }
void gage_ui_color_magenta() { printf("\033[35m"); fflush(stdout); }
void gage_ui_color_white() { printf("\033[37m"); fflush(stdout); }
void gage_ui_color_black() { printf("\033[30m"); fflush(stdout); }
void gage_ui_bg_red() { printf("\033[41m"); fflush(stdout); }
void gage_ui_bg_green() { printf("\033[42m"); fflush(stdout); }
void gage_ui_bg_blue() { printf("\033[44m"); fflush(stdout); }
void gage_ui_bg_yellow() { printf("\033[43m"); fflush(stdout); }
void gage_ui_bg_cyan() { printf("\033[46m"); fflush(stdout); }
void gage_ui_bg_magenta() { printf("\033[45m"); fflush(stdout); }
void gage_ui_bg_white() { printf("\033[47m"); fflush(stdout); }
void gage_ui_bg_black() { printf("\033[40m"); fflush(stdout); }

// --- TYPOGRAPHY TEXT STYLES ---
void gage_ui_style_reset() { printf("\033[0m"); fflush(stdout); }
void gage_ui_style_bold() { printf("\033[1m"); fflush(stdout); }
void gage_ui_style_dim() { printf("\033[2m"); fflush(stdout); }
void gage_ui_style_italic() { printf("\033[3m"); fflush(stdout); }
void gage_ui_style_underline() { printf("\033[4m"); fflush(stdout); }
void gage_ui_style_blink() { printf("\033[5m"); fflush(stdout); }
void gage_ui_style_reverse() { printf("\033[7m"); fflush(stdout); }
void gage_ui_style_hidden() { printf("\033[8m"); fflush(stdout); }
void gage_ui_style_strikethrough() { printf("\033[9m"); fflush(stdout); }

// --- CANVAS & CANVAS CLEAR MANIPULATORS ---
void gage_ui_reset_canvas() { printf("\033[0m\033[2J\033[H"); fflush(stdout); }
void gage_ui_screen_clear() { printf("\033[2J\033[H"); fflush(stdout); }
void gage_ui_clear_line() { printf("\033[2K"); fflush(stdout); }
void gage_ui_clear_line_to_end() { printf("\033[K"); fflush(stdout); }
void gage_ui_clear_line_to_start() { printf("\033[1K"); fflush(stdout); }

// --- CURSOR GRID COORDINATES CONTROL ---
void gage_ui_move_cursor(int x, int y) { printf("\033[%d;%dH", y, x); fflush(stdout); }
void gage_ui_cursor_up(int n) { printf("\033[%dA", n); fflush(stdout); }
void gage_ui_cursor_down(int n) { printf("\033[%dB", n); fflush(stdout); }
void gage_ui_cursor_forward(int n) { printf("\033[%dC", n); fflush(stdout); }
void gage_ui_cursor_backward(int n) { printf("\033[%dD", n); fflush(stdout); }
void gage_ui_save_cursor() { printf("\033[s"); fflush(stdout); }
void gage_ui_restore_cursor() { printf("\033[u"); fflush(stdout); }
void gage_ui_cursor_hide() { printf("\033[?25l"); fflush(stdout); }
void gage_ui_cursor_show() { printf("\033[?25h"); fflush(stdout); }

// --- WINDOWS SCROLL MODES ---
void gage_ui_set_scroll_region(int top, int bottom) { printf("\033[%d;%dr", top, bottom); fflush(stdout); }
void gage_ui_reset_scroll_region() { printf("\033[r"); fflush(stdout); }
void gage_ui_scroll_up(int n) { printf("\033[%dS", n); fflush(stdout); }
void gage_ui_scroll_down(int n) { printf("\033[%dT", n); fflush(stdout); }
void gage_ui_enable_alt_buffer() { printf("\033[?1049h"); fflush(stdout); }
void gage_ui_disable_alt_buffer() { printf("\033[?1049l"); fflush(stdout); }

// --- GRAPHIC LAYOUT WICKETS & WIDGETS ---
void gage_ui_draw_box() { printf("[UI Border Box Area]\n"); }
void gage_ui_draw_divider() { printf("------------------------------------\n"); }
void gage_ui_print_at(const char* text, int x, int y) { printf("\033[%d;%dH%s", y, x, text); fflush(stdout); }
void gage_ui_draw_horizontal_bar(int val, int max, int width) {
    if (max <= 0) return;
    int filled = (val * width) / max;
    printf("[");
    for(int i=0; i<width; i++) printf(i < filled ? "#" : " ");
    printf("] %d%%\n", (val * 100) / max);
    fflush(stdout);
}
void gage_ui_draw_solid_rect(int x, int y, int w, int h) {
    for(int i=0; i<h; i++) {
        printf("\033[%d;%dH", y+i, x);
        for(int j=0; j<w; j++) printf(" ");
    }
    fflush(stdout);
}
void gage_ui_draw_border_rect(int x, int y, int w, int h) {
    for(int i=0; i<h; i++) {
        printf("\033[%d;%dH", y+i, x);
        for(int j=0; j<w; j++) {
            if (i == 0 || i == h-1 || j == 0 || j == w-1) printf("#");
            else printf(" ");
        }
    }
    fflush(stdout);
}
void gage_ui_print_centered(const char* str, int width) {
    int len = strlen(str);
    int pad = (width - len) / 2;
    for(int i=0; i<pad; i++) printf(" ");
    printf("%s\n", str);
}
void gage_ui_draw_loading_spinner(int frame) {
    char s[] = {'|', '/', '-', '\\'};
    printf("%c", s[frame % 4]);
    fflush(stdout);
}
void gage_ui_set_terminal_title(const char* title) { printf("\033]2;%s\007", title); fflush(stdout); }
void gage_ui_ring_visual_bell() { printf("\033[g"); fflush(stdout); }
