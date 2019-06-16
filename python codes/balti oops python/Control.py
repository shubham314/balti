from vpython import *
import serial
import time
from CsvBuilder import *

class Control(object):

    arduinoSerialData = serial.Serial('com5', 9600, timeout=1)
    time.sleep(2)

    ball = sphere(color=color.green, radius=5, make_trail=True, retain=60)
    ball.pos = vector(10, 10, 0)

    ball2 = sphere(color=color.cyan, radius=5)
    ball2.pos = vector(0, 0, 20)

    timestep = 0.01
    t = 0
    x = 0
    height = 0
    difference = 0.005
    omega = 1
    oldpos = vector(ball.pos)
    step2 = 0
    dir2 = 0
    pos2 = 0

    def __init__(self, t, x, height, difference, omega, oldpos, arduinoSerialData, ball, ball2,dist, horizontal, vertical):
        """

        :type ball2:
        """
        self.t = t
        self.x = x
        self.height = height
        self.difference = difference
        self.omega = omega
        self.oldpos = oldpos
        self.arduinoSerialData = arduinoSerialData
        self.ball = ball
        self.ball2 = ball2
        self.horizontal = horizontal
        self.vertical = vertical
        self.dist = dist

    def perprocess(self):
        rate(1000)
        if self.arduinoSerialData.inWaiting() > 0:
            myData2 = self.arduinoSerialData.readline()
            myData = myData2.decode('utf8')
            print(len(myData2))
            datanums = myData.split(',')
            lidar = float(datanums[0])
            stepper = float(datanums[1])
            # servo = float(datanums[2])
            # rank = float(datanums[3])
            print(myData, lidar, stepper)
            # print (servo)
            # print (rank)

    def run(self):
        while 1 == 1:
            a = float(self.lidar)

            "try to change variable 425 for calibration of stepper"
            d = float((360/425)*self.stepper)

            velocity = vector(0.5, 0, 0)
            #b = [1, 1, 1] "find its use"

            self.horizontal = self.ball.pos.x
            self.vertical = self.ball.pos.y
            self.dist = self.ball.pos.z


            self.horizontal = a * sin(d)
            self.vertical = a * cos(d)
            self.dist = self.height



            '''these lines are for the pillars Control.py is for horizontal and second line is for vertical'''
            # curve(pos=[ball.pos, ball2.pos],retain =6)
            # curve(pos=[ball.pos,lastpos], thickness=1,color =color.cyan)
            # lastpos = self.ball.pos + velocity   "find its mean in the code"

            x = x + 1
            print(d)
            height = height + difference
            if height > 70:
                difference = -0.5

            if height < 1:
                difference = 0.5

            if x > 425:
                x = 0
            "make if else case to start stop csv data recording"
            storedata = CsvBuilder(self.horizontal, self.vertical, self.dist).csvCall()

    def send_data(self):
        while True:
         """in tihs section the  lower deck string si sent in the format as
         step2,dir2,pos2 """

            outputstring = str(self.step2)+','+str(self.dir2)+','+str(self.pos2)
            self.arduinoSerialData.write(outputstring)  # Convert the decimal number to ASCII then send it to the Arduino

