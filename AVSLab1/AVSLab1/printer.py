import matplotlib.pyplot as plt
import sys
import json

header = sys.argv[1]

with open('data.json') as file:
    data = json.load(file)

# print(data)

plt.plot(data[0], data[1], marker='o', linestyle='')

plt.xlabel('Iterations')
plt.ylabel('Time')
plt.title(header)
plt.grid(True)

plt.show()