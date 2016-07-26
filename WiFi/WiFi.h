//
// Created by insane on 7/18/16.
//

#ifndef WARPI_WIFIMONITOR_H
#define WARPI_WIFIMONITOR_H


#include "WiFiObject.h"
#include "../GPS/GPSObject.h"

class WiFiMonitor {
public:
    static void run(WiFi wifi, GPS gps);
};


#endif //WARPI_WIFIMONITOR_H
