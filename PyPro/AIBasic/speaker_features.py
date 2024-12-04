import numpy as np
import python_speech_features as mfcc
from sklearn import preprocessing

def calculate_delta(array):
    rows, cols = array.shape
    deltas = np.zeros((rows, 20))
    N = 2
    for i in range(rows):
        index = []
        j = 1
        while j <= N:
            if i - j < 0:
                first = 0
            else:
                first = i - j
            if i + j > rows - 1:
                second = rows - 1
            else:
                second = i + j
            index.append((second, first))
            j += 1
        deltas[i] = (array[index[0][0]] - array[index[0][1]] + (2 * (array[index[1][0]] - array[index[1][1]]))) / 10
        return deltas

# 从音频信号中提取特征，具体来说，它提取了 MFCC（梅尔频率倒谱系数）
# 和 一阶差分特征（Delta 特征），并将它们组合成一个特征矩阵，供后续的音频处理或机器学习任务使用。
# extract_features 是一个函数，用于从音频信号中提取特征。
# 输入参数：
# audio：音频信号的时域数据，通常是一个一维 NumPy 数组，表示音频的采样值。
# rate：音频的采样率，表示每秒采样的次数（单位：Hz）。
# 返回值：
# 返回一个二维特征矩阵，包含 MFCC 特征和 Delta 特征。

# 代码的整体作用
# 输入：音频信号和采样率。
# 输出：包含 MFCC 特征和 Delta 特征的二维特征矩阵。
# 主要步骤：
# 计算音频的 MFCC 特征。
# 对 MFCC 特征进行标准化。
# 计算 MFCC 特征的一阶差分（Delta 特征）。
# 将 MFCC 特征和 Delta 特征拼接在一起，形成最终的特征矩阵。
def extract_features(audio, rate):
    # mfcc.mfcc：这是一个函数，用于计算音频的 MFCC（Mel - Frequenc Cepstral Coefficients，梅尔频率倒谱系数）。
    # MFCC是音频信号处理中常用的特征，特别是在语音识别和音频分类任务中。它通过将音频信号转换到梅尔频率域，提取出反映音频频谱特性的倒谱系数。
    # 参数说明：audio：输入的音频信号。rate：音频的采样率。0.025：帧长，表示每帧音频的时长为25毫秒。
    # 0.01：帧移，表示相邻帧之间的时间间隔为10毫秒（帧重叠15毫秒）。20：提取的MFCC系数数量，通常取12或20。
    # appendEnergy = True：是否将每帧的能量作为一个附加特征。
    # 返回值：mfcc_feat是一个二维数组，形状为(n_frames, n_features)，其中：
    # n_frames是音频被分割的帧数。n_features是每帧提取的MFCC特征数量（这里是20）。
    mfcc_feat = mfcc.mfcc(audio, rate, 0.025, 0.01, 20, appendEnergy=True)
    # 标准化MFCC特征
    # 将MFCC特征的每个维度标准化为均值为0，标准差为1。
    # 标准化可以消除特征之间的量纲差异，提高模型的训练效果。
    mfcc_feat = preprocessing.scale(mfcc_feat)
    # 用于计算Delta特征。Delta特征是MFCC特征的一阶差分，表示每帧特征的变化趋势，能够捕捉音频信号的动态信息。
    delta = calculate_delta(mfcc_feat)
    # 组合MFCC和Delta特征
    # 将标准化后的MFCC特征和Delta特征拼接在一起，形成一个新的特征矩阵。
    combined = np.hstack((mfcc_feat, delta))
    # 返回拼接后的特征矩阵combined，供后续的音频处理或机器学习任务使用
    return combined


# MFCC 和 Delta 特征的意义
# MFCC 特征：
# 是音频信号的频谱特征，能够反映音频的频率分布。
# 在语音识别、音频分类等任务中，MFCC 是最常用的特征之一。
# Delta 特征：
# 是 MFCC 特征的动态变化信息，能够捕捉音频信号的时间变化趋势。
# Delta 特征通常与 MFCC 特征一起使用，以提高模型的性能。

#  应用场景
# 语音识别：提取 MFCC 和 Delta 特征作为输入特征，用于训练语音识别模型。
# 音频分类：如音乐风格分类、情感识别等。
# 说话人识别：通过 MFCC 和 Delta 特征捕捉说话人的语音特征。
# 这段代码实现了音频特征提取的核心步骤，提取了 MFCC 和 Delta 特征，
# 并将它们组合成一个特征矩阵。通过这些特征，可以将音频信号转化为数值化的特征表示，供机器学习模型使用。
