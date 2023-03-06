import numpy as np
import matplotlib.pyplot as plt



x = np.linspace(-5, 5, 100)
y = np.linspace(-5, 5, 100)
X, Y = np.meshgrid(x, y)

Z = np.arctan2(X, Y)

fig = plt.figure()

ax = plt.axes(projection = '3d')
ax.plot_surface(X, Y, Z, cmap = 'viridis')
ax.set_xlabel('X')
ax.set_ylabel('Y')
ax.set_zlabel('Z')
ax.set_title('arctan2(x, y)')
plt.show()


