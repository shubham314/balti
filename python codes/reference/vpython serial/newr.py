from visual import *
from random import random
import time

ball = sphere(color=color.green, radius=5)
ball.pos = vector(10, 10, 0)
ball2 = sphere(color=color.red, radius=5)
ball2.pos = vector(0, 0, 20)
timestep = 0.01

t = 0
x = 0
height = 0
difference = 0.005
omega = 10
oldpos = vector(ball.pos)
a = 100
while (1 == 1):
        rate(50)
        velocity = vector(1, 0, 0)
        b = [1, 1, 1]
        ball.pos.x = a * sin(omega * x*omega)
        ball.pos.y = a * cos(omega * x*omega)

       # lastpos = ball.pos + velocity
       # curve(pos=[ball.pos, lastpos], thickness=1, color=color.cyan)

        x = x + 1
        print x

        if x > 360:
            x = 0
        time.sleep(0.05)

