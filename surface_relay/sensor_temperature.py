# Purpose of this script is to take temperature readings and output them to ROS
# Inputs: 
# [1] temperature reading from 1x VINT temperature phidget: iSVP
# [2] ROS2 launch file: hub_port_number_temperature_sensor
# [3] ROS2 launch file: maximum_data_length_characters

# Output: 
# [1] ROS2 topic: /system_health/temperature/

# Sources for information
# [1] Temperature sensor: Phidget ID TMP1000_0. Link: https://www.phidgets.com/?&prodid=724
# [2] Hub Phidget: ID HUB0001_1. Link: https://www.phidgets.com/?tier=3&catid=2&pcid=1&prodid=1202

import rclpy
from rclpy.node import Node
from std_msgs.msg import String
import time

from Phidget22.Phidget import *
from Phidget22.Devices.TemperatureSensor import *

class TemperatureReader(Node):
	def __init__(self):
		super().__init__("system_health_temperature")

		# Set ROS topics
		self._publish_temperature = self.create_publisher(String, 'system_health/temperature', 10)

		# Get parameters from launch file
		#self._hub_port_number_temperature_sensor = rospy.get_param('~hub_port_number_temperature_sensor')
		hub_port_number_temperature_sensor = 0
		#self._maximum_data_length_characters = rospy.get_param('~maximum_data_length_characters')
		self._maximum_data_length_characters = 5

		# Setup the temperature reader
		temperatureSensor0 = TemperatureSensor()
		temperatureSensor0.setHubPort(hub_port_number_temperature_sensor)
		temperatureSensor0.setDeviceSerialNumber(683019)
		print("temperature port set. Hub port: " + str(hub_port_number_temperature_sensor))

		print("Temperature sensor setup complete. Beginning readings\n")
		temperatureSensor0.setOnTemperatureChangeHandler(self._on_temperature_change)
		temperatureSensor0.openWaitForAttachment(5000) # milliseconds. Wait time recommended by manufacturer
		#time.sleep(50) # seconds

	def _on_temperature_change(self, sensor_info, temperature_celsius):
		# Convert celsius to Fahrenheit
		temperature_fahrenheit = self._celsius_to_fahrenheit(temperature_celsius)

		# Convert both temperature readings [C / F] to strings
		temperature_celsius_str = str(temperature_celsius)
		temperature_fahrenheit_str = str(temperature_fahrenheit)

		# Convert both temperature readings to a uniform length for better human readability, and add the unit
		celsius_data_uniform_length_returned = self._uniform_data_length(temperature_celsius_str, "C")
		fahrenheit_data_uniform_length_returned = self._uniform_data_length(temperature_fahrenheit_str, "F")

		#print(celsius_data_uniform_length_returned)
		#print(fahrenheit_data_uniform_length_returned)

		#print("Data str returned : " + data_str_returned)

		# Convert data to str
		msg = String()
		#msg.data = str(temperature_fahrenheit)
		msg.data = fahrenheit_data_uniform_length_returned + ", " + celsius_data_uniform_length_returned

		print("Message data is: " + msg.data)
		# Publish data to rostopic: system_health/temperature
		self._publish_data(msg)

	def _celsius_to_fahrenheit(self, temperature_celsius):
		# Convert celsius to fahrenheit
		temperature_fahrenheit = (temperature_celsius * (9/5)) + 32
		return temperature_fahrenheit

	def _uniform_data_length(self, str_data, unit):
		data_string = str_data
		#print("Length before: " + data_string)
		if len(data_string)<self._maximum_data_length_characters:
			data_string = data_string + "0"
		elif len(data_string)>self._maximum_data_length_characters:
			data_string = data_string[0:self._maximum_data_length_characters]
		else:
			pass
		#print("Length after : " + data_string)

		if unit == "C":
			data_string = data_string + " C"
		else:
			data_string = data_string + " F"

		return data_string

	def _publish_data(self, temperature_data):		
		# Publish temperature reading data
		self._publish_temperature.publish(temperature_data)

def main(args=None):
	# initialize rclpy and the node
	rclpy.init(args=args)
	node = TemperatureReader()
	rclpy.spin(node)
	node.destroy_node()
	rclpy.shutdown()

if __name__ == 'main':
	main()
