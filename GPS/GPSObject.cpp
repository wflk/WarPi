//
// Created by insane on 7/18/16.
//

#include "GPSObject.h"

bool GPS::get_do_run() {
    return this->do_run;
}

struct gps_data_t* GPS::get_gps_data() {
    return this->gps_data;
}

void GPS::set_do_run(bool value) {
    this->do_run = value;
}

void GPS::set_sleep_time(int sleep_time) {
    this->sleep_time = sleep_time;
}

int GPS::get_sleep_time() {
    return this->sleep_time;
}

void GPS::set_wait_time(int wait_time) {
    this->wait_time = wait_time;
}

int GPS::get_wait_time() {
    return this->wait_time;
}

void GPS::set_gps_data(struct gps_data_t* gps_data) {
    this->gps_data = gps_data;
}

std::string GPS::get_crash_reason() {
    return this->crash_reason;
}

void GPS::set_crash_reason(std::string crash_reson) {
    this->crash_reason = crash_reson;
}

void GPS::set_last_error(std::string error) {
    this->last_error = error;
}
std::string GPS::get_last_error() {
    return this->last_error;
}