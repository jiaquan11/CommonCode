#include <iostream>

using namespace std;
enum class LogLevel {
    DEBUG,
    INFO,
    ERROR,
    FATAL
};

int main(int argc, char* argv[]) {
    //用户传递最低显示的日志级别
    //debug < info < error < fatal
    //0 1 2 3
    //test_main_log debug
    //默认是DEBUG及以上都显示
    auto logLevel = LogLevel::DEBUG;
    if (argc > 1) {
        string levelStr = argv[1];//用户设置传递的日志级别
        if (levelStr == "info") {
			logLevel = LogLevel::INFO;
        } else if (levelStr == "error") {
			logLevel = LogLevel::ERROR;
        } else if (levelStr == "fatal") {
			logLevel = LogLevel::FATAL;
		}
    }
    //测试日志1 debug
    //判断日志级别是否满足条件
    //              打印日志
     {
        LogLevel level = LogLevel::DEBUG;
        string context = "test log 1";//日志内容
        if (level >= logLevel) {
            string levelStr = "debug";
            if (LogLevel::INFO == level) {
                levelStr = "info";
            } else if (LogLevel::ERROR == level) {
				levelStr = "error";
            } else if (LogLevel::FATAL == level) {
				levelStr = "fatal";
			}
			cout << levelStr + ":" << context << endl;
		}
     }

    //测试日志2 info
	{
	     LogLevel level = LogLevel::INFO;
	     string context = "test log 2";//日志内容
	     if (level >= logLevel) {
		     string levelStr = "debug";
		     if (LogLevel::INFO == level) {
			     levelStr = "info";
		     } else if (LogLevel::ERROR == level) {
			     levelStr = "error";
		     } else if (LogLevel::FATAL == level) {
			     levelStr = "fatal";
		     }
		     cout << levelStr + ":" << context << endl;
	     }
    }

    //测试日志3 error
	{
		LogLevel level = LogLevel::ERROR;
		string context = "test log 3";//日志内容
		if (level >= logLevel) {
			string levelStr = "debug";
			if (LogLevel::INFO == level) {
				levelStr = "info";
			} else if (LogLevel::ERROR == level) {
				levelStr = "error";
			} else if (LogLevel::FATAL == level) {
				levelStr = "fatal";
			}
			cout << levelStr + ":" << context << endl;
		}
	}

    //测试日志4 fatal
	{
		LogLevel level = LogLevel::FATAL;
		string context = "test log 4";//日志内容
		if (level >= logLevel) {
			string levelStr = "debug";
			if (LogLevel::INFO == level) {
				levelStr = "info";
			} else if (LogLevel::ERROR == level) {
				levelStr = "error";
			} else if (LogLevel::FATAL == level) {
				levelStr = "fatal";
			}
			cout << levelStr + ":" << context << endl;
		}
	}
}
