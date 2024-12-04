import torch
from torchvision import datasets, transforms
import torch.nn as nn
import torch.nn.functional as F
import torch.optim as optim

#print(torch.__version__)

# 使用 PyTorch 框架实现的简单深度神经网络，用于对 MNIST 数据集进行手写数字识别
# 导入必要的库：包括 PyTorch 和 torchvision，用于处理张量和图像数据。
# 检查 CUDA 可用性：判断是否有 GPU 可用，并设置相应的设备（cuda 或 cpu）。
# 数据预处理：定义数据转换操作，包括将图像转换为张量和标准化处理。
# 加载数据集：下载并加载 MNIST 训练和测试数据集。
# 定义数据加载器：创建数据加载器，用于批量加载数据并打乱数据顺序。
# 定义神经网络模型：通过继承 nn.Module 类定义一个简单的全连接神经网络模型，包括两个全连接层和一个 dropout 层。
# 定义训练和测试步骤：分别定义训练和测试模型的逻辑，包括前向传播、计算损失、反向传播和参数更新。
# 创建优化器：使用 Adam 优化器来调整模型参数。
# 训练和测试模型：在指定的轮次（epochs）内进行训练和测试，输出训练损失和测试集的平均损失及准确率。
# 通过这些步骤，代码实现了一个基本的深度学习流程，用于对 MNIST 数据集进行分类任务。

# 判断是否有cuda可用
use_cuda = torch.cuda.is_available()
print(use_cuda)

#设置device变量
if use_cuda:
    device = torch.device('cuda')
else:
    device = torch.device('cpu')

#设置对数据进行处理的逻辑
transform = transforms.Compose([
    #让数据转成Tensor张量
    transforms.ToTensor(),
    #让图片数据进行标准归一化，0.1307是标准归一化的均值，0.3081是标准归一化的方差
    transforms.Normalize((0.1307,), (0.3081,))  #标准化处理
])

#读取数据
datasets1 = datasets.MNIST('./data', train=True, download=True, transform=transform)
datasets2 = datasets.MNIST('./data', train=False, download=True, transform=transform)

#设置数据加载器，顺带手设置批次大小和是否打乱数据顺序
train_loader = torch.utils.data.DataLoader(datasets1, batch_size=128, shuffle=True)
test_loader = torch.utils.data.DataLoader(datasets2, batch_size=1000)

# for batch_idx, data in enumerate(train_loader, 0):
#     inputs, targets = data
#     # view在下一行会把我们的训练集(60000, 1, 28, 28)转换成(60000, 28*28)
#     x = inputs.view(-1, 28*28)
#     #计算所有训练样本的标准差和均值
#     x_std = x.std().item()
#     x_mean = x.mean().item()
#
# print('均值mean为：'+str(x_mean))
# print('标准差std为：'+str(x_std))

#通过自定义类来构建模型
class Net(nn.Module):
    def __init__(self):
        super(Net, self).__init__()
        #定义第一个全连接层，输入维度是28*28，输出维度是128
        self.fc1 = nn.Linear(28*28, 128)
        #定义一个dropout层，用于防止过拟合
        self.dropout = nn.Dropout(0.2)
        #定义第二个全连接层，输入维度是128，输出维度是10
        self.fc2 = nn.Linear(128, 10)

    #前向传播函数
    def forward(self, x):
        #将输入张量x展平成一维张量
        x = torch.flatten(x, 1)
        #第一个全连接层
        x = self.fc1(x)
        #使用ReLU激活函数
        x = F.relu(x)
        #dropout层
        x = self.dropout(x)
        #第二个全连接层
        x = self.fc2(x)
        #使用log_softmax激活函数
        output = F.log_softmax(x, dim=1)
        return output

#创建一个模型实例
model = Net().to(device)

#定义训练模型的逻辑
def train_step(data, target, model, optimizer):
    optimizer.zero_grad()
    output = model(data)
    #nll代表negative log likelihood loss，负对数似然损失
    loss = F.nll_loss(output, target)
    #反向传播的本质是计算梯度
    loss.backward()
    #本质就是应用梯度下降算法来更新模型参数
    optimizer.step()
    return loss

#定义测试模型的逻辑
def test_step(data, target, model, test_loss, correct):
    output = model(data)
    #累积的批次损失
    test_loss += F.nll_loss(output, target, reduction='sum').item()
    #获得对数概率最大值对应的索引号，这里其实就是类别号
    pred = output.argmax(dim=1, keepdim=True)
    #判断预测值和真实值是否相等，相等则返回True，否则返回False
    correct += pred.eq(target.view_as(pred)).sum().item()
    return test_loss, correct

#创建训练调参使用的优化器
optimizer = optim.Adam(model.parameters(), lr=0.001)

#真正的分轮次训练
EPOCHS = 5

for epoch in range(EPOCHS):
    model.train()
    for batch_idx, (data, target) in enumerate(train_loader):
        data, target = data.to(device), target.to(device)
        loss = train_step(data, target, model, optimizer)
        #每隔10个批次打印一次训练损失
        if batch_idx % 10 == 0:
            print('Train Epoch: {} [{}/{} ({:.0f}%)]\tLoss: {:.6f}'.format(
                epoch, batch_idx * len(data), len(train_loader.dataset),
                       100. * batch_idx / len(train_loader), loss.item()))

    model.eval()
    test_loss = 0
    correct = 0
    with torch.no_grad():
        for data, target in test_loader:
            data, target = data.to(device), target.to(device)
            test_loss, correct = test_step(data, target, model, test_loss, correct)
    test_loss /= len(test_loader.dataset)
    print('\nTest set: Average loss: {:.4f}, Accuracy: {}/{} ({:.0f}%)\n'.format(
        test_loss, correct, len(test_loader.dataset),
        100. * correct / len(test_loader.dataset))
    )

