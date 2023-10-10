#!/bin/bash

# Purpose of this script is to start the Surface Relay health monitoring system script file

# Check if config_status file exists. If it doesn't, create it and the rest of the config setup 
if ! [ -d "config_status.txt" ]
then
	# Create config_status.txt
	echo "Creating config_status.txt"
	touch config_status.txt
	echo 'config_status.txt created' | sudo tee -a config_status.txt
	echo ""

	# Create the data_storage_sensors folder
	echo "Creating data_storage_sensors folder"
	mkdir data_storage_sensors
	echo '/data_storage_sensors/ folder created' | sudo tee -a config_status.txt
	echo ""

	# Move the libphidget libraries to the correct location
	echo "Moving the Phidget libraries to the proper location"
	cd ../phidget_libraries/
	cp -R libphidget22-1.16.20230707 /usr/lib/
	cp -R libphidget22extra-1.16.20230707 /usr/lib/
	echo 'Phidget libraries moved to proper location' | sudo tee -a config_status.txt
	echo ""
	
	# Return to surface_relay/surface_relay
	echo Returning to original directory
	cd ../surface_relay
fi

# Source ros
source /opt/ros/foxy/setup.bash
source /opt/ros2_ws/install/setup.bash

# Let user know the script is starting
#echo
#echo Make sure the phidget sensors are in the following configuration with the phidget hub:
#echo Temperature -- hub port 0
#echo Amperage ----- hub port 1
#echo Voltage ------ hub port 2
#echo
#echo Note: amperage sensor has 2 data ports to the phidget hub - use the bottom data port [AC RMS]
#echo

echo --- Starting Surface Relay health monitoring system ---
echo

# Start the system health monitoring script
ros2 run surface_relay sensor_package
