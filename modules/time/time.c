#include <time.h>
#include <unistd.h>
#include <sys/time.h>

// --- CORE SYSTEM CHRONOMETERS ---
int gage_time_stamp() { return (int)time(NULL); }
int gage_time_ms_stamp() { struct timeval tv; gettimeofday(&tv, NULL); return (int)(tv.tv_sec * 1000 + tv.tv_usec / 1000); }
int gage_time_us_stamp() { struct timeval tv; gettimeofday(&tv, NULL); return (int)(tv.tv_sec * 1000000 + tv.tv_usec); }
int gage_time_cpu_ticks() { return (int)clock(); }
int gage_time_ticks_per_sec() { return (int)CLOCKS_PER_SEC; }

// --- THREAD FREEZERS (EXECUTION PAUSES) ---
void gage_time_sleep_sec(int s) { sleep(s); }
void gage_time_sleep_ms(int ms) { usleep(ms * 1000); }
void gage_time_sleep_us(int us) { usleep(us); }

// --- LIVE CALENDAR CURRENT EXTRACTORS ---
int gage_time_current_year() { time_t t=time(NULL); struct tm *m=localtime(&t); return m->tm_year+1900; }
int gage_time_current_month() { time_t t=time(NULL); struct tm *m=localtime(&t); return m->tm_mon+1; }
int gage_time_current_day() { time_t t=time(NULL); struct tm *m=localtime(&t); return m->tm_mday; }
int gage_time_current_hour() { time_t t=time(NULL); struct tm *m=localtime(&t); return m->tm_hour; }
int gage_time_current_min() { time_t t=time(NULL); struct tm *m=localtime(&t); return m->tm_min; }
int gage_time_current_sec() { time_t t=time(NULL); struct tm *m=localtime(&t); return m->tm_sec; }
int gage_time_day_of_year() { time_t t=time(NULL); struct tm *m=localtime(&t); return m->tm_yday; }
int gage_time_day_of_week() { time_t t=time(NULL); struct tm *m=localtime(&t); return m->tm_wday; }
int gage_time_is_dst() { time_t t=time(NULL); struct tm *m=localtime(&t); return m->tm_isdst; }

// --- CALENDAR ALGORITHMIC CALCULATORS ---
int gage_time_is_leap_year(int y) { return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0); }
int gage_time_days_in_month(int m, int y) { if(m==2) return ((y%4==0 && y%100!=0)||(y%400==0))?29:28; return (m==4||m==6||m==9||m==11)?30:31; }
int gage_time_century(int y) { return (y / 100) + 1; }
int gage_time_is_weekend(int d, int m, int y) { struct tm t = {0}; t.tm_mday = d; t.tm_mon = m - 1; t.tm_year = y - 1900; mktime(&t); return (t.tm_wday == 0 || t.tm_wday == 6); }

// --- TIMELINE ANCHOR SHIFTS & OFFSETS ---
int gage_time_add_secs(int ts, int s) { return ts + s; }
int gage_time_add_mins(int ts, int m) { return ts + (m * 60); }
int gage_time_add_hours(int ts, int h) { return ts + (h * 3600); }
int gage_time_add_days(int ts, int d) { return ts + (d * 86400); }
int gage_time_add_weeks(int ts, int w) { return ts + (w * 604800); }
int gage_time_sub_secs(int ts, int s) { return ts - s; }
int gage_time_sub_mins(int ts, int m) { return ts - (m * 60); }
int gage_time_sub_hours(int ts, int h) { return ts - (h * 3600); }
int gage_time_sub_days(int ts, int d) { return ts - (d * 86400); }
int gage_time_sub_weeks(int ts, int w) { return ts - (w * 604800); }

// --- INTERVAL DELTA COMPARATORS ---
int gage_time_diff_seconds(int t1, int t2) { return t1 - t2; }
int gage_time_diff_minutes(int t1, int t2) { return (t1 - t2) / 60; }
int gage_time_diff_hours(int t1, int t2) { return (t1 - t2) / 3600; }
int gage_time_diff_days(int t1, int t2) { return (t1 - t2) / 86400; }

// --- METRIC CONVERSION SCALERS ---
int gage_time_to_minutes(int s) { return s / 60; }
int gage_time_to_hours(int s) { return s / 3600; }
int gage_time_to_days(int s) { return s / 86400; }
int gage_time_mins_to_secs(int m) { return m * 60; }
int gage_time_hours_to_secs(int h) { return h * 3600; }
int gage_time_days_to_secs(int d) { return d * 86400; }

// --- CHRONO ASSEMPLERS & PACKAGERS ---
int gage_time_make_timestamp(int h, int m, int s) { return (h * 3600) + (m * 60) + s; }
int gage_time_make_epoch(int d, int mon, int y) { struct tm t = {0}; t.tm_mday = d; t.tm_mon = mon - 1; t.tm_year = y - 1900; return (int)mktime(&t); }

// --- PROCEDURAL PERIOD VALIDATORS ---
int gage_time_is_morning() { time_t t=time(NULL); struct tm *m=localtime(&t); return m->tm_hour < 12; }
int gage_time_is_afternoon() { time_t t=time(NULL); struct tm *m=localtime(&t); return m->tm_hour >= 12 && m->tm_hour < 17; }
int gage_time_is_evening() { time_t t=time(NULL); struct tm *m=localtime(&t); return m->tm_hour >= 17 && m->tm_hour < 21; }
int gage_time_is_night() { time_t t=time(NULL); struct tm *m=localtime(&t); return m->tm_hour >= 21 || m->tm_hour < 5; }

// --- HARDWARE BENCHMARKS & LIFESCALE ---
int gage_time_clock_runtime() { return (int)(clock() / CLOCKS_PER_SEC); }
int gage_time_timezone_offset() { time_t t = time(NULL); struct tm *g = gmtime(&t); time_t tg = mktime(g); struct tm *l = localtime(&t); time_t tl = mktime(l); return (int)(tl - tg) / 3600; }
