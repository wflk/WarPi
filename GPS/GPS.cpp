//
// Created by insane on 8/3/16.
//

#include <cmath>
#include "GPS.h"

gps_data_t GPS::get_current_location() {
    struct gps_data_t gps_data;
    int rc;

    if ((rc = gps_open("localhost", this->gpsd_port.c_str(), &gps_data)) == -1) {
        this->last_error = "GPS_OPEN";
        this->all_errors.push_back(this->last_error);
        return gps_data;
    }
    gps_stream(&gps_data, WATCH_ENABLE | WATCH_JSON, NULL);

    if (gps_waiting(&gps_data, this->timeout)) {
        if ((rc = gps_read(&gps_data)) == -1) {
            this->last_error == "GPS_READ";
            this->all_errors.push_back(this->last_error);
            return gps_data;
        } else {
            if ((gps_data.status == STATUS_FIX) && (gps_data.fix.mode == MODE_2D || gps_data.fix.mode == MODE_3D) &&
                !isnan(gps_data.fix.longitude) && !isnan(gps_data.fix.latitude)) {
                return gps_data;
            } else {
                this->last_error == "NO_GPS_DATA";
                this->all_errors.push_back(this->last_error);
                return gps_data;
            }
        }
    } else {
        this->last_error = "TIMEOUT";
        this->all_errors.push_back(this->last_error);
        return gps_data;
    }
}

void GPS::set_do_run(bool value) {
    this->do_run = value;
}

bool GPS::get_do_run() {
    return this->do_run;
}

void GPS::set_gpsd_port(std::string gpsd_port) {
    this->gpsd_port = gpsd_port;
}

std::string GPS::get_gpsd_port() {
    return this->gpsd_port;
}

void GPS::set_timeout(int timeout) {
    this->timeout = timeout;
}

int GPS::get_timeout() {
    return this->timeout;
}