//
// Created by insane on 7/18/16.
//

#ifndef WARPI_MANAGER_H
#define WARPI_MANAGER_H

#include "../GPS/GPS.h"
#include "../GPS/GPSMonitor.h"
#include "../WiFi/WiFiMonitor.h"

#include <boost/thread.hpp>

class Manager {
private:
    GPS gps;
    WiFi wiFi;
    GPSMonitor gpsMonitor;
    WiFiMonitor wiFiMonitor;

    bool do_run = true;

    boost::thread gps_monitor_thread;
    boost::thread wifi_monitor_thread;

public:
    bool run_gps_monitor = true;
    bool run_wifi_monitor = true;

    bool get_do_run();

    void start_gps_monitor_thread();
    void join_gps_monitor_thread();

    void start_wifi_monitor_thread();
    void join_wifi_monitor_thread();
};


#endif //WARPI_MANAGER_H
