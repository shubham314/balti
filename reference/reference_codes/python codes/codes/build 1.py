from vpython import *
from random import random
import serial
import time
import numpy as np 
impo
arduinoSerialData = serial.Serial('com7', 9600, timeout=1)
time.sleep(2)
ball=sphere(color=color.green,radius=5)
ball.pos=vector(10,10,0)
ball2=sphere(color=color.red,radius=5)
ball2.pos=vector(0,0,20)
timestep = 0.01

t =0
x=0
height = 0
difference = 0.005
omega= 1
oldpos = vector(ball.pos) 

while (1==1):
  rate(1000)
  if(arduinoSerialData.inWaiting()>0):
 
    myData2= arduinoSerialData.readline()

    myData = myData2.decode('utf8')
    #print(len(myData2))
        #Remember to split the line of text into an array at the commas
    dataNums=myData.split(',')       #Remember to split the line of text into an array at the commas
    datanums = myData.split(',')
    stepper = float(datanums[0])
    servo = float(datanums[1])
    lidar = float(datanums[2])
    #rank = float(datanums[3])
    #print (myData)
    #print (lidar)
    #print (stepper)
    #print (servo)
    a = lidar
    c = float(stepper)
    f = float(360)
    g = float(200)
    e  = float(f/g)
    d = float(c*e)

    velocity = vector(0.5,0,0)
    b = [1,1,1]
   # ball.pos.x = a*sin(omega*x)
   # ball.pos.y = a*cos(omega*x)
    ball.pos.x = a*sin(stepper)
    ball.pos.y = a*cos(stepper)
    ball.pos.z = servo #height
    
    lastpos = ball.pos + velocity
 
    #curve(pos=[ball.pos, ball2.pos])
    curve(pos=[ball.pos,lastpos], thickness=1,color =color.cyan,make_trail=True,
                 retain =10)
  

    print (stepper,servo,lidar,sin(stepper))
#
#     height = height + difference
  #  if height > 70:
   #    difference = -0.5
    #if height < 1:
     #   difference = 0.5

    if x>425:
        x = 0
 