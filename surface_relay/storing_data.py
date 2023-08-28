# Purpose of this script is to make a blank text file and save data to it

import os
import time
from datetime import datetime

class StoringData(object):
	def __init__(self):
		# set inital parameters
		print("Storing data code running")

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
		while True:
			# Get data you want
			# data = data # if data isn't a string type, transform to a string

			# example data ""Iterator is at #". Each datapoint is given a timestamp
			i = 0 # iterator
			while i<4:
				iterator_str = str(i)
				data = "Iterator is at: " + iterator_str
				
				timestamp_current = time.time()
				timestamp_current_readable = datetime.fromtimestamp(timestamp_current)
				
				with open("%s" % self._timestamp_filename, "a") as datafile:
					datafile.write("%s : %s\n" % (timestamp_current_readable, data))
				i = i +1
			
			print("Iterator finished. Program ending")
			exit()

if __name__ == '__main__':
        node = StoringData()
        node.run()
