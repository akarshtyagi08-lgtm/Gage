#include <stdio.h>
#include "net.c"

int main() {
    printf("=== GAGE DYNAMIC NETWORK INTERFACE & SOCKET UTILITIES DEMO ===\n\n");

    // 1. Validation Network Connectivity Status
    printf("[Connectivity] Checking absolute global link state parameters...\n");
    if (gage_net_is_connected()) {
        printf("[Connectivity] Status confirmation: ONLINE ENGINE PIPELINE DETECTED\n");
    } else {
        printf("[Connectivity] Warning confirmation: OFFLINE LOCAL THREAD ISOLATION ACTIVE\n");
    }

    // 2. Direct Core Router Tracking Route Discovery
    printf("\n[Routing Parameters] Extracting internal network gateway markers:\n");
    gage_net_print_gateway_ip();

    // 3. Dynamic Targeted Ping Checks via Input Arguments
    const char* target_host = "cloudflare.com";
    printf("\n[Probes] Launching targeted network ping probe onto host '%s':\n", target_host);
    gage_net_ping_custom(target_host);

    // 4. Custom Remote Socket Interface Check
    int target_port = 443;
    printf("\n[Sockets Audit] Testing remote transport security gate on %s:%d...\n", target_host, target_port);
    int port_status = gage_net_check_port_custom(target_host, target_port);
    printf("[Sockets Audit] Connection analysis response: %s\n", port_status ? "PORT ACTIVE (OPEN)" : "PORT REFUSED (CLOSED)");

    // 5. Dynamic Web Server Status Verification Call
    const char* target_url = "https://google.com";
    printf("\n[HTTP Subsystem] Querying remote status indicator headers for '%s':\n", target_url);
    printf("HTTP Response Return Code: ");
    gage_net_http_get_status(target_url);

    // 6. Zone File Record Interceptions Check
    printf("\n[DNS Records Sub-Engine] Fetching text verification tokens data for 'google.com':\n");
    gage_net_nslookup_txt("google.com");

    // 7. Security Layer SSL Certificates Metrics Check
    printf("\n[Security Layer Audits] Fetching certificate expiry timelines maps for '%s':\n", target_host);
    gage_net_ssl_expiry_check(target_host);

    // 8. Interface State Profile Dump Sweep
    printf("\n[Adapter Subsystem] Extracting metrics table for local link frames:\n");
    gage_net_netstat_interface("wlan0");

    printf("\n=== NETWORK UTILITIES MODULE ENGINE SWEEP SUCCESSFUL ===\n");
    return 0;
}
