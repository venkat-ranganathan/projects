# https://pytorch.org/tutorials/beginner/basics/quickstart_tutorial.html
# essential python code to train CNN model over the MNIST dataset.

#   Ven Ranganathan
#   EECE 580, Prof Li
#   Assignment 1

import matplotlib.pyplot as plt
import torch
from torch import nn
from torch.utils.data import DataLoader
from torchvision import datasets
from torchvision.transforms import ToTensor


device = "cuda" if torch.cuda.is_available() else "cpu"

# Step 1: Download the dataset
training_data = datasets.MNIST( # changed from FashionMNIST
    root="data",
    train=True,
    download=True,
    transform=ToTensor(),
)
test_data = datasets.MNIST( # changed from FashionMNIST
    root="data",
    train=False,
    download=True,
    transform=ToTensor(),
)

# Step 2: Create data loaders so you do not have to code how data items are used
batch_size = 64
train_dataloader = DataLoader(training_data, batch_size=batch_size, shuffle=True)
test_dataloader = DataLoader(test_data, batch_size=batch_size)


# Step 3: Define the model
class NeuralNetwork(nn.Module):
    def __init__(self):
        super().__init__()
        self.flatten = nn.Flatten()
        self.linear_relu_stack = nn.Sequential(
            nn.Linear(28*28, 512),
            nn.ReLU(),
            nn.Linear(512, 512),
            nn.ReLU(),
            nn.Linear(512, 10)
        )

    def forward(self, x):
        x = self.flatten(x)
        logits = self.linear_relu_stack(x)
        return logits

model = NeuralNetwork().to(device)
print(model)

# Step 4: setup training parameters and procedure
loss_fn = nn.CrossEntropyLoss()
optimizer = torch.optim.SGD(model.parameters(), lr=0.5) # changed form lr=1e-3, lr=0.5 leads to 98.5% ACC with 10 epochs

# declare lists
train_loss1 = []
train_loss1_average = []
train_correct1 = []
train_correct1_average = []
test_loss = []
test_correct = []

def train(dataloader, model, loss_fn, optimizer, train_loss1, train_correct1):
    size = len(dataloader.dataset)
    num_batches = len(dataloader)
    train_loss, train_correct = 0, 0
    model.train()
    for batch, (X, y) in enumerate(dataloader):
        X, y = X.to(device), y.to(device)

        # Compute prediction error
        pred = model(X)
        train_loss = loss_fn(pred, y)
        train_correct = (pred.argmax(1) == y).type(torch.float).sum().item() # calculate training accuracy

        # Backpropagation
        train_loss.backward()
        optimizer.step()
        optimizer.zero_grad()

        if batch % 100 == 0:
            train_loss, current = train_loss.item(), (batch + 1) * len(X)
            train_loss1.append(train_loss) # add training loss data to list
            print(f"loss: {train_loss:>7f}  [{current:>5d}/{size:>5d}]")

        train_correct1.append(train_correct) # add training accuracy data to list

def test(dataloader, model, loss_fn, test_loss, test_correct):
    size = len(dataloader.dataset)
    num_batches = len(dataloader)
    model.eval()
    loss, correct = 0, 0

    with torch.no_grad():
        for X, y in dataloader:
            X, y = X.to(device), y.to(device)
            pred = model(X)
            loss += loss_fn(pred, y).item()
            correct += (pred.argmax(1) == y).type(torch.float).sum().item()
    loss /= num_batches
    correct /= size
    print(f"Test Error: \n Accuracy: {(100*correct):>0.1f}%, Avg loss: {loss:>8f} \n")

    test_loss.append(loss)
    test_correct.append(correct)


# Step 5: Conduct training
epochs = 10 # hw completes in 5 epochs, Li said 10 epochs is fine
for t in range(epochs):
    print(f"Epoch {t+1}\n-------------------------------")
    train(train_dataloader, model, loss_fn, optimizer, train_loss1, train_correct1)
    test(test_dataloader, model, loss_fn, test_loss, test_correct)
    train_loss1_average.append(sum(train_loss1)/len(train_loss1)) # calculate average training loss
    train_correct1_average.append((sum(train_correct1) / batch_size / len(train_correct1))) # calculate average training accuracy
    train_correct1.clear() # clear training list for next run

print("Done!")


# Step 6: Plot data
fig, ax = plt.subplots()             # Create a figure containing a single Axes.

ax.plot(train_correct1_average, label='Training Accuracy')
ax.plot(train_loss1_average, label='Training Loss')
ax.plot(test_correct, linestyle=':',label='Test Accuracy')
ax.plot(test_loss, linestyle=':',label='Test Loss')

plt.xlabel("Epochs")
plt.ylabel("Accuracy or Loss")
plt.title("MNIST DNN Model Accuracy & Loss vs Epochs")
ax.legend()

plt.show()


# Brute force testing results

# test 1
# batch size 64
# epoch 10
# learning rate 1e-3
# accuracy 84.5%

# test 2
# batch size 64
# epoch 10
# learning rate 1e-4
# accuracy 36.2%

# test 3
# batch size 64
# epoch 10
# learning rate 1e-2
# accuracy 94.1%

# test 4
# batch size 64
# epoch 10
# learning rate 1e-1
# accuracy 98.0%

# test 5
# batch size 64
# epoch 10
# learning rate 0.9
# accuracy 97.4%

# test 6
# batch size 64
# epoch 10
# learning rate 0.8
# accuracy 98.0%

# test 7
# batch size 64
# epoch 10
# learning rate 0.7
# accuracy 98.3%

# test 8
# batch size 64
# epoch 10
# learning rate 0.5
# accuracy 98.5%

# test 9
# batch size 64
# epoch 10
# learning rate 0.1 same as 1e-1
# accuracy 98.1%

# test 10
# batch size 64
# epoch 10
# learning rate 10
# accuracy 9.8%

# test 11
# batch size 64
# epoch 10
# learning rate 1
# accuracy 97.1%

# test 12
# batch size 64
# epoch 10
# learning rate 0.2
# accuracy 98.4%

# test 13
# batch size 64
# epoch 10
# learning rate 0.4
# accuracy 98.0%

# test 14
# batch size 64
# epoch 10
# learning rate 0.5 # best so far
# accuracy 98.5%



