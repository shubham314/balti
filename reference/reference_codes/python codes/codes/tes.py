from vpython import *
from random import random
import serial
import time
import math
arduinoSerialData = serial.Serial('com7', 9600, timeout=1)
time.sleep(2)
ball=sphere(color=color.green,radius=5)
ball.pos=vector(10,10,0)
ball2=sphere(color=color.red,radius=5)
ball2.pos=vector(0,0,20)
timestep = 0.01

stepper_steps = 200

t=0

dt = 1/(360/stepper_steps) #number of degrees by t
t=t+dt
omega = 0.0314159/t

height =0


oldpos = vector(ball.pos) 

finished = False
while not finished:
        rate(60)
        if(arduinoSerialData.inWaiting()>0):

                myData2= arduinoSerialData.readline()
                myData = myData2.decode('utf8')
                #Remember to split the line of text into an array at the commas
                dataNums=myData.split(',')       #Remember to split the line of text into an array at the commas
                datanums = myData.split(',')
                stepper = float(datanums[0])
                servo = float(datanums[1])
                lidar = float(datanums[2])
                a = lidar
                c = float(stepper)
                f = float(360)
                g = float(200)
                e  = float(f/g)
                d = float(c*e)

                velocity = vector(0.5,0,0)
                b = [1,1,1]
                t+=dt
                
                ball.pos.x = a*sin(omega*t)  #omega*t
                ball.pos.y = a*cos(omega*t)
                #ball.pos.x = a*sin(stepper)
                # ball.pos.y = a*cos(stepper)
                ball.pos.z = servo #height

                lastpos = ball.pos + velocity

                #curve(pos=[ball.pos, ball2.pos])
                curve(pos=[ball.pos,lastpos], thickness=1,color =color.cyan,make_trail=True,
                                retain =10)


                print (stepper,servo,lidar,sin(stepper))
               
                if t>199:
                        t = 0
