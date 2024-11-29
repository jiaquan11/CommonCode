#pragma once
#include <fstream>
#include "log_output.h"

class LogFileOutput : public LogOutput {
public:
	bool Open(const std::string& file);

	void Output(const std::string& log) override;

private:
	std::ofstream ofs_;
};

