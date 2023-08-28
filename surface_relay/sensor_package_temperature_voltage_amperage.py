# Purpose of this script is to take voltage, amperage, and temperature readings and output them to ROS and the /data_storage_sensors folder

# Inputs: 
# [2] Voltage reading from 1x VINT voltage phidget: 1x battery [22.2V]
# [3] Amperage reading from 1x VINT amperage phidget: 1x battery [22.2V]
# [4] temperature reading from 1x VINT temperature phidget: iSVP [Surface Relay sphere]

# Output: 
# [1] ROS2 topic: /surface_relay/system_health/voltage
# [2] ROS2 topic: /surface_relay/system_health/amperage
# [3] ROS2 topic: /surface_relay/system_health/temperature
# [4] ROS2 topic: /surface_relay/system_health/health_summary
# [5] Txt file storing sensor data: /surface_relay/surface_relay/data_storage_sensors/
# [5.1] Name of the txt file will be the timestamp when the script was started
# [5.2] Data in that txt file is prefaced by the timestamp of that data

# Sources for information
# [1] Voltage sensor: Phidget ID 1135_0B. Link: https://www.phidgets.com/?tier=3&catid=16&pcid=14&prodid=1067
# [2] Amperage sensor: Phidget ID 1122_0. Link: https://www.phidgets.com/?tier=3&catid=16&pcid=14&prodid=93
# [3] Temperature sensor: Phidget ID TMP1000_0. Link: https://www.phidgets.com/?&prodid=724
# [4] Hub Phidget: ID HUB0001_1. Link: https://www.phidgets.com/?tier=3&catid=2&pcid=1&prodid=1202

import rclpy
from rclpy.node import Node
from std_msgs.msg import String
import time

import os
from datetime import datetime

from Phidget22.Phidget import *
from Phidget22.Devices.TemperatureSensor import *
from Phidget22.Devices.VoltageRatioInput import *
from Phidget22.Devices.VoltageInput import *

