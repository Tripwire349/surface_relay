# Purpose of this script is to take all sensor readings and output them to ROS in an easy human-readable format

# Inputs: 
# [1] 1x temperature reading: Surface Relay internals
# [2] 1x voltage reading: 1x battery [22.2V]
# [3] 1x amperage reading: 1x battery [22.2V]

# Outputs: 
# [1] ROS topic /system_health/summary/
# [2] Data stored in /surface_relay/surface_relay/data_storage. Txt file name is the timestamp the script initially started, each line in the txt file has the data taken and timestamp of that data

# Sources for information
# [1] Temperature sensor: Phidget ID TMP1000_0. Link: https://www.phidgets.com/?&prodid=724
# [2] Voltage sensor: Phidget ID 1135_0B. Link: https://www.phidgets.com/?tier=3&catid=16&pcid=14&prodid=1067
# [3] Amperage sensor: Phidget ID 1122_0. Link: https://www.phidgets.com/?tier=3&catid=16&pcid=14&prodid=93
# [4] Hub Phidget: ID HUB0001_1. Link: https://www.phidgets.com/?tier=3&catid=2&pcid=1&prodid=1202

import rospy
from std_msgs.msg import String
import time
import os
from datetime import datetime

class SystemHealthReader(object):
	def __init__(self):
		rospy.init_node('system_health_summary')
		rospy.loginfo('TemperatureReader. Namespace = %s', rospy.get_namespace())
		
		if rospy.is_shutdown():
			rospy.logerr('ROS master not running!')
			return

		# Get parameters from launch file
		self._system_update_seconds = rospy.get_param('~system_update_time_seconds_value') # System update time (seconds)

		# Set ROS topics
		self._subscribe_to_temperature_readings = rospy.Subscriber(String, 'system_health/temperature', self._on_receive_temperature_data)
		self._subscribe_to_voltage_readings = rospy.Subscriber(String, 'system_health/voltage', self._on_receive_voltage_data)
		self._subscribe_to_amperage_readings = rospy.Subscriber(String, 'system_health/amperage', self._on_receive_amperage_data)
		self._publish_system_health_summary = rospy.Publisher(String, 'system_health/summary', queue_size = 10)

		# Setup initial readings
		self._temperature_reading = 0
		self._voltage_reading = 0
		self._amperage_reading = 0

		self._system_health_summary_string = ""

		### Data storage [surface_relay/surface_relay/data_storage/]
		# setup file and folder paths
		current_directory = os.getcwd()
		path_to_data_storage = current_directory + "/data_storage/"

		# get timestamp, and make it readable by humans
		timestamp = time.time()
		timestamp_readable = datetime.fromtimestamp(timestamp)
		
		# set filepath for blank txt file as: $CURRENT_DIRECTORY + "/data_storage/" + $TIMESTAMP + ".txt"
		self._timestamp_filename = path_to_data_storage + str(timestamp_readable) + ".txt"

		# publish activation time to surface_relay/data_storage
		f = open("%s" % self._timestamp_filename, "x")
		f.close

	def run(self):
		while not rospy.is_shutdown():
			# Publish data
			self.publish_data

			# Sleep for a set amount of time
			time.sleep(self._system_update_seconds)

		rospy.on_shutdown(self._shutdown)

	def _shutdown(self):
		print("Terminating program")

	def _on_receive_temperature_data(self, data):
		# Take received data
		self._temperature_reading = data.data
		#print("Temperature data received: %s" %s self._temperature_reading)
		print("Temperature data received: " + str(self._temperature_reading))

	def _on_receive_voltage_data(self, data):
		# Take received data
		self._voltage_readings = data.data
		#print("Voltage data received: %s" %s self._voltage_reading)
		print("Voltage data received: " + str(self._voltage_reading))


	def _on_receive_amperage_data(self, data):
		# Take received data
		self._amperage_readings = data.data
		#print("Amperage data received: %s" %s self._amperage_reading)
		print("Amperage data received: " + str(self._amperage_reading))

	def publish_data(self, system_summary_data):
		# Combine all data into single human-readable string
		self._system_health_summary_string = "Amperage [A]: %s\nVoltage [V]: %s\nTemperature [F]: %s" %s (self._amperage_reading, self._voltage_reading, self._temperature_reading)
		print(self._system_health_summary_string)

		### Output data
		# Publish system health string
		self._publish_system_health_summary.publish(self._system_health_summary_string)

		# Store data in /surface_relay/surface_relay/data_storage/
		timestamp_current = time.time()
		timestamp_current_readable = datetime.fromtimestamp(timestamp_current)
		with open("%s" % self._timestamp_filename, "a") as datafile:
			datafile.write("%s : %s\n" % (timestamp_current_readable, self._system_health_summary_string))

		# Sleep, so code outputs at regular intervals [set in launch file]
		time.sleep(self._system_update_seconds)

if __name__ == 'main':
	node = SystemHealthReader()
	node.run()
	rospy.spin()
