#pragma once

#include "xlog.h"
#include <map>
#include <string>
#include <functional>
#include <vector>

class XLOG_API UserInput{
public:
	//��������̨�����ȡ�û�����
	void Start(std::function<void(std::vector<std::string>)>init = [] (std::vector<std::string>){});
	void Stop() {
		is_exit = true;
	}
	//ע���������Ļص�����
	UserInput& Reg(std::string key, std::function<void(const std::string&)> func) {
		key_funcs_[key] = func;
		return *this;
	}

	UserInput& RegTask(std::string key, std::function<void()> func) {
		task_funcs_[key] = func;
		return *this;
	}
private:
	//����ѭ���Ƿ��˳�
	bool is_exit{ false };
	//�ؼ���ӳ�亯����
	// key: -s -d
	// value: �ص��������ݲ���
	std::map<std::string, std::function<void(const std::string&)>>key_funcs_;
	//��ʼ������
	//std::function<void()>init_func_ = [] {};
	//����ִ�к���
	std::map<std::string, std::function<void()>>task_funcs_;
};

