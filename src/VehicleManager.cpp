#include "VehicleManager.h"
#include <iostream>
#include <chrono>
#include <iomanip>

void VehicleManager::addSignal(std::shared_ptr<VehicleSignal> signal) {
    Signals.push_back(signal);
}

void VehicleManager::startSimulation() {
    for(std::shared_ptr<VehicleSignal> &Signal: Signals) {
        Signalthread.emplace_back([Signal] () {
            while(true) {
                Signal->update();
                std::this_thread::sleep_for(std::chrono::seconds(1));
            }
        });
    }
}

void VehicleManager::printDashboard() {
    while(true) {
        std::time_t time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        std::cout<< "Time : "<< std::put_time(std::localtime(&time), "%Y-%m-%d %H:%M:%S");
        std::cout<<"\n-----------------------------------------------------"<<std::endl;
        for(std::shared_ptr<VehicleSignal> &signal: Signals) {
            std::cout<<std::setw(12)<<std::left<<signal->getName()<<" : "<<signal->getValue()<<std::endl;
        }
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}