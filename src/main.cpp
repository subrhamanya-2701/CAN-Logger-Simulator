#include <iostream>
#include <iomanip>
#include <thread>
#include "VehicleManager.h"

void AskUser(std::string &Name, float &minVal, float &maxVal, float &steps) {
    std::cout<<std::left<<std::setw(25)<<"Enter Signal Name: ";
    std::cin>>Name;
    std::cout<<std::left<<std::setw(25)<<"Enter Minimum Value: ";
    std::cin>>minVal;
    std::cout<<std::endl;
    std::cout<<std::left<<std::setw(25)<<"Enter Maximum Value: ";
    std::cin>>maxVal;
    std::cout<<std::endl;
    std::cout<<std::left<<std::setw(25)<<"Enter Update Step Value: ";
    std::cin>>steps;
}

int main () {
    VehicleManager mVehicleManager;

    std::string SignalName;
    float minVal {0}, maxVal {0}, steps {5};

    std::cout<<"Welcome to Can Logger Simulation"<<std::endl;
    while(true) {
        std::string mUserInput;
        std::cout<<"You want to add Signal (Y/N) : ";
        std::cin>>mUserInput;
        if(mUserInput == "N") {
            if(mVehicleManager.getSignalsize() > 0) {
                std::cout<<"Starting the Simulations";
                std::this_thread::sleep_for(std::chrono::seconds(1));
                std::cout<<".";
                std::this_thread::sleep_for(std::chrono::seconds(1));
                std::cout<<".";
                std::this_thread::sleep_for(std::chrono::seconds(1));
                std::cout<<"."<<std::endl;
                mVehicleManager.startSimulation();
                break;
            }
            else {
                std::cout<<"Can't start simulation for Empty signals::Exit"<<std::endl;
                exit(0);
            }
        } else if(mUserInput == "Y") {
            AskUser(SignalName, minVal, maxVal, steps);
            auto signal = std::make_shared<VehicleSignal>(SignalName, minVal, maxVal, steps);
            mVehicleManager.addSignal(signal);
        }
        else {
            std::cout<<"Entered wrong Input please Try Again..."<<std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }
    mVehicleManager.printDashboard();
}