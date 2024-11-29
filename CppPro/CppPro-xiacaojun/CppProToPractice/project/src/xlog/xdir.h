#pragma once
#include "xlog.h"
#include <string>
#include <vector>

//Ŀ¼����Ĭ��C++17
struct XLOG_API XFile {
	std::string name;
	std::string path;
	std::string ext;
};

class XLOG_API XDir{
public:
	//��ȡpathĿ¼�µ������ļ�
	// ��������ȡ��Ŀ¼�ļ�
	//����Ŀ¼�ļ��б�
	std::vector<XFile> GetFiles(const std::string& path);
	static bool IsDir(const std::string& path);
	static bool Create(const std::string& path);
};

