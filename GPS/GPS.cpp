//
// Created by insane on 7/15/16.
//

#include "GPS.h"
#include "gps.h"


void GPSMonitor::run(GPS gps) {
    struct gps_data_t gps_data;
    Database db;
    gps_open("localhost", DEFAULT_GPSD_PORT, &gps_data);
    gps_stream(&gps_data, WATCH_ENABLE|WATCH_JSON, NULL);
    while (gps.get_do_run()) {
        if(gps_read(&gps_data) == -1){
            continue;
        } else {
            gps.set_gps_data(&gps_data);
            db.gps_log(gps_data.fix.longitude, gps_data.fix.latitude, gps_data.fix.altitude, gps_data.fix.speed, gps_data.satellites_used, std::to_string(gps_data.fix.time));
        }
        boost::this_thread::sleep(boost::posix_time::seconds(gps.get_sleep_time()));
    }
}

