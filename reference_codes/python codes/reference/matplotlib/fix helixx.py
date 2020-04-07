from mpl_toolkits.mplot3d import Axes3D
from matplotlib import rcParams
import matplotlib.pyplot as plt
import numpy as np

theta = np.linspace(-9 * np.pi, 9 * np.pi, 300)

radius = 10


x = []
y = []
x = radius * np.cos(theta)

def helix():

    for i in theta:
        if (i < 10 * np.pi):
            x.append(radius * np.cos(i))
        else:
            x.append((radius + 2.0) * np.cos(i))


    for j in theta:
        if (j < 10 * np.pi):
            y.append(radius * np.sin(j))
        else:
            y.append((radius + 2.0) * np.sin(j))

helix()
fig = plt.figure()
ax = fig.gca(projection='3d')
ax.plot(x, y, theta,
        label='Parametric Curve',  # label of the curve
        color='DarkMagenta',  # colour of the curve
        linewidth=1,  # thickness of the line
        linestyle='-'  # available styles - -- -. :
        )

ax.set_xlim(-5, 5)
ax.set_ylim(-10, 10)
ax.set_zlim(-9 * np.pi, 9 * np.pi)

plt.show()


