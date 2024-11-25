#include "xexec.h"
#include <iostream>
#include <string>
#ifdef _WIN32
#else
	#define _popen popen  //linux下没有_popen函数，用popen代替
#endif

using namespace std;
bool XExec::Start(const char* cmd, std::function<void(const std::string&)> func) {
	/*
	 *_popen 是 C/C++ 标准库中一个用于创建管道（pipe）并执行外部命令的函数。
	 *它允许当前进程与子进程之间进行通信，通常用于捕获子进程的输出或向子进程输入数据
	*/
	//重定向错误输出重定向到标准输出
	//ffmpeg -y -i biterate9.mp4 out.mp4 2>&1
	string tmp = cmd;
	tmp += " 2>&1";//2>&1表示将2错误输出crr重定向到1标准输出 1
	cout << "Start Cmd:" << tmp << endl;
	auto fp = _popen(tmp.c_str(), "r");//执行外部进程
	if (fp == nullptr) {
		cout << "_popen failed" << endl;
		return false;
	}
	running_ = true;

	fut_ = async([fp, this, func] {//异步执行,lambda表达式
		string tmp;
		char c = 0;
		while (c = fgetc(fp)) {//读取外部进程的输出
			//cout << c << flush;
			if (c == EOF) {
				break;
			}
			// /r回到当前行的开头，/n到下一行的开头
			if (c == '\n' || c == '\r') {
				//cout << tmp << endl;
				if (tmp.empty()) {
					continue;
				}
				{
					if (func) {
						func(tmp);//如果设置了回调函数，就调用回调函数
					} else {
						lock_guard<mutex> lock(mux_);
						outs_.push(tmp);//每次缓存一行输出的字符串到队列中，供GetOutput获取
					}
				}
				tmp = "";
				continue;
			}
			tmp += c;
		}
		_pclose(fp);
		running_ = false;
		return true;//异步执行完成
		});
	return true;
}

//获取控制台的输出
bool XExec::GetOutput(std::string& out) {
	lock_guard<mutex> lock(mux_);
	if (outs_.empty()) {
		return false;
	}
	out = move(outs_.front());
	outs_.pop();
	return true;
}