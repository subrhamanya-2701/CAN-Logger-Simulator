#ifndef VEHICLE_SIGNAL_H
#define VEHICLE_SIGNAL_H

#include <string>
#include <mutex>

class VehicleSignal {
    public:
        VehicleSignal(const std::string& name, float minVal, float maxVal, float step);
        void updateSignal();
        float getSignalValue();
        std::string getSignalName();
    private:
        float mSignal;
        std::string mSignalname;
        float minVal, maxVal, step;
        std::mutex mtx;
};

#endif
