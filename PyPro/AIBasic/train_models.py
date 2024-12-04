import numpy as np
from scipy.io.wavfile import read
from speaker_features import extract_features
from sklearn.mixture import GaussianMixture
import pickle

source = 'D:/study/computerStudy/personcode/CommonCode/PyPro/AIBasic/speaker-identification/development_set/'

train_file = 'D:/study/computerStudy/personcode/CommonCode/PyPro/AIBasic/speaker-identification/development_set_enroll.txt'

dest = './speaker_models/'

file_paths = open(train_file, 'r')

features = np.asarray(())

count = 1

for path in file_paths:
    path = path.strip() #去掉首尾空格
    print(source + path)

    #一个个地读取原声音文件
    sr, audio = read(source + path)

    #提取40个维度的音频特征(MFCC+Delta)
    vector = extract_features(audio, sr)

    if features.size == 0:
        features = vector
    else:
        features = np.vstack((features, vector)) #将每一个音频文件的特征拼接在一起

    #训练集是每5个文件对应一个说话人
    if count == 5:
        #这里就相对于是用一个人的5条语音文件，对应来使用一个GMM模型建模
        #n_components=16表示GMM模型的个数
        #max_iter=200表示GMM模型的最大迭代次数
        #covariance_type='diag'表示GMM模型的协方差类型
        #n_init=3表示GMM模型的初始化次数
        gmm = GaussianMixture(n_components=16, max_iter=200, covariance_type='diag', n_init=3)
        gmm.fit(features) #训练GMM模型

        #落地保存每一个人对应的GMM模型
        picklefile = path.split('-')[0] + '.gmm'
        pickle.dump(gmm, open(dest + picklefile, 'wb'))

        features = np.asarray(())
        count = 0
    count += 1

