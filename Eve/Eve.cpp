//
// Created by insane on 8/4/16.
//

#include "Eve.h"
#include <python2.7/Python.h>

void Eve::run() {
    FILE *eve = fopen("eve.py", "r");
    Py_Initialize();
    PyRun_SimpleFile(eve, "eve.py");
    Py_Finalize();
}