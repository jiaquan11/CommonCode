#pragma once
#include <string>
//日志的输出接口，输出到设备
class LogOutput {
public:
	/*
	* 日志输出
	* @param log 格式化后的日志内容
	*/
	virtual void Output(const std::string& log) = 0;
};