//
// Created by insane on 8/3/16.
//

#ifndef WARPI_DATABASE_H
#define WARPI_DATABASE_H


#include <string>
#include "../Client/Client.h"
#include "../Eve/Eve.h"
#include <boost/thread/thread.hpp>

class Database {
private:
    Eve eve;
    std::string database_port = "";
    boost::thread *eve_thread = new boost::thread(&Eve::run);
public:
    bool gps_logging(double longitude, double latitude, double speed);

    bool ap_logging(double longitude, double latitude, double speed, std::string essid, std::string bssid, double freq,
                    std::string encryption);

    bool ap_in_db(std::string essid, std::string bssid);






};


#endif //WARPI_DATABASE_H
