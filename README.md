# CommonCode
各种计算机语言的demo示例学习
一、OCPro项目
OC相关的工程项目
--iOS开发之Objective-C（基础篇）-李飞
OCbase-lifei


二、CppPro项目
CPP相关的工程项目
--C++零基础到工程实战视频课程-夏曹俊
CppPro-xiacaojun->CppProToPractice
该目录中各子项目工程功能介绍
工程项目说明
1、constdemo
const和constexpr的区别
2、stringdemo
string的基本使用
3、test_main_log
简单的日志逻辑，通过main参数传递
4、testbase16
base16算法的编解码转换
5、testwhile
模拟命令执行操作
6、test_base16_func
用函数的方式封装base16算法
7、testpointandref
指针和引用的区分说明
8、test_cout_cin
输入输出的部分用法
9、streamlog
输入输出实例-日志模块
10、test_class_log
日志模块类的封装
11、test_class_copy
拷贝构造函数,移动构造函数，赋值运算符重载的说明
12、test_unique_ptr
智能指针的使用
13、msg_server
基于多线程实现一个http消息发送和分发的简单demo
14、project
test_xlog
xlog
新建一个测试日志库的工程及日志库，同时添加有执行外部程序和用户输入模块
xvideo_edit
xlog
接收控制台命令，实现视频的加解密播放及转码操作及批量处理指令


三、PyPro项目
--【2024最新版】人工智能零基础入门教程！（理论+实战）39讲全
AIBasic
1、diabetes_linear_regression.py
这段代码实现了一个简单的多元线性回归模型，用于预测糖尿病数据集中的目标值（y）
2、iris_logistic_regression.py
使用逻辑回归模型 对鸢尾花数据集进行分类，并评估模型的准确率
3、20newsgroups_logistic_regression.py
使用逻辑回归模型 对20newsgroups数据集进行分类，并评估模型的准确率
4、hello_CountVectorizer.py
使用 CountVectorizer 将文本数据（corpus）转换为 词频矩阵
5、MNIST_classification_logistic_regression.py
使用 逻辑回归模型 对 MNIST 手写数字数据集 进行分类，并评估模型的准确率
6、KMeans_implement.py
使用KMeans模型对数据进行聚类
7、speaker_features.py  test_speaker.py train_models.py
使用高斯混合模型对提取的音频特征信息进行建模训练并测试识别

PyTorch_Study
1、mnist_dnn.py
使用 PyTorch 框架实现的简单深度神经网络，用于对 MNIST 数据集进行手写数字识别

--目前B站最全最细的AI大模型全套教程，2024最新版，包含所有干货
ai_demo
1、openai_test.py
使用openai模型简洁控制台用户循环交互示例
2、json_mode.py
使用json格式显示回复
3、seed.py
使用种子，可以确保每次请求回复的格式相同
4、count_token.py
统计分词的tokens的数量
5、limit_token.py
实现基于最大token数量的消息列表限制带会话长度管理的控制台循环聊天
6、test_chatbot_app.py
使用streamlit生成一个网页