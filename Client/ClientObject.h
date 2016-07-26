//
// Created by insane on 7/21/16.
//

#ifndef WARPI_CLIENTOBJECT_H
#define WARPI_CLIENTOBJECT_H


#include <string>
#include <vector>

class ClientObject {
private:
    std::string external_main_node = "";
    std::string internal_main_node = "";

    int sleep_time = 10;

    bool do_run = true;

    std::vector<std::string> *commands = new std::vector<std::string>;

public:
    void fetch_commands();
    void work_commands();

    void set_do_run(bool value);
    bool get_do_run();

    void add_command(std::string command);
    std::vector<std::string> *get_commands();
};


#endif //WARPI_CLIENTOBJECT_H
