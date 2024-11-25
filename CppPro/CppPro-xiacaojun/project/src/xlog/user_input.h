#pragma once

#include "xlog.h"
#include <map>
#include <string>
#include <functional>
#include <vector>

class XLOG_API UserInput{
public:
	//启动控制台任务获取用户输入
	void Start(std::function<void(std::vector<std::string>)>init = [] (std::vector<std::string>){});
	void Stop() {
		is_exit = true;
	}
	//注册参数处理的回调函数
	UserInput& Reg(std::string key, std::function<void(const std::string&)> func) {
		key_funcs_[key] = func;
		return *this;
	}

	UserInput& RegTask(std::string key, std::function<void()> func) {
		task_funcs_[key] = func;
		return *this;
	}
private:
	//任务循环是否退出
	bool is_exit{ false };
	//关键字映射函数表
	// key: -s -d
	// value: 回调函数传递参数
	std::map<std::string, std::function<void(const std::string&)>>key_funcs_;
	//初始化函数
	//std::function<void()>init_func_ = [] {};
	//任务执行函数
	std::map<std::string, std::function<void()>>task_funcs_;
};

