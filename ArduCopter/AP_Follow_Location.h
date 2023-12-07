#pragma once

#ifndef AP_Follow_Location_H
#define AP_Follow_Location_H

#include "GCS_Mavlink.h"
#include <AP_Common/Location.h>
#include <AP_HAL/AP_HAL.h>
#include "AP_GPSParser.h"

class AP_Follow_Location
{
    friend class Copter; // for access to _chan in parameter declarations
public:
    AP_Follow_Location();
    void _init();
    void update_velocity();
    bool change_location(AP_GPSParser gpsParser);
    bool check_location();
    bool getSimLoc();

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
    Location coordinate1;
    Location coordinate2;
    Location coordinate3;
    Location coordinate4;
    Location coordinate5;
    Location coordinate6;
    Location coordinate7;
    Location coordinate8;
    Location coordinate9;
    Location coordinate10;
    Location coordinate11;
    Location coordinate12;
    Location coordinate13;
    Location coordinate14;
    Location coordinate15;
    Location coordinate16;
    Location coordinate17;
    Location coordinate18;
    Location coordinate19;
    Location coordinate20;
    Location coordinate21;
    Location coordinate22;
    Location coordinate23;
    Location coordinate24;
    Location coordinate25;
    Location coordinate26;
    Location coordinate27;
    Location coordinate28;
    Location coordinate29;
    Location coordinate30;
    Location coordinate31;
    Location coordinate32;
    Location coordinate33;
    Location coordinate34;
    Location coordinate35;
    Location coordinate36;
    Location coordinate37;
    Location coordinate38;
    Location coordinate39;
    Location coordinate40;
    Location coordinate41;
    Location coordinate42;
    Location coordinate43;
    Location coordinate44;
    Location coordinate45;
    Location coordinate46;
    Location coordinate47;
    Location coordinate48;
    Location coordinate49;
    Location coordinate50;
};
#endif // AP_Follow_Location_H