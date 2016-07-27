//
// Created by insane on 7/15/16.
//

#include "GPS.h"
#include "../Database/Database.h"
#include "gps.h"


void GPSMonitor::run(GPS gps) {
    int rc;
    struct gps_data_t gps_data;
    struct timeval tv;
    Database db;
    if((rc = gps_open("localhost", DEFAULT_GPSD_PORT, &gps_data)) == -1){
        gps.set_crash_reason(gps_errstr(rc));
        gps.set_do_run(false);
    }
    gps_stream(&gps_data, WATCH_ENABLE|WATCH_JSON, NULL);
    while (gps.get_do_run()) {
        if(gps_waiting(&gps_data, gps.get_wait_time())){
            if((rc = gps_read(&gps_data)) == -1){
                gps.set_last_error(gps_errstr(rc));
            } else {
                if ((gps_data.status == STATUS_FIX) && (gps_data.fix.mode == MODE_2D || gps_data.fix.mode == MODE_3D) && !isnan(gps_data.fix.longitude) && !isnan(gps_data.fix.latitude)){
                    gps.set_gps_data(&gps_data);
                    gettimeofday(&tv, NULL);
                    db.gps_log(gps_data.fix.longitude, gps_data.fix.latitude, gps_data.fix.speed, gps_data.satellites_used, std::to_string(tv.tv_sec));
                }
            }
        }
    }
}

