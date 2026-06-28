# 🎨 Terminal User Interface Drawing Module Documentation

The `ui` module maps raw terminal escape protocols into easily called graphics commands, cell painters, rendering controllers, and style manipulators for Gage.

## Complete Feature Matrix

| Feature Function | Visual Escape Target | Rendering Mode | Interface Capabilities & Purpose |
| :--- | :--- | :--- | :--- |
| `gage_ui_draw_box()` | Output Stream | Plain Text | Draws clear structural borders loops bounding console regions. |
| `gage_ui_draw_divider()`| Output Stream | Plain Text | Draws linear separation tracks dividing visualization cells. |
| `gage_ui_color_red()` | Foreground | Red Channel | Renders subsequent text letters characters in pure red. |
| `gage_ui_color_green()` | Foreground | Green Channel| Renders subsequent text letters characters in pure green. |
| `gage_ui_color_blue()` | Foreground | Blue Channel | Renders subsequent text letters characters in pure blue. |
| `gage_ui_color_yellow()`| Foreground | Yellow Layer | Renders subsequent text letters characters in pure yellow. |
| `gage_ui_color_cyan()` | Foreground | Cyan Layer | Renders subsequent text letters characters in pure cyan. |
| `gage_ui_color_magenta()`| Foreground | Magenta Layer| Renders subsequent text letters characters in pure magenta. |
| `gage_ui_color_white()` | Foreground | White Matrix | Renders subsequent text letters characters in pure white. |
| `gage_ui_color_black()` | Foreground | Black Track | Renders subsequent text letters characters in pure black. |
| `gage_ui_bg_red()` | Background | Cell Area | Covers backend text blocks layout in structural red. |
| `gage_ui_bg_green()` | Background | Cell Area | Covers backend text blocks layout in structural green. |
| `gage_ui_bg_blue()` | Background | Cell Area | Covers backend text blocks layout in structural blue. |
| `gage_ui_bg_yellow()` | Background | Cell Area | Covers backend text blocks layout in structural yellow. |
| `gage_ui_bg_cyan()` | Background | Cell Area | Covers backend text blocks layout in structural cyan. |
| `gage_ui_bg_magenta()` | Background | Cell Area | Covers backend text blocks layout in structural magenta. |
| `gage_ui_bg_white()` | Background | Cell Area | Covers backend text blocks layout in structural white. |
| `gage_ui_bg_black()` | Background | Cell Area | Covers backend text blocks layout in structural black. |
| `gage_ui_style_reset()` | System State | All Resets | Strips out formatting properties from terminal tracks. |
| `gage_ui_style_bold()` | System State | Font Style | Amplifies text weighting bounds visibility configurations. |
| `gage_ui_style_dim()` | System State | Font Style | Scales char intensity variables downwards to drop glare. |
| `gage_ui_style_italic()`| System State | Font Style | Slants structural typography maps fields into italics. |
| `gage_ui_style_underline()`| System State| Text Effect | Trims character outlines baseline directly with highlights. |
| `gage_ui_style_blink()` | System State | Text Effect | Activates rapid cell refresh state transitions triggers. |
| `gage_ui_style_reverse()`| System State | Text Effect | Inverts foreground value registers with background sets. |
| `gage_ui_style_hidden()` | System State | Text Effect | Conceals char fields keeping data securely invisible. |
| `gage_ui_screen_clear()`| Console Screen| Full Clear | Purges visual grid allocations resetting tracking limits. |
| `gage_ui_cursor_move_up()`| Grid Tracker | Position Shift| Steps workspace view position pointer up by 1 grid cell line. |
| `gage_ui_cursor_move_down()`|Grid Tracker| Position Shift| Steps workspace view position pointer down by 1 grid cell line. |
| `gage_ui_cursor_hide()` | Grid Tracker | Visibility | Masks console typing tracking ticks during text screen animations. |
