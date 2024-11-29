#pragma once

#include "xlog.h"
#include <string>
#include <queue>
#include <future>
#include <functional>
/*
* ִ���ⲿ����
*/
class XLOG_API XExec {
public:
	//ִ���ⲿ����
	//����̨����
	//����̨����ص������Ϊ�գ�����ȡ����̨��������ú�д�뻺�����
	bool Start(const char* cmd, std::function<void(const std::string&)> func = nullptr);
	//�����Ƿ���ִ��
	bool Running() {
		return running_;
	}
	//��ȡ����̨�����
	bool GetOutput(std::string& out);
	bool Wait() {
		return fut_.get();
	}

private:
	bool running_{ false };
	//�������
	std::queue<std::string> outs_;
	//����ִ���߳�
	std::future<bool> fut_;
	std::mutex mux_;
};

