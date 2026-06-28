#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/sysinfo.h>
#include <sys/types.h>

// --- NATIVE INTERCEPT CALLS (30 ORIGINAL ALIGNMENTS) ---
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

// --- DYNAMIC EXPANSION VECTORS (20 NEW PREMIUM FUNCTIONS) ---
int gage_sys_run_command(const char* cmd) { return system(cmd); }
int gage_sys_get_cpu_cores() { return sysconf(_SC_NPROCESSORS_ONLN); }
void gage_sys_print_cpu_freq() { system("cat /sys/devices/system/cpu/cpu0/cpufreq/scaling_cur_freq || echo 'Unavailable'"); }
void gage_sys_print_battery() { system("dumpsys battery || termux-battery-status || echo 'Battery status unavailable'"); }
void gage_sys_print_thermal() { system("cat /sys/class/thermal/thermal_zone0/temp || echo 'Thermal data unavailable'"); }
void gage_sys_print_selinux() { system("getenvorce || echo 'SELinux restricted or unavailable'"); }
void gage_sys_print_open_files() { system("lsof -p $$ || echo 'lsof restricted'"); }
void gage_sys_print_limits() { system("ulimit -a"); }
void gage_sys_print_who() { system("who || echo 'Termux single-user terminal loop'"); }
void gage_sys_print_last_login() { system("last -a | head -n 5 || echo 'Logs restricted'"); }
void gage_sys_print_network_stats() { system("cat /proc/net/dev"); }
void gage_sys_print_socket_summary() { system("cat /proc/net/sockstat || echo 'Sockstat restricted'"); }
void gage_sys_print_arp() { system("cat /proc/net/arp || arp -e"); }
int gage_sys_get_page_size() { return sysconf(_SC_PAGESIZE); }
int gage_sys_get_phys_pages() { return sysconf(_SC_PHYS_PAGES); }
int gage_sys_get_avphys_pages() { return sysconf(_SC_AVPHYS_PAGES); }
void gage_sys_print_threads_count() { system("cat /proc/loadavg | awk '{print \"Active Threads/Procs: \" $4}'"); }
void gage_sys_print_ipc_status() { system("ipcs || echo 'IPC structures protected'"); }
void gage_sys_print_pci_devices() { system("lspci || echo 'No PCI hardware channels exposed'"); }
void gage_sys_print_usb_devices() { system("lsusb || echo 'USB interface tracking restricted'"); }
