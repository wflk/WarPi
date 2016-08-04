//
// Created by insane on 8/4/16.
//

#include "Eve.h"
#include <python2.7/Python.h>
#include <string>

void Eve::run() {
    std::string eve = "from eve import Eve\n\n"
            "my_settings = { 'MONGO_HOST: 'localhost', 'MONGO_PORT': 27017, 'MONGO_DBNAME': 'WarPi', 'DOMAIN': {'gps': {}, 'aps': {}} }"
            "app = Eve(settings=my_settings)\n"
            "app.run()\n";
    Py_Initialize();
    PyRun_SimpleString(eve.c_str());
    Py_Finalize();
}