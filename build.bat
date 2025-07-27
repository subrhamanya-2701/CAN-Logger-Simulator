@echo off
setlocal

echo Compiling...

:: Compile source files

g++ -c .\src\VehicleManager.cpp -I include -o .\VehicleManager.o
if errorlevel 1 (
    echo Failed to Compile VehicleManager.cpp
    goto end
)

g++ -c .\src\VehicleSignal.cpp -I include -o .\VehicleSignal.o
if errorlevel 1 (
    echo Failed to Compile VehicleSignal.cpp
    goto end
)

g++ -c .\src\main.cpp -I include -o .\main.o
if errorlevel 1 (
    echo Failed to Compile main.cpp
    goto end
)

:: Linking

echo Linking...
g++ .\VehicleManager.o .\VehicleSignal.o .\main.o -o .\CANLogger.exe
if errorlevel 1 (
    echo Linking Failed
    goto end
)
echo Successfully created CANLogger.exe
goto done

:end
echo Build Failed. Please check the errors above.

:done
endlocal