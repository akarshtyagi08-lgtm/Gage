#include <time.h>
#include <unistd.h>

int gage_time_stamp() { return (int)time(NULL); }
void gage_time_sleep_sec(int s) { sleep(s); }
void gage_time_sleep_ms(int ms) { usleep(ms * 1000); }
int gage_time_current_year() { time_t t=time(NULL); struct tm *m=localtime(&t); return m->tm_year+1900; }
int gage_time_current_month() { time_t t=time(NULL); struct tm *m=localtime(&t); return m->tm_mon+1; }
int gage_time_current_day() { time_t t=time(NULL); struct tm *m=localtime(&t); return m->tm_mday; }
int gage_time_current_hour() { time_t t=time(NULL); struct tm *m=localtime(&t); return m->tm_hour; }
int gage_time_current_min() { time_t t=time(NULL); struct tm *m=localtime(&t); return m->tm_min; }
int gage_time_current_sec() { time_t t=time(NULL); struct tm *m=localtime(&t); return m->tm_sec; }
int gage_time_is_leap_year(int y) { return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0); }
int gage_time_days_in_month(int m, int y) { if(m==2) return ((y%4==0 && y%100!=0)||(y%400==0))?29:28; return (m==4||m==6||m==9||m==11)?30:31; }
int gage_time_day_of_year() { time_t t=time(NULL); struct tm *m=localtime(&t); return m->tm_yday; }
int gage_time_day_of_week() { time_t t=time(NULL); struct tm *m=localtime(&t); return m->tm_wday; }
int gage_time_is_dst() { time_t t=time(NULL); struct tm *m=localtime(&t); return m->tm_isdst; }
int gage_time_cpu_ticks() { return (int)clock(); }
int gage_time_add_hours(int t, int h) { return t + (h * 3600); }
int gage_time_add_days(int t, int d) { return t + (d * 86400); }
int gage_time_diff_seconds(int t1, int t2) { return t1 - t2; }
int gage_time_diff_minutes(int t1, int t2) { return (t1 - t2)/60; }
int gage_time_diff_hours(int t1, int t2) { return (t1 - t2)/3600; }
int gage_time_diff_days(int t1, int t2) { return (t1 - t2)/86400; }
int gage_time_to_minutes(int s) { return s / 60; }
int gage_time_to_hours(int s) { return s / 3600; }
int gage_time_to_days(int s) { return s / 86400; }
int gage_time_clock_runtime() { return (int)(clock() / CLOCKS_PER_SEC); }
int gage_time_make_timestamp(int h, int m, int s) { return (h*3600)+(m*60)+s; }
int gage_time_is_morning() { time_t t=time(NULL); struct tm *m=localtime(&t); return m->tm_hour < 12; }
int gage_time_is_afternoon() { time_t t=time(NULL); struct tm *m=localtime(&t); return m->tm_hour >= 12 && m->tm_hour < 17; }
int gage_time_is_evening() { time_t t=time(NULL); struct tm *m=localtime(&t); return m->tm_hour >= 17 && m->tm_hour < 21; }
int gage_time_is_night() { time_t t=time(NULL); struct tm *m=localtime(&t); return m->tm_hour >= 21 || m->tm_hour < 5; }
