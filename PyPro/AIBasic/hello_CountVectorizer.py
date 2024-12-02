from sklearn.feature_extraction.text import CountVectorizer

#使用 CountVectorizer 将文本数据（corpus）转换为 词频矩阵，
# 即将文本表示为数值化的特征向量，方便后续的机器学习模型处理
'''
将文本数据（corpus）转化为数值化的特征表示（词频矩阵）。
每个句子被表示为一个向量，向量的每个元素表示某个单词在该句子中出现的次数。
这种表示方法是机器学习中常用的文本特征提取方法之一，适用于分类、聚类等任务
'''
corpus = [
    'This is a sample text.',
    'This text is another example text.',
    'This is just another text.'
]

vectorizer = CountVectorizer()
X = vectorizer.fit_transform(corpus)

print(X.toarray())