#pragma once
#include <string>
#include <map>

//map ��ϣ��
// map<key,val>con;
// con[key]=val;
//��ȡini�������ļ�
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

