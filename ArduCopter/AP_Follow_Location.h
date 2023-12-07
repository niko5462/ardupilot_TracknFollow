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
    coordinate1.lat = 570138952;
    coordinate1.lng = 99874556;
    coordinate2.lat = 570139262;
    coordinate2.lng = 99874865;
    coordinate3.lat = 570139571;
    coordinate3.lng = 99875174;
    coordinate4.lat = 570139880;
    coordinate4.lng = 99875484;
    coordinate5.lat = 570140189;
    coordinate5.lng = 99875793;
    coordinate6.lat = 570140498;
    coordinate6.lng = 99876102;
    coordinate7.lat = 570140808;
    coordinate7.lng = 99876411;
    coordinate8.lat = 570141117;
    coordinate8.lng = 99876721;
    coordinate9.lat = 570141426;
    coordinate9.lng = 99877030;
    coordinate10.lat = 570141735;
    coordinate10.lng = 99877339;
    coordinate11.lat = 570142044;
    coordinate11.lng = 99877648;
    coordinate12.lat = 570142354;
    coordinate12.lng = 99877957;
    coordinate13.lat = 570142663;
    coordinate13.lng = 99878267;
    coordinate14.lat = 570142972;
    coordinate14.lng = 99878576;
    coordinate15.lat = 570143281;
    coordinate15.lng = 99878885;
    coordinate16.lat = 570143591;
    coordinate16.lng = 99879194;
    coordinate17.lat = 570143900;
    coordinate17.lng = 99879503;
    coordinate18.lat = 570144209;
    coordinate18.lng = 99879813;
    coordinate19.lat = 570144518;
    coordinate19.lng = 99880122;
    coordinate20.lat = 570144827;
    coordinate20.lng = 99880431;
    coordinate21.lat = 570145137;
    coordinate21.lng = 99880740;
    coordinate22.lat = 570145446;
    coordinate22.lng = 99881050;
    coordinate23.lat = 570145755;
    coordinate23.lng = 99881359;
    coordinate24.lat = 570146064;
    coordinate24.lng = 99881668;
    coordinate25.lat = 570146373;
    coordinate25.lng = 99881977;
    coordinate26.lat = 570146683;
    coordinate26.lng = 99882286;
    coordinate27.lat = 570146992;
    coordinate27.lng = 99882596;
    coordinate28.lat = 570147301;
    coordinate28.lng = 99882905;
    coordinate29.lat = 570147610;
    coordinate29.lng = 99883214;
    coordinate30.lat = 570147920;
    coordinate30.lng = 99883523;
    coordinate31.lat = 570148229;
    coordinate31.lng = 99883832;
    coordinate32.lat = 570148538;
    coordinate32.lng = 99884142;
    coordinate33.lat = 570148847;
    coordinate33.lng = 99884451;
    coordinate34.lat = 570149150;
    coordinate34.lng = 99884754;
    coordinate35.lat = 570149451;
    coordinate35.lng = 99885054;
    coordinate36.lat = 570149751;
    coordinate36.lng = 99885354;
    coordinate37.lat = 570150051;
    coordinate37.lng = 99885654;
    coordinate38.lat = 570150351;
    coordinate38.lng = 99885955;
    coordinate39.lat = 570150651;
    coordinate39.lng = 99886255;
    coordinate40.lat = 570150951;
    coordinate40.lng = 99886555;
    coordinate41.lat = 570151251;
    coordinate41.lng = 99886855;
    coordinate42.lat = 570151551;
    coordinate42.lng = 99887155;
    coordinate43.lat = 570151851;
    coordinate43.lng = 99887455;
    coordinate44.lat = 570152152;
    coordinate44.lng = 99887755;
    coordinate45.lat = 570152452;
    coordinate45.lng = 99888055;
    coordinate46.lat = 570152752;
    coordinate46.lng = 99888356;
    coordinate47.lat = 570153052;
    coordinate47.lng = 99888656;
    coordinate48.lat = 570153352;
    coordinate48.lng = 99888956;
    coordinate49.lat = 570153652;
    coordinate49.lng = 99889256;
    coordinate50.lat = 570153952;
    coordinate50.lng = 99889556;


};
#endif // AP_Follow_Location_H