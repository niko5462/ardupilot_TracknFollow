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
