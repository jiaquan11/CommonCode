#pragma once
#include <string>
#include "log_format.h"
#include "log_output.h"

//��־����
enum class XLog {
	DEBUG,
	INFO,
	ERROR,
	FATAL
};

//�ۺ���
//ί��
// LogFormat��LogOutput�����־��ʽ�������
class Logger {
public:
	~Logger() {
		delete format_;
		format_ = nullptr;
		delete output_;
		output_ = nullptr;
	}

public:
	//��ʽ����д����־
	void Write(XLog level, const std::string& log,
			   const std::string& file, int line);

	void SetOutput(LogOutput* output) {
		output_ = output;
	}

	void SetFormat(LogFormat* format) {
		format_ = format;
	}

	void SetLevel(XLog level) {
		log_level_ = level;
	}

private:
	//��־��ʽ��
	LogFormat* format_{ nullptr };
	//��־���
	LogOutput* output_{ nullptr };

	//�����־����
	XLog log_level_{ XLog::DEBUG };
};

