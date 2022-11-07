import torch
import torch.nn.functional as F

torch.manual_seed(1)

z = torch.FloatTensor([1, 2, 3])

hypothesis = F.softmax(z, dim=0)
print(hypothesis)
print(hypothesis.sum())

z = torch.rand(3, 5, requires_grad=True)
hypothesis = F.softmax(z, dim=1)
print(hypothesis)
y = torch.randint(5, (3,)).long()
print(y)

y_one_hot = torch.zeros_like(hypothesis)
y_one_hot.scatter_(1, y.unsqueeze(1), 1)

print(y.unsqueeze_(1))
print(y_one_hot)

cost = (y_one_hot * -torch.log(hypothesis)).sum(dim=1).mean()
print(cost)
