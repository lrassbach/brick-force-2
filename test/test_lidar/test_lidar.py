from rplidar import RPLidar
import time
PORT = '/dev/ttyUSB0'   # Change if needed

lidar = RPLidar(PORT)
time.sleep(0.5)
print("RPLidar A2 connected. Starting scan...")

try:
    lidar.start_motor()

    for scan in lidar.iter_scans():
        print(scan)   # list of (quality, angle, distance)
except Exception:
    print("Stopping.")
finally:
    lidar.stop()
    lidar.stop_motor()
    lidar.disconnect()
