#include "Copter.h"

void Copter::gps_parser_task(){
    gpsParser.print_time("Start");
    gpsParser.setup();
    gpsParser.process();
    gpsParser.print_time("End");
}
