import numpy as np
import matplotlib.pyplot as plt
import time
from drawnow import *
import serial  # import Serial Library
plt.ion()
x = []
y = []
a = []
arduinoData = serial.Serial('com6', 9600)


def dd():
    plt.plot(x, y, 'bo-', linewidth=2)
    plt.xlim(-20, 20)
    plt.ylim(-20, 20)


# def aj():
#     for i in np.arange(0, 2 * np.pi, 2 * np.pi / 50):
#         x.append(a * np.cos(i))
#         y.append(a * np.sin(i))
#         drawnow(dd)
#         time.sleep(0.00001)


while True:  # While loop that loops forever
    while (arduinoData.inWaiting() == 0):  # Wait here until there is data
        pass  # do nothing
    # Convert first element to floating number and put in temp
    for i in np.arange(0, 2 * np.pi, 2 * np.pi / 20):
        arduinoString = arduinoData.readline()  # read the line of text from the serial port
        dataArray = arduinoString.split(',')  # Split it into an array called dataArray
        a = float(dataArray[0])
        x.append(a * np.cos(i))
        y.append(a * np.sin(i))
        drawnow(dd)
        time.sleep(0.00001)
        print a







