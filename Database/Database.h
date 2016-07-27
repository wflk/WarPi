//
// Created by insane on 7/15/16.
//

#ifndef WARPI_DATABASE_H
#define WARPI_DATABASE_H

#include <string>


class Database {
private:
    std::string address = "http://localhost:59840";
    std::string database = "warpi";

public:
    bool gps_log(double longitude, double latitude, double speed, int satellites_used, std::string timestamp);
    bool wifi_log(double longitude, double latitude, double speed, int satellites_used, std::string timestamp, std::string essid, std::string bssid, std::string encryption, std::string freq);
    bool wifi_in_database(std::string bssid);
    std::string get_wifi_password(std::string bssid);
};


#endif //WARPI_DATABASE_H
