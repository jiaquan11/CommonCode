#pragma once
#include <memory>
#include "xtask.h"
//获取用户的输入，执行视频处理任务
class XVideoInput {
public:
	//开始接收用户输入，并调用task执行任务
	void Start(std::unique_ptr<XTask> task);
};

