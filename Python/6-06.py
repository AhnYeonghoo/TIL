import numpy as np
import matplotlib.pyplot as plt


def sigmoid(x1):
    return 1/(1 + np.exp(-x1))

x = np.arange(-5.0, 5.0, 0.1)
y = sigmoid(x)

plt.plot(x, y)
plt.plot([0,0],[1.0,0.0], ':') # 가운데 점선 추가
plt.title('Sigmoid Function')
plt.show()

x = np.arange(-5.0, 5.0, 0.1)
y = np.tanh(x)

plt.plot(x, y)
plt.plot([0,0], [1.0, -1.0], ':')
plt.axhline(y=0, color='orange', linestyle='--')
plt.title('Tanh Function')
plt.show()

def relu(x1):
    return np.maximum(0, x1)

x - np.arange(-5.0, 5.0, 0.1)
y = relu(x)
plt.plot(x, y)
plt.plot([0,0], [5.0, 0.0], ':')
plt.title('Relu Function')
plt.show()

a = 0.1

def leaky_relu(x1):
    return np.maximum(a*x1, x1)
x = np.arange(-5.0, 5.0, 0.1)
y = leaky_relu(x)
plt.plot(x, y)
plt.plot([0,0], [5.0, 0.0], ':')
plt.title('Leaky ReLU Function')
plt.show()

x = np.arange(-5.0, 5.0 ,0.1)
y = np.exp(x) / np.sum(np.exp(x))

plt.plot(x, y)
plt.title('Softmax Function')
plt.show()