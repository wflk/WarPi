//
// Created by insane on 7/20/16.
//

#include "Client.h"

// TODO: Make client do stuff
void Client::run(ClientObject client) {
    while(client.get_do_run()){
        std::vector<std::string> *commands = client.get_commands();
    }
}