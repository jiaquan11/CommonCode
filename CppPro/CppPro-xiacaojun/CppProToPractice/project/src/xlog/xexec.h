#pragma once

#include "xlog.h"
#include <string>
#include <queue>
#include <future>
#include <functional>
/*
* 执行外部进程
*/
class XLOG_API XExec {
public:
	//执行外部进程
	//控制台命令
	//控制台输出回调，如果为空，不获取控制台输出，设置后不写入缓存队列
	bool Start(const char* cmd, std::function<void(const std::string&)> func = nullptr);
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

