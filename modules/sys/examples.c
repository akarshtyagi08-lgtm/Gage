#include <stdio.h>
#include "sys.c"

int main() {
    printf("=== GAGE PLATFORM KERNEL & ENVIRONMENT INTERCEPTOR DEMO ===\n\n");
    
    // 1. Native Identity Context Identifiers Audit
    printf("[Context] Process Descriptor Identifier (PID): %d\n", gage_sys_get_pid());
    printf("[Context] Parent Controller Identifier (PPID): %d\n", gage_sys_get_ppid());
    printf("[Context] System Page Allocation Size Const: %d bytes\n", gage_sys_get_page_size());

    // 2. Hardware Allocation Specs Queries
    printf("\n[Hardware] Querying Central Processing Core Matrix Data...\n");
    printf(" - Total Active Online Processing Cores Count: %d cores\n", gage_sys_get_cpu_cores());
    printf(" - Total Physical Memory Blocks Configured: %d pages\n", gage_sys_get_phys_pages());
    printf(" - Available Physical Memory Ready For Tasks: %d pages\n", gage_sys_get_avphys_pages());

    // 3. Current Live Platform Indicators Print Streams
    printf("\n[Platform OS Profile Indicators]:\n");
    gage_sys_print_os_release();
    printf("Kernel Revision: "); gage_sys_print_kernel();
    printf("Architecture Tag: "); gage_sys_print_architecture();
    printf("Machine Local Identity: "); gage_sys_print_hostname();

    // 4. Running Hardware Health Diagnostics Sensors 
    printf("\n[Sensors Health Diagnostics Audit Fields]:\n");
    printf("Current Core Temperature Millidegrees Mark: "); gage_sys_print_thermal();
    printf("Active Scheduler Load Profiles: "); gage_sys_print_threads_count();

    // 5. Shell Environment Pipeline Path Check
    printf("\n[Shell Environment Trajectory Markers]:\n");
    printf("Active Terminal Controller Context Profile: "); gage_sys_print_term_type();
    printf("Interpreter Execution Binary Directive Target: "); gage_sys_print_shell_path();

    // 6. Dynamic Custom Command Injection Test Execution Block
    printf("\n[Command Pipeline] Executing isolated memory tracking validation pipe...\n");
    int status = gage_sys_run_command("echo 'Gage Pipeline Test Verification Token: SUCCESS' && pwd");
    printf("[Command Pipeline] Trapped system interception status return code: %d\n", status);

    // 7. Safe Structural File Buffer Sync Operational Protocols
    printf("\n[Sync] Arming disk buffer flush sequence lines safely...\n");
    gage_sys_filesystem_sync();
    printf("[Sync] Kernel non-volatile cache matrices successfully harmonized with storage storage medium fields!\n");

    printf("\n=== DIAGNOSTIC SYSTEM SWEEP INTEGRATION SUCCESSFUL ===\n");
    return 0;
}
