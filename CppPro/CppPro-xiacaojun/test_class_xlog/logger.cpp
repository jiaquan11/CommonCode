#include "logger.h"

void Logger::Write(XLog level, const std::string& log,
				   const std::string& file, int line) {
	if (level < log_level_) {
		return;
	}
	//日志级别枚举类型转为字符串
	std::string levelstr = "debug";
	switch (level) {
	case XLog::INFO:
		levelstr = "info";
		break;
	case XLog::ERROR:
		levelstr = "error";
		break;
	case XLog::FATAL:
		levelstr = "fatal";
		break;
	default:
		break;
	}
	//格式化日志
	std::string logstr = format_->Format(levelstr, log, file, line);
	//输出日志
	output_->Output(logstr);
}