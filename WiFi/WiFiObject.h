//
// Created by insane on 7/18/16.
//

#ifndef WARPI_WIFI_H
#define WARPI_WIFI_H


#include <iwlib.h>
#include <string>

class WiFi {
private:
    wireless_scan* result;
    std::string interface = "wlan0";
    std::string crash_reason = NULL;
    int sleep_time = 1;

    bool interface_used = false;

    bool do_run = true;

public:
    void evaluate_results();

    void set_do_run(bool value);
    bool get_do_run();

    std::string get_wlan_interface();
    void set_wlan_interface(std::string interface);

    void set_crash_reason(std::string crash_reason);
    std::string get_crash_reason();

    wireless_scan* get_result();
    void set_result(wireless_scan *result);

    int get_sleep_time();
    void set_sleep_time(int sleep_time);

    bool is_interface_used();
    void set_interface_used(bool value);
};


#endif //WARPI_WIFI_H
