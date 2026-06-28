#include <stdio.h>
#include <unistd.h>
#include "ui.c"

int main() {
    // 1. Enter Alternate Screen Buffer to keep user shell logs clean
    gage_ui_enable_alt_buffer();
    gage_ui_cursor_hide();
    gage_ui_screen_clear();

    // 2. Set Terminal Title Meta Data
    gage_ui_set_terminal_title("Gage Compiler TUI Engine Dashboard Core v4.0");

    // 3. Render Top True-Color Header Bar Component
    gage_ui_color_hex_bg(0x111122);
    gage_ui_color_hex_text(0x00FFCC);
    gage_ui_style_bold();
    gage_ui_move_cursor(1, 1);
    gage_ui_draw_solid_rect(1, 1, 60, 3);
    
    gage_ui_move_cursor(15, 2);
    gage_ui_print_centered("=== GAGE ENGINE SYSTEMS MONITOR ===", 30);
    gage_ui_style_reset();

    // 4. Draw Core UI Workspace Matrix Frame Lines
    gage_ui_color_hex_text(0x444455);
    gage_ui_draw_border_rect(1, 5, 60, 15);

    // 5. Output Live Real-Time Variables Status Data Rows Maps
    gage_ui_color_hex_text(0xFFBB00);
    gage_ui_print_at("System State: ACTIVE PIPELINE", 4, 7);
    
    gage_ui_color_hex_text(0xFFFFFF);
    gage_ui_print_at("Compiler Stream Pointer: NATIVE_C", 4, 9);
    gage_ui_print_at("Buffer Optimization Flags: 0xFF", 4, 11);

    // 6. Procedural Component Simulation Loop: Live Progress Bar & Spinner
    gage_ui_print_at("Processing Dependency Matrices Rows: ", 4, 13);
    for(int i=1; i<=100; i+=5) {
        // Render Progress Bar Widget Component
        gage_ui_move_cursor(4, 15);
        gage_ui_color_hex_text(0x00AAFF);
        gage_ui_draw_horizontal_bar(i, 100, 30);
        
        // Render Live Spinning Loader Widget Component
        gage_ui_move_cursor(41, 13);
        gage_ui_color_hex_text(0xFF0055);
        gage_ui_draw_loading_spinner(i / 5);
        
        usleep(100000); // 100ms timing delta loop step delay
    }

    // 7. Finish Execution and Exit Alternate Buffers Layout
    gage_ui_style_reset();
    gage_ui_color_hex_text(0x00FF55);
    gage_ui_print_at("SYSTEM DEPLOYED SUCCESS! Press Enter to restore console.", 4, 18);
    
    getchar(); // Hold interface update visible until keystroke confirmation
    
    gage_ui_cursor_show();
    gage_ui_disable_alt_buffer();
    return 0;
}
