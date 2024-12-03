'''
import numpy as np
from sklearn.cluster import KMeans

#使用KMeans模型对数据进行聚类
#KMeans是一种聚类算法，用于将数据集中的样本划分为多个簇，
#使得同一簇内的样本之间的相似度较高，不同簇之间的相似度较低

#定义几个点
X = np.array([[1, 2], [1, 4], [1, 0],
              [4, 2], [4, 4], [4, 0]])

#初始化KMeans聚类模型
kmeans = KMeans(n_clusters=2, random_state=0)

#使用KMeans模型对数据进行聚类
kmeans.fit(X)

#输出聚类结果
print(kmeans.labels_)

#输出模型的聚类中心
print(kmeans.cluster_centers_)
'''

import numpy as np
import matplotlib.pyplot as plt

# 实现了一个简单的 KMeans 聚类算法。
# 生成了一个包含 3 组二维数据的模拟数据集。
# 使用 KMeans 算法对数据进行聚类。
# 可视化了聚类结果，包括样本点和聚类中心。

# 我们自己去实现KMeans算法，不依赖任何机器学习库
# 输入参数：
# X：输入数据集，形状为 (n_samples, n_features)，表示 n_samples 个样本，每个样本有 n_features 个特征。
# k：聚类的类别数，即将数据分为 k 个簇。
# max_iter：最大迭代次数，防止算法陷入死循环
def kmeans(X, k, max_iter=100):
    # 随机初始化k个聚类中心
    centers = X[np.random.choice(X.shape[0], k, replace=False)]

#初始化每个样本的标签为 0，表示初始时所有样本未被分配到任何簇。
    labels = np.zeros(X.shape[0])

    for i in range(max_iter):
        #计算每个样本到聚类中心的距离
        # 分配样本到最近的聚类中心点
        # 求的是欧式距离
        distances = np.sqrt(((X - centers[:, np.newaxis])**2).sum(axis=2))
        #看每一个样本离哪个中心点更近，也就是距离更小
        #找到每个样本距离最近的聚类中心的索引，作为该样本的标签
        new_labels = np.argmin(distances, axis=0)

        #更新聚类中心
        #对每个簇，计算该簇中所有样本的均值，作为新的聚类中心
        for j in range(k):
            centers[j] = X[new_labels == j].mean(axis=0)

        #如果聚类结果没有变化，则提前结束迭代
        #如果当前迭代的标签与上一轮完全相同，说明聚类结果不再变化，提前结束迭代
        if (new_labels == labels).all():
            break
        else:
            labels = new_labels
        #返回每个样本的聚类标签 labels 和最终的聚类中心 centers
        return labels, centers

#生成数据集，生成了3个组的数据
# 数据生成过程
# 使用 np.random.randn 生成 3 组二维正态分布数据，每组数据有 100 个样本。
# 每组数据的分布中心和方差不同：
# 第一组数据：均值为 [1, 0]，标准差为 0.75。
# 第二组数据：均值为 [-0.5, 0.5]，标准差为 0.25。
# 第三组数据：均值为 [-0.5, -0.5]，标准差为 0.5。
# 使用 np.vstack 将 3 组数据垂直堆叠，形成一个形状为 (300, 2) 的二维数据集。
X = np.vstack((np.random.randn(100, 2) * 0.75 + np.array([1, 0]),
               np.random.randn(100, 2) * 0.25 + np.array([-0.5, 0.5]),
               np.random.randn(100, 2) * 0.5 + np.array([-0.5, -0.5])))

#使用自己实现的KMeans算法对数据进行聚类
labels, centers = kmeans(X, 3)

#可视化聚类结果
plt.scatter(X[:, 0], X[:, 1], c=labels)
plt.scatter(centers[:, 0], centers[:, 1], marker='x', s = 200, linewidths=3, color='r')
plt.show()