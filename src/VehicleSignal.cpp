#include "VehicleSignal.h"

#include <stdlib.h>
VehicleSignal::VehicleSignal(const std::string& name, float minVal, float maxVal, float step) 
    : mSignalName(name), minVal(minVal), maxVal(maxVal), step(step), mSignalValue{minVal} {}

void VehicleSignal::update() {
    std::lock_guard<std::mutex> lock(mtx);
    mSignalValue += (rand()%2 == 0)? step : -step;
    if(mSignalValue > maxVal) mSignalValue = maxVal;
    else if(mSignalValue < minVal) mSignalValue = minVal;
}

float VehicleSignal::getValue() {
    std::lock_guard<std::mutex> lock(mtx);
    return mSignalValue;
}

std::string VehicleSignal::getName() {
    return mSignalName;
}