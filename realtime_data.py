import matplotlib.pyplot as plt
import matplotlib.animation as animation
import serial
import re

ser = serial.Serial('COM3', 9600, timeout=1)

fig, ax = plt.subplots()
xs = []
ys = []

pattern = re.compile(r"[-+]?\d*\.\d+|\d+")

def animate(i, xs, ys):
    try:
        line = ser.readline().decode('utf-8').strip()
        print(f"Read line: {line}")  

        if line:
            try:
                numbers = pattern.findall(line)

                if numbers:
                    distance = float(numbers[0])
                    xs.append(i)
                    ys.append(distance)

                    xs = xs[-100:]  
                    ys = ys[-100:]

                    ax.clear()
                    ax.plot(xs, ys, label='Distance (cm)')
                    ax.set_xlabel('Time')
                    ax.set_ylabel('Distance (cm)')
                    ax.set_title('Real-Time Distance Measurement')
                    ax.legend()

            except ValueError:
                print("Error")
                pass

    except serial.SerialException as e:
        print(f"SerialException: {e}")  

    return []

ani = animation.FuncAnimation(fig, animate, fargs=(xs, ys), interval=100, cache_frame_data=False)

plt.show()
