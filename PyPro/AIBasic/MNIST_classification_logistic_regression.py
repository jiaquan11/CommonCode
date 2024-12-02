import numpy as np
import matplotlib.pyplot as plt
from sklearn.datasets import fetch_openml
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.linear_model import LogisticRegression
from  sklearn.metrics import accuracy_score

# 加载MNIST数据集,手写数字识别数据集
mnist = fetch_openml('mnist_784')

img0 = np.array(mnist.data)[0]
#print(img0.shape)
# print(np.array(mnist.target)[0])
# img0 = img0.reshape(28, 28)
# plt.imshow(img0, cmap='gray')
# plt.show()

#数据预处理，标准归一化
#对像素值进行标准化，消除特征之间的量纲差异，提高模型的训练效果
#StandardScaler：标准化类，用于对数据集进行标准化处理
scaler = StandardScaler()
X = scaler.fit_transform(mnist.data)

#将数据集分为训练集和测试集
X_train, X_test, y_train, y_test = train_test_split(X, mnist.target, test_size=0.2, random_state=42)

#创建逻辑回归模型
model = LogisticRegression(max_iter=1000)

#使用训练集训练模型
model.fit(X_train, y_train)

#使用测试集进行预测
y_test_pred = model.predict(X_test)

#输出模型的准确率
print("准确率: %0.2f" % accuracy_score(y_test, y_test_pred))

print(model.predict([img0]))