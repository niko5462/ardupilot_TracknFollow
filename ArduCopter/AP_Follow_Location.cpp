#include "AP_Follow_Location.h"
#include "Copter.h"
#include <AP_Common/Location.h>

AP_Follow_Location::AP_Follow_Location(){
   // constructor
}

void AP_Follow_Location::_init(){
   // Temporary start location for testing
   startLoc.lat = 570138730;
   startLoc.lng = 99874617;
   startLoc.alt = 13;
   coordinate1.lat = 570138952;
   coordinate1.lng = 99874556;
   coordinate2.lat = 570140348;
   coordinate2.lng = 99873287;
   coordinate3.lat = 570141743;
   coordinate3.lng = 99872018;
   coordinate4.lat = 570143138;
   coordinate4.lng = 99870748;
   coordinate5.lat = 570144534;
   coordinate5.lng = 99869479;
   coordinate6.lat = 570145929;
   coordinate6.lng = 99868210;
   coordinate7.lat = 570147325;
   coordinate7.lng = 99866941;
   coordinate8.lat = 570148720;
   coordinate8.lng = 99865671;
   coordinate9.lat = 570150115;
   coordinate9.lng = 99864402;
   coordinate10.lat = 570151511;
   coordinate10.lng = 99863133;
   coordinate11.lat = 570152906;
   coordinate11.lng = 99861864;
   coordinate12.lat = 570154301;
   coordinate12.lng = 99860594;
   coordinate13.lat = 570155697;
   coordinate13.lng = 99859325;
   coordinate14.lat = 570157092;
   coordinate14.lng = 99858056;
   coordinate15.lat = 570158488;
   coordinate15.lng = 99856787;
   coordinate16.lat = 570159883;
   coordinate16.lng = 99855517;
   coordinate17.lat = 570161278;
   coordinate17.lng = 99854248;
   coordinate18.lat = 570162455;
   coordinate18.lng = 99855269;
   coordinate19.lat = 570163587;
   coordinate19.lng = 99856760;
   coordinate20.lat = 570164719;
   coordinate20.lng = 99858250;
   coordinate21.lat = 570165851;
   coordinate21.lng = 99859740;
   coordinate22.lat = 570166983;
   coordinate22.lng = 99861230;
   coordinate23.lat = 570168115;
   coordinate23.lng = 99862720;
   coordinate24.lat = 570169247;
   coordinate24.lng = 99864211;
   coordinate25.lat = 570170379;
   coordinate25.lng = 99865701;
   coordinate26.lat = 570171511;
   coordinate26.lng = 99867191;
   coordinate27.lat = 570172643;
   coordinate27.lng = 99868681;
   coordinate28.lat = 570173775;
   coordinate28.lng = 99870172;
   coordinate29.lat = 570174907;
   coordinate29.lng = 99871662;
   coordinate30.lat = 570176039;
   coordinate30.lng = 99873152;
   coordinate31.lat = 570177171;
   coordinate31.lng = 99874642;
   coordinate32.lat = 570178303;
   coordinate32.lng = 99876133;
   coordinate33.lat = 570179435;
   coordinate33.lng = 99877623;
   coordinate34.lat = 570178795;
   coordinate34.lng = 99878582;
   coordinate35.lat = 570177243;
   coordinate35.lng = 99879268;
   coordinate36.lat = 570175690;
   coordinate36.lng = 99879954;
   coordinate37.lat = 570174137;
   coordinate37.lng = 99880640;
   coordinate38.lat = 570172584;
   coordinate38.lng = 99881326;
   coordinate39.lat = 570171032;
   coordinate39.lng = 99882012;
   coordinate40.lat = 570169479;
   coordinate40.lng = 99882697;
   coordinate41.lat = 570167926;
   coordinate41.lng = 99883383;
   coordinate42.lat = 570166374;
   coordinate42.lng = 99884069;
   coordinate43.lat = 570164821;
   coordinate43.lng = 99884755;
   coordinate44.lat = 570163268;
   coordinate44.lng = 99885441;
   coordinate45.lat = 570161716;
   coordinate45.lng = 99886127;
   coordinate46.lat = 570160163;
   coordinate46.lng = 99886813;
   coordinate47.lat = 570158610;
   coordinate47.lng = 99887498;
   coordinate48.lat = 570157058;
   coordinate48.lng = 99888184;
   coordinate49.lat = 570155505;
   coordinate49.lng = 99888870;
   coordinate50.lat = 570153952;
   coordinate50.lng = 99889556;

}

