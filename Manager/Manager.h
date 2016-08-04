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
    bool client_do_run = true;

    WiFi *wifi = new WiFi();
    bool capture_handshakes = false; // TODO
    bool wardriving = false;
    bool crack_wep = false; // TODO
    bool crack_wps = false; // TODO

    GPS *gps = new GPS();
    bool gps_logging = false;
    int gps_logging_interval = 1000;

    bool do_run = false;

    void check_modules();

    void check_client();

    void check_wifi();

    void check_gps();

public:

    void run();

    bool get_do_run();

    void set_do_run(bool value);

};


#endif //WARPI_MANAGER_H
