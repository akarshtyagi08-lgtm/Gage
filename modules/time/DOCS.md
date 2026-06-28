# 🕒 High-Precision Time Module Documentation

The `time` module includes 30 core timing components, execution delay engines, clock parser wrappers, and calendar tracking utilities for Gage.

## Complete Feature Matrix

| Feature Function | Parameters | Return Scope | Functional Description |
| :--- | :--- | :--- | :--- |
| `gage_time_stamp()` | None | UNIX seconds | Fetches the universal clock tracking timestamp factor. |
| `gage_time_sleep_sec(s)` | `s` (Int) | Void | Freezes execution thread timelines by full seconds increments. |
| `gage_time_sleep_ms(ms)` | `ms` (Int) | Void | High-precision delay engine mapping millisecond scales. |
| `gage_time_current_year()` | None | Current Year | Returns the active year calendar number. |
| `gage_time_current_month()`| None | Month (1-12) | Returns the numerical index configuration of the current month. |
| `gage_time_current_day()` | None | Day (1-31) | Pulls the active monthly day count offset. |
| `gage_time_current_hour()` | None | Hour (0-23) | Parses military standard structural hour scales. |
| `gage_time_current_min()` | None | Minute (0-59)| Extracts current clock minute boundaries counters indicators. |
| `gage_time_current_sec()` | None | Second (0-59)| Extracts active ticking seconds markers profiles. |
| `gage_time_is_leap_year()` | `year` (Int) | `0` or `1` | Validates standard modular rules determining leap cycles. |
| `gage_time_days_in_month()`| `mon`, `year` | Days Count | Calculates structural constraints limit values for months. |
| `gage_time_day_of_year()` | None | Day (0-365) | Counts accumulated days elapsed since the yearly cycle reset. |
| `gage_time_day_of_week()` | None | Day (0-6) | Returns active structural tracking day vectors indices (0=Sun). |
| `gage_time_is_dst()` | None | `0` or `1` | Validates environment regional daylight saving alignments status. |
| `gage_time_cpu_ticks()` | None | CPU Ticks Int | Returns direct execution profiling metric from the processor core. |
| `gage_time_add_hours(t, h)`| Time, Hours | Future time | Steps timestamps forward inside target timeline parameters fields. |
| `gage_time_add_days(t, d)` | Time, Days | Future time | Steps timestamps forward by designated structural day scales. |
| `gage_time_diff_seconds()` | `t1`, `t2` | Delta Seconds | Resolves standard execution duration parameters deltas equations. |
| `gage_time_diff_minutes()` | `t1`, `t2` | Delta Minutes | Compares profiles spacing values down into full minutes scales. |
| `gage_time_diff_hours()` | `t1`, `t2` | Delta Hours | Evaluates structural time fields spacing down into hours layers. |
| `gage_time_diff_days()` | `t1`, `t2` | Delta Days | Measures structural intervals separation by full days layout. |
| `gage_time_to_minutes(s)` | `secs` (Int) | Minutes scale| Scales raw seconds integers indicators into standard minutes. |
| `gage_time_to_hours(s)` | `secs` (Int) | Hours scale | Scales raw seconds integers indicators into standard hours. |
| `gage_time_to_days(s)` | `secs` (Int) | Days scale | Scales raw seconds integers indicators into standard calendar days. |
| `gage_time_clock_runtime()`| None | App seconds | Tracks running thread lifespan metrics directly from boot phase. |
| `gage_time_make_timestamp()`| `h`, `m`, `s` | Custom scale | Packages manual variables inputs directly inside unified tracking frames. |
| `gage_time_is_morning()` | None | `0` or `1` | Evaluation flag verifying early morning calendar timelines criteria. |
| `gage_time_is_afternoon()`| None | `0` or `1` | Evaluation flag verifying mid-day calendar timelines criteria. |
| `gage_time_is_evening()` | None | `0` or `1` | Evaluation flag verifying late evening calendar timelines criteria. |
| `gage_time_is_night()` | None | `0` or `1` | Evaluation flag verifying nightly calendar timelines operational states. |
