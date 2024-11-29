#pragma once
#include "xtask.h"
#include "xexec.h"

//基于ffmpeg和ffplay工具实现的音视频模块
class FFTask : public XTask {
	//开启音视频处理任务，立刻返回，在线程中处理
	bool Start(const Data&) override;
	//获取任务进度0-100
	int Progress() override {
		return progress_;
	}
	bool Running() override {
		return exec_.Running();
	}
	int TotalSec() override {
		return total_sec_;
	}
	void Clear() {
		total_sec_ = 0;
		progress_ = 0;
	}
private:
	int total_sec_{ 0 };//视频总时长
	int progress_{ 0 };//处理进度
	XExec exec_;
};

