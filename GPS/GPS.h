//
// Created by insane on 8/3/16.
//

#ifndef WARPI_GPS_H
#define WARPI_GPS_H

#include <gps.h>
#include <string>
#include <vector>

class GPS {
private:
    bool do_run = false;
    std::string gpsd_port = "2947";

    std::string last_error = "";
    std::vector<std::string> all_errors = {};

    int timeout = 2000000;

    bool gps_logging = true;
    int gps_logging_interval = 1000;
public:
    gps_data_t get_current_location();

    void set_do_run(bool value);

    bool get_do_run();

    void set_gpsd_port(std::string gpsd_port);

    std::string get_gpsd_port();

    void set_timeout(int timeout);

    int get_timeout();

    void set_gps_logging_interval(int interval);

    int get_gps_logging_interval();

    void set_gps_logging(bool value);

    bool get_gps_logging();

};


#endif //WARPI_GPS_H
