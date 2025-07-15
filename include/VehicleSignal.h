#ifndef VEHICLE_SIGNAL_H
#define VEHICLE_SIGNAL_H

#include <string>
#include <mutex>

class VehicleSignal {
    public:
        VehicleSignal(const std::string& name, float minVal, float maxVal, float step);
        void update();
        float getValue();
        std::string getName();
    private:
        float mSignalValue;
        std::string mSignalName;
        float minVal, maxVal, step;
        std::mutex mtx;
};

#endif
