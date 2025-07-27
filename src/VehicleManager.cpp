#include "VehicleManager.h"
#include <iostream>
#include <chrono>
#include <iomanip>

std::ofstream csvlogFile;
std::mutex csvMutex;

void VehicleManager::addSignal(std::shared_ptr<VehicleSignal> signal) {
    Signals.push_back(signal);
}

void VehicleManager::startSimulation() {
    csvlogFile.open("logs/signals_log.csv");
    csvlogFile << "Timestamp,SignalName,Value\n";
    for(std::shared_ptr<VehicleSignal> &Signal: Signals) {
        Signalthread.emplace_back([Signal] () {
            while(true) {
                Signal->update();

                //Get the Current Time
                auto now = std::chrono::system_clock::now();
                std::time_t now_c = std::chrono::system_clock::to_time_t(now);
                std::stringstream timestamp;
                timestamp <<std::put_time(std::localtime(&now_c), "%Y-%m-%d %H:%M:%S");
                
                // Write to CSV
                {
                    std::lock_guard<std::mutex> lock(csvMutex);
                    csvlogFile << timestamp.str() << " : " << Signal->getName() << " : " << Signal->getValue() <<std::endl; 
                }
                
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
        std::cout<<"-------------------------------------------------------"<<std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

size_t VehicleManager::getSignalsize() {
    return Signals.size();
}