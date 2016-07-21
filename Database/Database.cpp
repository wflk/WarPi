//
// Created by insane on 7/15/16.
//

#include <restclient-cpp/restclient.h>
#include "Database.h"
#include "../JSON/json.hpp"

using json = nlohmann::json;

bool Database::gps_log(double longitude, double latitude, double altitude, double speed, int satellites_used, std::string timestamp) {
    std::string post_data;
    post_data.append("{\n");
    post_data.append("\"_id\" : " + timestamp + ",\n");
    post_data.append("\"longitude\" : " + std::to_string(longitude) + ",\n");
    post_data.append("\"latitude\" : " + std::to_string(latitude) + ",\n");
    post_data.append("\"altitude\" : " + std::to_string(altitude) + ",\n");
    post_data.append("\"speed\" : " + std::to_string(speed) + ",\n");
    post_data.append("\"satellites\" : " + std::to_string(satellites_used) + ",\n");
    post_data.append("\"timestamp\" : " + timestamp + "\n");
    post_data.append("}");

    RestClient::Response r = RestClient::post(address + "/" + database + "/gps_log", "application/json", post_data);

    if(r.code == 200){
        return true;
    }
    return false;
}

bool Database::wifi_log(double longitude, double latitude, double altitude, double speed, int satellites_used,
                        std::string timestamp, std::string essid, std::string bssid, std::string encryption,
                        std::string freq) {
    std::string post_data;
    post_data.append("{\n");
    post_data.append("\"_id\" : " + bssid + ",\n");
    post_data.append("\"longitude\" : " + std::to_string(longitude) + ",\n");
    post_data.append("\"latitude\" : " + std::to_string(latitude) + ",\n");
    post_data.append("\"altitude\" : " + std::to_string(altitude) + ",\n");
    post_data.append("\"speed\" : " + std::to_string(speed) + ",\n");
    post_data.append("\"satellites\" : " + std::to_string(satellites_used) + ",\n");
    post_data.append("\"timestamp\" : " + timestamp + ",\n");
    post_data.append("\"essid\" : " + essid + ",\n");
    post_data.append("\"bssid\" : " + bssid + ",\n");
    post_data.append("\"encryption\" : " + encryption + ",\n");
    post_data.append("\"frequency\" : " + freq + "\n");
    post_data.append("}");

    RestClient::Response r = RestClient::post(address + "/" + database + "/wifi_log", "application/json", post_data);

    if(r.code == 200){
        return true;
    }
    return false;
}

bool Database::wifi_in_database(std::string bssid) {
    RestClient::Response r = RestClient::get(address + "/" + database + "/wifi_log/" + bssid);
    if(r.code == 200){
        return true;
    }
    return false;
}

std::string Database::get_wifi_password(std::string bssid) {
    RestClient::Response r = RestClient::get(address + "/" + database + "/wifi_log/" + bssid);
    json structure = json::parse(r.body);
    if(structure.count("password") == 1){
        return structure["password"];
    }
    return NULL;
}
