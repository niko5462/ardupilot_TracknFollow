#include "Copter.h"

void Copter::follow_location(){
    static bool setupDone = false;


    //Checks if the drones has taken off
    if (flightmode->is_taking_off()){
        if (!setupDone){
            setupDone = true;
            return;
        }
    }

    //If setup is done stay in this loop
    if (setupDone){
        if ((!flightmode->is_taking_off()) && followLocation.location_changed(gpsParser)){
            if (followLocation.location_valid()){
                followLocation.update_velocity_vector(); 
                return;
            }
            return;
        }
        return;
    }
}