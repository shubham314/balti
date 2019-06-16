import numpy as np
import matplotlib.pyplot as plt
import time
from drawnow import *
import serial  # import Serial Library
plt.ion()
x = []
y = []
a = 10
def dd():
    plt.plot(x, y, 'bo-', linewidth=2)
    plt.xlim(-20,20)
    plt.ylim(-20,20)
for i in np.arange(0, 2 * np.pi, 2 * np.pi / 50):
    x.append(a*np.cos(i))
    y.append(a*np.sin(i))
    drawnow(dd)
    time.sleep(0.00001)
