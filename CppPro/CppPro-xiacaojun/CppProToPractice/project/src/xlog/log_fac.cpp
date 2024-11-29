#include "log_fac.h"
#include <iostream>
#include "log_console_output.h"
#include "log_file_output.h"
#include "xlog_format.h"
#include "xconfig.h"

#define LOGFILE "log.txt"

using namespace std;
void LogFac::Init(const std::string& con_file) {
	logger_.SetFormat(make_unique<XLogFormat>());

	XConfig conf;
	bool ret = conf.Read(con_file);//读取配置文件,存放到map中，用于后续获取
	string log_type = "console";
	string log_file = LOGFILE;
	string log_level = "debug";
	if (ret) {
		log_type = conf.Get("log_type");
		log_file = conf.Get("log_file");
		log_level = conf.Get("log_level");
	}
	if (log_level == "info") {
		logger_.SetLevel(XLog::INFO);
	} else if (log_level == "error") {
		logger_.SetLevel(XLog::ERROR);
	} else if (log_level == "fatal") {
		logger_.SetLevel(XLog::FATAL);
	} else {
		logger_.SetLevel(XLog::DEBUG);
	}

	if (log_type == "file") {
		if (log_file.empty()) {
			log_file = LOGFILE;
		}
		auto fout = make_unique<LogFileOutput>();
		if (!fout->Open(log_file)) {
			cerr << "open file failed" << log_file << endl;
		}
		logger_.SetOutput(move(fout));
	} else {
		logger_.SetOutput(make_unique<LogConsoleOutput>());
	}
}