from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
	ld = LaunchDescription()
	
	'''
	node_sensor_amperage = Node(
		package="surface_relay",
		executable="sensor_amperage",
	)
	'''
	
	
	'''
	node_sensor_voltage = Node(
		package="surface_relay",
		executable="sensor_voltage",
	)
	'''
	
	'''
	node_sensor_temperature = Node(
		package="surface_relay",
		executable="sensor_temperature",
	)
	'''

	'''
	node_sensor_health_summary = Node(
		package="surface_relay",
		executable="sensor_health_summary",
	)
	'''

	node_sensor_health_summary = Node(
		package="surface_relay",
		executable="sensor_package",
	)
	
	#ld.add_action(node_sensor_amperage)
	#ld.add_action(node_sensor_voltage)
	#ld.add_action(node_sensor_temperature)
	ld.add_action(node_sensor_health_summary)
	
	return ld
