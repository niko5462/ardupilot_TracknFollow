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
}

bool AP_Follow_Location::getSimLoc() {
   Copter::simVar;
   if (simVar== 0) {
         newLoc = Coordinate1;
      } else if (simVar== 1) {
         newLoc = Coordinate2;
      } else if (simVar== 2) {
         newLoc = Coordinate3;
      } else if (simVar== 3) {
         newLoc = Coordinate4;
      } else if (simVar== 4) {
         newLoc = Coordinate5;
      } else if (simVar== 5) {
         newLoc = Coordinate6;
      } else if (simVar== 6) {
         newLoc = Coordinate7;
      } else if (simVar== 7) {
         newLoc = Coordinate8;
      } else if (simVar== 8) {
         newLoc = Coordinate9;
      } else if (simVar== 9) {
         newLoc = Coordinate10;
      } else if (simVar== 10) {
         newLoc = Coordinate11;
      } else if (simVar== 11) {
         newLoc = Coordinate12;
      } else if (simVar== 12) {
         newLoc = Coordinate13;
      } else if (simVar== 13) {
         newLoc = Coordinate14;
      } else if (simVar== 14) {
         newLoc = Coordinate15;
      } else if (simVar== 15) {
         newLoc = Coordinate16;
      } else if (simVar== 16) {
         newLoc = Coordinate17;
      } else if (simVar== 17) {
         newLoc = Coordinate18;
      } else if (simVar== 18) {
         newLoc = Coordinate19;
      } else if (simVar== 19) {
         newLoc = Coordinate20;
      } else if (simVar== 20) {
         newLoc = Coordinate21;
      } else if (simVar== 21) {
         newLoc = Coordinate22;
      } else if (simVar== 22) {
         newLoc = Coordinate23;
      } else if (simVar== 23) {
         newLoc = Coordinate24;
      } else if (simVar== 24) {
         newLoc = Coordinate25;
      } else if (simVar== 25) {
         newLoc = Coordinate26;
      } else if (simVar== 26) {
         newLoc = Coordinate27;
      } else if (simVar== 27) {
         newLoc = Coordinate28;
      } else if (simVar== 28) {
         newLoc = Coordinate29;
      } else if (simVar== 29) {
         newLoc = Coordinate30;
      } else if (simVar== 30) {
         newLoc = Coordinate31;
      } else if (simVar== 31) {
         newLoc = Coordinate32;
      } else if (simVar== 32) {
         newLoc = Coordinate33;
      } else if (simVar== 33) {
         newLoc = Coordinate34; 
      } else if (simVar== 34) {
         newLoc = Coordinate35;
      } else if (simVar== 35) {
         newLoc = Coordinate36;
      } else if (simVar== 36) {
         newLoc = Coordinate37;
      } else if (simVar== 37) {
         newLoc = Coordinate38;
      } else if (simVar== 38) {
         newLoc = Coordinate39;
      } else if (simVar== 39) {
         newLoc = Coordinate40;
      } else if (simVar== 40) {
         newLoc = Coordinate41;
      } else if (simVar== 41) {
         newLoc = Coordinate42;
      } else if (simVar== 42) {
         newLoc = Coordinate43;
      } else if (simVar== 43) {
         newLoc = Coordinate44;
      } else if (simVar== 44) {
         newLoc = Coordinate45;
      } else if (simVar== 45) {
         newLoc = Coordinate46;
      } else if (simVar== 46) {
         newLoc = Coordinate47;
      } else if (simVar== 47) {
         newLoc = Coordinate48;
      } else if (simVar== 48) {
         newLoc = Coordinate49;
      } else if (simVar== 49) {
         newLoc = Coordinate50;
      } else if (simVar== 50) {
         newLoc = Coordinate51;
      }
}

bool AP_Follow_Location::get_location(AP_GPSParser _gpsParser){
   // receivedLoc.lat = _gpsParser.get_latitude();
   // receivedLoc.lng = _gpsParser.get_longitude();
   hal.console->printf("Latitude %li \n", receivedLoc.lat);
   hal.console->printf("Longitude %li \n", receivedLoc.lng);
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
