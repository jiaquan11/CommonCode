from sklearn.datasets import fetch_20newsgroups
from sklearn.metrics import accuracy_score
from sklearn.pipeline import make_pipeline
from sklearn.feature_extraction.text import CountVectorizer
from sklearn.linear_model import LogisticRegression

#使用逻辑回归模型 对20newsgroups数据集进行分类，并评估模型的准确率
#逻辑回归是一种分类算法，用于预测离散型目标值

# 加载20newsgroups数据集
newsgroups_train = fetch_20newsgroups(subset='train')
newsgroups_test = fetch_20newsgroups(subset='test')

#创建一个pipeline对象,用于文件特征提取和逻辑回归分类
pipeline = make_pipeline(CountVectorizer(), LogisticRegression(max_iter=3000))

#使用训练集训练模型
pipeline.fit(newsgroups_train.data, newsgroups_train.target)

#使用测试集进行预测
y_test_pred = pipeline.predict(newsgroups_test.data)

#输出模型的准确率
print("准确率: %0.2f" % accuracy_score(newsgroups_test.target, y_test_pred))

