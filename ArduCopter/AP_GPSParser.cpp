/******************
Class responsible for establishing connection to any unused serial port and read incoming data from it. Its saves the incoming to a one Byte buffer.

TO use this class, you need to include the following in your code:

#include "AP_GPSParser.h"
get_isReady() returns true if the buffer is ready to be parsed
get_buffer() returns the buffer

process() processes the incoming data and saves it to the buffer
setup() sets up the serial port

You can then use the buffer in your code to parse the data
*******************/

#include "AP_GPSParser.h"
#include <AP_HAL/AP_HAL.h>
#include <AP_SerialManager/AP_SerialManager.h>
#include <chrono>

AP_SerialManager serial_manager;

AP_GPSParser::AP_GPSParser() : uart(nullptr), mavlink_buffer_index(0){
    // constructor
}

void AP_GPSParser::print_time(char *str){
   using std::chrono::high_resolution_clock;
   auto now = high_resolution_clock::now().time_since_epoch();
   auto now_in_us = std::chrono::duration_cast<std::chrono::microseconds>(now).count();
   hal.console->printf("%s: %ld\n", str, now_in_us);
}

void AP_GPSParser::setup(){
    serial_manager.init();
    setup_uart(hal.serial(1), "SERIAL1"); // TELEM 1
}

void AP_GPSParser::setup_uart(AP_HAL::UARTDriver *uart_param, const char *name){
    this->uart = uart_param;
    if (uart == nullptr)
    {
        hal.console->println("Failed to find serial");
        return;
    }
    uart->begin(57600);
}

void AP_GPSParser::process(){
    read_from_serial(serial_manager.get_serial_by_id(1), "SERIAL1");
}

void AP_GPSParser::read_from_serial(AP_HAL::UARTDriver *uart_param, const char *name){
    if (uart_param == nullptr){
        hal.console->println("Failed to find serial");
        return;
    }else{
        while (uart_param->available()){
            uint8_t inc_data = uart_param->read();
            if (inc_data == '$'){
                readData = true;
            }else if (readData){
                save_to_buffer(inc_data);
                if (inc_data == '\r'){
                    split_coordinates();
                    readData = false;
                }
            }
        }
    }
}

void AP_GPSParser::save_to_buffer(uint8_t data){
    if (mavlink_buffer_index < sizeof(mavlink_buffer) - 1){
        mavlink_buffer[mavlink_buffer_index] = data;
        mavlink_buffer_index++;
        mavlink_buffer[mavlink_buffer_index] = '\0';
    }
}

bool AP_GPSParser::has_received_message(){
    if (mavlink_buffer_index > 0){
        return true;
    }else{
        return false;
    }
}

void AP_GPSParser::split_coordinates(){
    latitude = strtok((char *)mavlink_buffer, ",");
    longitude = strtok(NULL, ",");
    altitude = strtok(NULL, ",");
    //hal.console->printf("Latitude: %s \n", latitude);
    //hal.console->printf("Longitude: %s \n", longitude);
    //hal.console->printf("Altitude: %s \n", altitude);
    resetBuffer();
}

void AP_GPSParser::resetBuffer(){
    mavlink_buffer[0] = '\0';
    mavlink_buffer_index = 0;
}

uint32_t AP_GPSParser::get_latitude(){
    latf = atof(latitude) * 10000000.0;
    lat = static_cast<uint32_t>(latf);
    return lat;
}

uint32_t AP_GPSParser::get_longitude(){
    lngf = atof(longitude) * 10000000.0;
    lng = static_cast<uint32_t>(lngf);
    return lng;
}