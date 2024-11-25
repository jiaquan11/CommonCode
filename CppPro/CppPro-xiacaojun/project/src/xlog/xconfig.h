#pragma once
#include <string>
#include <map>

//map 哈希表
// map<key,val>con;
// con[key]=val;
//读取ini的配置文件
/*
log.conf
log_type=console
log_file=log.txt
log_level=debug
*/
class XConfig {
public:
	bool Read(const std::string& file);
	const std::string& Get(const std::string& key) const;

private:
	std::map<std::string, std::string> conf_;
};

