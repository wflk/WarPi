//
// Created by insane on 8/3/16.
//

#include "Database.h"
#include <json/json.h>
#include <restclient-cpp/restclient.h>

void Database::gps_logging(double longitude, double latitude, double speed) {
    std::time_t ts = std::time(nullptr);
    std::string data =
            "{\"lontitude\": \"" + std::to_string(longitude) + "\", \"latitude\": \"" + std::to_string(latitude)
            + "\", \"speed\": \"" + std::to_string(speed) + "\", \"time\": \"" + std::to_string(ts) + "\"}";
    RestClient::post("http://localhost:" + database_port + "/gps", "application/json", data);
}

void Database::ap_in_db(std::string essid, std::string bssid) {
    RestClient::Response r = RestClient::get("http://localhost:" + database_port + "/aps/" + bssid);
    Json::CharReaderBuilder data_builder;
    // TODO: Check return value on not found
}

void Database::ap_logging(double longitude, double latitude, double speed, std::string essid, std::string bssid,
                          double freq, std::string encryption) {
    std::time_t ts = std::time(nullptr);
    std::string data =
            "{\"essid\": \"" + essid + "\", \"bssid\": \"" + bssid + "\", \"freq\": \"" + std::to_string(freq) +
            "\", \"encryption\": \"" + encryption +
            "\", \"lontitude\": \"" + std::to_string(longitude) + "\", \"latitude\": \"" + std::to_string(latitude) +
            "\", \"speed\": \"" + std::to_string(speed) + "\", \"time\": \"" + std::to_string(ts) + "\"}";
    RestClient::post("http://localhost:" + database_port + "/aps", "application/json", data);
}

void Database::set_database_port(std::string port) {
    this->database_port = port;
}

std::string Database::get_database_port() {
    return this->database_port;
}