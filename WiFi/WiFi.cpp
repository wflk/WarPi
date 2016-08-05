//
// Created by insane on 8/3/16.
//

#include "WiFi.h"

wireless_scan *WiFi::get_near_networks() {
    wireless_scan_head head;

    iwrange range;
    int sock;

    sock = iw_sockets_open();
    if (iw_get_range_info(sock, this->wifi_interface.c_str(), &range) < 0) {
        this->last_error = "IW_GET_RANGE_INFO";
        this->all_errors.push_back(this->last_error);
        return NULL;
    }

    if (iw_scan(sock, (char *) this->wifi_interface.c_str(), range.we_version_compiled, &head) < 0) {
        this->last_error = "IW_SCAN";
        this->all_errors.push_back(this->last_error);
        return NULL;
    }
    return head.result;
}

void WiFi::set_wifi_interface(std::string ifname) {
    this->wifi_interface = ifname;
}

std::string WiFi::get_wifi_interface() {
    return this->wifi_interface;
}

void WiFi::set_do_run(bool value) {
    this->do_run = value;
}

bool WiFi::get_do_run() {
    return this->do_run;
}

void WiFi::set_last_scan(clock_t last_scan) {
    this->last_scan = last_scan;
}

clock_t WiFi::get_last_scan() {
    return this->last_scan;
}

void WiFi::set_scan_interval(int scan_interval) {
    this->scan_interval = scan_interval;
}

int WiFi::get_scan_interval() {
    return this->scan_interval;
}

bool WiFi::in_home_network() {
    wireless_scan *result = this->get_near_networks();
    while (NULL != result) {
        if ((this->home_network_essid == std::string(result->b.essid)) &&
            (this->home_network_bssid == std::string(result->ap_addr.sa_data))) {
            return true;
        }
    }
    return false;
}

void WiFi::set_home_network_essid(std::string essid) {
    this->home_network_essid = essid;
}

void WiFi::set_home_network_bssid(std::string bssid) {
    this->home_network_bssid = bssid;
}