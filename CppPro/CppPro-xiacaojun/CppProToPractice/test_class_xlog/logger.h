#pragma once
#include <string>
#include "log_format.h"
#include "log_output.h"
#include <memory>

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
		/*delete format_;
		format_ = nullptr;
		delete output_;
		output_ = nullptr;*/
	}

public:
	//��ʽ����д����־
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
	//��־��ʽ��
	//LogFormat* format_{ nullptr };
	//��־���
	//LogOutput* output_{ nullptr };
	std::unique_ptr<LogFormat> format_;
	std::unique_ptr<LogOutput> output_;
	//�����־����
	XLog log_level_{ XLog::DEBUG };
};

