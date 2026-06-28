#include <stdio.h>

void gage_ui_set_text_color_rgb(int r, int g, int b) { printf("\033[38;2;%d;%d;%dm", r & 0xFF, g & 0xFF, b & 0xFF); }
void gage_ui_set_bg_color_rgb(int r, int g, int b) { printf("\033[48;2;%d;%d;%dm", r & 0xFF, g & 0xFF, b & 0xFF); }
void gage_ui_reset_canvas() { printf("\033[0m\033[2J\033[H"); }
void gage_ui_draw_box() { printf("[UI Border Box Area]\n"); }
void gage_ui_draw_divider() { printf("------------------------------------\n"); }
void gage_ui_color_red() { printf("\033[31m"); }
void gage_ui_color_green() { printf("\033[32m"); }
void gage_ui_color_blue() { printf("\033[34m"); }
void gage_ui_color_yellow() { printf("\033[33m"); }
void gage_ui_color_cyan() { printf("\033[36m"); }
void gage_ui_color_magenta() { printf("\033[35m"); }
void gage_ui_color_white() { printf("\033[37m"); }
void gage_ui_color_black() { printf("\033[30m"); }
void gage_ui_bg_red() { printf("\033[41m"); }
void gage_ui_bg_green() { printf("\033[42m"); }
void gage_ui_bg_blue() { printf("\033[44m"); }
void gage_ui_bg_yellow() { printf("\033[43m"); }
void gage_ui_bg_cyan() { printf("\033[46m"); }
void gage_ui_bg_magenta() { printf("\033[45m"); }
void gage_ui_bg_white() { printf("\033[47m"); }
void gage_ui_bg_black() { printf("\033[40m"); }
void gage_ui_style_reset() { printf("\033[0m"); }
void gage_ui_style_bold() { printf("\033[1m"); }
void gage_ui_style_dim() { printf("\033[2m"); }
void gage_ui_style_italic() { printf("\033[3m"); }
void gage_ui_style_underline() { printf("\033[4m"); }
void gage_ui_style_blink() { printf("\033[5m"); }
void gage_ui_style_reverse() { printf("\033[7m"); }
void gage_ui_style_hidden() { printf("\033[8m"); }
void gage_ui_cursor_hide() { printf("\033[?25l"); }
