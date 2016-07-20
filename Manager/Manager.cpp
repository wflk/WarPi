//
// Created by insane on 7/18/16.
//

#include "Manager.h"

void Manager::start_gps_monitor_thread() {
    this->gps_monitor_thread = boost::thread(gpsMonitor.run, gps);
}

bool Manager::get_do_run() {
    return this->do_run;
}

void Manager::join_gps_monitor_thread() {
    this->gps_monitor_thread.join();
}

void Manager::start_wifi_monitor_thread() {
    this->wifi_monitor_thread = boost::thread(wiFiMonitor.run, wiFi);
}
void Manager::join_wifi_monitor_thread() {
    this->wifi_monitor_thread.join();
}