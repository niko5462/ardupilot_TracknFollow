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
    void update_velocity_vector();
    bool location_changed(AP_GPSParser gpsParser);
    bool location_valid();
private:
    double get_distance();
    Location newLoc;
    Location prevLoc;
    Vector3f vel;
    uint8_t mavBuffLat[64];
    uint8_t mavBuffLng[64];
    uint8_t mavBuffAlt[64];
    double wp_len;
    float x1;
    float y1;
    float z1;
    int num;
    bool DoesItWork = true;
};
#endif // AP_Follow_Location_H