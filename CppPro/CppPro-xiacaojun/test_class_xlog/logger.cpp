#include "logger.h"

void Logger::Write(XLog level, const std::string& log,
				   const std::string& file, int line) {
	if (level < log_level_) {
		return;
	}
	//��־����ö������תΪ�ַ���
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
	//��ʽ����־
	std::string logstr = format_->Format(levelstr, log, file, line);
	//�����־
	output_->Output(logstr);
}