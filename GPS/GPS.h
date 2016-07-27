//
// Created by insane on 7/15/16.
//

#ifndef WARPI_GPSMONITOR_H
#define WARPI_GPSMONITOR_H

#include <boost/thread/thread.hpp>
#include "GPSObject.h"


class GPSMonitor {
public:
    static void run(GPS gps);
};


#endif //WARPI_GPSMONITOR_H
