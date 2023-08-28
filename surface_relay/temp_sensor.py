from Phidget22.Phidget import *
from Phidget22.Devices.TemperatureSensor import *
import time

def onTemperatureChange(self, temperature):
	print("Temperature: " + str(temperature))

def main():
	temperatureSensor0 = TemperatureSensor()

	temperatureSensor0.setHubPort(0)
	temperatureSensor0.setDeviceSerialNumber(683019)

	temperatureSensor0.setOnTemperatureChangeHandler(onTemperatureChange)

	temperatureSensor0.openWaitForAttachment(5000)

	time.sleep(5)

	try:
		input("Press enter to stop\n")
	except (Exception, KeyboardInterrupt):
		pass

	temperatureSensor0.close()

main()
