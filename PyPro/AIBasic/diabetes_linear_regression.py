from sklearn import datasets
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression
from sklearn.metrics import mean_squared_error

# 这段代码实现了一个简单的多元线性回归模型，用于预测糖尿病数据集中的目标值（y）。
# 首先，我们加载糖尿病数据集，然后将数据集分为训练集和测试集。
# 接下来，我们创建一个多元线性回归算法对象，并使用训练集训练模型。
# 最后，我们使用测试集进行预测，并计算模型的均方误差。

# 加载糖尿病数据集
diabetes = datasets.load_diabetes()
X = diabetes.data #数据集的特征矩阵，共有442个样本，每个样本有10个特征
y = diabetes.target #目标值，即糖尿病进展的定量指标，每个样本对应一个目标值，共有442个目标值

# 将数据集分为训练集和测试集(输入数据集X和目标值y)
#test_size=0.2表示将数据集的20%分为测试集，80%分为训练集
#输出：X_train 和 y_train：训练集的特征和目标值，用于训练模型
#输出：X_test 和 y_test：测试集的特征和目标值，用于评估模型
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2)

#创建一个多元线性回归算法对象
lr = LinearRegression()

#使用训练集训练模型
#fit：模型训练函数，输入训练集的特征和目标值，输出训练好的模型
#通过训练集的特征和目标值，模型可以学习到特征和目标值之间的线性关系，从而可以预测新的样本的目标值
lr.fit(X_train, y_train)

# 使用测试集进行预测
#predict：模型预测函数，输入测试集的特征，输出模型预测的目标值
#通过模型预测函数，可以预测新的样本的目标值
#y_pred_train：训练集的目标值预测值
#y_pred_test：测试集的目标值预测值
#根据训练好的模型，分别对训练集和测试集的特征进行预测，得到目标值的估计
y_pred_train = lr.predict(X_train)
y_pred_test = lr.predict(X_test)

#打印模型的均方误差
#mean_squared_error：从sklearn.metrics中导入的函数，用于计算均方误差（MSE）
#MSE反映了预测值与真实值之间的平均平方误差，值越小表示模型性能越好
print("均方误差: %0.2f" % mean_squared_error(y_train, y_pred_train))
print("均方误差: %0.2f" % mean_squared_error(y_test, y_pred_test))
