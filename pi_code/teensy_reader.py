import serial
import time
# Use '/dev/ttyACM0' for USB or '/dev/serial0' for GPIO UART
ser = serial.Serial('/dev/ttyACM0', 57600, timeout=1)
ser.flush()
ser.dtr = True
ser.rts = True

while True:
    if ser.in_waiting > 0:
        line = ser.readline().decode('utf-8').rstrip()
        print(f"Teensy: {line}")
    else:
        print("nothing...")
        time.sleep(1)