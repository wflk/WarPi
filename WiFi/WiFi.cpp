//
// Created by insane on 7/18/16.
//

#include "WiFi.h"
#include "../Database/Database.h"
#include <boost/thread/thread.hpp>
#include "gps.h"

void WiFiMonitor::run(WiFi wifi, GPS gps) {
    Database db;
    int sock = iw_sockets_open();
    iwrange range;
    wireless_scan_head scan_head;
    if(iw_get_range_info(sock, wifi.get_wlan_interface().c_str(), &range) < 0){
        wifi.set_crash_reason("WIFI::CRASH::RANGE_INFO");
        wifi.set_do_run(false);
    }
    while(wifi.get_do_run()){
        if(!wifi.is_interface_used()){
            wifi.set_interface_used(true);
            if(iw_scan(sock, (char*)wifi.get_wlan_interface().c_str(), range.we_version_compiled, &scan_head) < 0){
                wifi.set_crash_reason("WIFI::CRASH::IW_SCAN");
                wifi.set_do_run(false);
            }
            wifi.set_result(scan_head.result);
            gps_data_t* gps_data = gps.get_gps_data();
            if(!db.wifi_in_database(scan_head.result->ap_addr.sa_data)){
                db.wifi_log(gps_data->fix.longitude, gps_data->fix.latitude, gps_data->fix.speed, gps_data->satellites_used, std::to_string(gps_data->fix.time), scan_head.result->b.essid, scan_head.result->ap_addr.sa_data, scan_head.result->b.name, std::to_string(scan_head.result->b.freq));
            }
            wifi.set_interface_used(false);
        }
        boost::this_thread::sleep(boost::posix_time::seconds(wifi.get_sleep_time()));
    }
}