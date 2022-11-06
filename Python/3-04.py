# 파이토치에서 이미 구현되어져 제공되고 있는 함수들을 불려 더 쉽게 선형 회귀 모델 구현

# nn.Linear()는 선형 회귀 모델
# nn.functional.mse_loss()는 평균 제곱 오차 (MES)

import torch
import torch.nn as nn
import torch.nn.functional as F

torch.manual_seed(1)
x_train = torch.FloatTensor([[1], [2], [3]])
y_train = torch.FloatTensor([[2], [4], [6]])

model = nn.Linear(1, 1) # input_dim = 1, output_dim = 1
print(list(model.parameters()))

optimizer = torch.optim.SGD(model.parameters(), lr=0.01)
nb_epochs = 2000

for epoch in range(nb_epochs+1):

    prediction = model(x_train) # H(x) 계산

    cost = F.mse_loss(prediction, y_train) # MES 계산
    optimizer.zero_grad()
    cost.backward()
    optimizer.step()

    if epoch % 100 == 0:
        print('Epoch {:4d}/{} Cost: {:.6f}'.format(epoch, nb_epochs, cost.item()))

new_var = torch.FloatTensor([[4.0]])

pred_y = model(new_var)

print("훈련 후 입력이 4일 때의 예측값: ", pred_y)

x_train = torch.FloatTensor([[73, 80, 75],
                             [93, 88, 93],
                             [89, 91, 90],
                             [96, 98, 100],
                             [73, 66, 70]])
y_train = torch.FloatTensor([[152], [185], [180], [196], [142]])
model = nn.Linear(3, 1)
print(list(model.parameters()))
optimizer = torch.optim.SGD(model.parameters(), lr=1e-5)
nb_epochs = 2000

for epoch in range(nb_epochs+1):
    prediction = model(x_train)
    cost = F.mse_loss(prediction, y_train)
    optimizer.zero_grad()
    cost.backward()
    optimizer.step()
    if epoch % 100 == 0:
        print('Epoch {:4d}/{} Cost: {:.6f}'.format(epoch, nb_epochs, cost.item()))

print(list(model.parameters()))