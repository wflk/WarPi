//
// Created by insane on 8/3/16.
//

#ifndef WARPI_CLIENT_H
#define WARPI_CLIENT_H


#include <ctime>
#include <string>
#include "../WiFi/WiFi.h"

// TODO: Dump database Data and send to server
// TODO: Get commands from Server

class Client {
private:
    WiFi *wifi = new WiFi();

    clock_t last_connect = clock();
    double connect_interval = 3600;
    bool connect_neccessary = false;

    bool do_run = false;

    std::string external_server = "";
    std::string internal_server = "";
    std::string server_port = "6666";

public:
    void set_last_connect(clock_t time);

    clock_t get_last_connect();

    void set_connect_interval(double seconds);

    double get_connect_interval();

    void set_connect_neccessary(bool value);

    bool get_connect_neccessary();

    void set_do_run(bool value);

    bool get_do_run();

    void set_external_server(std::string external_server);

    std::string get_external_server();

    void set_internal_server(std::string internal_server);

    std::string get_internal_server();

    void set_server_port(std::string server_port);

    std::string get_server_port();

    bool server_reachable();



};


#endif //WARPI_CLIENT_H
