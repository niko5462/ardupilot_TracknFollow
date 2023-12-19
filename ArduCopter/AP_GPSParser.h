#pragma once

#ifndef AP_GPSParser_H
#define AP_GPSParser_H

#include <AP_HAL/AP_HAL.h>
//#include <AP_SerialManager/AP_SerialManager.h>
#include <stdio.h>



class AP_GPSParser {
public:
    AP_GPSParser();
    void setup();
    void process();
    bool has_received_message();
    int32_t get_latitude();
    int32_t get_longitude();
private:
void resetBuffer();
void save_to_buffer(uint8_t data);
void read_from_serial(AP_HAL::UARTDriver *uart, const char *name);
void setup_uart(AP_HAL::UARTDriver *uart, const char *name);
const AP_HAL::HAL &hal = AP_HAL::get_HAL();    
void split_coordinates();

AP_HAL::UARTDriver *uart;
uint8_t mavlink_buffer[64];
char *trash;
char *latitude;
char *longitude;
char *altitude;
float latf;
float lngf;
unsigned long mavlink_buffer_index;
bool readData;

};

#endif // AP_GPSParser_H
