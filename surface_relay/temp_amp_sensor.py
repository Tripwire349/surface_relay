from Phidget22.Phidget import *
from Phidget22.Devices.TemperatureSensor import *
from Phidget22.Devices.VoltageRatioInput import *
import time

def onTemperature0_SensorChange(self, temperature):
	print("Temperature: " + str(temperature))

def onSensorChange(self, sensorValue, sensorUnit):
	print("SensorValue: " + str(sensorValue))
	print("SensorUnit: " + str(sensorUnit.symbol))
	print("----------")

def main():
	temperatureSensor0 = TemperatureSensor()
	voltageRatioInput0 = VoltageRatioInput()

	#temperatureSensor0.setIsHubPortDevice(True)
	temperatureSensor0.setHubPort(0)
	voltageRatioInput0.setIsHubPortDevice(True)
	voltageRatioInput0.setHubPort(1)
	
	#temperatureSensor0.setDeviceSerialNumber(683019)

	temperatureSensor0.setOnTemperatureChangeHandler(onTemperature0_SensorChange)
	voltageRatioInput0.setOnSensorChangeHandler(onSensorChange)

	temperatureSensor0.openWaitForAttachment(5000)
	voltageRatioInput0.openWaitForAttachment(5000)

	voltageRatioInput0.setSensorType(VoltageRatioSensorType.SENSOR_TYPE_1122_AC)
	#Other valid sensor types for this sensor include: SENSOR_TYPE_1122_DC

	time.sleep(5)

	temperatureSensor0.close()
	voltageRatioInput0.close()

main()
