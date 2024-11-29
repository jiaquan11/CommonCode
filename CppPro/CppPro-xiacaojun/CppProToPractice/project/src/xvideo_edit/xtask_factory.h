#pragma once
#include "xtask.h"
#include <memory>

//创建XTask对象
class XTaskFactory {
public:
	static std::unique_ptr<XTask> Create(int type = 0);
};

