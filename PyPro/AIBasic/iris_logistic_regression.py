from sklearn import datasets
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LogisticRegression
from sklearn.metrics import accuracy_score

#使用逻辑回归模型 对鸢尾花数据集进行分类，并评估模型的准确率
#逻辑回归是一种分类算法，用于预测离散型目标值
#逻辑回归模型可以用于二分类和多分类问题

# 加载鸢尾花数据集
iris = datasets.load_iris()
X = iris.data
y = iris.target
print(y)

# 将数据集分为训练集和测试集
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2)

# 创建一个逻辑回归算法对象
# 逻辑回归是一种分类算法，用于预测离散型目标值
# 逻辑回归模型可以用于二分类和多分类问题
#这里的逻辑回归会根据我们的数据集的目标值y的类型，自动选择二分类或多分类
#逻辑回归到底是把多分类转行成了多个二分类，还是说使用的是Softmax函数回归
lr = LogisticRegression(max_iter=1000)
#lr = LogisticRegression(mutli_class='ovr') #多分类转行成了多个二分类
#lr = LogisticRegression(mutli_class='multinomial')#使用的是Softmax函数回归，多分类

# 使用训练集训练模型
lr.fit(X_train, y_train)

# 使用测试集进行预测
y_test_pred = lr.predict(X_test)

# 打印模型的准确率
print("准确率: %0.2f" % accuracy_score(y_test, y_test_pred))