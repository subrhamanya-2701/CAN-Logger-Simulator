#ifndef VEHICLE_MANAGER_H
#define VEHICLE_MANAGER_H
#include "VehicleSignal.h"
#include <memory>
#include <vector>
#include <thread>

class VehicleManager {
    public:
        void addSignal(std::shared_ptr<VehicleSignal> signal);
        void startSimulation();
        void printDashboard();
    private:
        std::vector<std::shared_ptr<VehicleSignal>> Signals;
        std::vector<std::thread> Signalthread;
};

#endif