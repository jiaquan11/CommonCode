#pragma once
#include <string>

//音视频任务处理接口
class XTask {
public:
	struct Data {
		std::string type;//任务类型 cv play
		std::string src;//源文件
		std::string des;//目标文件
		bool is_enc{ true };//默认是加密  false表示解密
		std::string password;//加解密密钥
		int begin_sec{ 0 };//剪切的开始时间
		int end_sec{ 0 };//剪切的结束时间，0表示处理到结束
	};
	//开启音视频处理任务，立刻返回，在线程中处理
	virtual bool Start(const Data&) = 0;
	//获取任务进度0-100
	virtual int Progress() = 0;
	//任务是否处理结束
	virtual bool Running() = 0;
	//视频总时长（秒）
	virtual int TotalSec() = 0;
};