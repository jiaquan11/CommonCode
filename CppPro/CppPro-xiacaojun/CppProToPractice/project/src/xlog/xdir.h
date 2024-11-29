#pragma once
#include "xlog.h"
#include <string>
#include <vector>

//目录处理，默认C++17
struct XLOG_API XFile {
	std::string name;
	std::string path;
	std::string ext;
};

class XLOG_API XDir{
public:
	//获取path目录下的所有文件
	// 参数：读取的目录文件
	//返回目录文件列表
	std::vector<XFile> GetFiles(const std::string& path);
	static bool IsDir(const std::string& path);
	static bool Create(const std::string& path);
};

