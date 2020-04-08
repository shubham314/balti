from visual import *
from random import random
import serial
import time
arduinoSerialData = serial.Serial('com6', 115200,  parity=serial.PARITY_NONE,stopbits=serial.STOPBITS_ONE, bytesize=serial.EIGHTBITS,timeout=.1)
time.sleep(2)
ball=sphere(color=color.green,radius=5)
ball.pos=vector(10,10,0)
ball2=sphere(color=color.red,radius=5)
ball2.pos=vector(0,0,20)
timestep = 0.01
t =0
x=0
height = 0
difference = 50
omega= 5
oldpos = vector(ball.pos) 
a = 100
while (1==1):
    rate(100)
    if(arduinoSerialData.inWaiting()>0):
           
              m= arduinoSerialData.readline()
              n= float(m) 
 

              velocity = vector(0.5,0,0)
              b = [1,1,1]
              ball.pos.x = a*sin(n)
              ball.pos.y = a*cos(n)
              ball.pos.z = height
             # a = ball.pos
              lastpos = ball.pos + velocity
             # ball.pos += velocity 
              #curve(pos=[ball.pos, ball2.pos])
              #ring(pos=ball.pos, axis=(0,1,0), radius=0.5, thickness=1,color =color.red)
              curve(pos=[ball.pos,lastpos], thickness=1,color =color.cyan)
            
              x= x+1
             # print x
              #print t
              #print height
              print n
              

      
    if x>425:
        x = 0
        height = height + difference
    if height > 300:
          difference = -5
    if height < 52:
           difference = 5
