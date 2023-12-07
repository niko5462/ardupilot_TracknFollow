#pragma once

#ifndef AP_Follow_Location_H 
#define AP_Follow_Location_H

#include "GCS_Mavlink.h"
#include <AP_Common/Location.h>
#include <AP_HAL/AP_HAL.h>
#include "AP_GPSParser.h"

class AP_Follow_Location{
    friend class Copter; // for access to _chan in parameter declarations
public:
    AP_Follow_Location();
    void _init();
    void update_velocity();
    bool change_location(AP_GPSParser gpsParser);
    bool check_location();
    Location getSimLoc();
private:
    bool get_location(AP_GPSParser gpsParser);
    double get_distance();
    Location newLoc;
    Location prevLoc;
    Location startLoc;
    Location receivedLoc;
    Vector3f vel;
    uint8_t mavBuffLat[64];
    uint8_t mavBuffLng[64];
    uint8_t mavBuffAlt[64];
    double wp_len;
    float kp;
    float x1;
    float y1;
    float z1;
    int range;
    int num;
    bool DoesItWork = true;
};
#endif // AP_Follow_Location_H