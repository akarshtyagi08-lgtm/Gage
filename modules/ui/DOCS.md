# 🎨 The Ultimate Gage Terminal User Interface (TUI) Module (v4.0)

Welcome to the comprehensive system architectural documentation for the Gage Engine User Interface manipulation library. This module contains 50 production-ready, highly atomic C functions engineered to turn standard serial console text streams into fully customized, high-performance, true-color terminal tracking grids.

Building an interactive TUI within terminal windows (like Termux, bash, or SSH loops) can heavily restrict hardware speed if you spam text rewrites. Gage circumvents this bottleneck by employing low-level ANSI VT100 and XTERM command sequences directly piped into stdout blocks, completely eliminating the need for heavyweight third-party libraries like curses or ncurses.

---

## 🏗️ Architecture & Rendering Philosophy

The core philosophy governing the `ui` library is instant visual execution tracking. Every style modification, canvas update, or coordinate displacement is routed sequentially into stdout. To prevent video clipping or frame delay on mobile platforms, explicit byte synchronization is enforced via `fflush(stdout)` anchors directly inside the execution wrappers.

### Memory & Spatial Limits:
- **Allocation Footprint:** O(1) static space footprint. No heap allocation, preventing memory leaks on loops.
- **Hardware Agnostic:** Compiles under any standard clang runtime with support for 24-bit True Color profiles.

---

## 🎨 Section 1: Color Palettes (Dynamic RGB & Hex)
These functions control standard text character foreground styles and background cell matrix block fills dynamically.

### 1. `gage_ui_set_text_color_rgb(r, g, b)`
- **Functional Description:** Maps a true-color 24-bit RGB value block to all subsequent characters printed on stdout.
- **Parameters:**
  - `r` (int): Red channel intensity parameter bounded from 0 to 255.
  - `g` (int): Green channel intensity parameter bounded from 0 to 255.
  - `b` (int): Blue channel intensity parameter bounded from 0 to 255.
- **Internal Logic:** Automatically isolates channel parameters via an `& 0xFF` masking gate to prevent out-of-bounds escape faults inside standard tracking sequences.

### 2. `gage_ui_set_bg_color_rgb(r, g, b)`
- **Functional Description:** Establishes the block character background tile cell coloring dynamically.
- **Parameters:** Same bit thresholds as text color parameters fields (0-255 RGB layout).

### 3. `gage_ui_color_hex_text(hex)`
- **Functional Description:** Accepts a unified Hex color integer configuration code directly, extracting the RGB channels automatically via fast bitwise shift channels before outputting properties lines.
- **Parameters:**
  - `hex` (int): Standard Hex value mask integer (e.g., `0xFF00AA`).

### 4. `gage_ui_color_hex_bg(hex)`
- **Functional Description:** Implements unified Hex color rendering for background terminal grids cells blocks tracking lines.

### 5. `gage_ui_set_text_color_256(code)`
- **Functional Description:** Limits color registers directly down to standard index rows mapping fields matching 8-bit color arrays (0-255).
- **Parameters:** `code` (int) - Index of the target 256-color spreadsheet block configuration.

### 6. `gage_ui_set_bg_color_256(code)`
- **Functional Description:** 8-bit standard index color mapping properties wrapper for block text fields background matrices.

---

## 📜 Section 2: Legacy Backward Compatibility Layers
These functions provide direct parameterless access to simple standard VT100 8-color tables to retain structural project setups.

### 7. `gage_ui_color_red()`
- **Effect:** Sets text tracking lines foreground to simple red.

### 8. `gage_ui_color_green()`
- **Effect:** Sets text tracking lines foreground to simple green.

### 9. `gage_ui_color_blue()`
- **Effect:** Sets text tracking lines foreground to simple blue.

### 10. `gage_ui_color_yellow()`
- **Effect:** Sets text tracking lines foreground to simple yellow.

### 11. `gage_ui_color_cyan()`
- **Effect:** Sets text tracking lines foreground to simple cyan.

### 12. `gage_ui_color_magenta()`
- **Effect:** Sets text tracking lines foreground to simple magenta.

### 13. `gage_ui_color_white()`
- **Effect:** Sets text tracking lines foreground to simple white.

### 14. `gage_ui_color_black()`
- **Effect:** Sets text tracking lines foreground to simple black.

### 15. `gage_ui_bg_red()`
- **Effect:** Sets text background matrix blocks to simple red.

### 16. `gage_ui_bg_green()`
- **Effect:** Sets text background matrix blocks to simple green.

### 17. `gage_ui_bg_blue()`
- **Effect:** Sets text background matrix blocks to simple blue.

### 18. `gage_ui_bg_yellow()`
- **Effect:** Sets text background matrix blocks to simple yellow.

### 19. `gage_ui_bg_cyan()`
- **Effect:** Sets text background matrix blocks to simple cyan.

### 20. `gage_ui_bg_magenta()`
- **Effect:** Sets text background matrix blocks to simple magenta.

### 21. `gage_ui_bg_white()`
- **Effect:** Sets text background matrix blocks to simple white.

