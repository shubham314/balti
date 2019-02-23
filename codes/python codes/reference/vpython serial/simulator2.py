from __future__ import division
from math import *
from visual import *
import serial
import time
arduinoSerialData = serial.Serial('com6', 115200, timeout=.1)
time.sleep(2)

ball1 = sphere(pos= (35,33,0),radius = 5,color = color.green)
ball2 = sphere(pos = (0,0,0),radius = 5,color = color.blue)
trail = curve(color = color.red,radius = 0.5)

t= 1
dt = 1/(360/100) #number of degrees by t
omega = 0.0628/t
rotations = 1
height =0
difference = 5
finished = false
while not finished:
    rate(60)
    if (arduinoSerialData.inWaiting() > 0):
        myData = arduinoSerialData.readline()
        value = float(myData)
    t+=dt
    r =     value
    cosvalue = math.cos(omega*t)
    sinvalue = math.sin(omega*t)
    xposition = r*cosvalue
    yposition  = r*sinvalue
    p = vector(xposition,yposition,height)
    ball1.pos=p
    trail.append(ball1.pos)
    #print rotations
    #print t
    #print value
    print height
    if t>100:
        rotations +=1
        t = 0.1 # error correction
        height = height + difference
    if height > 15:
        difference = -5
    if height <1:
        difference = 5




