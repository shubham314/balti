from visual import *
from random import random
import serial
import time
arduinoSerialData = serial.Serial('com12', 115200, timeout=.1)
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
 
    myData= arduinoSerialData.readline()       #Remember to split the line of text into an array at the commas
    dataNums=myData.split(',')       #Remember to split the line of text into an array at the commas
    datanums = myData.split(',')
    lidar = float(datanums[0])
    stepper = float(datanums[1])
    servo = float(datanums[2])
    rank = float(datanums[3])
    print myData
    print lidar
    print stepper
    print servo
    print rank
    a = lidar
    c = double(stepper)
    f = float(360)
    g = float(425)
    e  = float(f/g)
    d = float(c*e)
    velocity = vector(0.5,0,0)
    b = [1,1,1]
   # ball.pos.x = a*sin(omega*x)
   # ball.pos.y = a*cos(omega*x)
    ball.pos.x = a*sin(d)
    ball.pos.y = a*cos(d)
    #ball.pos.z = height
    
    lastpos = ball.pos + velocity
 
    #curve(pos=[ball.pos, ball2.pos])
    curve(pos=[ball.pos,lastpos], thickness=1,color =color.cyan)
  
    x= x+1

    print d
   # print d
#    height = height + difference
 #   if height > 70:
  #    difference = -0.5
   # if height < 1:
    #    difference = 0.5

    if x>425:
        x = 0

 
