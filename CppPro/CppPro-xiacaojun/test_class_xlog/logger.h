#pragma once
#include <string>
#include "log_format.h"
#include "log_output.h"
#include <memory>

//日志级别
enum class XLog {
	DEBUG,
	INFO,
	ERROR,
	FATAL
};

//聚合类
//委托
// LogFormat和LogOutput完成日志格式化和输出
class Logger {
public:
	~Logger() {
		/*delete format_;
		format_ = nullptr;
		delete output_;
		output_ = nullptr;*/
	}

public:
	//格式化并写入日志
	void Write(XLog level, const std::string& log,
			   const std::string& file, int line);

	void SetOutput(std::unique_ptr<LogOutput> output) {
		output_ = move(output);
	}

	void SetFormat(std::unique_ptr<LogFormat> format) {
		format_ = move(format);
	}

	void SetLevel(XLog level) {
		log_level_ = level;
	}

private:
	//日志格式化
	//LogFormat* format_{ nullptr };
	//日志输出
	//LogOutput* output_{ nullptr };
	std::unique_ptr<LogFormat> format_;
	std::unique_ptr<LogOutput> output_;
	//最低日志级别
	XLog log_level_{ XLog::DEBUG };
};

