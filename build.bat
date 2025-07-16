@echo off

echo Compiling...
g++ -c .\include\VehicleManager.h
g++ -c .\include\VehicleSignal.h

g++ -c .\src\VehicleManager.cpp -I include -o .\VehicleManager.o
g++ -c .\src\VehicleSignal.cpp -I include -o .\VehicleSignal.o
g++ -c .\src\main.cpp -I include -o .\main.o

echo linking...
g++ .\VehicleManager.o .\VehicleSignal.o .\main.o -o .\CANLogger.exe

echo Successfully created CANLogger.exe