#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

/*
 * 获取当前时间
 * @param fmt 时间格式
 * @param time_zone 时区
 * @return 当前时间
 * 算法逻辑解释如下：
 * 1.获取当前的 Unix 时间戳（即从 1970 - 01 - 01 00:00 : 00 UTC 开始的秒数）
 * 2.根据时区调整时间
 * 3.根据时间戳计算年月日时分秒
 * 4.根据年月日时分秒计算当前时间
 * 5.返回当前时间
 */
static std::string GetNow(const char* fmt = "%Y-%m-%d %H:%M:%S", int time_zone = 8) {
	std::time_t unix_sec = std::time(nullptr); //获取当前的 Unix 时间戳（即从 1970 - 01 - 01 00:00 : 00 UTC 开始的秒数）
	std::tm tm;
	static const int kHoursInDay = 24;//一天24小时
	static const int kMinutesInHour = 60;//一小时60分钟
	static const int kDaysFromUnixTime = 2472632;//
	static const int kDaysFromYear = 153;//
	static const int kMagicUnkonwnFirst = 146097;//
	static const int kMagicUnkonwnSec = 1461;
	tm.tm_sec = unix_sec % kMinutesInHour;//
	int i = (unix_sec / kMinutesInHour);
	tm.tm_min = i % kMinutesInHour; //nn
	i /= kMinutesInHour;
	tm.tm_hour = (i + time_zone) % kHoursInDay; // hh
	tm.tm_mday = (i + time_zone) / kHoursInDay;
	int a = tm.tm_mday + kDaysFromUnixTime;
	int b = (a * 4 + 3) / kMagicUnkonwnFirst;
	int c = (-b * kMagicUnkonwnFirst) / 4 + a;
	int d = ((c * 4 + 3) / kMagicUnkonwnSec);
	int e = -d * kMagicUnkonwnSec;
	e = e / 4 + c;
	int m = (5 * e + 2) / kDaysFromYear;
	tm.tm_mday = -(kDaysFromYear * m + 2) / 5 + e + 1;
	tm.tm_mon = (-m / 10) * 12 + m + 2;
	tm.tm_year = b * 100 + d - 6700 + (m / 10);
	stringstream ss;
	ss << std::put_time(&tm, fmt); //#include <iomanip>
	return ss.str();
}

// 用户输入 LOGDEBUG("test log 001")
//生成一条日志： 2024-7-30 18:29:30 debug:test log 001 main.cpp:21
//可以设置日志输出为控制台、string和文件中
static ostream logstr(cout.rdbuf()); //设置buf

/*
 * 设置日志输出流
 * @param buf 输出流
 */
void SetLogBuf(streambuf* buf) {
	logstr.set_rdbuf(buf);
}

void LogWrite(string level, string log, string file, int line) {
	logstr << GetNow() << " " << level << " " << log << " " << file << ":" << line << endl;
}

#define LOGDEBUG(s) LogWrite("debug",s,__FILE__,__LINE__)
int main() {
	LOGDEBUG("test log 001");
	LOGDEBUG("test log 002");

	stringstream ss;
	SetLogBuf(ss.rdbuf());//设置日志输出到string
	LOGDEBUG("test log 003 stringstream");
	cout << "-----" << endl;
	cout << "ss.str():" << ss.str() << endl;

	ofstream ofs("log.txt", ios::app);
	SetLogBuf(ofs.rdbuf());//设置日志输出到文件
	LOGDEBUG("test log 004 ofstream");
	LOGDEBUG("test log 005 ofstream");

	system("pause");
	return 0;
}

