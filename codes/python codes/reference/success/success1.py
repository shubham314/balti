from __future__ import division
from math import *
from visual import *
import serial
import time
arduinoSerialData = serial.Serial('com6', 9600, timeout=.1) #call serial portt
time.sleep(2)# wait time
ball1 = sphere(pos=(35, 33, 0), radius=5, color=color.green,make_trail=True,
                 retain =60 )  #point and trail

ball2 = sphere(pos=(0, 0, 0), radius=5, color=color.blue)

t = 1
dt = 1 / (20 / 100)  # number of degrees by t
omega = 0.0628 / t  #ratio number
rotations = 1
height = 0
difference =0
x = 0 #rank
finished = false
while not finished:
    rate(60)
    if (arduinoSerialData.inWaiting() > 0):
        m = arduinoSerialData.readline()
        datanums = m.split(',')
        value = float(datanums[0])
        h = float(datanums[1])

    height = h
    t += dt
    r = value
    cosvalue = math.cos(omega * t)
    sinvalue = math.sin(omega * t)
    xposition = r * cosvalue
    yposition = r * sinvalue
    p = vector(xposition, yposition,height)
    ball1.pos = p
    x +=1

    time.sleep(0.01)
    print value ,  h

