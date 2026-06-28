#include <time.h>
#include <unistd.h>

// Returns the standard global UNIX epoch timestamp in seconds
int gage_time_stamp() { return (int)time(NULL); }

// Freezes program execution thread for a custom duration of seconds
void gage_time_sleep_sec(int s) { sleep(s); }

// Freezes program execution thread for a custom duration of milliseconds
void gage_time_sleep_ms(int ms) { usleep(ms * 1000); }

// Extracts the current calendar year calculation boundary from the OS clock
int gage_time_current_year() { time_t t=time(NULL); struct tm *m=localtime(&t); return m->tm_year+1900; }

// Extracts the current calendar month tracking metric (1 to 12)
int gage_time_current_month() { time_t t=time(NULL); struct tm *m=localtime(&t); return m->tm_mon+1; }

// Extracts the current monthly calendar day integer component
int gage_time_current_day() { time_t t=time(NULL); struct tm *m=localtime(&t); return m->tm_mday; }

// Extracts the current clock hour value matching military 24-hour timelines
int gage_time_current_hour() { time_t t=time(NULL); struct tm *m=localtime(&t); return m->tm_hour; }

// Extracts the current runtime clock minute marker constraint
int gage_time_current_min() { time_t t=time(NULL); struct tm *m=localtime(&t); return m->tm_min; }

// Extracts the current clock execution seconds ticking parameter
int gage_time_current_sec() { time_t t=time(NULL); struct tm *m=localtime(&t); return m->tm_sec; }

// Checks if a designated calendar year criteria qualifies as a leap year
int gage_time_is_leap_year(int y) { return (y%4==0 && y%100!=0)||(y%400==0); }

// Evaluates the exact structural days cap capacity belonging to a specific target month
int gage_time_days_in_month(int m, int y) { if(m==2) return ((y%4==0 && y%100!=0)||(y%400==0))?29:28; return (m==4||m==6||m==9||m==11)?30:31; }

// Returns the accumulated day timeline offset marker tracking inside the current year
int gage_time_day_of_year() { time_t t=time(NULL); struct tm *m=localtime(&t); return m->tm_yday; }

// Extracts the day sequence tracking index matching the active week cycle (0-6)
int gage_time_day_of_week() { time_t t=time(NULL); struct tm *m=localtime(&t); return m->tm_wday; }

// Validates whether Daylight Saving Time offsets are globally active inside the environment
int gage_time_is_dst() { time_t t=time(NULL); struct tm *m=localtime(&t); return m->tm_isdst; }

// Returns high-precision hardware CPU cycle execution ticks counters profiles
int gage_time_cpu_ticks() { return (int)clock(); }

// Offsets a given timestamp value directly forward by a designated hour variable capacity
int gage_time_add_hours(int t, int h) { return t + (h * 3600); }

// Offsets a given timestamp value directly forward by a designated day variable capacity
int gage_time_add_days(int t, int d) { return t + (d * 86400); }

// Calculates raw delta margins variations tracking intervals strictly in seconds
int gage_time_diff_seconds(int t1, int t2) { return t1 - t2; }

// Calculates delta margins intervals conversions matching clean minute limits
int gage_time_diff_minutes(int t1, int t2) { return (t1 - t2)/60; }

// Calculates delta variations metrics timelines intervals matching clear hours metrics
int gage_time_diff_hours(int t1, int t2) { return (t1 - t2)/3600; }

// Calculates timeline spacing separations boundaries matching full calendar days steps
int gage_time_diff_days(int t1, int t2) { return (t1 - t2)/86400; }

// Utility mathematical transformation processing raw seconds directly down into minutes scaling
int gage_time_to_minutes(int s) { return s / 60; }

// Utility mathematical transformation processing raw seconds directly down into hours scaling
int gage_time_to_hours(int s) { return s / 3600; }

// Utility mathematical transformation processing raw seconds directly down into calendar days scaling
int gage_time_to_days(int s) { return s / 86400; }

// Returns running application timeline indicators trackings directly scaled in full seconds
int gage_time_clock_runtime() { return (int)(clock() / CLOCKS_PER_SEC); }

// Assembles manual clock components indicators directly into a secondary absolute metrics baseline
int gage_time_make_timestamp(int h, int m, int s) { return (h*3600)+(m*60)+s; }

// Conditional checker flag identifying early morning operational hours timelines
int gage_time_is_morning() { time_t t=time(NULL); struct tm *m=localtime(&t); return m->tm_hour < 12; }

// Conditional checker flag identifying afternoon operational hours timelines
int gage_time_is_afternoon() { time_t t=time(NULL); struct tm *m=localtime(&t); return m->tm_hour >= 12 && m->tm_hour < 17; }

// Conditional checker flag identifying evening operational hours timelines
int gage_time_is_evening() { time_t t=time(NULL); struct tm *m=localtime(&t); return m->tm_hour >= 17 && m->tm_hour < 21; }

// Conditional checker flag identifying night operational hours timelines
int gage_time_is_night() { time_t t=time(NULL); struct tm *m=localtime(&t); return m->tm_hour >= 21 || m->tm_hour < 5; }
