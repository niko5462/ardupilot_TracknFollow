#include "Copter.h"

void Copter::follow_location(){
    static bool setupDone = false;

    if (flightmode->is_taking_off()){
        if (!setupDone){
            followLocation._init(); // Setting the start coordinates
            setupDone = true;
            return;
        }
    }

    if (setupDone){
        if ((!flightmode->is_taking_off()) && followLocation.getSimLoc()){
            if (followLocation.check_location()){
                followLocation.update_velocity(); 
                return;
            }
            return;
        }
        return;
    }
}