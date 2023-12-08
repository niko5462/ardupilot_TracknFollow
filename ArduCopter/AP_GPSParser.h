#pragma once

#ifndef AP_GPSParser_H
#define AP_GPSParser_H

#include <AP_HAL/AP_HAL.h>
#include <AP_SerialManager/AP_SerialManager.h>
#include <stdio.h>



class AP_GPSParser {
public:
    AP_GPSParser();
    void setup();
    void loop();
    uint32_t get_latitude();
    uint32_t get_longitude();
private:
    void reset_buffer();
    void save_to_buffer(uint8_t data);
    void read_from_serial(AP_HAL::UARTDriver *uart, const char *name);
    void setup_uart(AP_HAL::UARTDriver *uart, const char *name);  
    void split_coordinates();
    const AP_HAL::HAL &hal = AP_HAL::get_HAL();

    AP_HAL::UARTDriver *uart;
    uint8_t mavlink_buffer[64];
    char *latitude;
    char *longitude;
    char *altitude;
    uint32_t lat;
    uint32_t lng;
    uint8_t inc_data; //skal evt. kun defineres i cpp. Skal lige testes
    double latf;
    double lngf;
    unsigned long mavlink_buffer_index;
    bool readData;

};

#endif // AP_GPSParser_H
