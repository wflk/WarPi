#include <iostream>
#include <boost/thread/thread.hpp>

#include "Manager/ManagerFunction.h"


using namespace std;

int main() {
    boost::thread* manager_thread = new boost::thread(ManagerFunction::run);
    manager_thread->join();
}

/*
 * TODO:
 * WiFi Authentication (Get IWLib encryption codes(ieee 802.11))
 *
 * WiFi Thread Lock (eg.: Superclass has 'bool is_wifi_interface_used') (Same for eth later on)
 *
 * Network Object (eg.: Store information about if connected to network and IP ranges)
 * Network Function (eg.: Get Details for above Object, execute scans)
 *
 * Scanning and Spoofing
 *
 * WiFi Karma HotSpot (eg.: get most probed ssid -> open hotspot -> scan & poison)
 * Number Plate recognition (eg.: libpng -> take picture every x seconds -> openalpr -> plate, coords to db)
 *
 * Bluetooth (eg.: get near devices, put mac and services to db, act malicious)
 * GPS Map (eg.: Tangram Library for rendering)
 *
 */