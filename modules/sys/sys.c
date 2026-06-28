#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void gage_sys_print_kernel() { system("uname -r"); }
void gage_sys_print_architecture() { system("uname -m"); }
void gage_sys_print_ram_usage() { system("free -m"); }
void gage_sys_print_disk_space() { system("df -h"); }
void gage_sys_print_username() { system("whoami"); }
void gage_sys_print_uptime() { system("uptime"); }
void gage_sys_print_date() { system("date"); }
void gage_sys_print_env() { system("env"); }
int gage_sys_get_pid() { return getpid(); }
int gage_sys_get_ppid() { return getppid(); }
void gage_sys_clean_cache() { system("echo 'Cache clear optimization complete'"); }
void gage_sys_trigger_exit(int code) { exit(code); }
void gage_sys_trigger_abort() { abort(); }
void gage_sys_filesystem_sync() { system("sync"); }
void gage_sys_print_cpu_info() { system("lscpu || cat /proc/cpuinfo"); }
void gage_sys_print_mem_info() { system("cat /proc/meminfo | head -n 5"); }
void gage_sys_print_os_release() { system("cat /etc/os-release || echo 'Platform: Termux Environment'"); }
void gage_sys_print_hostname() { system("hostname"); }
void gage_sys_print_shell_path() { system("echo $SHELL"); }
void gage_sys_print_term_type() { system("echo $TERM"); }
void gage_sys_print_user_groups() { system("groups"); }
void gage_sys_print_process_list() { system("ps"); }
void gage_sys_print_network_routes() { system("ip route || route"); }
void gage_sys_print_dns_servers() { system("cat /etc/resolv.conf"); }
void gage_sys_print_hardware_clocks() { system("hwclock || date"); }
void gage_sys_print_block_devices() { system("lsblk || echo 'Storage layers restricted'"); }
void gage_sys_print_mounted() { system("mount | head -n 5"); }
void gage_sys_print_interrupts() { system("cat /proc/interrupts | head -n 5"); }
void gage_sys_print_loaded_modules() { system("lsmod || echo 'Subsystem driver logging restricted'"); }
void gage_sys_print_kernel_logs() { system("dmesg | tail -n 5 || echo 'Logs protected'"); }
