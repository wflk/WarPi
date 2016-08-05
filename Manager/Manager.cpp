//
// Created by insane on 8/3/16.
//

#include "Manager.h"
#include <fstream>
#include <rapidjson/document.h>
#include <rapidjson/stringbuffer.h>

void Manager::run() {
    while (this->do_run) {
        this->read_configuration();
        this->check_modules();
    }
}

void Manager::set_do_run(bool value) {
    this->do_run = value;
}

void Manager::check_modules() {
    this->check_client();
    this->check_wifi();
    this->check_gps();
}

void Manager::check_client() {
    if (client->get_do_run()) {
        if (client->get_connect_interval() < (double(clock() - client->get_last_connect()) / CLOCKS_PER_SEC)) {
            if (client->server_reachable()) {
                // TODO: Send stuff
            }
        }
    }
}

void Manager::check_wifi() {
    if (this->wardriving) {
        if (gps->get_do_run() && wifi->get_do_run()) {
            // TODO: Get gps data & wifi data -> put to db
        }
    }
    // TODO: Get encryption type
    if (this->capture_handshakes) {
        // TODO: Capture handshakes and check validity -> put path + date + location + ap details to db
    }
    if (this->crack_wep) {
        // TODO: Try different WEP attacks and check if can connect -> put date + location + password + ap details to db
    }
    if (this->crack_wps) {
        // TODO: Try cracking WPS
    }
}

void Manager::check_gps() {
    if (this->gps->get_gps_logging()) {
        // TODO: Log every x seconds location and put timestamp + location to db
    }
}


void Manager::read_configuration() {
    std::ifstream config_doc("/etc/WarPi/config.json");
    std::string config_doc_content((std::istreambuf_iterator<char>(config_doc)), (std::istreambuf_iterator<char>()));
    rapidjson::Document config;
    config.Parse(config_doc_content.c_str());
    rapidjson::Value &wifi_configuration = config["wifi_configuration"];
    this->wifi->set_do_run(wifi_configuration["use_wifi"].GetBool());
    this->wifi->set_wifi_interface(wifi_configuration["wifi_interface"].GetString());
    this->wifi->set_scan_interval(wifi_configuration["wifi_scan_interval"].GetInt());
    this->wifi->set_home_network_essid(wifi_configuration["home_network_essid"].GetString());
    this->wifi->set_home_network_bssid(wifi_configuration["home_network_bssid"].GetString());

    rapidjson::Value &gps_configuration = config["gps_configuration"];
    this->gps->set_do_run(gps_configuration["use_gps"].GetBool());
    this->gps->set_gpsd_port(gps_configuration["gpsd_port"].GetString());
    this->gps->set_timeout(gps_configuration["timeout"].GetInt());
    this->gps->set_gps_logging(gps_configuration["gps_logging"].GetBool());
    this->gps->set_gps_logging_interval(gps_configuration["gps_logging_interval"].GetInt());

    rapidjson::Value &database_configuration = config["database_configuration"];
    this->database->set_database_port(database_configuration["database_port"].GetString());

    rapidjson::Value &client_configuration = config["client_configuration"];
    this->client->set_do_run(client_configuration["use_server"].GetBool());
    this->client->set_connect_interval(client_configuration["connect_interval"].GetInt());
    this->client->set_external_server(client_configuration["external_server"].GetString());
    this->client->set_internal_server(client_configuration["internal_server"].GetString());
    this->client->set_server_port(client_configuration["server_port"].GetString());

    rapidjson::Value &global_configuration = config["global_configuration"];
    this->wardriving = global_configuration["wardriving"].GetBool();
    this->capture_handshakes = global_configuration["capture_handshakes"].GetBool();
    this->crack_wep = global_configuration["crack_wep"].GetBool();
    this->crack_wps = global_configuration["crack_wps"].GetBool();
}