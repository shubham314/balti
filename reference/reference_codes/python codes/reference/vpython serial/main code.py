from __future__ import division
from math import *
from vpython import *
import math
import serial
import time
arduinoSerialData = serial.Serial('com7', 9600, timeout=.1)
time.sleep(2)

ball1 = sphere(radius = 5,color = color.green)
ball1.pos=vector(10,10,0)
ball2 = sphere(radius = 5,color = color.blue)
ball2.pos=vector(0,0,20)

trail = curve(color = color.red,radius = 0.5)
trail2 = curve(color = color.black,radius = 1)
t= 1
dt = 1/(360/100) #number of degrees by t
omega = 0.0628/t
rotations = 1
height =0
difference = 5
finished = False
while not finished:
    rate(60)
    if (arduinoSerialData.inWaiting() > 0):
        m= arduinoSerialData.readline()
        datanums = (m.decode('utf8')).split(',')
        value = float(datanums[0])
        height = float(datanums[1])
        rank = float(datanums[2])

    t+=dt
    r = value
    cosvalue = math.cos(omega*t)
    sinvalue = math.sin(omega*t)
    xposition = r*cosvalue
    yposition  = r*sinvalue
    p = vector(xposition,yposition,height)
    ball1.pos=p
    trail.append(ball1.pos)#trail2.append(ball1.pos)
    #print rotations
    #print t
    #print value
    print(height)
    if t>100:
        rotations +=1
        t = 0.1 # error correction
    if rank <2 :
        trail.append(ball1.pos, color = color.red)
    if rank >1 :
        trail2.append(ball1.pos )

