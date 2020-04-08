import serial 
from visual import *
import time
 
arduinoSerialData = serial.Serial('com6', 9600)
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
     rate(1200)
     if (arduinoSerialData.inWaiting()>0):
         myData = arduinoSerialData.readline() 
         print myData
         dataNums=myData.split(',')
         lidar = ''.join(i for i in dataNums[0] if  i.isdigit())
         d= ''.join(i for i in dataNums[1] if  i.isdigit())
         #servo= ''.join(i for i in dataNums[2] if  i.isdigit())
         #rank = ''.join(i for i in dataNums[3] if  i.isdigit())

         print lidar
         velocity = vector(0.5,0,0)
         b = [1,1,1]
         a = lidar

        # ball.pos.x = a*sin(omega*x)
        # ball.pos.y = a*cos(omega*x)
         ball.pos.x = a*sin(d)
         ball.pos.y = a*cos(d)
         #ball.pos.z = height
         
         lastpos = ball.pos + velocity
      
         #curve(pos=[ball.pos, ball2.pos])
         curve(pos=[ball.pos,lastpos], thickness=1,color =color.cyan)
       
         x= x+0.3
       #  print x
      #   print t
     #    print height
        # print a
         print d
        # print d
     #    height = height + difference
      #   if height > 70:
       #    difference = -0.5
        # if height < 1:
         #    difference = 0.5
        # if x>1.26445:
         if x>425:
             x = 0



          

