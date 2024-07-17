import matplotlib.pyplot as plt 
import matplotlib.animation as animation
import serial

ser = serial.Serial('COM3',9600,timeout=1)        
fig, ax = plt.subplots()
xs = []
ys = []

def animate(i, xs, ys):
    line = ser.readline().decode('utf-8').strip()

    if line:
        try:
            distance = float(line)
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
            pass

ani = animation.FuncAnimation(fig, animate, fargs=(xs, ys), interval=100)
plt.show()