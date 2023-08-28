from Phidget22.Phidget import *
from Phidget22.Devices.VoltageRatioInput import *
import time

def onSensorChange(self, sensorValue, sensorUnit):
	print("SensorValue: " + str(sensorValue))
	print("SensorUnit: " + str(sensorUnit.symbol))
	print("----------")

def main():
	voltageRatioInput0 = VoltageRatioInput()

	voltageRatioInput0.setIsHubPortDevice(True)
	voltageRatioInput0.setHubPort(0)

	voltageRatioInput0.setOnSensorChangeHandler(onSensorChange)

	voltageRatioInput0.openWaitForAttachment(5000)

	voltageRatioInput0.setSensorType(VoltageRatioSensorType.SENSOR_TYPE_1122_AC)
	#Other valid sensor types for this sensor include: SENSOR_TYPE_1122_DC

	try:
		input("Press Enter to Stop\n")
	except (Exception, KeyboardInterrupt):
		pass

	voltageRatioInput0.close()

main()
