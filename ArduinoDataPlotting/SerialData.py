import serial

arduino = serial.Serial('COM7', 115200)
arduino.close()
arduino.open()

file = open("Voltage_Data.txt", "a")
file.write("Strain Gauge Voltage Data File")
file.close()

while True:
    data = arduino.readline()
    data_str = str(data.decode()).replace("\n", "")     # decodes, type casts, and removes the new line character
    file = open("Voltage_Data.txt", "a")                # open file in same directory as this file in append mode
    file.write(data_str)
    file.close()
