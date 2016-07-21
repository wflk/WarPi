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
    char* interface = "wlan0";
    std::string crash_reason = NULL;
    int sleep_time = 1;

    bool do_run = true;

public:
    void evaluate_results();

    void set_do_run(bool value);
    bool get_do_run();

    char* get_wlan_interface();
    void set_wlan_interface(char* interface);

    void set_crash_reason(std::string crash_reason);
    std::string get_crash_reason();

    wireless_scan* get_result();
    void set_result(wireless_scan *result);

    int get_sleep_time();
    void set_sleep_time(int sleep_time);
};


#endif //WARPI_WIFI_H
