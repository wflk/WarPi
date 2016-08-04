//
// Created by insane on 8/3/16.
//

#ifndef WARPI_WIFI_H
#define WARPI_WIFI_H

#include <iwlib.h>
#include <string>
#include <vector>

class WiFi {
private:
    bool do_run = false;

    clock_t last_scan = clock();
    int scan_interval = 1500;

    std::vector<std::string> all_errors = {};
    std::string last_error = "";

    std::string home_network_essid = "";
    std::string home_network_bssid = "";
    std::string wifi_interface = "";
public:
    wireless_scan *get_near_networks();

    void set_wifi_interface(std::string ifname);

    std::string get_wifi_interface();

    void set_do_run(bool value);

    bool get_do_run();

    void set_scan_interval(int scan_interval);

    int get_scan_interval();

    void set_last_scan(clock_t last_scan);

    clock_t get_last_scan();

    bool in_home_network();

};


#endif //WARPI_WIFI_H
