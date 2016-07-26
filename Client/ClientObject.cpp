//
// Created by insane on 7/21/16.
//

#include "ClientObject.h"

void ClientObject::add_command(std::string command) {
    this->commands->push_back(command);
}

// TODO: Check if network connection exists -> try ping server -> fetch commands (maybe refactor to bool function)
void ClientObject::fetch_commands() {

}

std::vector<std::string> *ClientObject::get_commands() {
    return this->commands;
}

bool ClientObject::get_do_run() {
    return this->do_run;
}

void ClientObject::set_do_run(bool value) {
    this->do_run = value;
}

// TODO: Loop through commands and execute actions
void ClientObject::work_commands() {

}