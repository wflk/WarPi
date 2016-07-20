//
// Created by insane on 7/18/16.
//

#include "WiFi.h"

bool WiFi::get_do_run() {
    return this->do_run;
}

void WiFi::set_do_run(bool value) {
    this->do_run = value;
}

char* WiFi::get_wlan_interface() {
    return this->interface;
}

void WiFi::set_wlan_interface(char*interface) {
    this->interface = interface;
}

std::string WiFi::get_crash_reason() {
    return this->crash_reason;
}

void WiFi::set_crash_reason(std::string crash_reason) {
    this->crash_reason = crash_reason;
}

void WiFi::set_result(wireless_scan *result) {
    this->result = result;
}

wireless_scan* WiFi::get_result() {
    return this->result;
}

void WiFi::set_sleep_time(int sleep_time) {
    this->sleep_time = sleep_time;
}

int WiFi::get_sleep_time() {
    return this->sleep_time;
}

void WiFi::evaluate_results() {
    while(NULL != result){

        result = result->next;
    }
}