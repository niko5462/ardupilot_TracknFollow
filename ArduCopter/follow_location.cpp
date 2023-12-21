#include "Copter.h"
#include <chrono>

void Copter::follow_location(){
    //followLocation.print_time("Start");
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
                //return;
            }
            //return;
        }
        //return;
    }
    //followLocation.print_time("End");
    return;
}
