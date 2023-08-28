from Phidget22.Phidget import *
from Phidget22.Devices.VoltageInput import *
import time

def onSensorChange(self, sensorValue, sensorUnit):
	print("SensorValue: " + str(sensorValue))
	print("SensorUnit: " + str(sensorUnit.symbol))
	print("----------")

def main():
	voltageInput2 = VoltageInput()

	voltageInput2.setIsHubPortDevice(True)
	voltageInput2.setHubPort(2)

	voltageInput2.setOnSensorChangeHandler(onSensorChange)

	voltageInput2.openWaitForAttachment(5000)

	voltageInput2.setSensorType(VoltageSensorType.SENSOR_TYPE_1135)

	try:
		input("Press Enter to Stop\n")
	except (Exception, KeyboardInterrupt):
		pass

	voltageInput2.close()

main()