bool AP_Follow_Location::getSimLoc() {

      if (copter.simVar == 0) {
         newLoc = coordinate1;
      } else if (copter.simVar == 1) {
         newLoc = coordinate2;
      } else if (copter.simVar == 2) {
         newLoc = coordinate3;
      } else if (copter.simVar == 3) {
         newLoc = coordinate4;
      } else if (copter.simVar == 4) {
         newLoc = coordinate5;
      } else if (copter.simVar == 5) {
         newLoc = coordinate6;
      } else if (copter.simVar == 6) {
         newLoc = coordinate7;
      } else if (copter.simVar == 7) {
         newLoc = coordinate8;
      } else if (copter.simVar == 8) {
         newLoc = coordinate9;
      } else if (copter.simVar == 9) {
         newLoc = coordinate10;
      } else if (copter.simVar == 10) {
         newLoc = coordinate11;
      } else if (copter.simVar == 11) {
         newLoc = coordinate12;
      } else if (copter.simVar == 12) {
         newLoc = coordinate13;
      } else if (copter.simVar == 13) {
         newLoc = coordinate14;
      } else if (copter.simVar == 14) {
         newLoc = coordinate15;
      } else if (copter.simVar == 15) {
         newLoc = coordinate16;
      } else if (copter.simVar == 16) {
         newLoc = coordinate17;
      } else if (copter.simVar == 17) {
         newLoc = coordinate18;
      } else if (copter.simVar == 18) {
         newLoc = coordinate19;
      } else if (copter.simVar == 19) {
         newLoc = coordinate20;
      } else if (copter.simVar == 20) {
         newLoc = coordinate21;
      } else if (copter.simVar == 21) {
         newLoc = coordinate22;
      } else if (copter.simVar == 22) {
         newLoc = coordinate23;
      } else if (copter.simVar == 23) {
         newLoc = coordinate24;
      } else if (copter.simVar == 24) {
         newLoc = coordinate25;
      } else if (copter.simVar == 25) {
         newLoc = coordinate26;
      } else if (copter.simVar == 26) {
         newLoc = coordinate27;
      } else if (copter.simVar == 27) {
         newLoc = coordinate28;
      } else if (copter.simVar == 28) {
         newLoc = coordinate29;
      } else if (copter.simVar == 29) {
         newLoc = coordinate30;
      } else if (copter.simVar == 30) {
         newLoc = coordinate31;
      } else if (copter.simVar == 31) {
         newLoc = coordinate32;
      } else if (copter.simVar == 32) {
         newLoc = coordinate33;
      } else if (copter.simVar == 33) {
         newLoc = coordinate34; 
      } else if (copter.simVar == 34) {
         newLoc = coordinate35;
      } else if (copter.simVar == 35) {
         newLoc = coordinate36;
      } else if (copter.simVar == 36) {
         newLoc = coordinate37;
      } else if (copter.simVar == 37) {
         newLoc = coordinate38;
      } else if (copter.simVar == 38) {
         newLoc = coordinate39;
      } else if (copter.simVar == 39) {
         newLoc = coordinate40;
      } else if (copter.simVar == 40) {
         newLoc = coordinate41;
      } else if (copter.simVar == 41) {
         newLoc = coordinate42;
      } else if (copter.simVar == 42) {
         newLoc = coordinate43;
      } else if (copter.simVar == 43) {
         newLoc = coordinate44;
      } else if (copter.simVar == 44) {
         newLoc = coordinate45;
      } else if (copter.simVar == 45) {
         newLoc = coordinate46;
      } else if (copter.simVar == 46) {
         newLoc = coordinate47;
      } else if (copter.simVar == 47) {
         newLoc = coordinate48;
      } else if (copter.simVar == 48) {
         newLoc = coordinate49;
      } else if (copter.simVar == 49) {
         newLoc = coordinate50;
      }

      copter.simVar++;
      return true;
}

bool AP_Follow_Location::get_location(AP_GPSParser _gpsParser){
   // receivedLoc.lat = _gpsParser.get_latitude();
   // receivedLoc.lng = _gpsParser.get_longitude();
   // hal.console->printf("Latitude %li \n", receivedLoc.lat);
   // hal.console->printf("Longitude %li \n", receivedLoc.lng);
   return true;
}

bool AP_Follow_Location::change_location(AP_GPSParser _gpsParser){
   if (get_location(_gpsParser)){
      prevLoc.alt = newLoc.alt;
      prevLoc.lat = newLoc.lat;
      prevLoc.lng = newLoc.lng;

      newLoc.alt = receivedLoc.alt;
      newLoc.lat = receivedLoc.lat;
      newLoc.lng = receivedLoc.lng;
      return true;
   }else {
      return false;
   }
}

bool AP_Follow_Location::check_location(){
   if (!check_latlng(newLoc.lat, newLoc.lng)){
      return false;
   } else if (newLoc.sanitize(copter.current_loc, prevLoc)){ 
      return false;
   } else {
      return true;
   }
}

double AP_Follow_Location::get_distance(){
   x1 = copter.current_loc.get_distance_NE(newLoc).x;
   y1 = copter.current_loc.get_distance_NE(newLoc).y;
   z1 = copter.current_loc.get_alt_cm(newLoc.get_alt_frame(), newLoc.alt);
   return sqrt(x1 * x1 + y1 * y1);
}

void AP_Follow_Location::update_velocity(){
   range = 50;
   kp = 1;
   wp_len = get_distance();
   if (wp_len > range){
      copter.set_mode(Mode::Number::LAND, ModeReason::GCS_COMMAND);
   }  else if (wp_len > 7.5){
      vel.x = (x1 * 100 / wp_len) * kp; // x1 is in meters and vel.x should be in cm/s. Therefore, we multiply by 100
      vel.y = (y1 * 100 / wp_len) * kp; // y1 is in meters and vel.y should be in cm/s. Therefore, we multiply by 100
      vel.z = 0;
   }  else {
      vel.x = 0; // x, y, and z are set to 0 for hovering
      vel.y = 0;
      vel.z = 0;
   }
   copter.mode_guided.set_velocity(vel);
}
