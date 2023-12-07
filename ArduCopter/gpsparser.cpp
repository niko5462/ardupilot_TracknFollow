#include "Copter.h"

void Copter::gps_parser_task(){
    gpsParser.setup();
    gpsParser.process();
}
