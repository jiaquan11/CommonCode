#pragma once
#include <string>
//��־������ӿڣ�������豸
class LogOutput {
public:
	/*
	* ��־���
	* @param log ��ʽ�������־����
	*/
	virtual void Output(const std::string& log) = 0;
};