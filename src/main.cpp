#include <iostream>
#include <iomanip>
#include <thread>
#include "VehicleManager.h"

template<class T>
void getValidatedFloat(const std::string &prompt, T &value) {
    while (true) {
        std::cout<<std::left<<std::setw(25)<<prompt;
        std::cin>>value;

        if(std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout<<"Invald number. Please try again..."<<std::endl;
        }
        else {
            std::cin.ignore(1000, '\n');
            break;
        }
    }
}

void AskUser(std::string &Name, float &minVal, float &maxVal, float &steps) {
    getValidatedFloat("Enter Signal Name: ", Name);
    getValidatedFloat("Enter Minimum Value: ", minVal);
    getValidatedFloat("Enter Maximum Value: ", maxVal);
    getValidatedFloat("Enter Update Step Value: ", steps);
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
            std::cin.clear();
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }
    mVehicleManager.printDashboard();
}