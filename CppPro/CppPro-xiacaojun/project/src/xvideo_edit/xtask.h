#pragma once
#include <string>

//����Ƶ������ӿ�
class XTask {
public:
	struct Data {
		std::string type;//�������� cv play
		std::string src;//Դ�ļ�
		std::string des;//Ŀ���ļ�
		bool is_enc{ true };//Ĭ���Ǽ���  false��ʾ����
		std::string password;//�ӽ�����Կ
		int begin_sec{ 0 };//���еĿ�ʼʱ��
		int end_sec{ 0 };//���еĽ���ʱ�䣬0��ʾ��������
	};
	//��������Ƶ�����������̷��أ����߳��д���
	virtual bool Start(const Data&) = 0;
	//��ȡ�������0-100
	virtual int Progress() = 0;
	//�����Ƿ������
	virtual bool Running() = 0;
	//��Ƶ��ʱ�����룩
	virtual int TotalSec() = 0;
};