#pragma once
#include <string>

//LogFormat��־��ʽ���ӿ���
class LogFormat {
public:
	//���ظ�ʽ�������־תΪ�ַ���
	virtual std::string Format(const std::string& level, const std::string& log,
							   const std::string& file, int line) = 0;
};