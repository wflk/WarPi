//
// Created by insane on 8/3/16.
//

#include "Client.h"
#include <restclient-cpp/restclient.h>

void Client::set_last_connect(clock_t time) {
    this->last_connect = time;
}

clock_t Client::get_last_connect() {
    return this->last_connect;
}

void Client::set_connect_interval(double seconds) {
    this->connect_interval = seconds;
}

double Client::get_connect_interval() {
    return this->connect_interval;
}

void Client::set_connect_neccessary(bool value) {
    this->connect_neccessary = value;
}

bool Client::get_connect_neccessary() {
    return this->connect_neccessary;
}

void Client::set_do_run(bool value) {
    this->do_run = value;
}

bool Client::get_do_run() {
    return this->do_run;
}

void Client::set_external_server(std::string external_server) {
    this->external_server = external_server;
}

std::string Client::get_external_server() {
    return this->external_server;
}

void Client::set_internal_server(std::string internal_server) {
    this->internal_server = internal_server;
}

std::string Client::get_internal_server() {
    return this->internal_server;
}

void Client::set_server_port(std::string server_port) {
    this->server_port = server_port;
}

std::string Client::get_server_port() {
    return this->server_port;
}

bool Client::server_reachable() {
    RestClient::Response r;
    if (this->wifi->in_home_network()) {
        r = RestClient::post(this->internal_server + "/api/ping", "text/json", "ping");
    } else {
        r = RestClient::post(this->external_server + "/api/ping", "text/json", "ping");
    }
    if (r.code != 200) {
        return false;
    }
    return true;
}