### 22. `gage_ui_bg_black()`
- **Effect:** Sets text background matrix blocks to simple black.

---

## 🔤 Section 3: Typography Font Styling Controllers
Modifies individual char layout behavior traits without resetting absolute coordinates channels.

### 23. `gage_ui_style_reset()`
- **Description:** Instantly cleans out all active coloring parameters, bold states, blink tracks, and highlights profiles, returning text execution lines straight to environment standard defaults.

### 24. `gage_ui_style_bold()`
- **Description:** Amplifies text weighting bounds visibility configurations.

### 25. `gage_ui_style_dim()`
- **Description:** Diminishes style rendering brightness to produce low-contrast text loops.

### 26. `gage_ui_style_italic()`
- **Description:** Slants character visual grids components fields maps lines.

### 27. `gage_ui_style_underline()`
- **Description:** Inserts a solid character outline tracking baseline path beneath data strings.

### 28. `gage_ui_style_blink()`
- **Description:** Activates rapid refresh interval character visibility state shifts triggers.

### 29. `gage_ui_style_reverse()`
- **Description:** Interchanges active text color foreground parameters values directly with backgrounds fields.

### 30. `gage_ui_style_hidden()`
- **Description:** Conceals visual console data components while maintaining column alignments configurations.

### 31. `gage_ui_style_strikethrough()`
- **Description:** Renders a horizontal strike vector line across the exact midpoint axis of typography text lines.

---

## 🧼 Section 4: Canvas Clear Manipulators & Buffer Resets
Wipes down target display matrices safely to guarantee artifacts-free screen loops.

### 32. `gage_ui_reset_canvas()`
- **Description:** Completely flushes formatting states, drops style traits, purges active coordinates maps, and returns screen tracking loops home to coordinate point (1,1).

### 33. `gage_ui_screen_clear()`
- **Description:** Alternate wrapper to clean and reinitialize terminal windows allocations spaces.

### 34. `gage_ui_clear_line()`
- **Description:** Erases character data across the entire layout span of the currently active cursor text row.

### 35. `gage_ui_clear_line_to_end()`
- **Description:** Drops text indicators starting directly from the current cursor point to the right margin wall.

### 36. `gage_ui_clear_line_to_start()`
- **Description:** Drops text indicators starting from the current cursor point tracking backwards to the left boundary.

---

## 🎯 Section 5: Cursor Matrix Grid Tracking & Coordinates Control
Positions display print pointers dynamically across the 2D terminal workspace coordinates layout fields.

### 37. `gage_ui_move_cursor(x, y)`
- **Description:** Instantly sets the character printing baseline track straight to column `x` and row `y`.
- **Parameters:** `x` (int) - Column coordinate tracking index. `y` (int) - Row coordinate tracking index.

### 38. `gage_ui_cursor_up(n)`
- **Description:** Shifts cursor coordinates up vertically by a precise factor of N cells lines.

### 39. `gage_ui_cursor_down(n)`
- **Description:** Shifts cursor coordinates down vertically by a precise factor of N cells lines.

### 40. `gage_ui_cursor_forward(n)`
- **Description:** Shifts cursor coordinates forward horizontally by N cells rows.

### 41. `gage_ui_cursor_backward(n)`
- **Description:** Shifts cursor coordinates backward horizontally by N cells rows.

### 42. `gage_ui_save_cursor()`
- **Description:** Commands the system to store the active cursor position indices variables parameters maps inside an internal hardware register stack.

### 43. `gage_ui_restore_cursor()`
- **Description:** Pops the saved coordinate parameters back to restore tracking exactly where the line left off.

### 44. `gage_ui_cursor_hide()`
- **Description:** Completely hides the console typing indicator mark tick during rendering animations blocks.

### 45. `gage_ui_cursor_show()`
- **Description:** Restores visual console cursor visibility indicators tracking parameters.

---

## 🎛️ Section 6: Window Scroll Mechanics & Alternate Buffers
Manages advanced multi-buffer screen terminal workspaces constraints behavior traits.

### 46. `gage_ui_set_scroll_region(top, bottom)`
- **Description:** Isolates a precise horizontal row band (from `top` to `bottom`) to handle scrolling, freezing the rest of the terminal workspace context solid.
- **Parameters:** `top` (int) - Upper boundary line index. `bottom` (int) - Lower boundary line index.

### 47. `gage_ui_reset_scroll_region()`
- **Description:** Disables scrolling isolation frames maps fields back to defaults.

### 48. `gage_ui_scroll_up(n)`
- **Description:** Forcefully rolls text block lines upward inside isolated scroll tracking regions.

### 49. `gage_ui_scroll_down(n)`
- **Description:** Forcefully rolls text block lines downward inside isolated scroll tracking regions.

### 50. `gage_ui_enable_alt_buffer()`
- **Description:** Swaps into a clean secondary display layer memory space (Alternate Buffer). This allows game loops to clean and rewrite cells without corrupting user shell commands terminal logs history tracks.

---
*End of Comprehensive TUI Module Documentation.*