class SensorPackageReader(Node):
	def __init__(self):
		super().__init__("system_health_summary")

		# Set ROS topics
		self._publish_temperature = self.create_publisher(String, 'surface_relay/system_health/temperature', 10)
		self._publish_amperage = self.create_publisher(String, 'surface_relay/system_health/amperage', 10)
		self._publish_voltage = self.create_publisher(String, 'surface_relay/system_health/voltage', 10)
		self._publish_health_summary = self.create_publisher(String, 'surface_relay/system_health/health_summary', 10)

		# Set sensor parameters
		hub_port_number_temperature_sensor = 0
		hub_port_number_amperage_sensor = 1
		hub_port_number_voltage_sensor = 2
		publish_data_speed = 2 # seconds
		self._sensor_txt_file_storage_time = 2 # publish_data_speed x self._sensor_txt_file_storags_time = seconds between txt file recordings
		self._sensor_txt_file_iterator = 0
		
		# Set file and folder paths
		current_directory = os.getcwd()
		path_to_data_storage = current_directory + "/data_storage_sensors/"

		# Get timestamp, and make it readable by humans
		timestamp = time.time()
		timestamp_readable = datetime.fromtimestamp(timestamp)
		
		# Set filepath for blank txt file as: $CURRENT_DIRECTORY + "/data_storage_sensors/" + $TIMESTAMP + ".txt"
		self._timestamp_filename = path_to_data_storage + str(timestamp_readable) + ".txt"

		# Initialize txt file in surface_relay/surface_relay/data_storage_sensors
		f = open("%s" % self._timestamp_filename, "x")
		f.close
		
		# Set maximum characters for sensor readings for better human readability
		self._maximum_data_length_characters = 5

		# Setup the sensor readers
		temperatureSensor0 = TemperatureSensor() # temperature sensor
		voltageRatioInput0 = VoltageRatioInput() # amperage sensor
		voltageInput0 = VoltageInput() # voltage sensor
		
		temperatureSensor0.setHubPort(hub_port_number_temperature_sensor)
		voltageRatioInput0.setIsHubPortDevice(True)
		voltageRatioInput0.setHubPort(hub_port_number_amperage_sensor)
		voltageInput0.setIsHubPortDevice(True) 
		voltageInput0.setHubPort(hub_port_number_voltage_sensor)
		
		# Confirm all hub ports
		print("Voltage port set. Hub port ------ " + str(hub_port_number_voltage_sensor))
		print("Amperage port set. Hub port ----- " + str(hub_port_number_amperage_sensor))
		print("Temperature port set. Hub port -- " + str(hub_port_number_temperature_sensor))

		# Begin sensor readings
		print("Sensor setups complete. Beginning readings\n")
		temperatureSensor0.setOnTemperatureChangeHandler(self._on_temperature0_Sensorchange)
		voltageRatioInput0.setOnSensorChangeHandler(self._on_amperage_change)
		voltageInput0.setOnSensorChangeHandler(self._on_voltage_change)
		
		temperatureSensor0.openWaitForAttachment(5000) # milliseconds. Wait time recommended by manufacturer
		voltageRatioInput0.openWaitForAttachment(5000)
		voltageInput0.openWaitForAttachment(5000)
		
		voltageRatioInput0.setSensorType(VoltageRatioSensorType.SENSOR_TYPE_1122_AC) # other valid sensor types for this sensor include: SENSOR_TYPE_1122_DC, SENSOR_TYPE_1122_AC
		voltageInput0.setSensorType(VoltageSensorType.SENSOR_TYPE_1135)

		# Set by manufacturer, sensors stop reading after a timeout. This loop keeps the sensors running as long as the script is, then publishes the sensor data summary on timed intervals
		while True:
			time.sleep(publish_data_speed)
			self._publish_summary_data(self)

	def _on_temperature0_Sensorchange(self, sensor_info, temperature_celsius):
		# Convert celsius to Fahrenheit
		temperature_fahrenheit = self._celsius_to_fahrenheit(temperature_celsius)

		# Convert both temperature readings [C / F] to strings
		temperature_celsius_str = str(temperature_celsius)
		temperature_fahrenheit_str = str(temperature_fahrenheit)

		# Take the data and truncate/lengthen to the same length as the rest of the sensor data in the system for better human readability, and add the  sensor reading unit
		celsius_data_uniform_length_returned = self._uniform_data_length(temperature_celsius_str, "C")
		fahrenheit_data_uniform_length_returned = self._uniform_data_length(temperature_fahrenheit_str, "F")

		# Convert temperature data to ROS2-friendly publishable string
		temperature_final_data = String()
		temperature_final_data.data = fahrenheit_data_uniform_length_returned + ", " + celsius_data_uniform_length_returned

		# Set current temperature reading as global variable to be called by self._publish_summary_data
		self._temperature_summary = temperature_final_data.data		

		# Publish data to rostopic: surface_relay/system_health/temperature
		self._publish_temperature_data(temperature_final_data)

	def _on_amperage_change(self, hub_port_data, amperage_data, sensor_value_info):
		# Convert amperage data and unit to a string
		amperage_data_str = str(amperage_data)
		amperage_unit = str(sensor_value_info.symbol)

		# Take the data and truncate/lengthen to the same length as the rest of the sensor data in the system for better human readability, and add the  sensor reading unit
		amperage_data_uniform_length_returned = self._uniform_data_length(amperage_data_str, amperage_unit)

		# Convert data to str
		amperage_final_data = String()
		amperage_final_data.data = amperage_data_uniform_length_returned

		# Set current amperage reading as global variable to be called by self._publish_summary_data
		self._amperage_summary = amperage_final_data.data	

		# Publish data to rostopic: system_health/amperage
		self._publish_amperage_data(amperage_final_data)

	def _on_voltage_change(self, hub_port_data, voltage_data, sensor_value_info):
		# Convert voltage data and unit to a string
		voltage_data_str = str(abs(voltage_data))
		voltage_unit = str(sensor_value_info.symbol)
		
		# Take the data and truncate/lengthen to the same length as the rest of the sensor data in the system for better human readability, and add the  sensor reading unit
		voltage_data_uniform_length_returned = self._uniform_data_length(voltage_data_str, voltage_unit)
		
		# Convert data to str
		voltage_final_data = String()
		voltage_final_data.data = voltage_data_uniform_length_returned

		# Set current voltage reading as global variable to be called by self._publish_summary_data
		self._voltage_summary = voltage_final_data.data	
		
		# Publish data to rostopic: system_health/voltageage
		self._publish_voltage_data(voltage_final_data)

	def _celsius_to_fahrenheit(self, temperature_celsius):
		# Convert celsius to fahrenheit
		temperature_fahrenheit = (temperature_celsius * (9/5)) + 32
		return temperature_fahrenheit

	def _uniform_data_length(self, sensor_data_string, unit):
		# Purpose of this function is to take data from the sensors and either shorten or lengthen them to a uniform string length, then add the sensor unit. This is to maximize human readability of the data

		if len(sensor_data_string)<self._maximum_data_length_characters:
			sensor_data_string = sensor_data_string + "0"
		elif len(sensor_data_string)>self._maximum_data_length_characters:
			sensor_data_string = sensor_data_string[0:self._maximum_data_length_characters]
		else:
			pass
		
		# Add reading unit to the end of the data string
		sensor_data_string = sensor_data_string + " " + unit

		return sensor_data_string

	def _publish_temperature_data(self, temperature_data):		
		# Publish data to rostopic: surface_relay/system_health/temperature
		self._publish_temperature.publish(temperature_data)
		
	def _publish_amperage_data(self, amperage_data):
		# Publish data to rostopic: surface_relay/system_health/amperage
		self._publish_amperage.publish(amperage_data)
		
	def _publish_voltage_data(self, voltage_data):
		# Publish data to rostopic: surface_relay/system_health/voltage
		self._publish_voltage.publish(voltage_data)
		
	def _publish_summary_data(self, script_data):
		# Publish system health summary data
		system_health_summary_data = String()
		
		# Print system health summary information
		print("---")
		print("Voltage ------ " + self._voltage_summary)
		print("Amperage ----- " + self._amperage_summary)
		print("Temperature -- " + self._temperature_summary)
		print("---\n")
		
		# Publish data to rostopic: surface_relay/system_health/health_summary
		system_health_summary_data.data = "Voltage: " + self._voltage_summary + ", Amperage " + self._amperage_summary + ", Temperature " + self._temperature_summary
		self._publish_health_summary.publish(system_health_summary_data)
		
		if self._sensor_txt_file_iterator == self._sensor_txt_file_storage_time:
			timestamp_current = time.time()
			timestamp_current_readable = datetime.fromtimestamp(timestamp_current)

			with open("%s" % self._timestamp_filename, "a") as datafile:
				datafile.write("%s : %s\n" % (timestamp_current_readable, system_health_summary_data.data))
			
			self._sensor_txt_file_iterator = 0 # reset the counter
		else:
			self._sensor_txt_file_iterator += 1

def main(args=None):
	# initialize rclpy and the node
	rclpy.init(args=args)
	node = SensorPackageReader()
	rclpy.spin(node)
	node.destroy_node()
	rclpy.shutdown()

if __name__ == 'main':
	main()
