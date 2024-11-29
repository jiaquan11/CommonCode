#pragma once
#include <string>
#include "logger.h"

#define XLOGOUT(l, s) LogFac::Instance().logger().Write(l, s, __FILE__, __LINE__)
#define LOGDEBUG(s) XLOGOUT(XLog::DEBUG, s)
#define LOGINFO(s) XLOGOUT(XLog::INFO, s)
#define LOGERROR(s) XLOGOUT(XLog::ERROR, s)
#define LOGFATAL(s) XLOGOUT(XLog::FATAL, s)

/*
* 日志工厂类
* 单例模式
* 维护logger对象的生命周期
* 构建logger对象
*/
class LogFac {
private:
	LogFac() {}

public:
	static LogFac& Instance() {
		static LogFac fac;
		return fac;
	}

	//初始化Logger对象
	void Init(const std::string& con_file = "log.conf");
	Logger& logger() {
		return logger_;
	}
private:
	Logger logger_;
};

