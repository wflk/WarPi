//
// Created by insane on 8/3/16.
//

#ifndef WARPI_MANAGER_H
#define WARPI_MANAGER_H

#include "../Client/Client.h"
#include "../WiFi/WiFi.h"
#include "../GPS/GPS.h"
#include "../Database/Database.h"

// TODO: Self-management

class Manager {
private:
    Database *database = new Database();
    Client *client = new Client();
    GPS *gps = new GPS();

    WiFi *wifi = new WiFi();
    bool capture_handshakes = false; // TODO
    bool wardriving = false;
    bool crack_wep = false; // TODO
    bool crack_wps = false; // TODO



    bool do_run = false;
    std::string configuration_file = "/etc/WarPi/config.json";

    void check_modules();

    void check_client();

    void check_wifi();

    void check_gps();

    void read_configuration();

public:

    void run();

    void set_do_run(bool value);

};


#endif //WARPI_MANAGER_H
