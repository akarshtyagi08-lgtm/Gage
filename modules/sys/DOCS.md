# 🤖 System Interface Module Documentation

The `sys` module hooks Gage scripts directly into kernel calls, operating system commands, diagnostic interfaces, and platform metrics fields.

## Complete Feature Matrix

| Feature Function | Parameter | Output Target | Low-Level Operation & Purpose |
| :--- | :--- | :--- | :--- |
| `gage_sys_print_kernel()` | None | Terminal Stream| Prints the platform kernel revision data strings. |
| `gage_sys_print_architecture()`| None | Terminal Stream| Prints hardware architecture profile layout tags. |
| `gage_sys_print_ram_usage()` | None | Terminal Stream| Outputs active RAM usage matrix scaled directly in megabytes. |
| `gage_sys_print_disk_space()` | None | Terminal Stream| Parses structural mounting layers disk metrics configurations. |
| `gage_sys_print_username()` | None | Terminal Stream| Extracts active process security context user title. |
| `gage_sys_print_uptime()` | None | Terminal Stream| Reports platform duration stability trackers values. |
| `gage_sys_print_date()` | None | Terminal Stream| Renders regional standard calendar clock strings profiles. |
| `gage_sys_print_env()` | None | Terminal Stream| Dumps system environment dictionary parameter rows. |
| `gage_sys_get_pid()` | None | Unsigned Int | Returns the numerical process descriptor mapping integer. |
| `gage_sys_get_ppid()` | None | Unsigned Int | Returns parent workspace controller alignment identifier. |
| `gage_sys_clean_cache()` | None | Mock Pipeline | Dispatches structural storage purge validation mock runs. |
| `gage_sys_trigger_exit(code)`| `code` (Int) | Shell Process | Halts running process immediately returning exit signature flags. |
| `gage_sys_trigger_abort()` | None | Exception | Forces SIGABRT core drops for debug diagnostics sweeps. |
| `gage_sys_filesystem_sync()`| None | Kernel Buffers | Flushes pending operational sector updates to non-volatile disks. |
| `gage_sys_print_cpu_info()` | None | Terminal Stream| Evaluates processing core architectural properties lists. |
| `gage_sys_print_mem_info()` | None | Terminal Stream| Pulls advanced hardware paging allocations fields metrics maps. |
| `gage_sys_print_os_release()` | None | Terminal Stream| Exposes distributions meta data descriptors tracking lines. |
| `gage_sys_print_hostname()` | None | Terminal Stream| Resolves network machine domain identification properties. |
| `gage_sys_print_shell_path()` | None | Terminal Stream| Exposes default system console tracking targets directions. |
| `gage_sys_print_term_type()` | None | Terminal Stream| Identifies standard interactive visual formatting capabilities tags. |
| `gage_sys_print_user_groups()`| None | Terminal Stream| Dumps role permission authorization categories fields indices. |
| `gage_sys_print_process_list()`| None | Terminal Stream| Maps currently scheduled workspace thread instances details tables. |
| `gage_sys_print_network_routes()`| None | Terminal Stream| Evaluates out-of-boundary packet switching targets paths. |
| `gage_sys_print_dns_servers()`| None | Terminal Stream| Reports lookup server routing alignments indices definitions. |
| `gage_sys_print_hardware_clocks()`| None | Terminal Stream| Validates drift anomalies against atomic clock cycles maps. |
| `gage_sys_print_block_devices()`| None | Terminal Stream| Discovers structural device attachment mountings profiles matrices. |
| `gage_sys_print_mounted()` | None | Terminal Stream| Audits filesystem mount privilege parameters mapping maps. |
| `gage_sys_print_interrupts()` | None | Terminal Stream| Scans processor core electrical event trace indicators records. |
| `gage_sys_print_loaded_modules()`| None | Terminal Stream| Inspects base driver signature definitions tracking lists. |
| `gage_sys_print_kernel_logs()`| None | Terminal Stream| Pulls foundational boot event log alerts from kernel rings. |
