from mpl_toolkits.mplot3d import Axes3D
from matplotlib import rcParams
import matplotlib.pyplot as plt
import numpy as np
from drawnow import *
import matplotlib.animation as animation
from matplotlib.animation import FuncAnimation
import serial
arduinoData = serial.Serial('com6', 9600)


# radius = float(input("Radius  "))
# x = radius * np.cos(theta)

x = []
y = []
def dd():
    fig = plt.figure()
    ax = fig.gca(projection='3d')
    ax.plot(x, y, theta,
            label='Parametric Curve',  # label of the curve
            color='DarkMagenta',  # colour of the curve
            linewidth=1,  # thickness of the line
            linestyle='-'  # available styles - -- -. :
            )
    rcParams['legend.fontsize'] = 11  # legend font size
    ax.legend()  # adds the legend

    ax.set_xlabel('X axis')
    ax.set_xlim(-5, 5)
    ax.set_ylabel('Y axis')
    ax.set_ylim(-10, 10)
    ax.set_zlabel('Z axis')
    ax.set_zlim(-9 * np.pi, 9 * np.pi)

    ax.set_title('3D line plot,\n parametric curve', va='bottom')


while True:  # While loop that loops forever
    while (arduinoData.inWaiting() == 0):  # Wait here until there is data
        pass  # do nothing
    # Convert first element to floating number and put in temp
    #theta  =  np.linspace(-9 * np.pi, 9 * np.pi, 300)
    arduinoString = arduinoData.readline()  # read the line of text from the serial port
    dataArray = arduinoString.split(',')  # Split it into an array called dataArray
    a = float(dataArray[0])

    for i in theta:
        if (i < 4.5 * np.pi):
            x.append(a * np.cos(i))
        else:
            x.append((a + 2.0) * np.cos(i))


    for j in theta:
        if (j < 4.5 * np.pi):
            y.append(a * np.sin(j))
        else:
            y.append((a + 2.0) * np.sin(j))
    drawnow(dd)
