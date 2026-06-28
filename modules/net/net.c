#include <stdlib.h>

void gage_net_ping_dns() { system("ping -c 1 8.8.8.8"); }
void gage_net_curl_headers() { system("curl -I google.com"); }
void gage_net_wget_spider() { system("wget -q --spider google.com"); }
void gage_net_print_interfaces() { system("ip a || ifconfig"); }
void gage_net_print_sockets() { system("ss -tuln || netstat -tuln"); }
void gage_net_print_routes() { system("ip route"); }
void gage_net_traceroute() { system("traceroute google.com || echo 'No trace tool'"); }
void gage_net_dns_lookup() { system("dig google.com || nslookup google.com"); }
void gage_net_whois_query() { system("whois google.com || echo 'No whois'"); }
void gage_net_print_arp_table() { system("arp -a || ip neigh"); }
void gage_net_print_local_ip() { system("hostname -I"); }
void gage_net_print_public_ip() { system("curl ifconfig.me && echo"); }
void gage_net_scan_local_ports() { system("nc -zv localhost 22 80 || echo 'Scan locked'"); }
void gage_net_iptables_list() { system("iptables -L || echo 'Requires root'"); }
void gage_net_ufw_status() { system("ufw status || echo 'No UFW'"); }
void gage_net_curl_geo_ip() { system("curl -s http://ip-api.com/json/"); }
void gage_net_ping6_dns() { system("ping6 -c 1 google.com || echo 'No IPv6 channel'"); }
void gage_net_print_mac_addresses() { system("ip link"); }
void gage_net_curl_user_agent() { system("curl -s http://httpbin.org/user-agent"); }
void gage_net_curl_check_http2() { system("curl -I --http2 https://google.com | head -n 1"); }
void gage_net_print_statistics() { system("netstat -s || ip -s link"); }
void gage_net_print_active_connections() { system("netstat -an || ss -an"); }
void gage_net_test_dns_latency() { system("ping -c 3 1.1.1.1"); }
void gage_net_check_port_ssh() { system("nc -z -w3 localhost 22 && echo 'Open' || echo 'Closed'"); }
void gage_net_check_port_http() { system("nc -z -w3 localhost 80 && echo 'Open' || echo 'Closed'"); }
void gage_net_print_network_protocols() { system("cat /etc/protocols | head -n 5"); }
void gage_net_print_network_services() { system("cat /etc/services | head -n 5"); }
void gage_net_clear_dns_cache_mock() { system("echo 'DNS Cache Flushed'"); }
void gage_net_reset_interface_mock() { system("echo 'Interface reset triggered'"); }
void gage_net_print_wireless_info() { system("iwconfig || ip link"); }
