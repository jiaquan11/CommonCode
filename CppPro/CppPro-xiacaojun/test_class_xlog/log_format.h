#pragma once
#include <string>

//LogFormat日志格式化接口类
class LogFormat {
public:
	//返回格式化后的日志转为字符串
	virtual std::string Format(const std::string& level, const std::string& log,
							   const std::string& file, int line) = 0;
};