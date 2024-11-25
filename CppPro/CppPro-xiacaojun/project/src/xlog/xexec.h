#pragma once

#include "xlog.h"
#include <string>
#include <queue>
#include <future>

/*
* ִ���ⲿ����
*/
class XLOG_API XExec {
public:
	//ִ���ⲿ����
	bool Start(const char* cmd);
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

