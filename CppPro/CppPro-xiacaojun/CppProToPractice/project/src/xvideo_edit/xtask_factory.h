#pragma once
#include "xtask.h"
#include <memory>

//����XTask����
class XTaskFactory {
public:
	static std::unique_ptr<XTask> Create(int type = 0);
};

