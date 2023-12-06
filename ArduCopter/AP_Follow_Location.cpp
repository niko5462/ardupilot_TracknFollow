#include "AP_Follow_Location.h"
#include "Copter.h"
#include <AP_Common/Location.h>

AP_GPSParser gpsParser;
AP_Follow_Location::AP_Follow_Location(){

}

void AP_Follow_Location::_init(){
   // Temporary start location for testing
   StartLoc.lat = 570138730;
   StartLoc.lng = 99874617;
   StartLoc.alt = 13;
}

#include <iostream>
#include <cstring>

void splitString(const char* buffer, char* lngBuffer, char* latBuffer, char* altBuffer) {
    // Assuming the input string has the format "longitude latitude altitude"
    
    // Find the first space (longitude and latitude separator)
    const char* lonEnd = strchr(buffer, ',');
    
    if (lonEnd != nullptr) {
        // Calculate the length of the longitude string
        size_t lonLength = lonEnd - buffer;
        
        // Copy the longitude string to the lonBuffer
        strncpy(lngBuffer, buffer, lonLength);
        lngBuffer[lonLength] = '\0'; // Null-terminate the string
        
        // Move to the next character after the space
        buffer = lonEnd + 1;
        
        // Find the second space (latitude and altitude separator)
        const char* latEnd = strchr(buffer, ',');
        
        if (latEnd != nullptr) {
            // Calculate the length of the latitude string
            size_t latLength = latEnd - buffer;
            
            // Copy the latitude string to the latBuffer
            strncpy(latBuffer, buffer, latLength);
            latBuffer[latLength] = '\0'; // Null-terminate the string
            
            // Move to the next character after the space
            buffer = latEnd + 1;
            
            // Copy the remaining string to the altBuffer
            strcpy(altBuffer, buffer);
        } else {
            // If the second space is not found, set latBuffer and altBuffer to empty strings
            latBuffer[0] = '\0';
            altBuffer[0] = '\0';
        }
    } else {
        // If the first space is not found, set lonBuffer, latBuffer, and altBuffer to empty strings
        lngBuffer[0] = '\0';
        latBuffer[0] = '\0';
        altBuffer[0] = '\0';
    }
}


/*bool AP_Follow_Location::get_location(){
   if (gpsParser.has_recieved_message()) { 
   // This function checks if the location has been received from the Link module
   uint8_t* mavBuffer = gpsParser.get_buffer();
   num = 0;

   //create a for loop that takes every char up to a comma and puts it into receivedLoc.lat, receivedLoc.lng, and receivedLoc.alt
   for (size_t i = 0; i < sizeof(mavBuffer); i++){
      if (mavBuffer[i] != ','){
            switch (num)
         {
         case 0:
            mavBuffLat[i] = mavBuffer[i+1];
            break;
         case 1:
            mavBuffLng[i] = mavBuffer[i];
            break;
         case 2:
            mavBuffAlt[i] = mavBuffer[i];
            break;
         default:
            return false;
            break;
         }
      } else {
         num += 1;
      }
   }

   receivedLoc.lat = strtol(mavBuffLat, NULL, 10);
   receivedLoc.lng = strtol(mavBuffLng, NULL, 10);
   receivedLoc.alt = strtol(mavBuffAlt, NULL, 10);
   return true;
   }
}*/

bool AP_Follow_Location::change_location(){
   // This function gets the location from the Link module
   if (get_location()){                   // TODO: add that it only goes into this if statement if the location has changed as well
      NewLoc.alt = receivedLoc.alt; 
      NewLoc.lat = receivedLoc.lat;
      NewLoc.lng = receivedLoc.lng;
      return true;
   } else{
      return false;
   }
   
   // Temporary location for testing
   // NewLoc.alt = StartLoc.alt;
   // NewLoc.lat = StartLoc.lat;
   // NewLoc.lng = StartLoc.lng;
   
   /* ________________________________________________For testing _______________________________________________

   if (count != previous_count) { //whenever the count variable changes, add 5 to the lattitude and longitude
      NewLoc.lat -= 500;
      NewLoc.lng -= 500;
      previous_count = count;
   }
   return true;
   
   // ____________________________________________________________________________________________________________*/
}

bool AP_Follow_Location::check_location(){
   if (!check_latlng(NewLoc.lat, NewLoc.lng)) {
      // failed as the new location is not valid
      return false;
   } else if(NewLoc.sanitize(copter.current_loc)){ // if the location wasn't already sane don't load it
      // failed as the current location is not valid
      return false;
   } else{
      return true;
   }
}

double AP_Follow_Location::get_distance(){
   x1 = copter.current_loc.get_distance_NE(NewLoc).x;
   y1 = copter.current_loc.get_distance_NE(NewLoc).y;
   z1 = copter.current_loc.get_alt_cm(NewLoc.get_alt_frame(),NewLoc.alt);
   return sqrt(x1*x1 + y1*y1);
}

void AP_Follow_Location::update_velocity(){
   range = 100; //The range of the allowed follow mode
   kp = 1; //The proportional gain for the velocity controller

   // if the drone is out of range, it should land
   wp_len = get_distance();
   if (wp_len > range){
      copter.set_mode(Mode::Number::LAND, ModeReason::GCS_COMMAND);
   } else if (wp_len > 7.5){
      vel.x = (x1*100/wp_len)*kp;  // x1 is in meters and vel.x should be in cm/s. Therefroe, we multiply by 100
      vel.y = (y1*100/wp_len)*kp;  // y1 is in meters and vel.y should be in cm/s. Therefroe, we multiply by 100
      vel.z = z1*100/wp_len;
   } else {
      vel.x = 0;   // x, y, and z are set to 0 for hovering
      vel.y = 0;
      vel.z = 0;

      count += 1; // counter to change the location
   }
   copter.mode_guided.set_velocity(vel);
}



