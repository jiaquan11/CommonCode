#include <iostream>
#include "xlog_format.h"
#include "log_console_output.h"
#include "log_file_output.h"
#include "logger.h"
#include "log_fac.h"
//#include "xconfig.h"

using namespace std;
int main() {
    //XConfig conf;
    //conf.Read("log.conf");
    //cout << conf.Get("log_file") << endl;
    LogFac::Instance().Init();
    LogFac::Instance().logger().Write(XLog::DEBUG, "test logger", __FILE__, __LINE__);
    LOGDEBUG("test LogFac debug");
    LOGINFO("test LogFac info");
    LOGERROR("test LogFac error");
    LOGFATAL("test LogFac fatal");

#if 0
    Logger logger;
    logger.SetFormat(new XLogFormat());
    logger.SetOutput(new LogConsoleOutput());
    logger.SetLevel(XLog::INFO);
    logger.Write(XLog::DEBUG, "test debug logger", __FILE__, __LINE__);
    logger.Write(XLog::INFO, "test info logger", __FILE__, __LINE__);
    logger.Write(XLog::ERROR, "test error logger", __FILE__, __LINE__);
    logger.Write(XLog::FATAL, "test fatal logger", __FILE__, __LINE__);

    /*LogFileOutput fout;
    fout.Open("log.txt");
    fout.Output("test file log");

	LogConsoleOutput log_console_out;
	log_console_out.Output("test logConsoleOutput");

    XLogFormat xlog;
    auto str = xlog.Format("debug", "test XLogFormat format", __FILE__, __LINE__);
    cout << "str = " << str << endl;*/
#endif

    system("pause");
    return 0;
}