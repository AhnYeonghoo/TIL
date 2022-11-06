import numpy as np

t = np.array([0., 1., 2., 3., 4., 5., 6.])
print(t)

print(f'Rank of t: {t.ndim}') # 몇 차원인지
print(f'Shape of t: {t.shape}') # 크기가 몇인지

print(f't[0] t[1] t[-1]= {t[0], t[1], t[-1]}')
print(f't[2:5] t[4:-1] = {t[2:5], t[4:-1]}')
print(f't[:2], t[3:] = {t[:2], t[3:]}')

# 2D with Numpy
t = np.array([[1., 2., 3.],
             [4., 5., 6.],
              [7., 8., 9.],
              [10., 11., 12.]])
print(t)
print(f'Rank of t: {t.ndim}')
print(f'shape of t: {t.shape}')

# PyTorch Tensor Allocation

import torch

# 1D with PyTorch
t = torch.FloatTensor([0., 1., 2., 3., 4., 5., 6.])
print(t)
print(t.dim())
print(t.shape)
print(t.size())

print(t[0], t[1], t[-1])  # 인덱스로 접근
print(t[2:5], t[4:-1])    # 슬라이싱
print(t[:2], t[3:])       # 슬라이싱

t = torch.FloatTensor([[1., 2., 3.],
                      [4., 5., 6.],
                      [7., 8., 9.],
                      [10., 11., 12.]])
print(t)

print(t.dim())
print(t.size())
print()
print()
print(t[:, 1])
print(t[:, 1].size())
print(t[:, :-1])

# BroadCasting
m1 = torch.FloatTensor([[3, 3]])
m2 = torch.FloatTensor([[2, 2]])
print(m1 + m2)

# Vector + scalar
m1 = torch.FloatTensor([[1, 2]])
m2 = torch.FloatTensor([3])
print(m1 + m2)

# 2 x 1 Vector + 1 x 2 Vector
m1 = torch.FloatTensor([[1, 2]])
m2 = torch.FloatTensor([[3], [4]])
print(m1 + m2)

# 행렬 곱셈과 곱셈
m1 = torch.FloatTensor([[1, 2], [3, 4]])
m2 = torch.FloatTensor([[1], [2]])
print(f'Shape of Matrix 1: {m1.shape}')
print(f'Shape of Maxrix 2: {m2.shape}')
print(m1.matmul(m2))

m1 = torch.FloatTensor([[1, 2], [3, 4]])
m2 = torch.FloatTensor([[1], [2]])
print('Shape of Matrix 1: ', m1.shape) # 2 x 2
print('Shape of Matrix 2: ', m2.shape) # 2 x 1
print(m1 * m2) # 2 x 2
print(m1.mul(m2))

# 평균
t = torch.FloatTensor([1, 2])
print(t.mean())

print(7979337+953696)
