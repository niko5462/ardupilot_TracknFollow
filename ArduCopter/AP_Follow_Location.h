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

    Location Coordinate1;
    Location Coordinate2;
    Location Coordinate3;
    Location Coordinate4;
    Location Coordinate5;
    Location Coordinate6;
    Location Coordinate7;
    Location Coordinate8;
    Location Coordinate9;
    Location Coordinate10;
    Location Coordinate11;
    Location Coordinate12;
    Location Coordinate13;
    Location Coordinate14;
    Location Coordinate15;
    Location Coordinate16;
    Location Coordinate17;
    Location Coordinate18;
    Location Coordinate19;
    Location Coordinate20;
    Location Coordinate21;
    Location Coordinate22;
    Location Coordinate23;
    Location Coordinate24;
    Location Coordinate25;
    Location Coordinate26;
    Location Coordinate27;
    Location Coordinate28;
    Location Coordinate29;
    Location Coordinate30;
    Location Coordinate31;
    Location Coordinate32;
    Location Coordinate33;
    Location Coordinate34;
    Location Coordinate35;
    Location Coordinate36;
    Location Coordinate37;
    Location Coordinate38;
    Location Coordinate39;
    Location Coordinate40;
    Location Coordinate41;
    Location Coordinate42;
    Location Coordinate43;
    Location Coordinate44;
    Location Coordinate45;
    Location Coordinate46;
    Location Coordinate47;
    Location Coordinate48;
    Location Coordinate49;
    Location Coordinate50;
    Coordinate1.lat = 570138952;
    Coordinate1.lng = 998874556;
    Coordinate2.lat = 570139262;
    Coordinate2.lng = 998874865;
    Coordinate3.lat = 570139571;
    Coordinate3.lng = 998875174;
    Coordinate4.lat = 570139880;
    Coordinate4.lng = 998875484;
    Coordinate5.lat = 570140189;
    Coordinate5.lng = 998875793;
    Coordinate6.lat = 570140498;
    Coordinate6.lng = 998876102;
    Coordinate7.lat = 570140808;
    Coordinate7.lng = 998876411;
    Coordinate8.lat = 570141117;
    Coordinate8.lng = 998876721;
    Coordinate9.lat = 570141426;
    Coordinate9.lng = 998877030;
    Coordinate10.lat = 570141735;
    Coordinate10.lng = 998877339;
    Coordinate11.lat = 570142044;
    Coordinate11.lng = 998877648;
    Coordinate12.lat = 570142354;
    Coordinate12.lng = 998877957;
    Coordinate13.lat = 570142663;
    Coordinate13.lng = 998878267;
    Coordinate14.lat = 570142972;
    Coordinate14.lng = 998878576;
    Coordinate15.lat = 570143281;
    Coordinate15.lng = 998878885;
    Coordinate16.lat = 570143591;
    Coordinate16.lng = 998879194;
    Coordinate17.lat = 570143900;
    Coordinate17.lng = 998879503;
    Coordinate18.lat = 570144209;
    Coordinate18.lng = 998879813;
    Coordinate19.lat = 570144518;
    Coordinate19.lng = 998880122;
    Coordinate20.lat = 570144827;
    Coordinate20.lng = 998880431;
    Coordinate21.lat = 570145137;
    Coordinate21.lng = 998880740;
    Coordinate22.lat = 570145446;
    Coordinate22.lng = 998881050;
    Coordinate23.lat = 570145755;
    Coordinate23.lng = 998881359;
    Coordinate24.lat = 570146064;
    Coordinate24.lng = 998881668;
    Coordinate25.lat = 570146373;
    Coordinate25.lng = 998881977;
    Coordinate26.lat = 570146683;
    Coordinate26.lng = 998882286;
    Coordinate27.lat = 570146992;
    Coordinate27.lng = 998882596;
    Coordinate28.lat = 570147301;
    Coordinate28.lng = 998882905;
    Coordinate29.lat = 570147610;
    Coordinate29.lng = 998883214;
    Coordinate30.lat = 570147920;
    Coordinate30.lng = 998883523;
    Coordinate31.lat = 570148229;
    Coordinate31.lng = 998883832;
    Coordinate32.lat = 570148538;
    Coordinate32.lng = 998884142;
    Coordinate33.lat = 570148847;
    Coordinate33.lng = 998884451;
    Coordinate34.lat = 570149150;
    Coordinate34.lng = 998884754;
    Coordinate35.lat = 570149451;
    Coordinate35.lng = 998885054;
    Coordinate36.lat = 570149751;
    Coordinate36.lng = 998885354;
    Coordinate37.lat = 570150051;
    Coordinate37.lng = 998885554;
    Coordinate38.lat = 570150351;
    Coordinate38.lng = 998885554;
    Coordinate39.lat = 570150551;
    Coordinate39.lng = 998886254;
    Coordinate40.lat = 570150551;
    Coordinate40.lng = 998886554;
    Coordinate41.lat = 570151251;
    Coordinate41.lng = 998886854;
    Coordinate42.lat = 570151551;
    Coordinate42.lng = 998887154;
    Coordinate43.lat = 570151551;
    Coordinate43.lng = 998887554;
    Coordinate44.lat = 570152552;
    Coordinate44.lng = 998887755;
    Coordinate45.lat = 570152552;
    Coordinate45.lng = 998888055;
    Coordinate46.lat = 570152552;
    Coordinate46.lng = 998888355;
    Coordinate47.lat = 570153552;
    Coordinate47.lng = 998888556;
    Coordinate48.lat = 570153552;
    Coordinate48.lng = 998888856;
    Coordinate49.lat = 570153552;
    Coordinate49.lng = 998889156;
    Coordinate50.lat = 570153552;
    Coordinate50.lng = 998895556;

};
#endif // AP_Follow_Location_H