#pragma once
#include "log_output.h"
class LogConsoleOutput : public LogOutput {
public:
	void Output(const std::string& log) override;
};

