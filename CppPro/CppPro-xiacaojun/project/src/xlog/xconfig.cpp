#include "xconfig.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;
bool XConfig::Read(const std::string& file) {
	ifstream ifs(file);
	if (!ifs.is_open()) 
		return false;
	std::string line;
	for (;;) {
		getline(ifs, line);//读取每一行配置log_type=console
		std::string k, v;
		if (!line.empty()) {
			auto p = line.find('=');
			if (p <= 0) {
				continue;
			}
			k = line.substr(0, p);
			v = line.substr(p+1);
			cout << "k: " << k << " v:" << v << endl;
			conf_[k] = v;
		}
		//如果出错或者读到结尾
		if (!ifs.good()) {
			break;
		}
	}
	return true;
}

const std::string& XConfig::Get(const std::string& key)const {
	auto c = conf_.find(key);
	if (c == conf_.end()) {
		return "";
	}
	return c->second;
}