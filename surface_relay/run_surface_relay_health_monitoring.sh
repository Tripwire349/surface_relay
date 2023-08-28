#!/bin/bash

# Purpose of this script is to start the Surface Relay health monitoring system script file

# Check if /data_storage/ folder exists. If it doesn't, create it
if ! [ -d "data_storage_sensors/" ]
then
	echo "Creating data_storage_sensors folder"
	mkdir data_storage_sensors
fi

# Let user know the script is starting
echo
echo Set the phidget sensors to the following configuration with the phidget hub, then hit enter:
echo Temperature -- hub port 0
echo Amperage ----- hub port 1
echo Voltage ------ hub port 2
echo
echo Note: amperage sensor has 2 data ports to the phidget hub - use the bottom data port [AC RMS]
echo
read -p " "

echo --- Starting Surface Relay health monitoring system ---
echo

# Start the system health monitoring script
ros2 run surface_relay sensor_package
