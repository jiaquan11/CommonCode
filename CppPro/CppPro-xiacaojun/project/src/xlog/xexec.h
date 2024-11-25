#pragma once

#include "xlog.h"
#include <string>
#include <queue>
#include <future>

/*
* 执行外部进程
*/
class XLOG_API XExec {
public:
	//执行外部进程
	bool Start(const char* cmd);
	//任务是否还在执行
	bool Running() {
		return running_;
	}
	//获取控制台的输出
	bool GetOutput(std::string& out);
	bool Wait() {
		return fut_.get();
	}

private:
	bool running_{ false };
	//缓存队列
	std::queue<std::string> outs_;
	//任务执行线程
	std::future<bool> fut_;
	std::mutex mux_;
};

