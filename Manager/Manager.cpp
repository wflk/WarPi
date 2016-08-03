//
// Created by insane on 8/3/16.
//

#include "Manager.h"

void Manager::run() {
    while (this->do_run) {
        this->check_modules();
    }
}

void Manager::set_do_run(bool value) {
    this->do_run = value;
}

bool Manager::get_do_run() {
    return this->do_run;
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
    if (this->gps_logging) {
        // TODO: Log every x seconds location and put timestamp + location to db
    }
}