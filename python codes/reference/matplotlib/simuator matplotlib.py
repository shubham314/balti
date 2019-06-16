import matplotlib.pyplot as plt
import matplotlib.animation as animation
import time
import serial
from matplotlib import style
arduinoSerialData = serial.Serial('com6', 115200, timeout=.1)
time.sleep(2)

style.use('fivethirtyeight')

fig = plt.figure()
ax1 = fig.add_subplot(1,1,1)
while 1==1:

     if (arduinoSerialData.inWaiting() > 0):
          m = arduinoSerialData.readline()


     def animate(i):
        graph_data = m
        lines = graph_data.split('\n')
        xs = []
        ys = []
        for line in lines:
            if len(line) > 1:
                x, y = line.split(',')
                xs.append(x)
                ys.append(y)
                ax1.clear()
                ax1.plot(xs, ys)

                ani = animation.FuncAnimation(fig, animate, interval=1000)
                plt.show()