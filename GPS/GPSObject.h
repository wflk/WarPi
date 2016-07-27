//
// Created by insane on 7/18/16.
//

#ifndef WARPI_GPS_H
#define WARPI_GPS_H

#include <string>

class GPS {
private:
    std::string crash_reason = "";
    std::string last_error = "";
    struct gps_data_t* gps_data;
    bool do_run = true;
    int sleep_time = 3;
    int wait_time = 20000000;

public:
    std::string get_crash_reason();
    void set_crash_reason(std::string crash_reson);

    std::string get_last_error();
    void set_last_error(std::string error);

    void set_do_run(bool value);
    bool get_do_run();

    int get_sleep_time();
    void set_sleep_time(int sleep_time);

    int get_wait_time();
    void set_wait_time(int wait_time);

    struct gps_data_t* get_gps_data();
    void set_gps_data(struct gps_data_t* gps_data);
};


#endif //WARPI_GPS_H
