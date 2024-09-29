#   Ven Ranganathan
#   EECE 580, Prof Li
#   Assignment 2
#   Goal: Train CIFAR-10 dataset on custom ResNet model (ResNet-15, with 3 convolution layers removed from ResNet-18)
#   implemented learning rate scheduler, weight decay, cut off, label smoothing, and data augmentation
#   training loss/accuracy & testing loss/accuracy plotted

import torch
import torchvision
import torchvision.transforms as transforms
from torch.utils.data import DataLoader
import matplotlib.pyplot as plt
import numpy as np
import torch.nn as nn
import torch.nn.functional as F
import torch.optim as optim
import time

device = "cuda" if torch.cuda.is_available() else "cpu"

def imshow(img):
    img = img / 2 + 0.5  # unnormalize
    npimg = img.cpu().numpy()  # move to CPU for plotting
    plt.imshow(np.transpose(npimg, (1, 2, 0)))
    plt.show()

class Net(nn.Module):
    def __init__(self):
        super().__init__()
        # Custom ResNet--was ResNet-18, removed three convolution layers to bring down to ResNet-15
        # removed convolution layers: 9, 13, & 17
        self.conv1 = nn.Conv2d(3, 64, kernel_size=7, stride=1, padding='same')
        self.conv1_maxpool = nn.MaxPool2d(kernel_size=2, stride=2)
        self.conv1_bn = nn.BatchNorm2d(64)

        self.conv2 = nn.Conv2d(64, 64, kernel_size=3, stride=1, padding='same')
        self.conv2_bn = nn.BatchNorm2d(64)
        self.conv3 = nn.Conv2d(64, 64, kernel_size=3, stride=1, padding='same')
        self.conv3_bn = nn.BatchNorm2d(64)
        self.conv4 = nn.Conv2d(64, 64, kernel_size=3, stride=1, padding='same')
        self.conv4_bn = nn.BatchNorm2d(64)
        self.conv5 = nn.Conv2d(64, 64, kernel_size=3, stride=1, padding='same')
        self.conv5_bn = nn.BatchNorm2d(64)

        self.conv6 = nn.Conv2d(64, 128, kernel_size=3, stride=1, padding='same')
        self.conv6_maxpool = nn.MaxPool2d(kernel_size=2, stride=2)
        self.conv6_bn = nn.BatchNorm2d(128)
        self.conv7 = nn.Conv2d(128, 128, kernel_size=3, stride=1, padding='same')
        self.conv7_bn = nn.BatchNorm2d(128)
        self.conv7_shortcut_conv = nn.Conv2d(64, 128, kernel_size=1, stride=2)
        self.conv7_shortcut_bn = nn.BatchNorm2d(128)
        self.conv8 = nn.Conv2d(128, 128, kernel_size=3, stride=1, padding='same')
        self.conv8_bn = nn.BatchNorm2d(128)
        #self.conv9 = nn.Conv2d(128, 128, kernel_size=3, stride=1, padding='same')
        #self.conv9_bn = nn.BatchNorm2d(128)

        # add 10,11,12,13 convolution layers
        self.conv10 = nn.Conv2d(128, 256, kernel_size=3, stride=1, padding='same')
        self.conv10_maxpool = nn.MaxPool2d(kernel_size=2, stride=2)
        self.conv10_bn = nn.BatchNorm2d(256)
        self.conv11 = nn.Conv2d(256, 256, kernel_size=3, stride=1, padding='same')
        self.conv11_bn = nn.BatchNorm2d(256)
        self.conv11_shortcut_conv = nn.Conv2d(128, 256, kernel_size=1, stride=2)
        self.conv11_shortcut_bn = nn.BatchNorm2d(256)
        self.conv12 = nn.Conv2d(256, 256, kernel_size=3, stride=1, padding='same')
        self.conv12_bn = nn.BatchNorm2d(256)
        #self.conv13 = nn.Conv2d(256, 256, kernel_size=3, stride=1, padding='same')
        #self.conv13_bn = nn.BatchNorm2d(256)

        # add 14,15,16,17 convolution layers
        self.conv14 = nn.Conv2d(256, 512, kernel_size=3, stride=1, padding='same')
        self.conv14_maxpool = nn.MaxPool2d(kernel_size=2, stride=2)
        self.conv14_bn = nn.BatchNorm2d(512)
        self.conv15 = nn.Conv2d(512, 512, kernel_size=3, stride=1, padding='same')
        self.conv15_bn = nn.BatchNorm2d(512)
        self.conv15_shortcut_conv = nn.Conv2d(256, 512, kernel_size=1, stride=2)
        self.conv15_shortcut_bn = nn.BatchNorm2d(512)
        self.conv16 = nn.Conv2d(512, 512, kernel_size=3, stride=1, padding='same')
        self.conv16_bn = nn.BatchNorm2d(512)
        #self.conv17 = nn.Conv2d(512, 512, kernel_size=3, stride=1, padding='same')
        #self.conv17_bn = nn.BatchNorm2d(512)

        self.fc = nn.Linear(512, 10, bias=True)  # Fully connected layer; added bias=True 09/24/24 @ 12:15 AM

    # train feed forward network
    def forward(self, input):
        x = self.conv1(input)
        x = self.conv1_maxpool(x)
        x = F.relu(self.conv1_bn(nn.MaxPool2d(kernel_size=3, stride=2, padding=1)(x)))

        x1 = F.relu(self.conv2_bn(self.conv2(x)))
        x1 = F.relu(self.conv3_bn(self.conv3(x1)))
        x = x1 + x
        x1 = F.relu(self.conv4_bn(self.conv4(x)))
        x1 = F.relu(self.conv5_bn(self.conv5(x1)))
        x = x1 + x

        # removed convolution layer 9
        x2 = F.relu(self.conv6_bn(self.conv6_maxpool(self.conv6(x))))
        x2 = F.relu(self.conv7_bn(self.conv7(x2)))
        x = F.relu(x2 + self.conv7_shortcut_bn(self.conv7_shortcut_conv(x)))
        x2 = F.relu(self.conv8_bn(self.conv8(x)))
        #x2 = F.relu(self.conv9_bn(self.conv9(x2)))
        x = x2 + x

        # add forward code for convolution layers 10,11,12,13 (removed 13)
        x3 = F.relu(self.conv10_bn(self.conv10_maxpool(self.conv10(x))))
        x3 = F.relu(self.conv11_bn(self.conv11(x3)))
        x = F.relu(x3 + self.conv11_shortcut_bn(self.conv11_shortcut_conv(x)))
        x3 = F.relu(self.conv12_bn(self.conv12(x)))
        #x3 = F.relu(self.conv13_bn(self.conv13(x3)))
        x = x3 + x

        # add forward code for convolution layers 14,15,16,17 (removed 17)
        x4 = F.relu(self.conv14_bn(self.conv14_maxpool(self.conv14(x))))
        x4 = F.relu(self.conv15_bn(self.conv15(x4)))
        x = F.relu(x4 + self.conv15_shortcut_bn(self.conv15_shortcut_conv(x)))
        x4 = F.relu(self.conv16_bn(self.conv16(x)))
        #x4 = F.relu(self.conv17_bn(self.conv17(x4)))
        x = x4 + x

        x = torch.flatten(x, 1)  # flatten for fully connected layer
        x = self.fc(x)  # Use the defined fc layer

        return x

