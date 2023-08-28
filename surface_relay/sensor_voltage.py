# Purpose of this script is to take voltage readings and output them to ROS
# Inputs: Voltage readings from 11x VINT voltage phidgets: 8x batteries, 1x DCDC converters (5V, 12V, 24V)
# Outputs: ROS topic /system_health/voltage/

# Sources for information
# [1] Voltage sensor: Phidget ID 1135_0B. Link: https://www.phidgets.com/?tier=3&catid=16&pcid=14&prodid=1067
# [2] Hub Phidget: ID HUB0001_1. Link: https://www.phidgets.com/?tier=3&catid=2&pcid=1&prodid=1202

import rospy
import std_msgs.msg
import time

from Phidget22.Phidget import *
from Phidget22.Devices.VoltageInput import *

class VoltageReader(object):
	def __init__(self):
		rospy.init_node('system_health_voltage')
		rospy.loginfo('AmperageReader. Namespace = %s', rospy.get_namespace())
		if rospy.is_shutdown():
			rospy.logerr('ROS master not running!')
			return

		# Set ROS topics
		self._publish_amperage = rospy.Publisher(String, 'system_health/amperage', queue_size = 10)
		
		# Get parameters from launch file
		self._hub_port_number_amperage_sensor = rospy.get_param('~hub_port_number_amperage_sensor')

		# Initialize empty amperage reading
		self._amperage_reading = 0

	def run(self):
		while not rospy.is_shutdown():
			self._take_amperage()

		rospy.on_shutdown(self._shutdown)

	def _shutdown(self):
		self._amperage_channel.close()
		print("Amperage port closed. Terminating program")

	def _uniform_string_length(self, data):
		# Take an input string and either shorten it, or lengthen it to the appropriate string length so the reader can easy digest the information
		data_string = str(data)
		
		if len(data_string)<self._max_string_length:
			data_string = data_string + " "
		elif len(data_string)>self._max_string_length:
			data_string = data_string[0:self._max_string_length]
		else:
			pass
		
		self._amperage_reading = data_string

	def _take_amperage():
		# Setup the amperage reader
		self._voltageRatioInput = VoltageRatioInput()
		self._voltageRatioInput.setIsHubPortDevice(True)
		self._voltageRatioInput.setHubPort(hub_port_number_amperage_sensor)
		self._voltageRatioInput3.setOnSensorChangeHandler(self._onSensorChange)
		self._voltageRatioInput3.openWaitForAttachment(5000) # value recommended by manufacturer
		self._voltageRatioInput3.setSensorType(VoltageRatioSensorType.SENSOR_TYPE_1122_AC) # other valid sensor types for this sensor include: SENSOR_TYPE_1122_DC
		
		#print("Amperage port set. Hub port: %s" %s hub_port_number_amperage_sensor)
		print("Amperage port set. Hub port: " + str(hub_port_number_amperage_sensor))

	def _on_sensor_change(self, sensor_value, sensor_unit):
		# take data and truncate/lengthen to the same length as the rest of the sensor data in the system
		self._uniform_string_length(sensor_value)
		
		print("Amperage reading [" + str(self.getHubPort()) + "]: " + self._amperage_reading +  str(sensorUnit.symbol))
	
		# Send data to get published
		self.publish_data(sensor_value)
	
		try:
			input("Press Enter to Stop\n")
		except (Exception, KeyboardInterrupt):
			pass
	
	def publish_data(self, amperage_data):
		# Publish amperage reading data
		self._publish_amperage.publish(amperage_data)
	
if __name__ == 'main':
	node = AmperageReader()
	node.run()
	rospy.spin()
