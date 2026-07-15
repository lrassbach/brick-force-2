from rplidar import RPLidar
import time
PORT = '/dev/ttyUSB0'   # Change if needed

lidar = RPLidar(PORT, timeout=3.0)
time.sleep(0.5)
print("RPLidar A2 connected. Starting scan...")

try:
    print("start motor")
    lidar.start_motor()
    time.sleep(1.0)
    for scan in lidar.iter_scans():
        print(scan)   # list of (quality, angle, distance)
except Exception as e:
    print("Stopping: " + e)
finally:
    lidar.stop()
    lidar.stop_motor()
    lidar.disconnect()
