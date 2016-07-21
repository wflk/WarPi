//
// Created by insane on 7/18/16.
//

#include "Manager.h"


void ManagerFunction::run() {
    Manager manager;
    while(manager.get_do_run()){
        if(manager.run_gps_monitor){
            manager.start_gps_monitor_thread();
            manager.run_gps_monitor = false;
        }
        if(manager.run_wifi_monitor){
            manager.start_wifi_monitor_thread();
            manager.run_wifi_monitor = false;
        }
    }
}