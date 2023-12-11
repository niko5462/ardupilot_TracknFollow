#include "AP_Follow_Location.h"
#include "Copter.h"

#define RANGE 50
#define KP 1
#define PERIPHERY 7.5

// constructor
AP_Follow_Location::AP_Follow_Location(){
}

bool AP_Follow_Location::location_changed(AP_GPSParser _gpsParser){
      prevLoc.lat = newLoc.lat;
      prevLoc.lng = newLoc.lng;
      newLoc.lat = _gpsParser.get_latitude();
      newLoc.lng = _gpsParser.get_longitude();
      return true;
}

bool AP_Follow_Location::location_valid(){
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

void AP_Follow_Location::update_velocity_vector(){
   dist_len = get_distance();
   if (dist_len > RANGE){
      //automatic position hold with manual override, with automatic throttle
      copter.set_mode(Mode::Number::POSHOLD, ModeReason::GCS_COMMAND);
   }  else if (dist_len > PERIPHERY){
      vel.x = (x1 * 100 / dist_len) * KP; // x1 is in meters and vel.x should be in cm/s. Therefore, we multiply by 100
      vel.y = (y1 * 100 / dist_len) * KP; // y1 is in meters and vel.y should be in cm/s. Therefore, we multiply by 100
      vel.z = 0;
   }  else {
      vel.x = 0; // x, y, and z are set to 0 for hovering
      vel.y = 0;
      vel.z = 0;
   }
   copter.mode_guided.set_velocity(vel);
}
