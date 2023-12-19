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

bool AP_Follow_Location::get_location(AP_GPSParser _gpsParser){
   receivedLoc.lat = _gpsParser.get_latitude();
   receivedLoc.lng = _gpsParser.get_longitude();
   hal.console->printf("data: %li,%li\n", receivedLoc.lat, receivedLoc.lng);
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
