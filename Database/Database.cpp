//
// Created by insane on 8/3/16.
//

#include "Database.h"
#include <json/json.h>
#include <restclient-cpp/restclient.h>
#include <ctime>

bool Database::gps_logging(double longitude, double latitude, double speed) {
    std::time_t ts = std::time(nullptr);
    Json::Value data;
    data[std::to_string(ts)]["longitude"] = longitude;
    data[std::to_string(ts)]["latitude"] = latitude;
    data[std::to_string(ts)]["speed"] = speed;
    RestClient::Response r;

}

bool Database::ap_in_db(std::string essid, std::string bssid) {
    return true;
}

bool Database::ap_logging(double longitude, double latitude, double speed, std::string essid, std::string bssid,
                          double freq, std::string encryption) {
    return true;
}