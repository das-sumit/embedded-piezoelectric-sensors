# Date Created: 6/30/2022
# Author: Sumit Das (sumit.das.f@gmail.com)
# Program Description: reads data from a csv file and plots it.

from itertools import count
import pandas as pd
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation

plt.style.use('fivethirtyeight')

x_vals = []
y_vals = []

index = count()


def animate(i):
    data = pd.read_csv('data.csv')
    x = data['x_value']
    y1 = data['total_1']
    y2 = data['total_2']

    plt.cla()

    plt.plot(x, y1, label='Channel 1')
    plt.plot(x, y2, label='Channel 2')

    plt.legend(loc='upper left')
    plt.tight_layout()


print('before')
ani = FuncAnimation(plt.gcf(), animate, interval=1000)
print('after')

plt.tight_layout()
plt.show()                  # After this line, any following code won't run until the plot window is closed.
