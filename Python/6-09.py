import torch.nn as nn

class Architecture(nn.Module):
    def __init__(self, input_size, hidden_size, num_classes):
        super(Architecture, self).__init__()
        self.fc1 = nn.Linear(input_size, hidden_size)
        self.relu - nn.ReLU()
        self.fc2 = nn.Linear(hidden_size, hidden_size)
        self.relu = nn.ReLU()
        self.fc3 = nn.Linear(hidden_size, num_classes)

    def forward(self, x):
        out = self.fc1(x)
        out = self.relu(out)
        out = self.fc2(out)
        out = self.relu(out)
        out = self.fc3(out)
        return out

