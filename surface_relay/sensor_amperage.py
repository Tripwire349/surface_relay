# Purpose of this script is to take amperage readings and output them to ROS
# Input: amperage reading from 1x VINT amperage phidget: 1x battery [22.2V]
# Output: ROS topic /system_health/amperage/

# Sources for information
# [1] Amperage sensor: Phidget ID 1122_0. Link: https://www.phidgets.com/?tier=3&catid=16&pcid=14&prodid=93
# [2] Formula: voltage ratio to amperage (DC vs AC) is the link above > User Guide > Formulas
# [3] Hub Phidget: ID HUB0001_1. Link: https://www.phidgets.com/?tier=3&catid=2&pcid=1&prodid=1202

import rclpy
from rclpy.node import Node
from std_msgs.msg import String
import time

from Phidget22.Phidget import *
from Phidget22.Devices.VoltageRatioInput import *

class AmperageReader(Node):
	def __init__(self):
		super().__init__("system_health_amperage")

		# Set ROS topics
		self._publish_amperage = self.create_publisher(String, 'system_health/amperage', 10)
		
		# Get parameters from launch file
		# self._hub_port_number_amperage_sensor = rospy.get_param('~hub_port_number_amperage_sensor')
		hub_port_number_amperage_sensor = 1
		#self._maximum_data_length_characters = rospy.get_param('~maximum_data_length_characters')
		self._maximum_data_length_characters = 5

		# Initialize empty amperage reading
		#self._amperage_reading = 0

		# Setup the amperage reader
		self._voltageRatioInput0 = VoltageRatioInput()
		self._voltageRatioInput0.setIsHubPortDevice(True)
		self._voltageRatioInput0.setHubPort(hub_port_number_amperage_sensor)
		print("Amperage port set. Hub port: " + str(hub_port_number_amperage_sensor))
		self._voltageRatioInput0.setOnSensorChangeHandler(self._on_sensor_change)
		self._voltageRatioInput0.openWaitForAttachment(5000) # value recommended by manufacturer
		self._voltageRatioInput0.setSensorType(VoltageRatioSensorType.SENSOR_TYPE_1122_AC) # other valid sensor types for this sensor include: SENSOR_TYPE_1122_DC, SENSOR_TYPE_1122_AC

	def _on_sensor_change(self, hub_port_data, amperage_data, sensor_value_info):
		#print("data 1, hub: " + str(hub_port_data))
		#print("data 2, amps: " + str(amperage_data))
		#print("data 3, sensor value data: " + str(sensor_value_info))

		# Convert data to a string
		amperage_data_str = str(amperage_data)

		# take data and truncate/lengthen to the same length as the rest of the sensor data in the system


		amperage_data_uniform_length_returned = self._uniform_data_length(amperage_data_str, sensor_value_info.symbol)

		# Convert data to str
		msg = String()
		#msg.data = str(temperature_fahrenheit)
		msg.data = amperage_data_uniform_length_returned

		print("Message data is: " + msg.data)
		# Publish data to rostopic: system_health/amperage
		self._publish_data(msg)

	def _uniform_data_length(self, str_data, unit):
		# Take an input string and either shorten it, or lengthen it to the appropriate string length so the reader can easy digest the information

		if len(str_data)<self._maximum_data_length_characters:
			str_data = str_data + " "
		elif len(str_data)>self._maximum_data_length_characters:
			str_data = str_data[0:self._maximum_data_length_characters]
		else:
			pass

		# TODO: CHECK READING WITH MULTIMETER. UNIT SAYS IT'S IN 20+ AMP RANGE WITH A RASPBERRY PI. LIKELY mA
		#str_data = str_data + " " str(unit)
		str_data = str_data + " mA"

		return str_data

	def _publish_data(self, amperage_data):
		# Publish amperage reading data
		self._publish_amperage.publish(amperage_data)

def main(args=None):
	# initialize rclpy and the node
	rclpy.init(args=args)
	node = AmperageReader()
	rclpy.spin(node)
	node.destroy_node()
	rclpy.shutdown()

if __name__ == 'main':
	main()
