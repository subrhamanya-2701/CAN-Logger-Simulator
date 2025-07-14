#include "VehicleSignal.h"

VehicleSignal::VehicleSignal(const std::string& name, float minVal, float maxVal, float step) 
    : mSignalname(name), minVal(minVal), maxVal(maxVal), step(step) {}