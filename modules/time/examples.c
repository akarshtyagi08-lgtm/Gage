#include <stdio.h>
#include "time.c"

int main() {
    printf("=== GAGE HIGH-PRECISION TIME PROFILER DEMO ===\n\n");
    
    // 1. Audit System Timestamp Metrics
    printf("[Clocks] Core UNIX Timestamp: %d\n", gage_time_stamp());
    printf("[Clocks] Live Millisecond Stamp: %d\n", gage_time_ms_stamp());
    printf("[Clocks] Timezone GMT Shift Offset: %d hours\n", gage_time_timezone_offset());

    // 2. Performance Profiling Sweep Loop
    printf("\n[Profiler] Launching Code Block Optimization Profiling...\n");
    int start_us = gage_time_us_stamp();
    
    // Simulate complex iterative compile loops weight
    int acc = 0;
    for(int i=0; i<500000; i++) { acc += (i % 3); }
    
    int end_us = gage_time_us_stamp();
    printf("[Profiler] Process Loop Execution Time: %d microseconds\n", gage_time_diff_seconds(end_us, start_us));

    // 3. Calendar Arithmetic Verification
    printf("\n[Calendar] Current Date Parameters: %d/%d/%d\n", gage_time_current_day(), gage_time_current_month(), gage_time_current_year());
    printf("[Calendar] Is Year 2026 a Leap Year? %s\n", gage_time_is_leap_year(2026) ? "Yes" : "No");
    printf("[Calendar] Days count inside February 2024: %d\n", gage_time_days_in_month(2, 2024));
    printf("[Calendar] Day tracking offset within active yearly loop: Day %d\n", gage_time_day_of_year());

    // 4. Time Metric Shifters Verification
    int now_ts = gage_time_stamp();
    int future_ts = gage_time_add_days(now_ts, 5);
    printf("\n[Offsets] Future Timestamp shifting (Now + 5 Days): %d\n", future_ts);
    printf("[Offsets] Reversing scale back via conversion scaler: %d days\n", gage_time_to_days(gage_time_diff_seconds(future_ts, now_ts)));

    // 5. Procedural Phase Validation Check
    printf("\n[Period] Active Temporal Zone Flags:\n");
    printf(" - Morning? %s\n", gage_time_is_morning() ? "TRUE" : "FALSE");
    printf(" - Afternoon? %s\n", gage_time_is_afternoon() ? "TRUE" : "FALSE");
    printf(" - Evening? %s\n", gage_time_is_evening() ? "TRUE" : "FALSE");
    printf(" - Night? %s\n", gage_time_is_night() ? "TRUE" : "FALSE");

    // 6. Execution Delays Testing Node
    printf("\n[Delay] Arming high-speed delay block... (Pausing exactly 250ms)\n");
    gage_time_sleep_ms(250);
    printf("[Delay] Thread re-engaged successfully!\n");

    printf("\n=== PROFILER SWEEP COMPLETE ===\n");
    return 0;
}
