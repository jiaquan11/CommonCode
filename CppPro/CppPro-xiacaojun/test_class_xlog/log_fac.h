#pragma once
#include <string>
#include "logger.h"

#define XLOGOUT(l, s) LogFac::Instance().logger().Write(l, s, __FILE__, __LINE__)
#define LOGDEBUG(s) XLOGOUT(XLog::DEBUG, s)
#define LOGINFO(s) XLOGOUT(XLog::INFO, s)
#define LOGERROR(s) XLOGOUT(XLog::ERROR, s)
#define LOGFATAL(s) XLOGOUT(XLog::FATAL, s)

/*
* ��־������
* ����ģʽ
* ά��logger�������������
* ����logger����
*/
class LogFac {
private:
	LogFac() {}

public:
	static LogFac& Instance() {
		static LogFac fac;
		return fac;
	}

	//��ʼ��Logger����
	void Init(const std::string& con_file = "log.conf");
	Logger& logger() {
		return logger_;
	}
private:
	Logger logger_;
};

