import serial
from datetime import date

arduino = serial.Serial('COM7', 115200)
arduino.close()
arduino.open()

today = date.today()
date_string = today.strftime("%b-%d-%Y")
name_string = input('Enter Test Description: ')
file_name = date_string + " " + name_string + ".txt"
file = open(file_name, "a")
file.write("Strain Gauge Voltage Data File")
file.close()

while True:
    data = arduino.readline()
    data_str = str(data.decode()).replace("\n", "")     # decodes, type casts, and removes the new line character
    file = open(file_name, "a")                         # open file in same directory as this file in append mode
    file.write(data_str)
    file.close()