# Function to calculate accuracy
def calculate_accuracy(outputs, labels):
    _, predicted = torch.max(outputs, 1)
    return (predicted == labels).sum().item() / labels.size(0)

if __name__ == '__main__': # need for macOS
    transform = transforms.Compose([
        transforms.ToTensor(),
        transforms.Normalize((0.5, 0.5, 0.5), (0.5, 0.5, 0.5))
    ])

    batch_size = 1024 # inverted U-shape relationship between batch size and accuracy; larger batch size = more memory used

    data_augmentation_train = transforms.Compose([
        transforms.RandomCrop(32, padding=4),
        transforms.RandomHorizontalFlip(),
        transforms.ToTensor(), # converts numbers to 0,1
        transforms.Normalize((0.4914, 0.4822, 0.4465), (0.2023, 0.1994, 0.2010)),
        transforms.RandomErasing()
    ])

    data_augmentation_test = transforms.Compose([
        transforms.ToTensor(),
        transforms.Normalize((0.4914, 0.4822, 0.4465), (0.2023, 0.1994, 0.2010))
    ])

    trainset = torchvision.datasets.CIFAR10(root='./data', train=True, download=True, transform=data_augmentation_train)
    trainloader = torch.utils.data.DataLoader(trainset, batch_size=batch_size, shuffle=True, num_workers=8, pin_memory=torch.cuda.is_available())

    testset = torchvision.datasets.CIFAR10(root='./data', train=False, download=True, transform=data_augmentation_test)
    testloader = torch.utils.data.DataLoader(testset, batch_size=batch_size, shuffle=False, num_workers=8, pin_memory=torch.cuda.is_available())

    classes = ('plane', 'car', 'bird', 'cat', 'deer', 'dog', 'frog', 'horse', 'ship', 'truck')

    net = Net()
    net.to(device)  # Move model to device (GPU/CPU)

    criterion = nn.CrossEntropyLoss(label_smoothing=0.05)
    optimizer = optim.AdamW(net.parameters(), lr=0.0001, weight_decay=1e-4) #Adam optimizer works better than Stochastic Gradient Descent (SGD) in this homework
    scheduler = torch.optim.lr_scheduler.CosineAnnealingLR(optimizer, T_max=200) # learning rate scheduler

    num_epochs = 5

    # start
    print(f"Starting...")

    # initialize starting time
    init_time = time.time()

    # Lists to store metrics
    train_losses, train_accuracies = [], []
    test_losses, test_accuracies = [], []

    # Step 5: Train the network
    for epoch in range(num_epochs):
        net.train()
        running_loss = 0.0
        correct, total = 0, 0

        for i, data in enumerate(trainloader, 0):
            inputs, labels = data[0].to(device), data[1].to(device)  # Move inputs and labels to device
            optimizer.zero_grad()
            outputs = net(inputs)
            loss = criterion(outputs, labels)
            loss.backward()
            optimizer.step()

            running_loss += loss.item()
            correct += calculate_accuracy(outputs, labels) * labels.size(0)
            total += labels.size(0)

        train_losses.append(running_loss / len(trainloader))
        train_accuracies.append(correct / total)

        # Step 7: Evaluate on test set
        net.eval()
        test_loss, correct, total = 0.0, 0, 0

        with torch.no_grad():
            for data in testloader:
                images, labels = data[0].to(device), data[1].to(device)
                outputs = net(images)
                loss = criterion(outputs, labels)
                test_loss += loss.item()
                correct += calculate_accuracy(outputs, labels) * labels.size(0)
                total += labels.size(0)

        test_losses.append(test_loss / len(testloader))
        test_accuracies.append(correct / total)

        print(f'Epoch [{epoch + 1}/{num_epochs}], Train Loss: {train_losses[-1]:.4f}, Train Acc: {train_accuracies[-1]:.4f}, Test Loss: {test_losses[-1]:.4f}, Test Acc: {test_accuracies[-1]:.4f}, Elapsed Time: {time.time() - init_time:.4f} seconds')

    # Step 8: Plotting the results
    epochs = range(1, num_epochs + 1)

    plt.figure(figsize=(10, 6))
    plt.plot(epochs, train_losses, label='Training Loss', color='r', linestyle='--')
    plt.plot(epochs, test_losses, label='Testing Loss', color='b', linestyle='-')
    plt.plot(epochs, train_accuracies, label='Training Accuracy', color='g', linestyle='--')
    plt.plot(epochs, test_accuracies, label='Testing Accuracy', color='m', linestyle='-')
    plt.xlabel('Epochs')
    plt.ylabel('Loss/Accuracy')
    plt.title('Training & Testing Loss/Accuracy')
    plt.legend()
    plt.show()

    # Save the final model
    PATH = './cifar_net.pth'
    torch.save(net.state_dict(), PATH)

    # Print training time
    train_time = (time.time() - init_time)/60
    print(f"Training Time: {train_time:.4f} minutes")

    # end
    print(f"Complete")